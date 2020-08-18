#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "struct.h"
#include "func.h"
#include "assign.h"

#define HOWMANY 7
#define HOWLONG 30
#pragma warning(disable:4996)

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	runProgram();
	return 0;
}