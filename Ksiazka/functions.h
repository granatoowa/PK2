/**@file*/
#ifndef functions_h
#define functions_h

#pragma warning(disable:4996)

/**Funkcja czyszczaca ekran z opoznieniem 100.*/
void system_CLS();

/**Funkcja wypisujaca przepis na standardowe wyjscie
@param pHead Wskaznik na pierwszy element listy
*/
void writeRec(Recipe** pHead);

/**Funkcja alokujaca pamiec dla listy przepisow.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void addRecipe(Recipe** pHead, struct FILE* fp);

/**Funkcja wyszukujaca wszystkie przepisy z podanym przez uzytkownika skladnikiem oraz wypisujaca je na ekran. 
@param pHead Wskaznik na pierwszy element listy
@param ing Wskaznik na podany skladnik
*/
void searchIng(Recipe* pHead, char* ing);

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

/**Funkcja pobierajaca dane z pliku, alokujaca pamiec dla poszczegolnych wlasciwosci listy(nazwa, skladniki i przepis) oraz przypisujaca konkretne dane(ocena, koszt).
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void assign(Recipe** pHead, struct FILE* fp);

/**Funkcja zmieniajaca ocene przepisu.
@param pHead Wskaznik na pierwszy element listy
@param mark Zawiera ocene podana przez uzytkownika
@param length Zawiera ilosc przepisow z listy
@param num Zawiera numer przepisu podany przez uzytkownika
*/
void changeMark(Recipe** pHead, float mark, int length, int num);

/**Funkcja pobierajaca dane od uzytkownika dotyczace przepisu.
@param pHead Wskaznik na pierwszy element listy
*/
void userAssign(Recipe** pHead);

/**Funkcja dodajaca do listy przepis wpisany przez uzytkownika.
@param pHead Wskaznik na pierwszy element listy
*/
void userAddRecipe(Recipe** pHead);

/**Funkcja zwracajaca koszt przepisu. 
@param pHead Wskaznik na pierwszy element listy
*/
double menuCost(Recipe* pHead);

/**Funkcja tworzaca menu oraz wyliczajaca jego koszt. 
@param pHead Wskaznik na pierwszy element listy
@param listlength Zawiera iloœæ przepisow na liscie
*/
void menu(Recipe* pHead, int listlength);

/**Funkcja dealokujaca pamiec listy z przepisami. 
@param pHead Wskaznik na pierwszy element listy
*/
void deleteList(Recipe** pHead);

/**Funkcja zawierajaca cale menu glowne wraz z mozliwoscia wyboru.*/
void runProgram();

#endif
