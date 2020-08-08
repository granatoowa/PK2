/** @file */
#ifndef file_H
#define file_H
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

/**Funkcja alokujaca pamiec dla listy przepisow.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void addRecipe(Recipe** pHead, struct FILE* fp);

//MENU__________________________________________________________________________________________________________________________________________________________
/**Funkcja wpisujaca przepisy do pliku zwiazanym z menu.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void writeRecMenu(Recipe* pHead, struct FILE* fp);

/**Funkcja wyszukujaca przepisy, ktore maja zostac wpisane do menu.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
@param which Zawiera numer przepisu podanego przez uzytkownika
*/
double whichRecipe(Recipe* pHead, struct FILE* fp, int which);





#endif 
