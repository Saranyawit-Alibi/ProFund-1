#include <stdio.h>
#include <string.h>

char productID[100][20];
char productName[100][50];
int productQuantity[100];
char productDate[100][20];

int productCount = 0;

void OpenFile() {
    FILE *file = fopen("stock.csv","r");
    if(!file){
        printf("FILE : %p\n",file);
        printf("CANNOT OPEN FILE\n");
        return;
    }
    char line[200];
    while(fgets(line,sizeof(line),file)) {
        if (productCount >=100)break;
        sscanf(line,"%[^,],%[^,],%d,%s",
            productID[productCount],
            productName[productCount],
            &productQuantity[productCount],
            productDate[productCount]);
            productCount++;
    }
    fclose(file);
}
void WriteCSV(){
    FILE*file = fopen("stock.csv","w");
    if(file == NULL){
        printf("CANNOT OPEN FILE\n");
    }
    for(int i = 0 ; i < productCount ; i++) {
        fprintf(file,"%s,%s,%d,%s\n",
            productID[i],
            productName[i],
            productQuantity[i],
            productDate[i]);
    }
    fclose(file);
}
void ShowProduct(){
    printf("\n-----PRODUCT DATA-----\n");
    for (int i = 0 ; i < productCount ; i++) {
        printf("%s|%s|%d|%s\n",
            productID[i],
            productName[i],
            productQuantity[i],
            productDate[i]);
    }
}
void SearchProduct(){
    char name[40];
    printf("INPUT PRODUCT NAME : ");
    scanf("%s",name);
    
}
void AddProduct(){
        if(productCount>=100){
            printf("STOCK IS FULL\n");
            return;
        }
        printf("PRODUCT ID : ");
        scanf("%s",productID[productCount]);
        printf("PRODUCT NAME : ");
        scanf("%s",productName[productCount]);
        printf("QUANTITY : ");
        scanf("%d",&productQuantity[productCount]);
        printf("DATE(dd-mm-yyyy): ");
        scanf("%s",productDate[productCount]);
        productCount++;
        WriteCSV();
        printf("DONE!\n");
}
void UpdateProduct(){}
void DeleteProduct(){}
void Menu(){
    int ojo;
    do{
        printf("\n------MENU------\n");
        printf("1.SHOW PRODUCTS\n");
        printf("2.SEARCH PRODUCT\n");
        printf("3.ADD PRODUCT\n");
        printf("4.UPDATE PRODUCT\n");
        printf("5.DELETE PRODUCT\n");
        printf("0 TO EXIT\n");
        scanf("%d",&ojo);
        switch (ojo)
        {
            case 1 :ShowProduct();break;
            //case 2 :SearchProduct();break;
            case 3 :AddProduct();break;
            //case 4 :UpdateProduct();break;
            //case 5 :DeleteProduct();break;
        }
    } while (ojo != 0);
}

int main() {
        
    OpenFile();
    Menu();
    return 0;
}