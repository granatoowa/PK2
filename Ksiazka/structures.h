/**@file*/
#ifndef structures_h
#define structures_h
#define HOWMANY 7
#define HOWLONG 30

#pragma warning(disable:4996)

/**Struktura zawierajaca nazwe, skladniki, przepis, ocene, koszt jednej porcji oraz wskaznik na nastepny element.*/ 
typedef struct Struct {
	char* name;
	char* ingredients;
	char* recipe;
	double cost;
	double mark;
	char ing[HOWMANY][HOWLONG];
	struct Struct* pNext;
} Recipe;

#endif
