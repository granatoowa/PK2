#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "struct.h"
#include "func.h"
#include "file.h"

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

void reset() {
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
	yellow(); printf("\nRecipe Cookbook\n\n"); reset();
	printf("MENU\n");
	printf("1.Search recipe\n");
	printf("2.Mark recipe\n");
	printf("3.Add recipe\n");
	printf("4.Create menu and calculate cost\n");
	printf("\nEnter number(1-4):");
}

//SEARCH RECIPE____________________________________________________________________________________________________________________
void searchIng(Recipe* pHead, char* ing) {
	Recipe* wsk = pHead;
	while (wsk != NULL) {
		for (int i = 0; i < HOWMANY; i++) {
			if (strcmp(wsk->ing[i], ing) == 0) {
				printf("\n");
				writeRec(&wsk);
			}
		}
		//printf("%s", wsk->name);
		wsk = wsk->pNext;
	}
}

void searchRecipe(Recipe* pHead) {
	yellow(); printf("\nSEARCH RECIPE\n\n"); reset();
	char ing[20];
	printf("Enter ingredient: ");
	fgets(ing, 20, stdin);
	char* pch;
	pch = strtok(ing, ",\n");
	searchIng(pHead, pch);
}

//MARK RECIPE_______________________________________________________________________________________________________________________
void changeMark(Recipe* pHead, float mark, int length, int num) {
	//struct Struct* temp = pHead;
	Recipe* temp = pHead;
	for (int i = 0; i < length; i++) {
		if (i == (num - 1)) {
			//printf("%d.", i + 1);
			//printf("%s", temp->name);
			temp->mark = mark;
		}
		temp = temp->pNext;
	}
}

void markRecipe(Recipe* pHead, int listlength) {
	float mark;
	int num1;
	Recipe* wsk1 = pHead;
	yellow(); printf("\nMARK RECIPE \n\n"); reset();
	writeAllNames(pHead);
	printf("\nEnter recipe's number: "); //wybranie cyfry (przepisu)
	scanf("%d", &num1);
	printf("\nEnter mark: ");
	scanf("%f", &mark);
	changeMark(wsk1, mark, listlength, num1);  //zmienienie oceny
	printf("\nMark saved!\n");
}

//ADD RECIPE___________________________________________________________________________________________________________________________
void userNameAssign(Recipe** pHead) {
	char name1[150];
	printf("Enter name: ");
	fgets(name1, 150, stdin);
	size_t len = strlen(name1);
	(*pHead)->name = malloc(len + 1);
	strcpy((*pHead)->name, name1);
}

void userCostAssign(Recipe** pHead) {
	double cost;
	char buf[25];
	printf("Enter cost of one portion(in zl): ");
	fgets(buf, 25, stdin);
	cost = atof(buf);
	(*pHead)->cost = cost;
}

void userIngredientsAssign(Recipe** pHead) {
	char buf1[500];
	printf("Enter ingredients: ");
	fgets(buf1, 500, stdin);
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

void userRecipeAssign(Recipe** pHead) {
	char buf2[2000];
	printf("Enter recipe: ");
	fgets(buf2, 2000, stdin);
	size_t len2 = strlen(buf2);
	(*pHead)->recipe = malloc(len2 + 1);
	strcpy((*pHead)->recipe, buf2);
}

void userMarkAssign(Recipe** pHead) {
	double mark;
	char buf3[25];
	printf("Enter mark: ");
	fgets(buf3, 25, stdin);
	mark = atof(buf3);
	(*pHead)->mark = mark;
}

void userAssign(Recipe** pHead) {
	userNameAssign(pHead);
	userCostAssign(pHead);
	userIngredientsAssign(pHead);
	userRecipeAssign(pHead);
	userMarkAssign(pHead);
	writeRec(pHead);
	printf("Recipe saved!");
}

void userAddRecipe(Recipe** pHead) {
	yellow(); printf("\nADD RECIPE\n"); reset();
	if (*pHead == NULL) {
		*pHead = (Recipe*)malloc(sizeof(Recipe));
		(*pHead)->pNext = NULL;
		//PRZYPISANIE
		userAssign(pHead);
	}
	else {
		Recipe* pt = *pHead;
		while (pt->pNext != NULL) {
			pt = pt->pNext;
		}
		pt->pNext = (Recipe*)malloc(sizeof(Recipe));
		pt->pNext->pNext = NULL;
		//PRZYPISANIE
		userAssign(&(pt)->pNext);
	}
};

//MENU_______________________________________________________________________________________________________________________________________
void readFMenu() {
	char buff[10000];
	FILE* file1 = fopen("menu.txt", "r");
	if (file1 != NULL) {
		while (fgets(buff, 1000, file1) != NULL)
		{
			printf("%s", buff);
			//printf("%s\n", word);
		}
		fclose(file1);
	}
}

void writeFMenu(Recipe* pHead, int people, int menulength) {
	Recipe* wsk1 = pHead;
	int which;
	double cost;
	double recCost;
	cost = 0;
	FILE* file = fopen("menu.txt", "w");
	if (file != NULL) {
		fprintf(file, "\nMENU\n");
		for (int i = 0; i < 7; i++) {
			switch (i) {
			case 0:
				yellow(); printf("\nMONDAY\n"); reset();
				fprintf(file, "\nMONDAY\n");
				break;
			case 1:
				yellow(); printf("\nTUESDAY\n"); reset();
				fprintf(file, "\nTUESDAY\n");
				break;
			case 2:
				yellow(); printf("\nWEDNESDAY\n"); reset();
				fprintf(file, "\nWEDNESDAY\n");
				break;
			case 3:
				yellow(); printf("\nTHURDSAY\n"); reset();
				fprintf(file, "\nTHURSDAY\n");
				break;
			case 4:
				yellow(); printf("\nFRIDAY\n"); reset();
				fprintf(file, "\nFRIDAY\n");
				break;
			case 5:
				yellow(); printf("\nSATURDAY\n"); reset();
				fprintf(file, "\nSATURDAY\n");
				break;
			case 6:
				yellow(); printf("\nSUNDAY\n"); reset();
				fprintf(file, "\nSUNDAY\n");
				break;
			}
			for (int i = 0; i < menulength; i++) {
				printf("Enter %d. number: ", i + 1);
				scanf("%d", &which);
				which = which - 1;
				recCost = whichRecipe(wsk1, file, which);
				cost += recCost;
			}
		}
		cost *= people;
		fprintf(file, "COST: %0.001f zl", cost);
		system_CLS();
		fclose(file);
	}
}

void menu(Recipe* pHead, int listlength) {
	int menulength;
	int people;
	yellow(); printf("\nCREATE MENU AND CALCULATE COST\n"); reset();
	printf("\nFor how many people: ");
	scanf("%d", &people);
	writeAllNames(pHead);
	printf("\nHow many recipes do you want to add to the daily menu: ");
	scanf("%d", &menulength);
	writeFMenu(pHead, people, menulength);
	readFMenu();
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

void deleteList(Recipe** pHead) {
	Recipe* current = *pHead;
	Recipe* next;

	while (current != NULL) {
		next = current->pNext;
		free(current->recipe);
		free(current->name);
		free(current->ingredients);
		free(current);
		current = next;
	}
	*pHead = NULL;
}

//RUN_________________________________________________________________________________________________________________________________________________
void runProgram() {
	Recipe* pHead;
	pHead = (Recipe*)malloc(sizeof(Recipe));
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
	int num;
	scanf("%d", &num);
	while ((getchar()) != '\n');
	system_CLS();
	switch (num) {
	case 1:
		searchRecipe(pHead);
		//runProgram(); umozliwic dalsze korzystanie?
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
		//runProgram(); umozliwic dalsze korzystanie?
		break;
	default:
		break;
	}
}