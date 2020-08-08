#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "struct.h"
#include "func.h"
#include "file.h"

#pragma warning(disable:4996)

//ASSIGN______________________________________________________________________________________________________________________________________________________________
void nameAssign(Recipe** pHead, FILE* fp) {
	char name1[150];
	fgets(name1, 150, fp);
	size_t len = strlen(name1);
	(*pHead)->name = malloc(len + 1);
	strcpy((*pHead)->name, name1);
}

void costAssign(Recipe** pHead, FILE* fp) {
	char buf[50];
	double cost;
	fgets(buf, 50, fp);
	cost = atof(buf);
	(*pHead)->cost = cost;
}

void ingredientsAssign(Recipe** pHead, FILE* fp) {
	char buf1[500];
	fgets(buf1, 500, fp);
	size_t len1 = strlen(buf1);
	(*pHead)->ingredients = malloc(len1 + 1);
	strcpy((*pHead)->ingredients, buf1);
	char* pch;
	pch = strtok(buf1, ",\n");
	int i = 0;
	while (pch != NULL) {
		//printf("%s\n", pch);
		strcpy((*pHead)->ing[i], pch);
		//printf("%s\n", (*pHead)->ing[i]);
		pch = strtok(NULL, ",\n");
		i++;
	}
}

void recipeAssign(Recipe** pHead, FILE* fp) {
	char buf2[2000];
	fgets(buf2, 2000, fp);
	size_t len2 = strlen(buf2);
	(*pHead)->recipe = malloc(len2 + 1);
	strcpy((*pHead)->recipe, buf2);
}

void markAssign(Recipe** pHead, FILE* fp) {
	char buf3[25];
	double mark;
	fgets(buf3, 25, fp);
	mark = atof(buf3);
	(*pHead)->mark = mark;
}

void assign(Recipe** pHead, FILE* fp) {
	nameAssign(pHead, fp);
	costAssign(pHead, fp);
	ingredientsAssign(pHead, fp);
	recipeAssign(pHead, fp);
	markAssign(pHead, fp);
}

void addRecipe(Recipe** pHead, FILE* fp) {
	if (*pHead == NULL) {
		*pHead = (Recipe*)malloc(sizeof(Recipe));
		(*pHead)->pNext = NULL;
		assign(pHead, fp);
		//writeRec(pHead); // sprawdzenie
	}
	else {
		Recipe* pt = *pHead;
		while (pt->pNext != NULL) {
			pt = pt->pNext;
		}
		pt->pNext = (Recipe*)malloc(sizeof(Recipe));
		pt->pNext->pNext = NULL;
		assign(&(pt)->pNext, fp);
		//writeRec(&(pt)->pNext);   //sprawdzenie
	}
}


//MENU_________________________________________________________________________________________________________________________________________________________________
void writeRecMenu(Recipe* pHead, FILE* fp) {
	fprintf(fp, "%s", pHead->name);
	fprintf(fp, "Mark: %0.001f\nCost(one portion): %0.001f zl\n", pHead->mark, pHead->cost);
	fprintf(fp, "Ingredients: %s", pHead->ingredients);
	fprintf(fp, "Recipe: %s\n", pHead->recipe);
}

double whichRecipe(Recipe* pHead, FILE* fp, int which) {
	Recipe* wsk1 = pHead;
	double cost;
	for (int j = 0; j <= which; j++) {
		if (which == j) {
			//wpisanie do pliku menu
			writeRecMenu(wsk1, fp);
			cost = wsk1->cost;
		}
		wsk1 = wsk1->pNext;
	}
	return cost;
}