#include "data.h"

/* Initialize the store table */
void storeTableInit(tStoresTable *storesTable);

/* Load the stores data from a given file */
void storeTableLoad(tStoresTable *tabStores, const char* filename, tError *retVal);

/* The content of the string str is parsed into the fields of the store structure */
void getStoreObject(const char *str, tStore *store);

/* Add a store to a store table */
void storeTableAdd(tStoresTable *tabStores, tStore store, tError *retVal);

/* Remove a store (given its id) from a store table */
void storeTableDel(tStoresTable *tabStores, tStoreId storeId, tError *retVal);

/* Copy a store data (src) to another store structure (dst) */
void storeCpy(tStore *dst, tStore src);

/* Load the stores' inventories data from a given file */
void inventoriesLoad(tStoresTable *tabStores, const char* filename, tError *retVal);

/* The content of the string str is parsed into the fields of the inventory structure */
void getBGameObject(const char *str, tBGame *bgame, tStoreId *storeId);

/* Return the index of a store (given its id) in a store table (-1 if not found) */
int storeTableFind(tStoresTable tabStores, tStoreId id);

/* Add a board game to the inventory of a store (given its id) in a given store table */
void inventoryBGameAdd(tStoresTable *tabStores, tStoreId storeId, tBGame newBGame, tError *retVal);

/* Remove a board game (given its id) from a given inventory */
void inventoryBGameDel(tInventory *inventory, tBGameId bgameId, tError *retVal);

/* Save the stores data to a given file */
void storesTableSave(tStoresTable tabStores, const char* filename, tError *retVal);

/* The content of the fields of the store structure is written into the string str */
void getStoreStr(tStore store, int maxSize, char *str);

/* Save the stores' inventories data to a given file */
void inventoriesTableSave(tStoresTable tabStores, const char* filename, tError *retVal);

/* The content of the fields of the bgame structure is written into the string str */
void getBGameStr(tBGame bgame, int maxSize, char *str);

/* Check if a certain number (amount) of copies of a game (given its name) is available in a given store */
/* It returns the number of available copies of the particular board game */
void checkAvailability(tStore *store, char *name, int amount, tError *retVal, int *toSell);

/* Return the total price of buying, in a given store, the indicated number (amount) of copies of a board game (given its name) */
void calculatePrice(tStore *store, char *name, int amount, tError *retVal, float *pvp);

/* Update a store inventory to effectively buy the indicated amount of copies of the given game (by name) */
void updateBGames(tStore *store, char *name, int amount, tError *retVal);

/* Return in a new store table the stores whose warehouse' occupancy is equal to or higher than that indicated */
void storesTableFilterByWarehouse(tStoresTable tabStores, float occupancy, tStoresTable *tabStores2);

/* Store in buffer the name of the store whose purchases generated, in a given year, the highest benefit */
void mostProfitableStore (tStoresTable *tabStores, tPurchaseTable *tabPurchases, int year, tError *retVal, tStoreId *profStore);
