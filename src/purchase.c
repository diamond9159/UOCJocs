#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"
#include "purchase.h"
#include "bgame.h"

void purchaseTableInit(tPurchaseTable *purchasesTable) {
	
	purchasesTable->nPurchases= 0;
}

void purchaseTableLoad(tPurchaseTable *tabPurchases, const char* filename, tError *retVal) {

    *retVal = OK;

    FILE *fin=NULL;
    char line[MAX_LINE];
    tPurchase newPurchase;


    /* Initialize the output table */
    purchaseTableInit(tabPurchases);

    /* Open the input file */
    if((fin=fopen(filename, "r"))!=NULL) {

        /* Read all the stores */
        while(!feof(fin) && tabPurchases->nPurchases<MAX_PURCHASES) {
            /* Remove any content from the line */
            line[0] = '\0';
            /* Read one line (maximum 511 chars) and store it in "line" variable */
            fgets(line, MAX_LINE-1, fin);
            /* Ensure that the string is ended by 0*/
            line[MAX_LINE-1]='\0';
            if(strlen(line)>0) {
                /* Obtain the object */
                getPurchaseObject(line, &newPurchase);
                purchaseTableAdd(tabPurchases, newPurchase, retVal);
            }
        }
        /* Close the file */
        fclose(fin);

    }else {
        *retVal = ERR_CANNOT_READ;
    }
}
/* The content of the string str is parsed into the fields of the purchase structure */
void getPurchaseObject(const char *str, tPurchase *purchase)
{
    int auxPurchaseId, auxStoreId, auxNPurchased;
    float auxPrice;
    char buffer[MAX_LINE];

    /* read purchase data */
    sscanf(str, "%d %d %s %d %d/%d/%d %f",
        &auxPurchaseId, &auxStoreId, buffer, &auxNPurchased,
        &purchase->date.day, &purchase->date.month, &purchase->date.year, &auxPrice);

    strcpy(purchase->orders[0].bgame, buffer);
    purchase->orders[0].nPurchased = auxNPurchased;
    purchase->orders[0].price = auxPrice;

    purchase->purchaseId = (tPurchaseId)auxPurchaseId;
    purchase->storeId = (tStoreId)auxStoreId;
    purchase->nOrders = 1;
    purchase->price = purchase->orders[0].price * purchase->orders[0].nPurchased;
}

/* The content of the string str is parsed into the fields of the purchase structure */
void purchaseTableAdd(tPurchaseTable *tabPurchase, tPurchase newPurchase, tError *retVal)
{
    int iPurchase;

    *retVal = OK;
    if ( tabPurchase->nPurchases == MAX_ORDERS ){
        *retVal = ERR_MEMORY;
    } else{
        iPurchase = tabPurchaseFind(tabPurchase, newPurchase.purchaseId);
        if ( iPurchase == NO_PURCHASE ){ /* Purchase not existing */
            purchaseCpy (&(tabPurchase->table[tabPurchase->nPurchases]), newPurchase);
            tabPurchase->nPurchases++;           
        }
        else{ /* Purchase existing: add new order to it */
            orderCpy(&(tabPurchase->table[iPurchase].orders[tabPurchase->table[iPurchase].nOrders]), newPurchase.orders[0]);
            tabPurchase->table[iPurchase].nOrders++;
            tabPurchase->table[iPurchase].price += newPurchase.price;
        }
    }
}

int tabPurchaseFind (tPurchaseTable *tabPurchase, tPurchaseId id)
{
    int idx = NO_PURCHASE;
    int i;
    for ( i = 0; i < tabPurchase->nPurchases && ( idx == NO_PURCHASE ); i++ ) {
        if (tabPurchase->table[i].purchaseId == id)
        {
            idx = i;
        }
    }
    return idx;
}

void purchaseCpy(tPurchase *dst, tPurchase src) 
{   
    int i; 
    dst->purchaseId = src.purchaseId;
    dst->storeId = src.storeId;
    for (i = 0; i < src.nOrders; i++){
        orderCpy(&(dst->orders[i]), src.orders[i]);
    }
    dst->nOrders = src.nOrders;
    dateCpy(&(dst->date), src.date);
    dst->price = src.price;
}

void orderCpy(tOrder *dst, tOrder src) 
{    
    strcpy(dst->bgame, src.bgame);
    dst->nPurchased = src.nPurchased;
    dst->price = src.price;
}

int dateCmp( tDate d1, tDate d2 ) {

    int result;

    result= 0;

    if (d1.year > d2.year)
        result= 1;
    else if (d1.year < d2.year)
        result= -1;
    else {
        if (d1.month > d2.month)
            result= 1;
        else if (d1.month < d2.month)
            result= -1;
        else {
            if (d1.day > d2.day)
                result= 1;
            else if (d1.day < d2.day)
                result= -1;
        }
    }

    return result;
}

void dateCpy( tDate *d1, tDate d2 )
{
    d1->year= d2.year;
    d1->month= d2.month,
    d1->day= d2.day;
}

void purchaseTableSave(tPurchaseTable *tabPurchases, const char* filename, tError *retVal) {
    
    *retVal = OK;

    FILE *fout=NULL;
    int i, j;
    char str[MAX_LINE];
    
    /* Open the output file */
    if((fout=fopen(filename, "w"))==0) {
        *retVal = ERR_CANNOT_WRITE;
    } 
    else 
    {
        /* Save general purchase data to the file */
        for(i=0;i<tabPurchases->nPurchases;i++) 
        {
            for(j=0;j<tabPurchases->table[i].nOrders;j++) 
            {
                getPurchaseStr(tabPurchases->table[i], tabPurchases->table[i].orders[j], MAX_LINE, str);
                fprintf(fout, "%s\n", str);
            }
        }
                    
        /* Close the file */
        fclose(fout);
    }
}

/* The content of the fields of the purchase structure is written into the string str */
void getPurchaseStr(tPurchase purchase, tOrder order, int maxSize, char *str)
{
    /* Build the string */
    snprintf(str,maxSize-1,"%d %d %s %d %d/%d/%d %.2f",
             (int)purchase.purchaseId, (int)purchase.storeId,
             order.bgame, order.nPurchased,
             purchase.date.day, purchase.date.month, purchase.date.year,
             order.price);
}

void purchaseTableFilterByYearAndStore (tPurchaseTable *tabPurchases, int year, tStoreId storeId, tError *retVal, float *benefit){
    /*****************************************/
    /* Exercise 8b */    
    /*****************************************/













    /*****************************************/
}


void lessPopularCategory (tPurchaseTable *tabPurchases, tStoresTable *tabStores, tStoreId id, tError *retVal, tGameCategory *cat ){
    /*****************************************/
    /* Exercise 9b */    
    /*****************************************/














































    /*****************************************/
}

void newPurchase(tStoresTable *tabStores, tPurchaseTable *tabPurchase, tError *retVal) { 
    tError rVal;
    tPurchase purchase;
    *retVal = ERROR;
    int number, i, iPurchase, iStore, amount, toSell;
    char buffer[MAX_NAME];
    iStore = NO_STORE;
    
    while (*retVal == ERROR) {
        printf("Purchase id (integer between 1 and %d):\n>> ", MAX_PURCHASES);
        scanf("%d",&number);
        if(number >= 1 && number <= MAX_PURCHASES) {
            iPurchase = tabPurchaseFind(tabPurchase, number);
            if(iPurchase != NO_PURCHASE){
                printf("That purchase id is not valid, it already exists\n");
            } else{
                purchase.purchaseId= (tPurchaseId)number;
                *retVal = OK;
            }
        }
    }
    
    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("Store id (integer between 1 and %d):\n>> ", MAX_STORES);
        scanf("%d",&number);
        if(number >= 1 && number <= MAX_STORES) {
            iStore = storeTableFind(*tabStores, number);
            if(iStore == NO_STORE){
                printf("Not a valid store id\n");
            } else{
                purchase.storeId= (tStoreId)(number);
                *retVal = OK;
            }
        }
    }

    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("Number of board games to buy (integer between 1 and %d):\n>> ", MAX_ORDERS);
        scanf("%d",&number);
        if(number >= 1 && number <= MAX_ORDERS) {
            purchase.nOrders= number;
            *retVal = OK;
        }
    }

    purchase.price = 0.0;

    
    for ( i=0; i<purchase.nOrders; i++){
        *retVal = ERROR;
        while ( *retVal == ERROR ){
            printf("Name of the game to buy (order %d):\n>> ", i);
            scanf("%s", buffer);
            printf("Indicate the number of copies to buy:\n>>");
            scanf("%d", &amount);
            checkAvailability(&(tabStores->table[iStore]), buffer, amount, &rVal, &toSell);
            if ( toSell == 0){
                printf("Sorry, that game is not available\n");
            } else if (amount > toSell) {
                amount = toSell;
                printf("Sorry, only %d copies of that game will be sold\n", toSell);
                *retVal = OK;
            } else{
                printf("The game is available and the desired number of copies can be served\n");
                *retVal = OK;
            }
        }
        strcpy(purchase.orders[i].bgame, buffer);
        purchase.orders[i].nPurchased = amount;
        calculatePrice(&(tabStores->table[iStore]), buffer, 1, &rVal, &(purchase.orders[i].price));
        purchase.price += purchase.orders[i].price * purchase.orders[i].nPurchased;
    }
    
    printf("Set the purchase date:\n");
    number = 0;
    while(number < 1 || number > 31){
        printf("Day (between 1 and 31):\n>> ");
        scanf("%d",&number);
    }
    purchase.date.day = number;
    number = 0;
    while(number < 1 || number > 12){
        printf("Month (between 1 and 12):\n>> ");
        scanf("%d",&number);
    }
    purchase.date.month = number;
    number = 0;
    while(number < MIN_YEAR || number > MAX_YEAR ){
        printf("Year:\n>> ");
        scanf("%d",&number);
    }
    purchase.date.year = number;

    purchaseTableAdd(tabPurchase, purchase, retVal);
}

void purchaseTableDel(tPurchaseTable *tabPurchase, tPurchaseId id){
    int i, idx;
    idx = tabPurchaseFind (tabPurchase, id);
    if (idx != NO_PURCHASE){
        for(i=idx; i<tabPurchase->nPurchases-1; i++) {        
            purchaseCpy(&(tabPurchase->table[i]),tabPurchase->table[i+1]);
        }
        tabPurchase->nPurchases=tabPurchase->nPurchases-1;
    }
}
