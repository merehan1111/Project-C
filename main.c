#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define DEFAULT_COLOR 10
#define HIGHLIGHT_COLOR 18





/*

 void setTextColor(int color)
 {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
 }*/




typedef struct product product;
typedef struct category category;
typedef struct supermarket supermarket;

struct product
{
    char productName[30];
    int productPrice;
    int productQuantity;
};
struct category
{
    char categoryName[30];
    product products[30];
    int productCount;
};
struct supermarket
{
    category categorys[30];
    int categoryCount;

};


void initialSuper(supermarket *S)
{
    S->categoryCount =2;

    for(int i=0; i<2; i++)
    {
        S->categorys[i].productCount=2;
    }
        //c1
        strcpy(S->categorys[0].categoryName,"healthy_food");
        //c2
        strcpy(S->categorys[1].categoryName,"fish&meet");
        //p1
        strcpy(S->categorys[0].products[0].productName, "Broccoli");
        strcpy(S->categorys[0].products[1].productName, " Cucumber");
        //p2
        strcpy(S->categorys[1].products[0].productName, "salmon");
        strcpy(S->categorys[1].products[1].productName, " Lamb");
        //p1
        S->categorys[0].products[0].productPrice = 55;
        S-> categorys[0].products[0].productQuantity =2;
        S->categorys[0].products[1].productPrice = 100;
        S-> categorys[0].products[1].productQuantity =4;

        //p2
        S->categorys[1].products[0].productPrice = 300;
        S-> categorys[1].products[0].productQuantity =1;
        S->categorys[1].products[1].productPrice = 800;
        S-> categorys[1].products[1].productQuantity =2;


}

void displayProduct(supermarket *S)
{
    for(int i=0 ; i<S->categoryCount ; i++)
    {        printf("\n");


        printf(" (%d)categoryName:%s \n",i+1,S->categorys[i].categoryName);
        for(int j=0; j < S->categorys[i].productCount ; j++)
        {


            printf("\n    (%d)productName:%s      productPrice:%d      productQuantity:%d \n",j+1,S->categorys[i].products[j].productName
                   ,S->categorys[i].products[j].productPrice, S->categorys[i].products[j].productQuantity  );
        }
                printf("\n\n\n");

    }

}
void addCategory(supermarket *S)
{
    char catName[30];
    printf("Enter category");
    scanf("%s",catName);
    int categoryIndex = -1;
    for(int i=0; i<S->categoryCount ; i++)
    {
        if(strcmp(S->categorys[i].categoryName, catName)==0)
        {
            categoryIndex=i;
            break;
        }
    }
    if(categoryIndex ==-1)
    {

        strcpy(S->categorys[S->categoryCount].categoryName,catName);
        S->categorys[S->categoryCount].productCount=0;
        S->categoryCount++;
        printf("your added this success");
    }
    else
    {
        printf("NO place");
    }
}
void removeCategory(supermarket *S)
{
    if(S->categoryCount>0)
    {
        char catName[30];
        printf("Enter category want to remove");
        scanf("%s",catName);
        int categoryIndex = -1;
       for(int i=0; i<S->categoryCount ; i++)
       {
          if(strcmp(S->categorys[i].categoryName, catName)==0)
          {
            categoryIndex=i;
            break;
          }
        }
        if(categoryIndex !=-1)
        {
            for(int i=categoryIndex; i<S->categoryCount-1;i++)
            {
                S->categorys[i]=S->categorys[i+1];

            }
            S->categoryCount--;


            printf("Category removed successfully.\n");
        } else {
            printf("Category not found.\n");
        }





    }

}

void addproduct(supermarket *S)
{
    char catName[30];
    char pName[30];
    printf("Enter name of category");
    scanf("%s",catName);
    printf("Enter name of product");
    scanf("%s",pName);
    int price,quantity;
    int categoryIndex = -1;
   for(int i=0; i<S->categoryCount ; i++)
    {

       if(strcmp(S->categorys[i].categoryName, catName)==0)
      {
          printf("************************************************\n");
          categoryIndex=i;
          break;
      }
   }
  if(categoryIndex !=-1)

    {

      if(S->categorys[categoryIndex].productCount < 30)
            {


            printf("Enter price of pruduct");
            scanf("%d",&price);


              printf("Enter quantity of product");
              scanf("%d",&quantity);

           strcpy(S->categorys[ categoryIndex].products[S->categorys[ categoryIndex].productCount].productName , pName);
           S->categorys[categoryIndex].products[S->categorys[categoryIndex].productCount].productPrice=price;
           S->categorys[categoryIndex].products[S->categorys[categoryIndex].productCount].productQuantity=quantity;
           S->categorys[categoryIndex].productCount++;
        }

    printf("your added this success");

    }
    else
    {
        printf("NO place");

    }

}void removeProduct(supermarket *S) {
    if (S->categoryCount > 0) {
        char catName[30];
        char pName[30];
        printf("Enter the name of the category you want to remove: ");
        scanf("%s", catName);
        printf("Enter the name of the product you want to remove: ");
        scanf("%s", pName);

        int categoryIndex = -1;
        for (int i = 0; i < S->categoryCount; i++) {
            if (strcmp(S->categorys[i].categoryName, catName) == 0) {
                categoryIndex = i;
                break;
            }
        }

        int productIndex = -1;
        if (categoryIndex != -1) {
            for (int i = 0; i < S->categorys[categoryIndex].productCount; i++) {
                if (strcmp(S->categorys[categoryIndex].products[i].productName, pName) == 0) {
                    productIndex = i;
                    break;
                }
            }
        }

        if (productIndex != -1) {
            for (int i = productIndex; i < S->categorys[categoryIndex].productCount; i++) {
                S->categorys[categoryIndex].products[i] = S->categorys[categoryIndex].products[i + 1];
            }
            S->categorys[categoryIndex].productCount--;
        }
    }
}


void moveProduct(supermarket *S) {
    if (S->categoryCount > 1) {
        char pName[30];
        char sourceName[30];
        char destinationCatName[30];
        int sourceCategoryIndex = -1;

        printf("Enter the name of the category you want to move the product from: ");
        scanf("%s", sourceName);

        for (int i = 0; i < S->categoryCount; i++) {
            if (strcmp(S->categorys[i].categoryName, sourceName) == 0) {
                sourceCategoryIndex = i;
                break;
            }
        }

        int productIndex = -1;

        printf("Enter the name of the product you want to move: ");
        scanf("%s", pName);

        for (int i = 0; i < S->categorys[sourceCategoryIndex].productCount; i++) {
            if (strcmp(S->categorys[sourceCategoryIndex].products[i].productName, pName) == 0) {
                productIndex = i;
                break;
            }
        }

        int destinationCatIndex = -1;
        char destinationName[30];

        printf("Enter the name of the destination category: ");
        scanf("%s", destinationName);

        for (int i = 0; i < S->categoryCount; i++) {
            if (strcmp(S->categorys[i].categoryName, destinationName) == 0) {
                destinationCatIndex = i;
                break;
            }
        }

        if (destinationCatIndex != -1) {
            int destinationProdIndex = -1;

            for (int i = 0; i < S->categorys[destinationCatIndex].productCount; i++) {
                if (strcmp(S->categorys[destinationCatIndex].products[i].productName, pName) == 0) {
                    destinationProdIndex = i;
                    break;
                }
            }

            if (destinationProdIndex == -1) {
                S->categorys[destinationCatIndex].products[S->categorys[destinationCatIndex].productCount] =
                    S->categorys[sourceCategoryIndex].products[productIndex];
                S->categorys[destinationCatIndex].productCount++;

                for (int i = productIndex; i < S->categorys[sourceCategoryIndex].productCount - 1; i++) {
                    S->categorys[sourceCategoryIndex].products[i] = S->categorys[sourceCategoryIndex].products[i + 1];
                }

                S->categorys[sourceCategoryIndex].productCount--;
                printf("Moved the product %s from %s to %s successfully.\n\n", pName, sourceName, destinationName);
            }
        }
    }
}
void sellProduct(supermarket *S){

    int SumPrice=0;
    char pName[30];
    char cName[30];
    int quantity;
    int price;
    int categoryIndex=-1;

    printf("enter category want to sell \n");
    scanf("%s",cName);

    for(int i =0 ; i< S->categoryCount ; i++)
    {
        if(strcmp(S->categorys[i].categoryName,cName)==0)
        {
           categoryIndex = i;
            break;
        }
    }

    int productIndex = -1;

    if(categoryIndex != -1)
    {
        printf("enter name of product want to sell \n");
        scanf("%s",pName);

        for(int i =0 ; i< S->categorys[categoryIndex].productCount ; i++)
        {
            if(strcmp(S->categorys[categoryIndex].products[i].productName,pName)==0)
            {
                productIndex=i;
                break;
            }
        }
    }

    if(S->categorys[categoryIndex].products[productIndex].productQuantity>0)
    {
        printf("Enter quantity of product you want sell\n");

        do
        {
            if(scanf("%d", &quantity) == 1 && quantity> 0)
               {
                    break;
               }
               else
               {
                    printf("NON.\n");
               }

        }while(1);

       if(quantity <= S->categorys[categoryIndex].products[productIndex].productQuantity)
       {
            S->categorys[categoryIndex].products[productIndex].productQuantity -= quantity;
            SumPrice+=quantity*S->categorys[categoryIndex].products[productIndex].productPrice;

       }
       printf(" \n\n you sell  %s from category %s and the quantity %d and the Sumprice is %d \n\n",pName,cName,quantity,SumPrice);
        getche();
    }

}
void gotoxy(short x, short y)
{
    COORD coord ={0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


int main()

{


     supermarket S;
    initialSuper(&S);
    displayProduct(&S);


    int choose = 0;

    char menu[8][100] =
    {
        "Display Elandalis  market ",
        "Add Categorys",
        "Remove Categorys",
        "Add Products",
        "Remove Products",
        "Move Products",
        "Sell Products",
        "    Exit",
    };
    while (1)
    {
        system("cls");


         gotoxy(5, 1);
        printf("Elandalis Market \n");
        gotoxy(5, 2);
        printf("------------------------------");


        for (int i = 0; i < 8; i++)
        {

            gotoxy(2, 4 +i);

            if (choose  == i)
            {


                printf("/*/ %s /*/", menu[i]);

            }
            else
            {


                printf("   %s", menu[i]);

            }

        }


        char key = _getch();

        switch (key)
        {
        case 72:

            if (choose <= 0)
            {
                choose = 7;
            }
            else
            {
                choose--;
            }

            break;

        case 80:

            if (choose >= 7)
            {
                choose = 0;
            }
            else
            {
                choose++;
            }

            break;

        case 13:
            switch (choose)
            {
            case 0:
                system("cls");

                printf("OUR CATEGORIES & PRODUCTS: \n");

                displayProduct(&S);
                _getch();
                system("cls");
                break;

            case 1:
                system("cls");

                printf(" ADD CATEGORY:  ");
                displayProduct(&S);
                printf("\n\n");

                addCategory(&S);
                system("cls");
                break;

            case 2:

                system("cls");

                printf("REMOVE A CATEGORY: \n");
                displayProduct(&S);
                printf("\n\n");
                removeCategory(&S);

                system("cls");
                break;

            case 3:
                system("cls");
                printf(" ADD A NEW PRODUCT: \n");
                displayProduct(&S);
                printf("\n\n");
                addproduct(&S);;
                break;

            case 4:
                system("cls");
                printf("REMOVE A PRODUCT: \n");
                displayProduct(&S);
                printf("\n\n");
               removeProduct(&S);
                break;

            case 5:
                system("cls");
                system("cls");
                printf("MOVE A PRODUCT: \n");
                displayProduct(&S);
                printf("\n\n");
                moveProduct(&S);
                break;
            case 6:
                system("cls");
                printf("SELL A PRODUCT: \n");
                displayProduct(&S);
                printf("\n\n");
                sellProduct(&S);
                break;

            case 7:
                system("cls");
                return 0;
                break;
            }
        }
    }



/*
    supermarket S;
    initialSuper(&S);
    //displayProduct(&S);
    addCategory(&S);
    //displayProduct(&S);
    //removeCategory(&S);
    //displayProduct(&S);
    addproduct(&S);
    displayProduct(&S);
    removeProduct(&S);
    moveProduct(&S);
    displayProduct(&S);
*/




    return 0;

}
