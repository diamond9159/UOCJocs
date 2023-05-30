#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "data.h"
#include "store.h"
#include "bgame.h"
#include "api.h"
#include "purchase.h"

void storeTableInit(tStoresTable *storesTable) {
    storesTable->nStores=0;
}

void storeTableLoad(tStoresTable *tabStores, const char* filename, tError *retVal) {
    *retVal = OK;

    FILE *fin=NULL;
    char line[MAX_LINE];
    tStore newStore;


    /* Initialize the output table */
    storeTableInit(tabStores);

    /* Open the input file */
    if((fin=fopen(filename, "r"))!=NULL) {

        /* Read all the stores */
        while(!feof(fin) && tabStores->nStores<MAX_STORES) {
            /* Remove any content from the line */
            line[0] = '\0';
            /* Read one line (maximum 511 chars) and store it in "line" variable */
            fgets(line, MAX_LINE-1, fin);
            /* Ensure that the string is ended by 0*/
            line[MAX_LINE-1]='\0';
            if(strlen(line)>0) {
                /* Obtain the object */
                getStoreObject(line, &newStore);

                /* By default, the specialDiscount is set to 0 */
                newStore.specialDiscount = 0.0;

                /* By deault, no games are available in the store */
                newStore.inventory.nBGames=0;
                newStore.inventory.nStoredBGames=0;
                newStore.inventory.games.nBGames=0;

                /* Add the new store to the output table */
                storeTableAdd(tabStores, newStore, retVal);
            }
        }
        /* Close the file */
        fclose(fin);

    }else {
        *retVal = ERR_CANNOT_READ;
    }
}

/* The content of the string str is parsed into the fields of the store structure */
void getStoreObject(const char *str, tStore *store) {

    int auxId;
    char bufferName[MAX_LINE];
    char bufferCity[MAX_LINE];

    /* read store data */
    sscanf(str, "%d %s %s %d",
        &auxId, bufferName, bufferCity, &store->maxStorage);

    strcpy(store->name, bufferName);
    strcpy(store->city, bufferCity);
    store->storeId = (tStoreId)auxId;
}

void storeTableAdd(tStoresTable *tabStores, tStore store, tError *retVal) {

        *retVal = OK;

        /* Check if there enough space for the new store */
        if(tabStores->nStores>=MAX_STORES)
                *retVal = ERR_MEMORY;

        if (*retVal == OK) {
                /* Add the new store to the end of the table */
                storeCpy(&tabStores->table[tabStores->nStores],store);
                tabStores->nStores++;
        }
}

void storeTableDel(tStoresTable *tabStores, tStoreId storeId, tError *retVal) {

    int i;
    int pos;
    *retVal = ERR_NO_STORE;
    pos = storeTableFind(*tabStores, storeId);
    if (pos!=NO_STORE)
    {
	*retVal = OK;
        for(i=pos; i<tabStores->nStores-1; i++) {        
            storeCpy(&(tabStores->table[i]),tabStores->table[i+1]);
        }
        tabStores->nStores=tabStores->nStores-1;      
    }
}

void storeCpy(tStore *dst, tStore src)
{
    dst->storeId = src.storeId;
    strcpy(dst->name,src.name);
    strcpy(dst->city,src.city);
    dst->maxStorage= src.maxStorage;
    dst->inventory= src.inventory;
    dst->specialDiscount= src.specialDiscount;
}

void inventoriesLoad(tStoresTable *tabStores, const char* filename, tError *retVal) {

    *retVal = OK;

    FILE *fin=NULL;
    char line[MAX_LINE];
    tBGame newBGame;
    tStoreId storeId;
    
    storeId = ERR_NO_STORE;

    /* Open the input file */
    if((fin=fopen(filename, "r"))!=NULL) {

        /* Read all the board games to populate stores' inventories */
        while(!feof(fin)) {
            /* Remove any content from the line */
            line[0] = '\0';
            /* Read one line (maximum 511 chars) and store it in "line" variable */
            fgets(line, MAX_LINE-1, fin);
            /* Ensure that the string is ended by 0*/
            line[MAX_LINE-1]='\0';
            if(strlen(line)>0) {
                /* Obtain the object */
                getBGameObject(line, &newBGame, &storeId);

#ifdef TYPEDEF_COMPLETED
                /* By default, the board game discount is set to 0 */
                newBGame.discount = 0.0;
#endif

                /* Check if the board game is already in the store inventory */
                inventoryBGameAdd(tabStores, storeId, newBGame, retVal);
            }
        }
        /* Close the file */
        fclose(fin);

    }else {
        *retVal = ERR_CANNOT_READ;
    }
}

/* The content of the string str is parsed into the fields of the inventory structure */
void getBGameObject(const char *str, tBGame *bgame, tStoreId *storeId) {
#ifdef TYPEDEF_COMPLETED
    int auxStoreId, auxBGameId, auxCategory;

    /* read store data */
    sscanf(str, "%d %d %s %d %d %d %d %f %d",
        &auxStoreId, &auxBGameId, bgame->bgName, &bgame->age,
        &bgame->duration, &auxCategory, &bgame->launchDate,
        &bgame->price, &bgame->availability);

    bgame->bgameId = (tBGameId)auxBGameId;
    bgame->category = (tGameCategory)auxCategory;
    *storeId = (tStoreId)auxStoreId;
#endif
}

int storeTableFind(tStoresTable tabStores, tStoreId id) {

        int idx = NO_STORE;

        int i=0;
        while(i< tabStores.nStores && idx==NO_STORE) {
                /* Check if the id is the same */
                if((int)id==(int)(tabStores.table[i].storeId))  {
                        idx = i;
                }
                i++;
        }

        return idx;
}

void inventoryBGameAdd(tStoresTable *tabStores, tStoreId storeId, tBGame newBGame, tError *retVal) {
    int iStore = storeTableFind(*tabStores, storeId);
    if ( iStore != NO_STORE )
    {
        addBGame(&(tabStores->table[iStore]), newBGame, retVal);
    }else { /* Store does not exist */
        *retVal = ERR_STORE_INVALID;
    }

}

void inventoryBGameDel(tInventory *inventory, tBGameId bgameId, tError *retVal) 
{   
    *retVal = ERR_NO_BGAME;
#ifdef TYPEDEF_COMPLETED
    int i;
    int pos;
    pos = bgameTableFindId(&(inventory->games), bgameId);
    if (pos!=NO_BGAME)
    {
	*retVal = OK;
        inventory->nStoredBGames = inventory->nStoredBGames - inventory->games.table[pos].availability;
        for(i=pos; i<inventory->nBGames-1; i++) {        
            bgameCpy(&(inventory->games.table[i]),inventory->games.table[i+1]);
        }
        inventory->nBGames = inventory->nBGames-1;
    }
#endif
}

void storesTableSave(tStoresTable tabStores, const char* filename, tError *retVal) {

    *retVal = OK;

    FILE *fout=NULL;
    int i;
    char str[MAX_LINE];
    
    /* Open the output file */
    if((fout=fopen(filename, "w"))==0) {
        *retVal = ERR_CANNOT_WRITE;
    } else {
    
        /* Save all stores to the file */
        for(i=0;i<tabStores.nStores;i++) {
            getStoreStr(tabStores.table[i], MAX_LINE, str);
            fprintf(fout, "%s\n", str);            
        }
            
        /* Close the file */
        fclose(fout);
    }
}

/* The content of the fields of the store structure is written into the string str */
void getStoreStr(tStore store, int maxSize, char *str) {
    
    /* Build the string */  
    snprintf(str,maxSize-1,"%d %s %s %d", 
         (int)store.storeId, store.name, store.city, store.maxStorage);          
}

void inventoriesTableSave(tStoresTable tabStores, const char* filename, tError *retVal) {

    *retVal = OK;

    FILE *fout=NULL;
    int i, j, ngames;
    char str[MAX_LINE];
    
    /* Open the output file */
    if((fout=fopen(filename, "w"))==0) {
        *retVal = ERR_CANNOT_WRITE;
    } else {
    
        /* Save all stores to the file */
        for(i=0;i<tabStores.nStores;i++) {
            ngames = tabStores.table[i].inventory.games.nBGames;
            for(j=0; j<ngames; j++) {
                getBGameStr(tabStores.table[i].inventory.games.table[j], MAX_LINE, str);
                fprintf(fout, "%d %s\n", (int)tabStores.table[i].storeId, str);
            }               
        }
            
        /* Close the file */
        fclose(fout);
    }
}

/* The content of the fields of the bgame structure is written into the string str */
void getBGameStr(tBGame bgame, int maxSize, char *str) {
#ifdef TYPEDEF_COMPLETED
    /* Build the string */  
    snprintf(str,maxSize-1,"%d %s %d %d %d %d %.2f %d", 
         (int)bgame.bgameId, bgame.bgName, bgame.age, bgame.duration,
         (int)bgame.category, bgame.launchDate, bgame.price, bgame.availability);
#endif      
}

void checkAvailability(tStore *store, char *name, int amount, tError *retVal, int *toSell) {
    /*****************************************/
    /* Exercise 6a */    
    /*****************************************/



















    /*****************************************/
}

void calculatePrice(tStore *store, char *name, int amount, tError *retVal, float *pvp) {
    /*****************************************/
    /* Exercise 6b */    
    /*****************************************/


















    /*****************************************/
}

void updateBGames(tStore *store, char *name, int amount, tError *retVal) {
    /*****************************************/
    /* Exercise 6c */    
    /*****************************************/













    /*****************************************/
}

void storesTableFilterByWarehouse(tStoresTable tabStores, float occupancy, tStoresTable *tabStores2) 
{   
    /*****************************************/
    /* Exercise 8c */    
    /*****************************************/







    /*****************************************/
}

void mostProfitableStore (tStoresTable *tabStores, tPurchaseTable *tabPurchases, int year, tError *retVal, tStoreId *profStore){
    /*****************************************/
    /* Exercise 9a */    
    /*****************************************/



















    /*****************************************/
}
