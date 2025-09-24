#include <stdio.h>
#include <string.h>

char productID[100][20];
char productName[100][20];
int productQuantity[100];
char productDate[100][20];

int productCount = 0;

void OpenFile(){
    FILE *file = fopen("stock.csv","r");
    if(!file){
        printf("FILE : %p\n",file);
        printf("CANNOT OPEN FILE\n");
        return;
    }
    char line [200];
    while(fgets(line,sizeof(line),file)) {
        if (productCount >=100)break;
        sscanf(line,"%[^,],%[^,],%d,%s",
            productID[productCount],
            productName[productCount],
            productQuantity[productCount],
            productDate[productCount]);
    }
    fclose(file);
}
void ShowProduct(){
}
void SearchProduct(){
    char name[40];
    printf("INPUT PRODUCT NAME : ");
    scanf("%s",name);
    
}
void AddProduct(){
    FILE*file = fopen("stock.csv","w");
    if(file == NULL){
        printf("FILE : %p\n",file);
        printf("CANNOT OPEN FILE\n");
    }
    

    printf("ADD PRODUCT : ID , NAME , QUANTITY , DATE\n");
    //scanf("%s","%s","%d","%s",);
    //fprintf(file,"%s","%s","%d","%s",);

    fclose(file);

}
void UpdateProduct(){}
void DeleteProduct(){}
void Menu(){
    int ojo;
    do{
        printf("------MENU------\n");
        printf("1.SHOW PRODUCTS\n");
        printf("2.SEARCH PRODUCT\n");
        printf("3.ADD PRODUCT\n");
        printf("4.UPDATE PRODUCT\n");
        printf("5.DELETE PRODUCT\n");
        printf("0 TO EXIT\n");
        scanf("%d",&ojo);
        switch (ojo)
        {
            //case 1 :ShowProduct();break;
            //case 2 :SearchProduct();break;
            //case 3 :AddProduct();break;
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