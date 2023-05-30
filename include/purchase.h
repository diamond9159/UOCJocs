#include "data.h"

/* Initializes the given purchases table */
void purchaseTableInit(tPurchaseTable *purchasesTable);

/* Load the table of purchases from a file */
void purchaseTableLoad(tPurchaseTable *tabPurchases, const char* filename, tError *retVal);

/* Get a purchase object from its textual representation */
void getPurchaseObject(const char *str, tPurchase *purchase);

/* Add a new purchase to the table of purchases */
void purchaseTableAdd(tPurchaseTable *tabPurchases, tPurchase purchase, tError *retVal);

/* Return the index of a purchase associated to a given id in the purchase table (-1 if not found) */
int tabPurchaseFind (tPurchaseTable *tabPurchase, tPurchaseId id);

/* Copy the purchase data in src to dst*/
void purchaseCpy(tPurchase *dst, tPurchase src);

/* Copy the order data in src to dst*/
void orderCpy(tOrder *dst, tOrder src);

/* Compare two dates */
int dateCmp( tDate d1, tDate d2 );

/* Copy the date data in d2 to d1 */
void dateCpy( tDate *d1, tDate d2 );

/* Save a table of purchases to a file */
void purchaseTableSave(tPurchaseTable *tabPurchases, const char* filename, tError *retVal);

/* Get a textual representation of a purchase */
void getPurchaseStr(tPurchase purchase, tOrder order, int maxSize, char *str);

/* Return (in tabPurchases2) the total benefit of the purchases associated to a given store in a given year */
void purchaseTableFilterByYearAndStore (tPurchaseTable *tabPurchases, int year, tStoreId storeId, tError *retVal, float *benefit);

/* Return the category that has sold less board games in a given store */
void lessPopularCategory (tPurchaseTable *tabPurchases, tStoresTable *tabStores, tStoreId id, tError *retVal, tGameCategory *cat);

/* Read a new purchase data and store it in a given table */
void newPurchase(tStoresTable *tabStores, tPurchaseTable *tabPurchase, tError *retVal) ;

/* Remove a purchase (given its id) from a purchase table */
void purchaseTableDel(tPurchaseTable *tabPurchase, tPurchaseId id);
