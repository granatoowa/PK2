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

//CLEANING_______________________________________________________________________________________________________________________
void system_CLS() {
	Sleep(100);
	system("cls");
}

void system_3CLS() {
	Sleep(3000);
	system("cls");
}

//COLOR___________________________________________________________________________________________________________________________
void yellow() {
	printf("\033[1;33m");
}

void resetColor() {
	printf("\033[0m");
}

//WRITE___________________________________________________________________________________________________________________________
void writeRec(Recipe** pHead) {
	printf("%s", (*pHead)->name);
	printf("Mark: %0.001f\nCost(one portion): %0.001f zl\n", (*pHead)->mark, (*pHead)->cost);
	printf("Ingredients: %s", (*pHead)->ingredients);
	printf("Recipe: %s\n", (*pHead)->recipe);
}

void writeAllNames(Recipe* pHead) {
	Recipe* wsk = pHead;
	int i = 1;
	printf("\nRECIPES TO CHOOSE FROM\n");
	while (wsk != NULL) {
		printf("%d.%s", i, wsk->name);
		wsk = wsk->pNext;
		i++;
	}
}

//CONTENTS_________________________________________________________________________________________________________________________
void printStartMenu() {
	yellow(); printf("\nRecipe Cookbook\n\n"); resetColor();
	printf("MENU\n");
	printf("1.Search recipe\n");
	printf("2.Mark recipe\n");
	printf("3.Add recipe\n");
	printf("4.Create menu and calculate cost\n");
	printf("\nEnter number(1-4):");
}

//ATOF_____________________________________________________________________________________________________________________________
void costAtof(Recipe** pHead, char* buf) {
	double cost;
	cost = atof(buf);
	(*pHead)->cost = cost;
}

void markAtof(Recipe** pHead, char* buf3) {
	double mark;
	mark = atof(buf3);
	(*pHead)->mark = mark;
}

//SEARCH RECIPE____________________________________________________________________________________________________________________
void searchIng(Recipe* pHead, char* ing) {
	Recipe* wsk = pHead;
	while (wsk != NULL) {
		for (int i = 0; i < HOWMANY; i++) {
			if (strcmp(wsk->ing[i], ing) == 0) {
				printf("\n");
				writeRec(&wsk);
				printf("\n");
			}
		}
		//printf("%s", wsk->name);
		wsk = wsk->pNext;
	}
}

void searchRecipe(Recipe* pHead) {
	yellow(); printf("\nSEARCH RECIPE\n\n"); resetColor();
	char ing[20];
	printf("Enter ingredient: ");
	fgets(ing, 20, stdin);
	char* pch;
	pch = strtok(ing, ",\n");
	searchIng(pHead, pch);
	//free(pch);  jak zwolnic?
}

//MARK RECIPE_______________________________________________________________________________________________________________________
int changeMark(Recipe* pHead, float mark, int length, int num) {
	//struct Struct* temp = pHead;
	Recipe* temp = pHead;
	for (int i = 0; i < length; i++) {
		if (i == (num - 1)) {
			//printf("%d.", i + 1);
			//printf("%s", temp->name);
			temp->mark = mark;
			return 1;
		}
		temp = temp->pNext;
	}
	return 0;
}

void markRecipe(Recipe* pHead, int listlength) {
	float mark;
	int num1;
	int done;
	Recipe* wsk1 = pHead;
	yellow(); printf("\nMARK RECIPE \n\n"); resetColor();
	writeAllNames(pHead);
	printf("\nEnter recipe's number: "); //wybranie cyfry (przepisu)
	scanf("%d", &num1);
	printf("\nEnter mark: ");
	scanf("%f", &mark);
	done = changeMark(wsk1, mark, listlength, num1); 
	if(done == 1)
		printf("\nMark saved!\n"); //zmienienie oceny
	//printf("\nMark saved!\n");
}

//END______________________________________________________________________________________________________________________________________________
void endFWrite(Recipe* pHead) {
	//ZAPISANIE LISTY DO PLIKU!!!!!
	Recipe* temp = pHead;
	FILE* file = fopen("recipes.txt", "w");
	if (file != NULL) {
		while (temp) {
			fprintf(file, "%s", temp->name);
			fprintf(file, "%0.001f\n", temp->cost);
			fprintf(file, "%s", temp->ingredients);
			fprintf(file, "%s", temp->recipe);
			if (temp->pNext) {
				fprintf(file, "%0.001f\n", temp->mark);
			}
			else {
				fprintf(file, "%0.001f", temp->mark);
			}
			temp = temp->pNext;
		}
		fclose(file);
	}
}

//RUN_________________________________________________________________________________________________________________________________________________
void runProgram() {
	Recipe* pHead;
	pHead = NULL;
	FILE* file = fopen("recipes.txt", "r");
	int listlength = 0;
	if (file)
	{
		do {
			addRecipe(&pHead, file);
			listlength++;
		} while (feof(file) == 0);
		fclose(file);
	}
	printStartMenu();
	//deleteList();
	int num;
	scanf("%d", &num);
	while ((getchar()) != '\n');
	system_CLS();
	switch (num) {
	case 1:
		searchRecipe(pHead);
		//runProgram();  //umozliwic dalsze korzystanie?
		break;
	case 2:
		markRecipe(pHead, listlength);
		system_3CLS();
		endFWrite(pHead);
		deleteList(&pHead);
		runProgram();
		break;
	case 3:
		userAddRecipe(&pHead);
		system_3CLS();
		endFWrite(pHead);
		deleteList(&pHead);
		runProgram();
		break;
	case 4:
		menu(pHead, listlength);
		deleteList(&pHead);
		//runProgram();  //umozliwic dalsze korzystanie?
		break;
	default:
		break;
	}
	deleteList(&pHead);
}