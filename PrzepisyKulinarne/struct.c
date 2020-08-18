#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "struct.h"
#include "func.h"
#include "assign.h"
#include "menu.h"

#pragma warning(disable:4996)

void putNULL(Recipe** pHead) {
	if ((*pHead) !=NULL) {
		(*pHead)->name = NULL;
		(*pHead)->ingredients = NULL;
		(*pHead)->recipe = NULL;
	}
}

void nameMalloc(Recipe** pHead, char* name1) {
	size_t len = strlen(name1);
	(*pHead)->name = malloc(len + 1);
	if ((*pHead)->name != NULL) {
		strcpy((*pHead)->name, name1);
	}
}

void ingredientsMalloc(Recipe** pHead, char* buf1) {
	size_t len1 = strlen(buf1);
	(*pHead)->ingredients = malloc(len1 + 1);
	if ((*pHead)->ingredients != NULL) {
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
}

void recipeMalloc(Recipe** pHead, char *buf2) {
	size_t len2 = strlen(buf2);
	(*pHead)->recipe = malloc(len2 + 1);
	if ((*pHead)->recipe !=NULL) {
		strcpy((*pHead)->recipe, buf2);
	}
}

void addRecipe(Recipe** pHead, FILE* fp) {
	if (*pHead == NULL) {
		*pHead = (Recipe*)malloc(sizeof(Recipe));
		if ((*pHead) != NULL) {
			(*pHead)->pNext = NULL;
			putNULL(pHead);
			assign(pHead, fp);
		}
		//writeRec(pHead); // sprawdzenie
	}
	else {
		Recipe* pt = *pHead;
		while (pt->pNext != NULL) {
			pt = pt->pNext;
		}
		pt->pNext = (Recipe*)malloc(sizeof(Recipe));
		if (pt->pNext != NULL) {
			pt->pNext->pNext = NULL;
			assign(&(pt)->pNext, fp);
		}
		//writeRec(&(pt)->pNext);   //sprawdzenie
	}
}

void userAddRecipe(Recipe** pHead) {
	yellow(); printf("\nADD RECIPE\n"); resetColor();
	if (*pHead == NULL) {
		*pHead = (Recipe*)malloc(sizeof(Recipe));
		if ((*pHead) != NULL) {
			(*pHead)->pNext = NULL;
			//PRZYPISANIE
			userAssign(pHead);
		}
	}
	else {
		Recipe* pt = *pHead;
		while (pt->pNext != NULL) {
			pt = pt->pNext;
		}
		pt->pNext = (Recipe*)malloc(sizeof(Recipe));
		if ((pt->pNext) != NULL) {
			pt->pNext->pNext = NULL;
			//PRZYPISANIE
			userAssign(&(pt)->pNext);
		}
	}
};

void deleteList(Recipe** pHead) {
	Recipe* current = *pHead;
	Recipe* next = NULL;
	while (current != NULL) {
		next = current->pNext;
		free(current->name);
		free(current->ingredients);
		free(current->recipe);
		free(current);
		current = next;
	}
	*pHead = NULL;
}