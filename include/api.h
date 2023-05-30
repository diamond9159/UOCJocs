#include "data.h"

/* 
 * Methods for application data management 
 */

/* Initialize the application data */
void appDataInit(tAppData *object);

/* Load/save the application data from/to file */
void appDataLoad(tAppData *object, tError *error);
void appDataSave(tAppData object, tError *retVal);

/* Allow to assign a path to the application data */
void appDataSetPath(tAppData *object, const char *path);

/* 
 * API
 */

/* Return a table with the stores */
void getStores(tAppData object, tStoresTable *result);

/* Return a table with the purchases */
void getPurchases(tAppData object, tPurchaseTable *result);

/* Add a new board game to a given board games table */
void addBGame(tStore *store, tBGame newBGame, tError *retVal);

/* Check if the store warehouse capacity is >= 80% */
void checkStoreCapacity(tStore *store, bool *dtApplied);

/* Print the purchases table tickets */
void printPurchaseTickets(tPurchaseTable *tabPurchases);

/* Print a purchase ticket */
void printTickets (tPurchase *purchase);
