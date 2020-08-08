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
void reset();

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

//SEARCH RECIPE__________________________________________________________________________________________________________________________________________________________
/**Funkcja wyszukujaca wszystkie przepisy z podanym przez uzytkownika skladnikiem oraz wypisujaca je na ekran.
@param pHead Wskaznik na pierwszy element listy
@param ing Wskaznik na podany skladnik
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
void changeMark(Recipe* pHead, float mark, int listlength, int num);

/**Funkcja pobierajaca od uzytkownika numer przepisu oraz ocene, aby zmienic ocene przepisu.
@param pHead Wskaznik na pierwszy element listy
@param listlength Zawiera dlugosc listy
*/
void markRecipe(Recipe* pHead, int listlength);

//ADD RECIPE_____________________________________________________________________________________________________________________________________________________________
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

/**Funkcja dodajaca do listy przepis wpisany przez uzytkownika.
@param pHead Wskaznik na pierwszy element listy
*/
void userAddRecipe(Recipe** pHead);

//MENU__________________________________________________________________________________________________________________________________________________________________
/**Funkcja pobierajaca dane z pliku dotyczacego menu i wypisujaca je na ekran.*/
void readFMenu();

/**Funkcja wpisujaca menu do pliku oraz wyliczajaca jego koszt.
@param pHead Wskaznik na pierwszy element listy
@param people Zawiera ilosc osob podana przez uzytkownika
@param menulength Zawiera dlugosc menu
*/
void writeFMenu(Recipe* pHead, int people, int menulength);

/**Funkcja tworzaca menu.
@param pHead Wskaznik na pierwszy element listy
@param listlength Zawiera iloœæ przepisow na liscie
*/
void menu(Recipe* pHead, int listlength);

//END___________________________________________________________________________________________________________________________________________________________________
/**Funkcja zapisujaca koncowa liste do pliku
@param pHead Wskaznik na pierwszy element listy
*/
void endFWrite(Recipe* pHead);

/**Funkcja dealokujaca pamiec listy z przepisami.
@param pHead Wskaznik na pierwszy element listy
*/
void deleteList(Recipe** pHead);
//RUN__________________________________________________________________________________________________________________________________________________________________
/**Funkcja zawierajaca cale menu glowne wraz z mozliwoscia wyboru.*/
void runProgram();

#endif 