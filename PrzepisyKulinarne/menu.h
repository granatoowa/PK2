/**@file*/
#ifndef menu_h
#define menu_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define HOWMANY 7
#define HOWLONG 30

#pragma warning(disable:4996)

//MENU__________________________________________________________________________________________________________________________________________________________________
/**Funkcja pobierajaca dane z pliku dotyczacego menu i wypisujaca je na ekran.*/
void readFMenu();

/**Funkcja wpisujaca do pliku i wypisujaca na ekran informacje w zaleznosci od dnia
@param i Zawiera informacje o dniu tygodnia
@param file Wskaznik na plik
*/
void switchDays(int i, struct FILE* file);

/**Funkcja wpisujaca menu do pliku oraz wyliczajaca jego koszt.
@param pHead Wskaznik na pierwszy element listy
@param people Zawiera ilosc osob podana przez uzytkownika
@param menulength Zawiera dlugosc menu
*/
void writeFMenu(Recipe* pHead, int people, int menulength);

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

/**Funkcja tworzaca menu.
@param pHead Wskaznik na pierwszy element listy
@param listlength Zawiera iloœæ przepisow na liscie
*/
void menu(Recipe* pHead, int listlength);

#endif

