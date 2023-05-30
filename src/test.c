#include <stdio.h>
#include <string.h>
#include <math.h>
#include "test.h"


#define STORE1 "1 BGAMESTORE-BCN BARCELONA 60"
#define STORE2 "2 BGAMESTORE-VLC VALENCIA 50"
#define STORE3 "3 BGAMESTORE-MAD MADRID 50"

#define BGAME11 "1 1 CATAN 10 75 0 1995 41.95 10"
#define BGAME12 "1 2 UNANIMO 8 20 4 2021 11.95 9"
#define BGAME13 "1 3 STRIKE 8 15 3 2012 29.99 5"
#define BGAME14 "1 4 ZOMBICIDE 13 180 1 2012 89.99 5"
#define BGAME15 "1 5 VIRUS 8 20 2 2015 13.95 25"
#define BGAME16 "1 6 TRIVIAL-PURSUIT 16 90 5 1981 34.99 4"
#define BGAME21 "2 1 CATAN 10 75 0 1995 41.95 3"
#define BGAME22 "2 2 UNANIMO 8 20 4 2021 11.95 25"
#define BGAME23 "2 3 STRIKE 8 15 3 2012 29.99 1"
#define BGAME24 "2 4 ZOMBICIDE 13 180 1 2012 89.99 10"
#define BGAME25 "2 5 VIRUS 8 20 2 2015 13.95 8"
#define BGAME26 "2 6 TRIVIAL-PURSUIT 16 90 5 1981 34.99 3"
#define BGAME31 "3 1 CATAN 10 75 0 1995 41.95 11"
#define BGAME32 "3 2 UNANIMO 8 20 4 2021 11.95 0"
#define BGAME33 "3 3 STRIKE 8 15 3 2012 29.99 0"
#define BGAME34 "3 4 ZOMBICIDE 13 180 1 2012 89.99 2"
#define BGAME35 "3 5 VIRUS 8 20 2 2015 13.95 1"
#define BGAME36 "3 6 TRIVIAL-PURSUIT 16 90 5 1981 34.99 5"
#define BGAME37 "3 7 SMART10 12 15 5 2021 29.99 2"

#define PUR11 "1 1 CATAN 2 1/1/2023 40.00"
#define PUR12 "1 1 UNANIMO 1 1/1/2023 10.00"
#define PUR13 "1 1 ZOMBICIDE 1 1/1/2023 80.00"
#define PUR21 "2 1 STRIKE 1 2/3/2023 29.99"
#define PUR31 "3 1 VIRUS 2 3/3/2023 13.95"
#define PUR41 "4 1 TRIVIAL-PURSUIT 1 4/3/2023 34.99"
#define PUR51 "5 2 CATAN 2 1/3/2023 41.95"
#define PUR61 "6 2 CATAN 1 2/3/2023 35.00"
#define PUR62 "6 2 ZOMBICIDE 2 2/3/2023 89.99"
#define PUR71 "7 3 CATAN 1 1/3/2023 41.95"
#define PUR72 "7 3 UNANIMO 2 1/3/2023 11.95"
#define PUR73 "7 3 ZOMBICIDE 1 1/3/2023 89.99"
#define PUR74 "7 3 STRIKE 1 1/3/2023 29.99"
#define PUR81 "8 3 VIRUS 1 2/3/2023 41.95"
#define PUR91 "9 3 STRIKE 1 2/3/2023 29.99"
#define PUR92 "9 3 TRIVIAL-PURSUIT 1 2/3/2022 30.00"

void runTests() 
{	
    int passedTest= 0;
    int totalTest= 0;
    float percent= 0.0;

    printf("===============================================\n");
    printf("====       PRACTICAL ACTIVITY TESTS        ====\n");
    printf("===============================================\n");	
    
    testTableOperation(&totalTest, &passedTest);
    testUpdateStores(&totalTest, &passedTest);
    testBGamesSales(&totalTest, &passedTest);
    testFilters(&totalTest, &passedTest);
    testFilters2(&totalTest, &passedTest);
    testStatistics(&totalTest, &passedTest);

    if (totalTest>0)
        percent= (float)passedTest/totalTest*100.0;
    else {
        percent= 0.0;
    }

    printf("===================================\n");
    printf("====       TEST SUMMARY        ====\n");
    printf("===================================\n");		
    printf("\tPR: Passed %d of %d [%0.2f%%]\n", 
    	passedTest, totalTest, percent);
    printf("===================================\n");		
}

void testTableOperation(int *totalTest, int *passedTest) 
{
    tStore store1, store2, store3;
    tBGameTable bgames, bgames_empty;
    tBGame game11, game12, game13, gamecpy;
    tStoreId storeId;
	tError retVal;
#ifdef TYPEDEF_COMPLETED
    int idx;
#endif

	getStoreObject(STORE1, &store1);
	store1.inventory.nBGames = 0;
	store1.inventory.nStoredBGames = 0;
	getStoreObject(STORE2, &store2);
	store2.inventory.nBGames = 0;
	store2.inventory.nStoredBGames = 0;
	getStoreObject(STORE3, &store3);
	store3.inventory.nBGames = 0;
	store3.inventory.nStoredBGames = 0;

 	bgameTableInit(&bgames);
 	bgameTableInit(&bgames_empty);

 	getBGameObject(BGAME11, &game11, &storeId);
 	getBGameObject(BGAME12, &game12, &storeId);
 	getBGameObject(BGAME13, &game13, &storeId);

	printf("=================================================\n");
	printf(" TABLE OPERATIONS: add, delete, find (Ex. 1, 2, 3)\n");
	printf("=================================================\n");
                            
	printf("\nTest 1.1: Copy a bgame to another");
	(*totalTest)++;
	bgameCpy(&gamecpy, game11);
	if (bgameCmp (game11, gamecpy) == 0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour copying a tBGame into another)\n");
	}
    
    printf("\nTest 1.2: Look for a board game id in an empty table");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	idx = bgameTableFindId(&bgames, game11.bgameId);
	if (idx == NO_BGAME) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour searching for an id in an empty tBGameTable)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour searching for an id in an empty tBGameTable)\n");
#endif

	printf("\nTest 1.3: Look for a board game name in an empty table");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	idx = bgameTableFindName(&bgames, game11.bgName);
	if (idx == NO_BGAME) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour searching for a name in an empty tBGameTable)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour searching for a name in an empty tBGameTable)\n");
#endif
    
	printf("\nTest 1.4: Add a board game in an empty table");
	(*totalTest)++;
	bgameTableAdd(&bgames, game11, &retVal);
	if (retVal == OK &&
		bgames.nBGames == 1) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour adding a game in an empty tBGameTable)\n");
	}

	printf("\nTest 1.5: Add a board game that already exists in a table");
	(*totalTest)++;
	bgameTableAdd(&bgames, game11, &retVal);
	if (retVal == OK &&
		bgames.nBGames == 1) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour adding a game that already exists in tBGameTable)\n");
	}

	printf("\nTest 1.6: Add a new board game in a non-empty table");
	(*totalTest)++;
	bgameTableAdd(&bgames, game12, &retVal);
	if (retVal == OK &&
		bgames.nBGames == 2) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour adding a new game in a non-empty tBGameTable)\n");
	}

	printf("\nTest 1.7: Add a board game in a table that is already full");
	(*totalTest)++;
	bgames.nBGames = MAX_BGAMES;
	bgameTableAdd(&bgames, game13, &retVal);
	if (retVal == ERR_MEMORY &&
		bgames.nBGames == MAX_BGAMES) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour adding a game in tBGameTable that is already full)\n");
	}
	bgames.nBGames = 2;

	printf("\nTest 1.8: Look for a board game id in an empty table");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	idx = bgameTableFindId(&bgames, game11.bgameId);
	if (idx == 0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour searching for an existing id in a tBGameTable\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour searching for an existing id in a tBGameTable\n");
#endif

	printf("\nTest 1.9: Look for a board game name in an empty table");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	idx = bgameTableFindName(&bgames, game11.bgName);
	if (idx == 0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour searching for an existing name in a tBGameTable\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour searching for an existing name in a tBGameTable\n");
#endif

	printf("\nTest 1.10: Delete a board game in an empty table");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	bgameTableDel(&bgames_empty, game11.bgameId, &retVal);
	if (retVal == ERR_NO_BGAME) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour deleting a game in an empty table)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour deleting a game in an empty table)\n");
#endif
    
    printf("\nTest 1.11: Delete a board game that exists in a table");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	bgameTableDel(&bgames, game12.bgameId, &retVal);
	if (retVal == OK &&
		bgames.nBGames == 1) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour deleting a game that exists in a table)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour deleting a game that exists in a table)\n");
#endif

	printf("\nTest 1.12: Delete a board game that does not exist in a table");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	bgameTableDel(&bgames, game12.bgameId, &retVal);
	if (retVal == ERR_NO_BGAME &&
		bgames.nBGames == 1) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour deleting a game that does not exist in a table)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour deleting a game that does not exist in a table)\n");
#endif

}

void testUpdateStores(int *totalTest, int *passedTest) 
{
    bool sCapacity;
    tStore store1;
    tBGame game11, game12, game13, game15;
    tStoreId storeId;
	tError retVal;
    
	getStoreObject(STORE1, &store1);
	store1.inventory.nBGames = 0;
	store1.inventory.nStoredBGames = 0;
 	getBGameObject(BGAME11, &game11, &storeId);
	getBGameObject(BGAME12, &game12, &storeId);
	getBGameObject(BGAME13, &game13, &storeId);
	getBGameObject(BGAME15, &game15, &storeId);

	printf("=================================================\n");
	printf(" STORES OPERATIONS: add bgame, check warehouse (Ex. 5)\n");
	printf("=================================================\n");
                            
	printf("\nTest 2.1: Add a board game to an empty store");
	(*totalTest)++;
	getBGameObject(BGAME11, &game11, &storeId);
	addBGame(&store1, game11, &retVal);
 	if (retVal == OK &&
 		store1.inventory.nStoredBGames == 10 &&
 		store1.inventory.nBGames == 1 && 
 		bgameCmp(store1.inventory.games.table[0], game11) == 0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour adding a game to a store inventory)\n");
	}

	printf("\nTest 2.2: Add a board game to a store whose inventory games list is full");
	(*totalTest)++;
	store1.inventory.nBGames = MAX_BGAMES;
	addBGame(&store1, game12, &retVal);
 	if (retVal == ERR_MEMORY &&
 		store1.inventory.nStoredBGames == 10 &&
 		store1.inventory.nBGames == MAX_BGAMES ) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour adding a game to a store whose inventory games list is full)\n");
	}
	store1.inventory.nBGames = 1;

	printf("\nTest 2.3: Add a board game to a store whose warehouse is full");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	store1.inventory.nStoredBGames = store1.maxStorage;
	addBGame(&store1, game12, &retVal);
 	if (retVal == ERR_FULL_WAREHOUSE &&
 		store1.inventory.nStoredBGames == store1.maxStorage &&
 		store1.inventory.nBGames == 2 && 
 		store1.inventory.games.table[1].availability == 0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour adding a game to a store whose warehouse is full)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour adding a game to a store whose warehouse is full)\n");
#endif
	store1.inventory.nStoredBGames = 10;

	printf("\nTest 2.4: Add a board game to a store whose warehouse is partially populated");
	(*totalTest)++;
	addBGame(&store1, game13, &retVal);
 	if (retVal == OK &&
 		store1.inventory.nStoredBGames == 15 &&
 		store1.inventory.nBGames == 3 && 
 		bgameCmp(store1.inventory.games.table[2], game13) == 0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour adding a game to a store whose warehouse is partially populated)\n");
	}
	
	printf("\nTest 2.5: Check warehouse occupancy (no more than 80 percent) ");
	(*totalTest)++;
	checkStoreCapacity(&store1, &sCapacity);
 	if (sCapacity == 0 &&
 		store1.specialDiscount == 0 ) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour checking warehouse occupancy less than 80 percent)\n");
	}

	printf("\nTest 2.6: Check warehouse occupancy (more than 80 percent) ");
	(*totalTest)++;
	addBGame(&store1, game15, &retVal);
	addBGame(&store1, game15, &retVal);
	checkStoreCapacity(&store1, &sCapacity);
 	if (sCapacity == 1 &&
 		store1.specialDiscount == 20 ) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour checking warehouse occupancy is >= 80 percent)\n");
	}

}

void testBGamesSales(int *totalTest, int *passedTest){

	tStore store1, store2, store3;
	tStoresTable tabStores;
	tBGame game11, game12, game13, game14, game15, game16, game33;
    tStoreId storeId;
	tError retVal;
#ifdef TYPEDEF_COMPLETED
	int toSell;
	float pvp;
#endif

	getStoreObject(STORE1, &store1);
	getStoreObject(STORE2, &store2);
	getStoreObject(STORE3, &store3);
	storeTableInit(&tabStores);
    
	storeTableAdd(&tabStores, store1, &retVal);
	storeTableAdd(&tabStores, store2, &retVal);
	storeTableAdd(&tabStores, store3, &retVal);

	getBGameObject(BGAME11, &game11, &storeId);
	getBGameObject(BGAME12, &game12, &storeId);
	getBGameObject(BGAME13, &game13, &storeId);
	getBGameObject(BGAME14, &game14, &storeId);
	getBGameObject(BGAME15, &game15, &storeId);
	getBGameObject(BGAME16, &game16, &storeId);
	getBGameObject(BGAME33, &game33, &storeId);

	printf("=================================================\n");
	printf(" SALES OPERATIONS: AVAILABILITY, PRICE, SELL (Ex. 6)\n");
	printf("=================================================\n");
                           
	printf("\nTest 3.1: Check if a board game is available (game not inventored, store does not have games)");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	storeId = 1;
	checkAvailability(&store1, game11.bgName, 1, &retVal, &toSell);
 	if (retVal == ERR_NO_BGAME &&
 		store1.inventory.nStoredBGames == 0 &&
 		store1.inventory.nBGames == 0 && toSell == 0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour trying to checkAvailability of a game not inventored, store does not have games)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour trying to checkAvailability of a game not inventored, store does not have games)\n");
#endif

	storeId = 3;
	addBGame(&store3, game33, &retVal);
	printf("\nTest 3.2: Check if a board game is available (game inventored but not stock)");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	checkAvailability(&store3, game33.bgName, 1, &retVal, &toSell);
 	if (retVal == ERR_NO_STOCK && toSell == 0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour trying to checkAvailability of a game inventored, but not stock)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour trying to checkAvailability of a game inventored, but not stock)\n");
#endif

	printf("\nTest 3.3: Check if a board game is available (game not inventored, store has games)");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	checkAvailability(&store3, game11.bgName, 1, &retVal, &toSell);
 	if (retVal == ERR_NO_BGAME && toSell == 0) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour trying to checkAvailability of a game not inventored, store has games)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour trying to checkAvailability of a game not inventored, store has games)\n");
#endif

	printf("\nTest 3.4: Check if a board game is available (game inventored, partial amount available)");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	addBGame(&store1, game11, &retVal);
	checkAvailability(&store1, game11.bgName, 100, &retVal, &toSell);
	printf("%d %d %d\n", retVal, toSell, store1.inventory.games.table[0].availability );
 	if (retVal == OK && toSell == 10 &&
 		store1.inventory.games.table[0].availability == 10) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour trying to checkAvailability of a game inventored, partial amount available)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour trying to checkAvailability of a game inventored, partial amount available)\n");
#endif

	printf("\nTest 3.5: Check if a board game is available (game inventored, whole amount available)");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	addBGame(&store1, game12, &retVal);
	checkAvailability(&store1, game12.bgName, 1, &retVal, &toSell);
 	if (retVal == OK && toSell == 1 &&
 		store1.inventory.games.table[1].availability == 9) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour trying to checkAvailability of a game inventored, whole amount available)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour trying to checkAvailability of a game inventored, whole amount available)\n");
#endif

	printf("\nTest 3.6: Calculate price (the game is not inventored)");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	calculatePrice(&store1, game13.bgName, 1, &retVal, &pvp);
 	if (retVal == ERR_NO_BGAME) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour calculating price when the game is not inventored)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour calculating price when the game is not inventored)\n");
#endif

	printf("\nTest 3.7: Calculate price (no stock)");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	calculatePrice(&store3, game33.bgName, 1, &retVal, &pvp);
 	if (retVal == ERR_NO_STOCK) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour calculating price when there is no stock of the game)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour calculating price when there is no stock of the game)\n");
#endif

	printf("\nTest 3.8: Calculate price (enough stock)");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	calculatePrice(&store1, game11.bgName, 2, &retVal, &pvp);
 	if (retVal == OK && pvp >= 83 && pvp <= 84) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour calculating price when there is stock of the game)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour calculating price when there is stock of the game)\n");
#endif

	printf("\nTest 3.9: Calculate price (enough stock)");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	calculatePrice(&store1, game11.bgName, 200, &retVal, &pvp);
 	if (retVal == OK && pvp >= 419 && pvp <= 420) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour calculating price when there is stock of the game)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour calculating price when there is stock of the game)\n");
#endif

	printf("\nTest 3.10: Update bgames in a store (nothing sold)");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	updateBGames(&store3, game11.bgName, 1, &retVal);
	if (retVal == ERR_NO_BGAME) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour updating bgames in a store when nothing sold)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour updating bgames in a store when nothing sold)\n");
#endif

	printf("\nTest 3.11: Update bgames in a store (some copies sold)");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	updateBGames(&store1, game11.bgName, 1, &retVal);
	if (retVal == OK &&
		store1.inventory.games.table[0].availability == 9) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour updating bgames in a store when some copies are sold)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour updating bgames in a store when some copies are sold)\n");
#endif

	printf("\nTest 3.12: Update bgames in a store (all copies sold)");
	(*totalTest)++;
#ifdef TYPEDEF_COMPLETED
	updateBGames(&store1, game11.bgName, 100, &retVal);
	if (retVal == OK &&
		store1.inventory.games.table[0].availability == 0 ) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour updating bgames in a store when all copies are sold)\n");
	}
#else
    printf("\n\t-> FAIL (unexpected behaviour updating bgames in a store when all copies are sold)\n");
#endif
	
}

void testFilters(int *totalTest, int *passedTest){
	tStore store1, store2, store3;
	tStoresTable tabStores;
    tBGame game11, game12, game13, game14, game15, game16;
    tBGame game21, game22, game23, game24, game25, game26;
    tBGame game31, game32, game33, game34, game35, game36, game37;
    tStoreId storeId;
	tError retVal;

	getStoreObject(STORE1, &store1);
	getStoreObject(STORE2, &store2);
	getStoreObject(STORE3, &store3);
	storeTableInit(&tabStores);
	
 	getBGameObject(BGAME11, &game11, &storeId);
	getBGameObject(BGAME12, &game12, &storeId);
	getBGameObject(BGAME13, &game13, &storeId);
	getBGameObject(BGAME14, &game14, &storeId);
	getBGameObject(BGAME15, &game15, &storeId);
	getBGameObject(BGAME16, &game16, &storeId);
	addBGame(&store1, game11, &retVal);
	addBGame(&store1, game12, &retVal);
	addBGame(&store1, game13, &retVal);
	addBGame(&store1, game14, &retVal);
	addBGame(&store1, game15, &retVal);
	addBGame(&store1, game16, &retVal);

	getBGameObject(BGAME21, &game21, &storeId);
	getBGameObject(BGAME22, &game22, &storeId);
	getBGameObject(BGAME23, &game23, &storeId);
	getBGameObject(BGAME24, &game24, &storeId);
	getBGameObject(BGAME25, &game25, &storeId);
	getBGameObject(BGAME26, &game26, &storeId);
	addBGame(&store2, game21, &retVal);
	addBGame(&store2, game22, &retVal);
	addBGame(&store2, game23, &retVal);
	addBGame(&store2, game24, &retVal);
	addBGame(&store2, game25, &retVal);
	addBGame(&store2, game26, &retVal);

	getBGameObject(BGAME31, &game31, &storeId);
	getBGameObject(BGAME32, &game32, &storeId);
	getBGameObject(BGAME33, &game33, &storeId);
	getBGameObject(BGAME34, &game34, &storeId);
	getBGameObject(BGAME35, &game35, &storeId);
	getBGameObject(BGAME36, &game36, &storeId);
	getBGameObject(BGAME37, &game37, &storeId);
	addBGame(&store3, game31, &retVal);
	addBGame(&store3, game32, &retVal);
	addBGame(&store3, game33, &retVal);
	addBGame(&store3, game34, &retVal);
	addBGame(&store3, game35, &retVal);
	addBGame(&store3, game36, &retVal);
	addBGame(&store3, game37, &retVal);

	printf("=================================================\n");
	printf(" FILTERS: By Category, by warehouse (Ex. 8a, 8c)\n");
	printf("=================================================\n");

	printf("\nTest 4.1: Filter bgame table by category (empty table)");
	(*totalTest)++;
	tBGameTable tabBGames;
	bgameTableInit(&tabBGames);
	tBGameTable tabBGames2;
	bgameTableInit(&tabBGames2);
	tGameCategory cat = TRIVIA;
	bgameTableFilterByCategory(&tabBGames, cat, &tabBGames2);
	if (tabBGames2.nBGames == 0 ) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour filtering bgame table by category with empty table)\n");
	}

	printf("\nTest 4.2: Filter bgame table by category (TRIVIA)");
	(*totalTest)++;

	bgameTableInit(&tabBGames2);
	bgameTableFilterByCategory(&(store3.inventory.games), cat, &tabBGames2);
	if (tabBGames2.nBGames == 2 ) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour filtering bgame table by category)\n");
	}

	printf("\nTest 4.3: Check occupancy >= 90 %% (empty table)");
	(*totalTest)++;
	tStoresTable tabStores2;
	storeTableInit(&tabStores2);
	float occupancy = 90;
	storesTableFilterByWarehouse(tabStores, occupancy, &tabStores2);
	
	if (tabStores2.nStores == 0 ) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour checking >= 90%% occupancy with empty table)\n");
	}

	storeTableAdd(&tabStores, store1, &retVal);
	storeTableAdd(&tabStores, store2, &retVal);
	storeTableAdd(&tabStores, store3, &retVal);	

	printf("\nTest 4.4: Check occupancy >= 90 %% ");
	(*totalTest)++;
	storeTableInit(&tabStores2);
	occupancy = 90;
	storesTableFilterByWarehouse(tabStores, occupancy, &tabStores2);
	
	if (tabStores2.nStores == 2 && 
		tabStores2.table[0].storeId == 1 &&
		tabStores2.table[1].storeId == 2) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour checking >= 90%% occupancy)\n");
	}
}

void testFilters2(int *totalTest, int *passedTest){
	tError retVal;
	tPurchase pur11, pur12, pur13, pur21, pur31, pur41;
	tPurchase pur51, pur61, pur62, pur71, pur72, pur73, pur74;
	tPurchase pur81, pur91, pur92;
	tPurchaseTable tabPurchases;
	int year;
	float benefit;
	tStoreId storeId = (tStoreId) 1;

	getPurchaseObject(PUR11, &pur11);
	getPurchaseObject(PUR12, &pur12);
	getPurchaseObject(PUR13, &pur13);
	getPurchaseObject(PUR21, &pur21);
	getPurchaseObject(PUR31, &pur31);
	getPurchaseObject(PUR41, &pur41);
	getPurchaseObject(PUR51, &pur51);
	getPurchaseObject(PUR61, &pur61);
	getPurchaseObject(PUR62, &pur62);
	getPurchaseObject(PUR71, &pur71);
	getPurchaseObject(PUR72, &pur72);
	getPurchaseObject(PUR73, &pur73);
	getPurchaseObject(PUR74, &pur74);
	getPurchaseObject(PUR81, &pur81);
	getPurchaseObject(PUR91, &pur91);
	getPurchaseObject(PUR92, &pur92);

	purchaseTableInit(&tabPurchases);

	printf("=================================================\n");
	printf(" FILTERS: By year and store (Ex. 8b)\n");
	printf("=================================================\n");

	printf("\nTest 4.5: Check benefit filtering by year and store (empty purchases table)");
	(*totalTest)++;
	year = 2023;
	purchaseTableFilterByYearAndStore (&tabPurchases, year, storeId, &retVal, &benefit);
	if (retVal == ERROR) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour filtering by year and store with empty table)\n");
	}

	purchaseTableAdd(&tabPurchases, pur11, &retVal);
	purchaseTableAdd(&tabPurchases, pur12, &retVal);
	purchaseTableAdd(&tabPurchases, pur13, &retVal);
	purchaseTableAdd(&tabPurchases, pur21, &retVal);
	purchaseTableAdd(&tabPurchases, pur31, &retVal);
	purchaseTableAdd(&tabPurchases, pur41, &retVal);
	purchaseTableAdd(&tabPurchases, pur51, &retVal);
	purchaseTableAdd(&tabPurchases, pur61, &retVal);
	purchaseTableAdd(&tabPurchases, pur62, &retVal);
	purchaseTableAdd(&tabPurchases, pur71, &retVal);
	purchaseTableAdd(&tabPurchases, pur72, &retVal);
	purchaseTableAdd(&tabPurchases, pur73, &retVal);
	purchaseTableAdd(&tabPurchases, pur74, &retVal);
	purchaseTableAdd(&tabPurchases, pur81, &retVal);
	purchaseTableAdd(&tabPurchases, pur91, &retVal);
	purchaseTableAdd(&tabPurchases, pur92, &retVal);

	printf("\nTest 4.6: Check benefit filtering by year and store");
	(*totalTest)++;
	purchaseTableFilterByYearAndStore (&tabPurchases, year, storeId, &retVal, &benefit);
	if (retVal == OK && benefit >= 262 && benefit <= 263) { /* Benefit should be 262.88 */
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour filtering by year and store)\n");
	}
}



void testStatistics(int *totalTest, int *passedTest){

	tStore store1, store2, store3;
	tStoresTable tabStores;
    tBGame game11, game12, game13, game14, game15, game16;
    tBGame game21, game22, game23, game24, game25, game26;
    tBGame game31, game32, game33, game34, game35, game36;
    tStoreId storeId;
	tError retVal;
	tPurchase pur11, pur12, pur13, pur21, pur31, pur41;
	tPurchase pur51, pur61, pur62, pur71, pur72, pur73, pur74;
	tPurchase pur81, pur91, pur92;
	tPurchaseTable tabPurchases;
	int year;
	tStoreId mostProf;
	tGameCategory category;

	getStoreObject(STORE1, &store1);
	getStoreObject(STORE2, &store2);
	getStoreObject(STORE3, &store3);
	storeTableInit(&tabStores);
	
 	getBGameObject(BGAME11, &game11, &storeId);
	getBGameObject(BGAME12, &game12, &storeId);
	getBGameObject(BGAME13, &game13, &storeId);
	getBGameObject(BGAME14, &game14, &storeId);
	getBGameObject(BGAME15, &game15, &storeId);
	getBGameObject(BGAME16, &game16, &storeId);
	addBGame(&store1, game11, &retVal);
	addBGame(&store1, game12, &retVal);
	addBGame(&store1, game13, &retVal);
	addBGame(&store1, game14, &retVal);
	addBGame(&store1, game15, &retVal);
	addBGame(&store1, game16, &retVal);

	getBGameObject(BGAME21, &game21, &storeId);
	getBGameObject(BGAME22, &game22, &storeId);
	getBGameObject(BGAME23, &game23, &storeId);
	getBGameObject(BGAME24, &game24, &storeId);
	getBGameObject(BGAME25, &game25, &storeId);
	getBGameObject(BGAME26, &game26, &storeId);
	addBGame(&store2, game21, &retVal);
	addBGame(&store2, game22, &retVal);
	addBGame(&store2, game23, &retVal);
	addBGame(&store2, game24, &retVal);
	addBGame(&store2, game25, &retVal);
	addBGame(&store2, game26, &retVal);

	getBGameObject(BGAME31, &game31, &storeId);
	getBGameObject(BGAME32, &game32, &storeId);
	getBGameObject(BGAME33, &game33, &storeId);
	getBGameObject(BGAME34, &game34, &storeId);
	getBGameObject(BGAME35, &game35, &storeId);
	getBGameObject(BGAME36, &game36, &storeId);
	addBGame(&store3, game31, &retVal);
	addBGame(&store3, game32, &retVal);
	addBGame(&store3, game33, &retVal);
	addBGame(&store3, game34, &retVal);
	addBGame(&store3, game35, &retVal);
	addBGame(&store3, game36, &retVal);

	getPurchaseObject(PUR11, &pur11);
	getPurchaseObject(PUR12, &pur12);
	getPurchaseObject(PUR13, &pur13);
	getPurchaseObject(PUR21, &pur21);
	getPurchaseObject(PUR31, &pur31);
	getPurchaseObject(PUR41, &pur41);
	getPurchaseObject(PUR51, &pur51);
	getPurchaseObject(PUR61, &pur61);
	getPurchaseObject(PUR62, &pur62);
	getPurchaseObject(PUR71, &pur71);
	getPurchaseObject(PUR72, &pur72);
	getPurchaseObject(PUR73, &pur73);
	getPurchaseObject(PUR74, &pur74);
	getPurchaseObject(PUR81, &pur81);
	getPurchaseObject(PUR91, &pur91);
	getPurchaseObject(PUR92, &pur92);

	purchaseTableInit(&tabPurchases);

	printf("=================================================\n");
	printf(" STATISTICS (Ex. 9)\n");
	printf("=================================================\n");

	printf("\nTest 5.1: Check most profitable store (empty store and purchases table)");
	(*totalTest)++;
	year = 2023;
	mostProfitableStore(&tabStores, &tabPurchases, year, &retVal, &mostProf);
	if (retVal == ERR_NO_STORE) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour checking most profitable store with empty table)\n");
	}

	purchaseTableAdd(&tabPurchases, pur11, &retVal);
	purchaseTableAdd(&tabPurchases, pur12, &retVal);
	purchaseTableAdd(&tabPurchases, pur13, &retVal);
	purchaseTableAdd(&tabPurchases, pur21, &retVal);
	purchaseTableAdd(&tabPurchases, pur31, &retVal);
	purchaseTableAdd(&tabPurchases, pur41, &retVal);
	purchaseTableAdd(&tabPurchases, pur51, &retVal);
	purchaseTableAdd(&tabPurchases, pur61, &retVal);
	purchaseTableAdd(&tabPurchases, pur62, &retVal);
	purchaseTableAdd(&tabPurchases, pur71, &retVal);
	purchaseTableAdd(&tabPurchases, pur72, &retVal);
	purchaseTableAdd(&tabPurchases, pur73, &retVal);
	purchaseTableAdd(&tabPurchases, pur74, &retVal);
	purchaseTableAdd(&tabPurchases, pur81, &retVal);
	purchaseTableAdd(&tabPurchases, pur91, &retVal);
	purchaseTableAdd(&tabPurchases, pur92, &retVal);

	printf("\nTest 5.2: Check most profitable store (empty store table)");
	(*totalTest)++;
	mostProfitableStore(&tabStores, &tabPurchases, year, &retVal, &mostProf);
	if (retVal == ERR_NO_STORE) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour checking most profitable store with empty table)\n");
	}

	storeTableAdd(&tabStores, store1, &retVal);
	storeTableAdd(&tabStores, store2, &retVal);
	storeTableAdd(&tabStores, store3, &retVal);	

	printf("\nTest 5.3: Check most profitable store");
	(*totalTest)++;
	mostProfitableStore(&tabStores, &tabPurchases, year, &retVal, &mostProf);
	if (retVal == OK && mostProf == 2) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour checking most profitable store \n");
	}

	printf("\nTest 5.4: Check less popular category");
	(*totalTest)++;
	storeId = (tStoreId) 1;
	lessPopularCategory(&tabPurchases, &tabStores, storeId, &retVal, &category);
	if (retVal == OK && category == AMERITRASH) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour checking less popular category)\n");
	}

	printf("\nTest 5.5: Check less popular category");
	(*totalTest)++;
	storeId = (tStoreId) 2;
	lessPopularCategory(&tabPurchases, &tabStores, storeId, &retVal, &category);
	if (retVal == OK && category == CARDS) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour checking less popular category)\n");
	}

	printf("\nTest 5.6: Check less popular category");
	(*totalTest)++;
	storeId = (tStoreId) 3;
	lessPopularCategory(&tabPurchases, &tabStores, storeId, &retVal, &category);
	if (retVal == OK && category == EUROGAME) {
		printf("\n\t-> OK\n");
		(*passedTest)++;
	} else {
		printf("\n\t-> FAIL (unexpected behaviour checking less popular category)\n");
	}

	
	

}
