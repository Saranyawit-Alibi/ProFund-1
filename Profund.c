#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_LEN 100
#define FILENAME "inventory.csv"

typedef struct {
    char productID[20];
    char productName[50];
    int stockQuantity;
    char inspectionDate[20];
} Product;

Product products[MAX_PRODUCTS];
int productCount = 0;

// อ่านข้อมูลจากไฟล์ CSV
void loadCSV() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No file name %s Making new file...\n", FILENAME);
        return;
    }
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        if (productCount >= MAX_PRODUCTS) break;
        Product p;
        sscanf(line, "%[^,], %[^,], %d, %s",
               p.productID, p.productName, &p.stockQuantity, p.inspectionDate);
        products[productCount++] = p;
    }
    fclose(file);
}

// เขียนข้อมูลกลับไปที่ CSV
void saveCSV() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Cannot write file\n");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%s,%s,%d,%s\n",
                products[i].productID,
                products[i].productName,
                products[i].stockQuantity,
                products[i].inspectionDate);
    }
    fclose(file);
}

// แสดงสินค้าทั้งหมด
void displayAll() {
    printf("\n--- Products info ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("%s | %s | %d | %s\n",
               products[i].productID,
               products[i].productName,
               products[i].stockQuantity,
               products[i].inspectionDate);
    }
}

// เพิ่มสินค้าใหม่
void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Stock max\n");
        return;
    }
    Product p;
    printf("Input ProductID: ");
    scanf("%s", p.productID);
    printf("Input Product Name: ");
    scanf("%s", p.productName);
    printf("Input Amount: ");
    scanf("%d", &p.stockQuantity);
    printf("Input Date (YYYY-MM-DD): ");
    scanf("%s", p.inspectionDate);

    products[productCount++] = p;
    saveCSV();
    printf("Item Added\n");
}

// ค้นหาสินค้า
void searchProduct() {
    char key[50];
    printf("input ProductID or product name: ");
    scanf("%s", key);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].productID, key) == 0 ||
            strcmp(products[i].productName, key) == 0) {
            printf("Found: %s | %s | %d | %s\n",
                   products[i].productID,
                   products[i].productName,
                   products[i].stockQuantity,
                   products[i].inspectionDate);
            return;
        }
    }
    printf("Product not found\n");
}

// อัปเดตข้อมูลสินค้า
void updateProduct() {
    char key[50];
    printf("Input ProductID to update: ");
    scanf("%s", key);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].productID, key) == 0) {
            printf("Product: %s | %s | %d | %s\n",
                   products[i].productID,
                   products[i].productName,
                   products[i].stockQuantity,
                   products[i].inspectionDate);

            printf("Input New Amount: ");
            scanf("%d", &products[i].stockQuantity);
            saveCSV();
            printf("Updated\n");
            return;
        }
    }
    printf("Product not found\n");
}

// ลบสินค้า
void deleteProduct() {
    char key[50];
    printf("Input ProductID to delete: ");
    scanf("%s", key);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].productID, key) == 0) {
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
            saveCSV();
            printf("Deleted\n");
            return;
        }
    }
    printf("Product not found\n");
}

// เมนูหลัก
void menu() {
    int choice;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Show products\n");
        printf("2. Add products\n");
        printf("3. Serch product\n");
        printf("4. Update product\n");
        printf("5. Delete product\n");
        printf("0. Close program\n");
        printf("Choose: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: displayAll(); break;
            case 2: addProduct(); break;
            case 3: searchProduct(); break;
            case 4: updateProduct(); break;
            case 5: deleteProduct(); break;
        }
    } while (choice != 0);
}

int main() {
    loadCSV();
    menu();
    return 0;
}