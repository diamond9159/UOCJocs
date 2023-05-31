#include "bgame.h"
#include "data.h"
#include "purchase.h"
#include "store.h"

#include <api.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void appDataInit(tAppData* object)
{
    /* Set parent folder as the default path */
    strcpy(object->path, ""); // "../");

    /* Initialize the stores table */
    storeTableInit(&(object->stores));

    /* Initialize the purchases table */
    purchaseTableInit(&(object->purchases));
}

void appDataLoad(tAppData* object, tError* retVal)
{
    char path[MAX_LINE];
    *retVal = OK;

    /* Load the table of stores */
    snprintf(path, MAX_PATHNAME + MAX_FILENAME, "%sstores.txt", object->path);
    printf("Reading stores...\n");
    storeTableLoad(&(object->stores), path, retVal);
    if(*retVal != OK) {
        printf("ERROR: Error reading the file of stores\n");
    }

    /* Populate stores' inventories */
    snprintf(path, MAX_PATHNAME + MAX_FILENAME, "%sbgames.txt", object->path);
    printf("Reading bgames...\n");
    inventoriesLoad(&(object->stores), path, retVal);
    if(*retVal != OK) {
        printf("ERROR: Error reading the file of bgames (to set inventories)\n");
    }

    /* Load the table of purchases */
    snprintf(path, MAX_PATHNAME + MAX_FILENAME, "%spurchases.txt", object->path);
    printf("Reading purchases...\n");
    purchaseTableLoad(&(object->purchases), path, retVal);
    if(*retVal != OK) {
        printf("ERROR: Error reading the file of purchases\n");
    }
}

void appDataSave(tAppData object, tError* retVal)
{
    char path[MAX_LINE];
    *retVal = OK;

    /* Save the table of stores */
    snprintf(path, MAX_PATHNAME + MAX_FILENAME, "%sstores.txt", object.path);
    storesTableSave(object.stores, path, retVal);
    printf("Saving stores (stores.txt)...\n");
    if(*retVal != OK) {
        printf("ERROR: Error saving the file of stores\n");
    }

    /* Save the table of stores' inventories */
    snprintf(path, MAX_PATHNAME + MAX_FILENAME, "%sbgames.txt", object.path);
    printf("Saving inventories (bgames.txt)...\n");
    inventoriesTableSave(object.stores, path, retVal);
    if(*retVal != OK) {
        printf("ERROR: Error saving the file of bgames\n");
    }

    /* Save the table of purchases */
    snprintf(path, MAX_PATHNAME + MAX_FILENAME, "%spurchases.txt", object.path);
    printf("Saving purchases (purchases.txt)...\n");
    purchaseTableSave(&(object.purchases), path, retVal);
    if(*retVal != OK) {
        printf("ERROR: Error saving the file of purchases\n");
    }
}

void appDataSetPath(tAppData* object, const char* path) { strncpy(object->path, path, MAX_PATHNAME - 1); }

/***********************
 *        API
 **********************/

void getStores(tAppData object, tStoresTable* result) { *result = object.stores; }

void getPurchases(tAppData object, tPurchaseTable* result)
{
    printf("Get purchases---\n");
    *result = object.purchases;
}

void addBGame(tStore* store, tBGame newBGame, tError* retVal)
{
    /*****************************************/
    /* Exercise 5a */
    /*****************************************/

    int nBGamesCopy = store->inventory.nBGames;
    int nStoredBGamesCopy = store->inventory.nStoredBGames;

    *retVal = ERROR;

    if(nBGamesCopy == MAX_BGAMES) {
        *retVal = ERR_MEMORY;
    } else {
        if((nStoredBGamesCopy + newBGame.availability) > store->maxStorage) {
            *retVal = ERR_FULL_WAREHOUSE;
            newBGame.availability = 0;
        }

        int pos;
        pos = bgameTableFindId(&(store->inventory.games), newBGame.bgameId);
        if(pos != NO_BGAME) {
            store->inventory.games.table[nBGamesCopy] = newBGame;
            store->inventory.games.nBGames++;

            store->inventory.storeId = store->storeId;
            store->inventory.nBGames = store->inventory.games.nBGames;
        }
        store->inventory.nStoredBGames += newBGame.availability;
        if(*retVal != ERR_FULL_WAREHOUSE)
            *retVal = OK;
    }

    /*****************************************/
}

void checkStoreCapacity(tStore* store, bool* dtApplied)
{
    /*****************************************/
    /* Exercise 5b */
    /*****************************************/
#define FULL_RATE 0.8;

    int nStoredBGamesCopy = store->inventory.nStoredBGames;
    float full = 1.0 - (float)((float)nStoredBGamesCopy / (float)store->maxStorage);

    if(full >= FULL_RATE) {
        store->specialDiscount = 20.0;
        *dtApplied = true;
    } else {
        store->specialDiscount = 0.0;
        *dtApplied = false;
    }

    /*****************************************/
}

void printPurchaseTickets(tStoresTable* tabStores, tPurchaseTable* tabPurchases)
{
    int i;
    for(i = 0; i < tabPurchases->nPurchases; i++)
        printTickets(tabStores, &(tabPurchases->table[i]));
}

void printTickets(tStoresTable* tabStores, tPurchase* purchase)
{
    /*****************************************/
    /* Exercise 7 */
    /*****************************************/

    int pos = storeTableFind(tabStores, purchase->storeId);
    char storeName[MAX_NAME] = tabStores.table[pos].name;

    printf("--------------------------------------------------\n");
    printf("%s\n", storeName);
    printf("--------------------------------------------------\n");
    printf("%-20s %10s\n", "Board Game", "Units");
    printf("--------------------------------------------------\n");

    float total = 0.0;
    for(int i = 0; i < purchase->nOrders; i++) {
        tOrder* order = &(purchase->orders[i]);
        printf("%-20s %10d\n", order->bgame, order->nPurchased);
        total += (order->price * order->nPurchased);
    }

    printf("--------------------------------------------------\n");
    printf("%31s %10.2f\n", "Total:", total);
    printf("--------------------------------------------------\n");

    /*****************************************/
}
