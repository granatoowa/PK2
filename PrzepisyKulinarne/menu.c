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
	printf("\n");
}

void switchDays(int i, FILE* file) {
	switch (i) {
	case 0:
		yellow(); printf("\nMONDAY\n"); resetColor();
		fprintf(file, "\nMONDAY\n");
		break;
	case 1:
		yellow(); printf("\nTUESDAY\n"); resetColor();
		fprintf(file, "\nTUESDAY\n");
		break;
	case 2:
		yellow(); printf("\nWEDNESDAY\n"); resetColor();
		fprintf(file, "\nWEDNESDAY\n");
		break;
	case 3:
		yellow(); printf("\nTHURDSAY\n"); resetColor();
		fprintf(file, "\nTHURSDAY\n");
		break;
	case 4:
		yellow(); printf("\nFRIDAY\n"); resetColor();
		fprintf(file, "\nFRIDAY\n");
		break;
	case 5:
		yellow(); printf("\nSATURDAY\n"); resetColor();
		fprintf(file, "\nSATURDAY\n");
		break;
	case 6:
		yellow(); printf("\nSUNDAY\n"); resetColor();
		fprintf(file, "\nSUNDAY\n");
		break;
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
			switchDays(i, file);
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
void menu(Recipe* pHead, int listlength) {
	int menulength;
	int people;
	yellow(); printf("\nCREATE MENU AND CALCULATE COST\n"); resetColor();
	printf("\nFor how many people: ");
	scanf("%d", &people);
	writeAllNames(pHead);
	printf("\nHow many recipes do you want to add to the daily menu: ");
	scanf("%d", &menulength);
	writeFMenu(pHead, people, menulength);
	readFMenu();
}
