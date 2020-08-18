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

//ASSIGN______________________________________________________________________________________________________________________________________________________________
void nameAssign(Recipe** pHead, FILE* fp) {
	char name1[150];
	fgets(name1, 150, fp);
	nameMalloc(pHead, name1);
}

void costAssign(Recipe** pHead, FILE* fp) {
	char buf[50];
	fgets(buf, 50, fp);
	costAtof(pHead, buf);
}

void ingredientsAssign(Recipe** pHead, FILE* fp) {
	char buf1[500];
	fgets(buf1, 500, fp);
	ingredientsMalloc(pHead, buf1);
}

void recipeAssign(Recipe** pHead, FILE* fp) {
	char buf2[2000];
	fgets(buf2, 2000, fp);
	recipeMalloc(pHead, buf2);
}

void markAssign(Recipe** pHead, FILE* fp) {
	char buf3[25];
	fgets(buf3, 25, fp);
	markAtof(pHead, buf3);
}

void assign(Recipe** pHead, FILE* fp) {
	nameAssign(pHead, fp);
	costAssign(pHead, fp);
	ingredientsAssign(pHead, fp);
	recipeAssign(pHead, fp);
	markAssign(pHead, fp);
}

//USER ASSIGN_____________________________________________________________________________________________________________________________________________________
void userNameAssign(Recipe** pHead) {
	char name1[150];
	printf("Enter name: ");
	fgets(name1, 150, stdin);
	nameMalloc(pHead, name1);
}

void userCostAssign(Recipe** pHead) {
	char buf[25];
	printf("Enter cost of one portion(in zl): ");
	fgets(buf, 25, stdin);
	costAtof(pHead, buf);
}

void userIngredientsAssign(Recipe** pHead) {
	char buf1[500];
	printf("Enter ingredients: ");
	fgets(buf1, 500, stdin);
	ingredientsMalloc(pHead, buf1);
}

void userRecipeAssign(Recipe** pHead) {
	char buf2[2000];
	printf("Enter recipe: ");
	fgets(buf2, 2000, stdin);
	recipeMalloc(pHead, buf2);
}

void userMarkAssign(Recipe** pHead) {
	char buf3[25];
	printf("Enter mark: ");
	fgets(buf3, 25, stdin);
	markAtof(pHead, buf3);
}

void userAssign(Recipe** pHead) {
	userNameAssign(pHead);
	userCostAssign(pHead);
	userIngredientsAssign(pHead);
	userRecipeAssign(pHead);
	userMarkAssign(pHead);
	//printf("Your recipe:\n");
	//writeRec(pHead);
	yellow();  printf("\nRecipe saved!"); resetColor();
}
