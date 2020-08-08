#pragma once
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
	char* name; ///< Nazwa przepisu
	char* ingredients; ///< Nazwy skladnikow
	char* recipe; ///< Receptura
	double cost; ///< Koszt przepisu
	double mark; ///< Ocena przepisu
	char ing[HOWMANY][HOWLONG]; ///< Tablica skladnikow
	struct Struct* pNext; ///< Wskaznik na nastepny element
} Recipe;

#endif
