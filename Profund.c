#include <stdio.h>
#include <string.h>

void OpenFile(){
    FILE*file = fopen("stock.csv","r");
    if(file == NULL){
        printf("FILE : %p\n",file);
        printf("CANNOT OPEN FILE\n");
    } else {
        printf("FILE : %p\n",file);
        printf("OPEN FILE\n");
    }
    fclose(file);
}
void ShowProduct(){}
void SearchProduct(){
    char name[40];
    printf("INPUT PRODUCT NAME : ");
    scanf("%s",name);
    
}
void AddProduct(){}
void UpdateProduct(){}
void DeleteProduct(){

}

void Menu(){
    int ojo;
    do{
        printf("------MENU------\n");
        printf("1.SHOW PRODUCTS\n");
        printf("2.SEARCH PRODUCT\n");
        printf("3.ADD PRODUCT\n");
        printf("4.UPDATE PRODUCT\n");
        printf("5.DELETE PRODUCT\n");
        scanf("%d",ojo);
        /*switch (ojo)
        {
            case 1 :ShowProduct();break;
            case 2 :SearchProduct();break;
            case 3 :AddProduct();break;
            case 4 :UpdateProduct();break;
            case 5 :DeleteProduct();break;
        }*/
    } while (ojo != 0);
}

    int main() {
        OpenFile();
        Menu();
        return 0;
    }