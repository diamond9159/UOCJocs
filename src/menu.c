#include <stdio.h>
#include <string.h>

#include "data.h"
#include "api.h"
#include "menu.h"
#include "store.h"
#include "bgame.h"
#include "purchase.h"

int getOption(int numOptions) {
	int option=0;
		
	while(option<1 || option>numOptions) {
		/* Read the input */
		printf(">> ");
			scanf("%u", &option);
		getchar();
		
		/* Check the user input */
		if(option<1 || option>numOptions) {
			printf("Incorrect option.\n");
		}
	}
	 return option;
}

void readStoreId(tStoresTable *tabStores, tStoreId *id) {
    int idx;
    *id=NO_STORE;
    while(*id<0 || *id>MAX_STORES) {
        /* Read the input */
        printf("Introduce a store id (>=0):\n>> ");
        scanf("%u", id);
        getchar();
        
        /* Check the user input */
        idx = storeTableFind(*tabStores, *id);
        if(idx == NO_STORE) {
            *id=NO_STORE;
            printf("Incorrect store id.\n");
        }
    }
}

void readBGame (tBGame *bgame, tError *retVal) {	
    /*****************************************/
    /* Exercise 4 */    
    /*****************************************/

    char buffer[MAX_NAME];
    int number;
    float discount;
    
    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("BGame id (integer between 1 and %d):\n>> ",MAX_BGAMES);
        scanf("%d",&number);
        if(number >= 1 && number <= MAX_BGAMES) {
            bgame->bgameId= (tBGameId)(number);
            *retVal = OK;
        }
    }
    
    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("BGame name (max %d char, no spaces):\n>> ", MAX_NAME-1);
        scanf("%s",buffer);
        length = strlen(buffer);
        if (length<MAX_NAME) {
            strncpy(bgame->name, buffer, MAX_NAME);
            *retVal = OK;
        }
    }
    
    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("BGame age (integer Must be greater than zero):\n>> ");
        scanf("%d",&number);
        if(number > 0) {
            bgame->age = number;
            *retVal = OK;
        }
    }

    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("BGame duration (integer must be greater than zero):\n>> ");
        scanf("%d",&number);
        if(number > 0) {
            bgame->duration = number;
            *retVal = OK;
        }
    }
    
    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("BGame category (EUROGAME=0, AMERITRASH=1, CARDS=2, DICE=3, PARTY=4, TRIVIA=5):\n>> ");
        scanf("%d",&number);
        if(number >= 0 && number <=5) {
            bgame->category = (tGameCategory)(number);
            *retVal = OK;
        }
    }

    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("BGame launchDate (integer must be between 1900 and 2023, both inclusive):\n>> ");
        scanf("%d",&number);
        if(number >= 1900 && number <=2023) {
            bgame->launchDate = number;
            *retVal = OK;
        }
    }

    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("BGame price (float must be >=0.0):\n>> ");
        scanf("%f",&discount);
        if(discount>=0.0) {
            bgame->price = discount;
            *retVal = OK;
        }
    }
    
    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("BGame discount (float between 0.0 and 100.0):\n>> ");
        scanf("%f",&discount);
        if(discount>=0.0 && discount<=100.0) {
            bgame->discount = discount;
            *retVal = OK;
        }
    }

    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("BGame availability (integer must be greater than or equal to zero):\n>> ");
        scanf("%d",&number);
        if(number >= 0) {
            bgame->availability = number;
            *retVal = OK;
        }
    }

    /*****************************************/
}

void readStore(tStore *store, tError *retVal) {	

	*retVal = ERROR;

	char buffer[MAX_NAME];
	int number, length, i;
    float discount;
    tBGame bgame;
    
    while (*retVal == ERROR) {
        printf("Store id (integer between 1 and %d):\n>> ",MAX_STORES);
        scanf("%d",&number);
        if(number >= 1 && number <= MAX_STORES) {
            store->storeId= (tStoreId)(number);
            *retVal = OK;
        }
    }
    
    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("Store name (max %d char, no spaces):\n>> ", MAX_NAME-1);
        scanf("%s",buffer);
        length = strlen(buffer);
        if (length<MAX_NAME) {
            strncpy(store->name,buffer,MAX_NAME);
            *retVal = OK;
        }
    }

    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("Store city (max %d char, no spaces):\n>> ", MAX_NAME-1);
        scanf("%s",buffer);
        length = strlen(buffer);
        if (length<MAX_NAME) {
            strncpy(store->city,buffer,MAX_NAME);
            *retVal = OK;
        }
    }

    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("Store max storage (integer between 1 and %d):\n>> ", MAX_STORAGE);
        scanf("%d",&number);
        if(number>=0 && number <=MAX_STORAGE) {
            store->maxStorage= number;
            *retVal = OK;
        }
    }
	
    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("Store special discount (float between 0.0 and 100.0):\n>> ");
        scanf("%f",&discount);
        if(discount>=0 && discount <=100) {
            store->specialDiscount= discount;
            *retVal = OK;
        }
    }

    *retVal = ERROR;
    while (*retVal == ERROR) {
        printf("Number of board games available in the store: (between 1 and %d)\n>> ", MAX_BGAMES);
        scanf("%d",&number);
        if (number>0 && number<MAX_BGAMES){
            *retVal = OK;
        }
    }

    store->inventory.nStoredBGames = 0;
    for ( i=0; i<number; i++){
        readBGame (&bgame, retVal);
        addBGame(store, bgame, retVal);
    }
    
}


/*****************
 **   MAIN MENU **
*****************/
void printMainMenuOptions() {
	/* Show menu options */
	printf("=======================\n");
	printf(" Main Menu \n");
	printf("=======================\n");
	printf("1) Load data from file\n");
    printf("2) Save data to file\n");
	printf("3) Manage stores\n");
	printf("4) Manage purchases\n");
	printf("5) View statistics\n");
	printf("6) Exit\n");	
}

tMainMenuOptions getMainMenuOption() {
	/* Convert to the correct type */
	return (tMainMenuOptions)(getOption(6)-1);
}

void mainMenu(tAppData *appData) 
{
	tMainMenuOptions option;
	tError retVal;
		
	/* Assign the data path */
	appDataSetPath(appData,""); //"../");
		
	/* Start the menu */
    
    /* Show list of options and ask the user for an option */
    printMainMenuOptions();
    option=getMainMenuOption();
    
	while (option!=MAIN_MENU_EXIT) 
    {
		/* Do the action for the given option */
		if (option == MAIN_MENU_LOAD) {
			appDataLoad(appData,&retVal);
			if(retVal==OK) {
				printf("Data loaded\n");
			} else {	
				printf("No previous data loaded\n");
			}
        } else if (option == MAIN_MENU_SAVE) {
            appDataSave(*appData,&retVal);
            if(retVal!=OK) {
                printf("Cannot save the data\n");
            }
            printf("Saved completed\n");
		} else if (option == MAIN_MENU_STORES) {
			storesMenu(appData);
		} else if (option == MAIN_MENU_PURCHASE) {
			purchaseMenu(appData);
		} else if (option == MAIN_MENU_STAT) {
			statMenu(appData);
		} 
        
		/* Show list of options and ask the user for an option */
		printMainMenuOptions();
		option=getMainMenuOption();
	}
}

/*********************************
 **   STORES MANAGEMENT MENU **
*********************************/
void printStoresMenuOptions() {
	/* Show menu options */
	printf("=======================\n");
	printf(" Manage stores\n");
	printf("=======================\n");
	printf("1) List stores\n");	
    printf("2) List stores' inventories\n"); 
	printf("3) Add store\n");
	printf("4) Delete store\n");	
    printf("5) Check capacity\n");
	printf("6) Exit\n");	
}

tStoresMenuOptions getStoresMenuOption() {
	/* Convert to the correct type */
    return (tStoresMenuOptions)(getOption(6)-1);
}

void storesMenu(tAppData *appData) {
    tStoresMenuOptions option;
    tStore newStore;
    tStoresTable storesTable;
    tStoreId storeId;
    tError retVal;
            
    /* Start the menu */
    /* Show list of options and ask the user for an option */
    printStoresMenuOptions();
    option=getStoresMenuOption();    
    
    while(option!=STORES_MENU_EXIT)
    {       
        /* Do the action for the given option */
        if (option == STORES_MENU_LIST ) {
            getStores(*appData, &storesTable);
            printStoresTable(storesTable);
        } else if (option == INVENTORIES_MENU_LIST ) {
            getStores(*appData, &storesTable);
            printInventories(storesTable);
        } else if (option == STORES_MENU_ADD ) {
            getStores(*appData, &storesTable);
            readStore(&newStore, &retVal);
            if(retVal!=OK) {
                printf("Error with the readStore function\n");
            }
            storeTableAdd(&storesTable, newStore, &retVal);
            if(retVal==ERR_MEMORY) {
                printf("The table is full, cannot add more stores\n");
            }
            appData->stores = storesTable;
        } else if (option == STORES_MENU_DELETE ) {
            getStores(*appData, &storesTable);
            readStoreId(&storesTable, &storeId);
            storeTableDel(&storesTable, storeId, &retVal);
            if(retVal==ERR_NO_STORE) {
                printf("The store to delete does not exist\n");
            }
            appData->stores = storesTable;
        } else if (option == STORES_MENU_CHECK_CAPACITY ) {
            getStores(*appData, &storesTable);
            checkStoresCapacity(&storesTable);
            appData->stores = storesTable;
        }
        
        /* Show list of options and ask the user for an option */
        printStoresMenuOptions();
        option=getStoresMenuOption();        
    }
}

void printStoresTable(tStoresTable tabStores){
    int i;
    if ( tabStores.nStores == 0 ) {
        printf("The stores table is empty\n");
    } else{
        printf("Store id; Name; City; Max storage; Special Discount\n");
        for ( i = 0; i < tabStores.nStores; i++ ){
            printf("%d; %s; %s; %d; %.2f\n",
                (int) tabStores.table[i].storeId, tabStores.table[i].name,
                tabStores.table[i].city, tabStores.table[i].maxStorage,
                tabStores.table[i].specialDiscount);
        }
    }
}

void printInventories(tStoresTable tabStores){
    int i;
    tStore store;
#ifdef TYPEDEF_COMPLETED
    int j;
    tBGameTable bgames;
#endif
    if ( tabStores.nStores == 0 ) {
        printf("The stores table is empty\n");
    } else{
        for ( i = 0; i < tabStores.nStores; i++ ){
            store = tabStores.table[i];
            printf("\nInventory of store %d:\n", (int) store.storeId);
            if (store.inventory.nStoredBGames == 0) {
                printf("This store does not have any board games right now.\n");
            } else {
                printf("Number of different board games available: %d\n", store.inventory.nBGames);
                printf("Number of board games stored (in total): %d\n", store.inventory.nStoredBGames);
                printf("BGame id; name; age; duration; category; launch date; price; discount; available\n");
#ifdef TYPEDEF_COMPLETED
                bgames = store.inventory.games;
                for ( j = 0; j < store.inventory.nBGames; j++ ){
                    printf("%d; %s; %d; %d; %d; %d; %.2f; %.2f; %d\n",
                        (int) bgames.table[j].bgameId, bgames.table[j].bgName,
                        bgames.table[j].age, bgames.table[j].duration, 
                        (int) bgames.table[j].category, bgames.table[j].launchDate,
                        bgames.table[j].price, bgames.table[j].discount, bgames.table[j].availability);
                }
#endif
            }
        }
    }
}

void checkStoresCapacity(tStoresTable *tabStores){
    int i;
    bool sCapacity;
    if ( tabStores->nStores == 0 ) {
        printf("The stores table is empty\n");
    } else{
        for ( i = 0; i < tabStores->nStores; i++ ){
	    checkStoreCapacity(&(tabStores->table[i]), &sCapacity);
            if (sCapacity){
                printf("The store %d now has a special discout (due to warehouse saturation)\n",
                 (int) tabStores->table[i].storeId);
            }
        }
    }
}

/*********************************
 **   PURCHASES MANAGEMENT MENU **
*********************************/
void printPurchasesMenuOptions() {
    /* Show menu options */
    printf("=======================\n");
    printf(" Manage purchases\n");
    printf("=======================\n");
    printf("1) List purchases\n"); 
    printf("2) Add purchase\n");
    printf("3) Delete purchase\n");    
    printf("4) Print tickets\n");
    printf("5) Exit\n");    
}

tPurchaseMenuOptions getPurchasesMenuOption() {
    /* Convert to the correct type */
    return (tPurchaseMenuOptions)(getOption(5)-1);
}

void purchaseMenu(tAppData *appData) {
    tPurchaseMenuOptions option;
    tStoresTable storesTable;
    tPurchaseTable purchasesTable;
    int id;
    tError retVal;
            
    /* Start the menu */
    /* Show list of options and ask the user for an option */
    printPurchasesMenuOptions();
    option=getPurchasesMenuOption();    
    
    while(option!=PURCHASE_MENU_EXIT)
    {       
        /* Do the action for the given option */
        if (option == PURCHASE_MENU_LIST ) {
            purchasesTable = appData->purchases;
            printPurchasesTable(&purchasesTable);
        } else if (option == PURCHASE_MENU_ADD ) {
            purchasesTable = appData->purchases;
            storesTable = appData->stores;
            newPurchase(&storesTable, &purchasesTable, &retVal);
            if(retVal!=OK) {
                printf("Error with newPurchase function, no new purchase added\n");
            }
            appData->purchases = purchasesTable;
        } else if (option == PURCHASE_MENU_DELETE ) {
            purchasesTable = appData->purchases;
            printf("Purchase id to delete:\n>> ");
            scanf("%d",&id);
            purchaseTableDel(&purchasesTable, id);
            appData->purchases = purchasesTable;
        } else if (option == PURCHASE_MENU_PRINT_TICKETS ) {
            purchasesTable = appData->purchases;
            printPurchaseTickets(&purchasesTable);
        }
        /* Show list of options and ask the user for an option */
        printPurchasesMenuOptions();
        option=getPurchasesMenuOption();        
    }
}

void printPurchasesTable(tPurchaseTable *tabPurchases){//(tPurchaseTable tabPurchases){
    int i, j;
    if ( tabPurchases->nPurchases == 0 ) {
        printf("The purchases table is empty\n");
    } else{
        for ( i = 0; i < tabPurchases->nPurchases; i++ ){
            printf("\nPurchase id %d; Store id %d; nOrders %d; %d/%d/%d; %.2f\n",
                (int) tabPurchases->table[i].purchaseId, 
                (int) tabPurchases->table[i].storeId,
                tabPurchases->table[i].nOrders,
                tabPurchases->table[i].date.day,
                tabPurchases->table[i].date.month,
                tabPurchases->table[i].date.year,
                tabPurchases->table[i].price);
                printf("ORDERS:\n");
            for ( j=0; j < tabPurchases->table[i].nOrders; j++ ){
                printf("%s %d %.2f\n",
                tabPurchases->table[i].orders[j].bgame,
                tabPurchases->table[i].orders[j].nPurchased,
                tabPurchases->table[i].orders[j].price);
            }
        }
    }
}

/*********************************
 **   STATS MANAGEMENT MENU **
*********************************/
void printStatMenuOptions() {
    /* Show menu options */
    printf("=======================\n");
    printf(" Stats \n");
    printf("=======================\n");
    printf("1) Get the most profitable store\n");  
    printf("2) Get the less popular category for a store\n");   
    printf("3) Exit\n");    
}

tStatMenuOptions getStatMenuOption() {
    /* Convert to the correct type */
    return (tStatMenuOptions)(getOption(3)-1);
}

void statMenu(tAppData *appData){
    tStatMenuOptions option;
    tStoresTable tabStores;
    tPurchaseTable tabPurchases;
    tGameCategory category;
    int year;
    int iStore;
    tStoreId storeId;
    tError retVal;
    /* Start the menu */
    /* Show list of options and ask the user for an option */
    printStatMenuOptions();
    option=getStatMenuOption();

    while(option!=STAT_MENU_EXIT)
    {
        if (option == STAT_MENU_MOST_PROFITABLE_STORE) {           
            tabStores = appData->stores;
            tabPurchases = appData->purchases;
            /* Read the year to look for */
            printf("Introduce a year:\n>> ");
            scanf("%u", &year);
            getchar();
            mostProfitableStore (&tabStores, &tabPurchases, year, &retVal, &iStore);
            if (retVal != OK )
                printf("There are not stores registered yet or purchases for that year\n");
            else
                printf("The most profitable store of year %d is: %s\n", year, tabStores.table[iStore].name);
            
        } else if (option == STAT_MENU_LESS_POPULAR_CATEGORY) {           
            tabStores = appData->stores;
            readStoreId(&tabStores, &storeId);
            tabPurchases = appData->purchases;
            lessPopularCategory (&tabPurchases, &tabStores, storeId, &retVal, &category);
            if (retVal != OK )
                printf("Error with the lessPopularCategory\n");
            else {
                printf("The less popular category is: ");
                switch (category){
                    case EUROGAME:
                        printf("EUROGAME\n");
                        break;
                    case AMERITRASH:
                        printf("AMERITRASH\n");
                        break;
                    case CARDS:
                        printf("CARDS\n");
                        break;
                    case DICE:
                        printf("DICE\n");
                        break;
                    case PARTY:
                        printf("PARTY\n");
                        break;
                    case TRIVIA:
                        printf("TRIVIA\n");
                        break;
                    }
            }
        }
        /* Show list of options and ask the user for an option */
        printStatMenuOptions();
        option=getStatMenuOption();
    }
}
