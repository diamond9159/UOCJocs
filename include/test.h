/* Run all the test set */
#include "data.h"
#include "api.h"
#include "store.h"
#include "bgame.h"
#include "purchase.h"

/* Runs the applications tests */
void runTests();
void testTableOperation(int *totalTest, int *passedTest);
void testUpdateStores(int *totalTest, int *passedTest);
void testBGamesSales(int *totalTest, int *passedTest);
void testFilters(int *totalTest, int *passedTest);
void testFilters2(int *totalTest, int *passedTest);
void testStatistics(int *totalTest, int *passedTest);