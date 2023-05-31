#include <stdbool.h>

/* This code ensures that this file is included only once */
#ifndef __DATA_H
#define __DATA_H
/* If the constant DATA_H is not defined (ifndef), the code is added, otherwise,
 * this code is excluded. When the code is added, the constant is defined,
 * therefore next time this file will be included it will be defined and no
 * inclusion will be done. */

/* Uncomment the line below once you've completed the exercise 1*/
// #define TYPEDEF_COMPLETED

#define MAX_PATHNAME 255
#define MAX_FILENAME 25
#define MAX_LINE 514
#define MAX_NAME 100
#define MAX_BGAMES 150
#define MAX_BGAMES_PER_PURCHASE 50
#define MAX_STORES 40
#define MAX_STORAGE 50
#define MAX_ORDERS 500
#define MAX_PURCHASES 500
#define NO_BGAME -1
#define NO_STORE -1
#define NO_PURCHASE -1
#define NO_CATEGORY -1
#define ERR_STORE_INVALID -1
#define MIN_YEAR 1900
#define MAX_YEAR 2023

/* Definition of the error type. */
typedef enum {
    OK = 1,
    ERROR = 0,
    ERR_CANNOT_READ = -1,
    ERR_CANNOT_WRITE = -2,
    ERR_MEMORY = -3,
    ERR_DUPLICATED_ENTRY = -4,
    ERR_INVALID_DATA = -5,
    ERR_ENTRY_NOT_FOUND = -6,
    ERR_NO_BGAME = -7,
    ERR_NO_STORE = -8,
    ERR_NO_PURCHASE = -9,
    ERR_FULL_WAREHOUSE = -10,
    ERR_NO_STOCK
} tError;

/* Definition of the game categories type. */
typedef enum { EUROGAME, AMERITRASH, CARDS, DICE, PARTY, TRIVIA } tGameCategory;

/* Definition of the identifiers types */
typedef int tBGameId;
typedef int tScreenId;
typedef int tStoreId;
typedef int tPurchaseId;

/* Definition of the data type. */
typedef struct {
    int day;
    int month;
    int year;
} tDate;

/* Definition of the board game type. */
typedef struct {
    /*****************************************/
    /* Exercise 1 */
    /*****************************************/
    tBGamieId bgameId;
    char bgName[MAX_NAME];
    int age;
    int duration;
    tGameCategory category;
    int launchDate;
    float price;
    float discount;
    int availability;

    /*****************************************/
} tBGame;

/* Definition of the board game table type. */
typedef struct {
    tBGame table[MAX_BGAMES];
    int nBGames;
} tBGameTable;

/* Definition of the inventory type. */
typedef struct {
    tStoreId storeId;
    int nBGames;
    int nStoredBGames;
    tBGameTable games;
} tInventory;

/* Definition of the store type. */
typedef struct {
    tStoreId storeId;
    char name[MAX_NAME];
    char city[MAX_NAME];
    int maxStorage;
    tInventory inventory;
    float specialDiscount;
} tStore;

/* Definition of the board stores table type. */
typedef struct {
    tStore table[MAX_STORES];
    int nStores;
} tStoresTable;

/* Definition of the order type. */
typedef struct {
    char bgame[MAX_NAME];
    int nPurchased; /* Number of units */
    float price;    /* Per unit */
} tOrder;

/* Definition of the purchase type. */
typedef struct {
    tPurchaseId purchaseId;
    tStoreId storeId;
    tOrder orders[MAX_BGAMES_PER_PURCHASE];
    int nOrders;
    tDate date;
    float price; /* Accumulated */
} tPurchase;

/* Definition of the purchase table type. */
typedef struct {
    tPurchase table[MAX_PURCHASES];
    int nPurchases;
} tPurchaseTable;

/* Definition of the application data structure */
typedef struct {
    /* Path where data will be stored */
    char path[MAX_PATHNAME];

    /* Stores table */
    tStoresTable stores;

    /* Purchases table */
    tPurchaseTable purchases;

} tAppData;

/***********************
 *    COMMON HEADERS
 **********************/

/* Compare two board games */
int bgameCmp(tBGame g1, tBGame g2);

/* Copy a date onto another date */
void bgameCpy(tBGame* dst, tBGame src);

#endif /*__DATA_H*/
