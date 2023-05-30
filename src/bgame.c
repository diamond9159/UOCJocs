#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bgame.h"

void bgameTableInit(tBGameTable *gamesTable) {
    
    gamesTable->nBGames= 0;
}

void convertToUpper( char *string )
{
    int i, len;
    char originalChar;

    len= strlen(string);
    for (i= 0; i < len; i++) {
        originalChar= string[i];
        if (originalChar >= 'a' && originalChar <= 'z')
            string[i]= originalChar + 'A' - 'a';
    }
}

int namesCmp(char *n1, char *n2) {

    char string1[MAX_LINE];
    char string2[MAX_LINE];

    strcpy( string1, n1 );
    strcpy( string2, n2 );
    convertToUpper( string1 );
    convertToUpper( string2 );

    return strcmp(string1,string2);
}

int bgameCmp(tBGame g1, tBGame g2) {
#ifdef TYPEDEF_COMPLETED
    int different = namesCmp(g1.bgName, g2.bgName);
    if (!different){
        different = (g1.bgameId != g2.bgameId) ||
                    (g1.age != g2.age) ||
                    (g1.duration != g2.duration) ||
                    (g1.category != g2.category) ||
                    (g1.launchDate != g2.launchDate) ||
                    (g1.price != g2.price) ||
                    (g1.discount != g2.discount) ||
                    (g1.availability != g2.availability);
    }
    return different;
#else
    return true;
#endif
}


void bgameCpy(tBGame *dst, tBGame src) 
{    
    /*****************************************/
    /* Exercise 2a */    
    /*****************************************/









    /*****************************************/
}

void bgameTableAdd(tBGameTable *tabBGames, tBGame bgame, tError *retVal) {
    /*****************************************/
    /* Exercise 3a */    
    /*****************************************/















    /*****************************************/
}

int bgameTableFindId(tBGameTable *tabBGames, tBGameId id)
{
    int idx = NO_BGAME;
    /*****************************************/
    /* Exercise 2b */    
    /*****************************************/








    /*****************************************/
    return idx;
}

int bgameTableFindName(tBGameTable *tabBGames, char *name)
{
    int idx = NO_BGAME;
    /*****************************************/
    /* Exercise 2b */    
    /*****************************************/








    /*****************************************/
    return idx;
}

void bgameTableDel(tBGameTable *tabBGames, tBGameId id, tError *retVal) 
{   
    /*****************************************/
    /* Exercise 3b */    
    /*****************************************/







   






    /*****************************************/
}

void bgameTableFilterByCategory(tBGameTable *tabBGames, tGameCategory category, tBGameTable *tabBGames2) 
{   
    /*****************************************/
    /* Exercise 8a */    
    /*****************************************/





      




    /*****************************************/
}
