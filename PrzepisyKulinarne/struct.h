/**@file*/
#ifndef struct_h
#define struct_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define HOWMANY 7
#define HOWLONG 30

#pragma warning(disable:4996)

/**Struktura zawierajaca nazwe, skladniki, przepis, ocene, koszt jednej porcji oraz wskaznik na nastepny element.*/
typedef struct Struct {
	char* name; ///< Zawiera nazwe przepisu
	char* ingredients; ///< Zawiera nazwy skladnikow
	char* recipe; ///< Zawiera recepture
	double cost; ///< Zawiera koszt przepisu
	double mark; ///< Zawiera ocene przepisu
	char ing[HOWMANY][HOWLONG]; ///< Zawiera tablica skladnikow
	struct Struct* pNext; ///< Wskaznik na nastepny element
} Recipe;

/**Funkcja ustawiajaca NULL dla konkretnych elementow struktury.
@param pHead Wskaznik na pierwszy element listy
*/
void putNULL(Recipe** pHead);

/**Funkcja alokujaca pamiec dla nazwy przepisu.
@param pHead Wskaznik na pierwszy element listy
@param name1 Wskaznik na nazwe przepisu
*/
void nameMalloc(Recipe** pHead, char* name1);

/**Funkcja alokujaca pamiec dla skladnikow przepisu.
@param pHead Wskaznik na pierwszy element listy
@param buf1 Wskaznik na skladniki przepisu
*/
void ingredientsMalloc(Recipe** pHead, char* buf1);

/**Funkcja alokujaca pamiec dla receptury przepisu.
@param pHead Wskaznik na pierwszy element listy
@param buf2 Wskaznik na recepture przepisu
*/
void recipeMalloc(Recipe** pHead, char* buf2);

/**Funkcja alokujaca pamiec dla listy przepisow.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void addRecipe(Recipe** pHead, struct FILE* fp);

/**Funkcja dodajaca do listy przepis wpisany przez uzytkownika.
@param pHead Wskaznik na pierwszy element listy
*/
void userAddRecipe(Recipe** pHead);

/**Funkcja dealokujaca pamiec listy z przepisami.
@param pHead Wskaznik na pierwszy element listy
*/
void deleteList(Recipe** pHead);

#endif
