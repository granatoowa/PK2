/** @file */
#ifndef assign_H
#define assign_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#pragma warning(disable:4996)

//ASSIGN_____________________________________________________________________________________________________________________________________________________
/**Funkcja pobierajaca z pliku dane dotyczace nazwy przepisu i alokujaca dla nich pamiec.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void nameAssign(Recipe** pHead, struct FILE* fp);

/**Funkcja pobierajaca z pliku dane dotyczace kosztu przepisu i alokujaca dla nich pamiec.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void costAssign(Recipe** pHead, struct FILE* fp);

/**Funkcja pobierajaca z pliku dane dotyczace skladnikow przepisu i alokujaca dla nich pamiec.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void ingredientsAssign(Recipe** pHead, struct FILE* fp);

/**Funkcja pobierajaca z pliku dane dotyczace receptury i alokujaca dla nich pamiec.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void recipeAssign(Recipe** pHead, struct FILE* fp);

/**Funkcja pobierajaca z pliku dane dotyczace oceny przepisu i alokujaca dla nich pamiec.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void markAssign(Recipe** pHead, struct FILE* fp);

/**Funkcja przypisujaca konketne dane do elementow listy.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void assign(Recipe** pHead, struct FILE* fp);

// USER ASSIGN_____________________________________________________________________________________________________________________________________________________________
/**Funkcja pobierajaca od uzytkownika dane dotyczace nazwy przepisu.
@param pHead Wskaznik na pierwszy element listy
*/
void userNameAssign(Recipe** pHead);

/**Funkcja pobierajaca od uzytkownika dane dotyczace kosztu przepisu.
@param pHead Wskaznik na pierwszy element listy
*/
void userCostAssign(Recipe** pHead);

/**Funkcja pobierajaca od uzytkownika dane dotyczace skladnikow przepisu.
@param pHead Wskaznik na pierwszy element listy
*/
void userIngredientsAssign(Recipe** pHead);

/**Funkcja pobierajaca od uzytkownika dane dotyczace receptury.
@param pHead Wskaznik na pierwszy element listy
*/
void userRecipeAssign(Recipe** pHead);

/**Funkcja pobierajaca od uzytkownika dane dotyczace oceny przepisu.
@param pHead Wskaznik na pierwszy element listy
*/
void userMarkAssign(Recipe** pHead);

/**Funkcja pobierajaca dane od uzytkownika dotyczace przepisu.
@param pHead Wskaznik na pierwszy element listy
*/
void userAssign(Recipe** pHead);

#endif 
