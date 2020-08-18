/** @file */
#ifndef func_H
#define func_H

#pragma warning(disable:4996)

//CLEANING________________________________________________________________________________________________________________________________________________________________
/**Funkcja czyszczaca ekran z opoznieniem 100.*/
void system_CLS();

/**Funkcja czyszczaca ekran z opoznieniem 3000.*/
void system_3CLS();

//COLOR___________________________________________________________________________________________________________________________________________________________________
/**Funkcja zmieniajaca kolor czcionki.*/
void yellow();

/**Funkcja przywracajaca bialy kolor czcionki.*/
void resetColor();

//WRITE___________________________________________________________________________________________________________________________________________________________________
/**Funkcja wypisujaca przepis na standardowe wyjscie.
@param pHead Wskaznik na pierwszy element listy
*/
void writeRec(Recipe** pHead);

/**Funkcja wypisujaca nazwy wszystkich przepisow z listy na standardowe wyjscie.
@param pHead Wskaznik na pierwszy element listy
*/
void writeAllNames(Recipe* pHead);

//CONTENTS_______________________________________________________________________________________________________________________________________________________________
/**Funkcja wypisujaca menu programu na standardowe wyjscie.*/
void printStartMenu();

//ATOF___________________________________________________________________________________________________________________________________________________________________
/**Funkcja konwertujaca wartoœæ kosztu przepisu zapisana w ³añcuchu znaków do postaci liczby zmiennoprzecinkowej(double)
@param pHead Wskaznik na pierwszy element listy
@param buf Wskaznik na cyfre/liczbe dotyczaca kosztu przepisu
*/
void costAtof(Recipe** pHead, char* buf);

/**Funkcja konwertujaca wartoœæ kosztu przepisu zapisana w ³añcuchu znaków do postaci liczby zmiennoprzecinkowej(double)
@param pHead Wskaznik na pierwszy element listy
@param buf3 Wskaznik na cyfre/liczbe dotyczaca oceny przepisu
*/
void markAtof(Recipe** pHead, char* buf3);

//SEARCH RECIPE__________________________________________________________________________________________________________________________________________________________
/**Funkcja wyszukujaca wszystkie przepisy z podanym przez uzytkownika skladnikiem oraz wypisujaca je na ekran.
@param pHead Wskaznik na pierwszy element listy
@param ing Wskaznik na skladnik podany przez uzytkownika
*/
void searchIng(Recipe* pHead, char* ing);

/**Funkcja pobierajaca nazwe skladnika od uzytkownika do wyszukania przepisu.
@param pHead Wskaznik na pierwszy element listy
*/
void searchRecipe(Recipe* pHead);

//MARK RECIPE____________________________________________________________________________________________________________________________________________________________
/**Funkcja zmieniajaca ocene przepisu.
@param pHead Wskaznik na pierwszy element listy
@param mark Zawiera ocene podana przez uzytkownika
@param listlength Zawiera dlugosc listy
@param num Zawiera numer przepisu podany przez uzytkownika
*/
int changeMark(Recipe* pHead, float mark, int listlength, int num);

/**Funkcja pobierajaca od uzytkownika numer przepisu oraz ocene, aby zmienic ocene przepisu.
@param pHead Wskaznik na pierwszy element listy
@param listlength Zawiera dlugosc listy
*/
void markRecipe(Recipe* pHead, int listlength);

//END___________________________________________________________________________________________________________________________________________________________________
/**Funkcja zapisujaca koncowa liste do pliku
@param pHead Wskaznik na pierwszy element listy
*/
void endFWrite(Recipe* pHead);

//RUN__________________________________________________________________________________________________________________________________________________________________
/**Funkcja zawierajaca cale menu glowne wraz z mozliwoscia wyboru.*/
void runProgram();

#endif 