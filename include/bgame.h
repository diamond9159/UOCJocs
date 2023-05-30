#include "data.h"

/* Initializes the given board games table */
void bgameTableInit(tBGameTable *gamesTable);

/* Converts an string to upper case */
void convertToUpper( char *string );

/* Compare two board games (given the tBGame structs) and return 0 if equal, 1 otherwise*/
int bgameCmp(tBGame g1, tBGame g2);

/* Compare two board games names (given the name strings) */
int namesCmp(char *n1, char *n2);

/* Copy a given board game data (src) to another (dst) */
void bgameCpy(tBGame *dst, tBGame src);

/* Add a new board game to the table of board games */
void bgameTableAdd(tBGameTable *tabBGames, tBGame bgame, tError *retVal);

/* Find a board game (given its id or name) in the table and return its position */
int bgameTableFindId(tBGameTable *tabBGames, int id);
int bgameTableFindName(tBGameTable *tabBGames, char *name);

/* Remove the first occurence of a board game in the table */
void bgameTableDel(tBGameTable *tabBGames, tBGameId id, tError *retVal);

/* Generate a table with the board games of a given table whose category is the same as that provided */
void bgameTableFilterByCategory(tBGameTable *tabBGames, tGameCategory category, tBGameTable *tabBGames2);
