#include "data.h"
#include "api.h"

/* Define the main menu options type */
typedef enum {  MAIN_MENU_LOAD, MAIN_MENU_SAVE, MAIN_MENU_STORES, 
                MAIN_MENU_PURCHASE, MAIN_MENU_STAT,
                MAIN_MENU_EXIT} tMainMenuOptions;

/* Define the stores management menu options type */
typedef enum {  STORES_MENU_LIST, INVENTORIES_MENU_LIST, 
                STORES_MENU_ADD, STORES_MENU_DELETE,
                STORES_MENU_CHECK_CAPACITY, 
                STORES_MENU_EXIT} tStoresMenuOptions;
    
/* Define the purchases management menu options type */
typedef enum {  PURCHASE_MENU_LIST, PURCHASE_MENU_ADD,
                PURCHASE_MENU_DELETE, PURCHASE_MENU_PRINT_TICKETS,
                PURCHASE_MENU_EXIT } tPurchaseMenuOptions;

/* Define the statistics management menu options type */
typedef enum {  STAT_MENU_MOST_PROFITABLE_STORE,
                STAT_MENU_LESS_POPULAR_CATEGORY,
                STAT_MENU_EXIT } tStatMenuOptions;

/* Request an option to the user and check its validity */
int getOption(int numOptions);

/* Request a store id to the user and check its validity */
void readStoreId(tStoresTable *tabStores, tStoreId *id);

/* Read a new board game data */
void readBGame (tBGame *bgame, tError *retVal);

/* Read a new store data (including inventory) */
void readStore(tStore *store, tError *retVal);

/* Print the main menu options */
void printMainMenuOptions();

/* Get the option for the main menu */
tMainMenuOptions getMenuOption();

/* Perform the actions for the main menu */
void mainMenu(tAppData *appData);

/* Print the stores management menu options */
void printStoresMenuOptions();

/* Get the option for the store management menu */
tStoresMenuOptions getStoresMenuOption();

/* Perform the actions for the stores management menu */
void storesMenu(tAppData *appData);

/* Print the stores information */
void printStoresTable(tStoresTable tabStores);

/* Print the stores' inventories information */
void printInventories(tStoresTable tabStores);

/* Check if the stores warehouses capacitoes are >= 80% */
void checkStoresCapacity(tStoresTable *tabStores);

/* Print the purchases menu options */
void printPurchasesMenuOptions();

/* Get the option for the purchase menu */
tPurchaseMenuOptions getPurchasesMenuOption();

/* Perform the actions for the purchase menu */
void purchaseMenu(tAppData *appData);

/* Print the purchases information */
void printPurchasesTable(tPurchaseTable *tab);//tPurchaseTable tabPurchases);

/* Print the statistics menu options */
void printStatMenuOptions();

/* Get the option for the statistics menu */
tStatMenuOptions getStatMenuOption();

/* Perform the actions for the statistics management menu */
void statMenu(tAppData *appData);
