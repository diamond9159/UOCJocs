#include <stdio.h>
#include <math.h>
#include <string.h>
#include <api.h>
#include <time.h>

#include "data.h"
#include "bgame.h"
#include "store.h"
#include "purchase.h"

void appDataInit(tAppData *object) 
{
	/* Set parent folder as the default path */
	strcpy(object->path, ""); // "../");
	
	/* Initialize the stores table */
	storeTableInit(&(object->stores));
	
	/* Initialize the purchases table */
	purchaseTableInit(&(object->purchases));
}

void appDataLoad(tAppData *object, tError *retVal) {
	char path[MAX_LINE];
	*retVal = OK;
	
	/* Load the table of stores */
	snprintf(path,MAX_PATHNAME+MAX_FILENAME,"%sstores.txt", object->path);
	printf("Reading stores...\n");
	storeTableLoad(&(object->stores), path, retVal);
	if(*retVal!=OK) {
		printf("ERROR: Error reading the file of stores\n");
	}

    /* Populate stores' inventories */
    snprintf(path,MAX_PATHNAME+MAX_FILENAME,"%sbgames.txt", object->path);
    printf("Reading bgames...\n");
    inventoriesLoad(&(object->stores), path, retVal);
    if(*retVal!=OK) {
		printf("ERROR: Error reading the file of bgames (to set inventories)\n");
	}

	/* Load the table of purchases */
	snprintf(path,MAX_PATHNAME+MAX_FILENAME,"%spurchases.txt", object->path);
	printf("Reading purchases...\n");
	purchaseTableLoad(&(object->purchases), path, retVal);
	if(*retVal!=OK) {
		printf("ERROR: Error reading the file of purchases\n");
	}
}

void appDataSave(tAppData object, tError *retVal)  {
	char path[MAX_LINE];
	*retVal = OK;
	
	/* Save the table of stores */
	snprintf(path,MAX_PATHNAME+MAX_FILENAME,"%sstores.txt", object.path);
	storesTableSave(object.stores, path, retVal);
	printf("Saving stores (stores.txt)...\n");
	if(*retVal!=OK) {
		printf("ERROR: Error saving the file of stores\n");
	}
	
	/* Save the table of stores' inventories */
	snprintf(path,MAX_PATHNAME+MAX_FILENAME,"%sbgames.txt", object.path);
	printf("Saving inventories (bgames.txt)...\n");
	inventoriesTableSave(object.stores, path, retVal);
	if(*retVal!=OK) {
		printf("ERROR: Error saving the file of bgames\n");
	}
    
	/* Save the table of purchases */
	snprintf(path,MAX_PATHNAME+MAX_FILENAME,"%spurchases.txt", object.path);
	printf("Saving purchases (purchases.txt)...\n");
	purchaseTableSave(&(object.purchases), path, retVal);
	if(*retVal!=OK) {
		printf("ERROR: Error saving the file of purchases\n");
	}
}

void appDataSetPath(tAppData *object, const char *path)  {		
	strncpy(object->path, path, MAX_PATHNAME - 1);	
}


/*********************** 
 *        API
 **********************/

void getStores(tAppData object, tStoresTable *result) {
	*result = object.stores;	
}

void getPurchases(tAppData object, tPurchaseTable *result) {
	printf("Get purchases---\n");
	*result = object.purchases;	
}

void addBGame(tStore *store, tBGame newBGame, tError *retVal) {
    /*****************************************/
    /* Exercise 5a */    
    /*****************************************/
















 










    /*****************************************/
}

void checkStoreCapacity(tStore *store, bool *dtApplied) {
    /*****************************************/
    /* Exercise 5b */    
    /*****************************************/







    /*****************************************/
}


void printPurchaseTickets(tPurchaseTable *tabPurchases) {
    int i;
    for (i=0; i<tabPurchases->nPurchases; i++)
        printTickets(&(tabPurchases->table[i]));
}


void printTickets (tPurchase *purchase){
    /*****************************************/
    /* Exercise 7 */    
    /*****************************************/








    /*****************************************/
}
