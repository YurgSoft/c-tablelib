#include <stdio.h>
#include <stdlib.h>


//***********************************************
//			LIST OF ALL THE STRUCTS DATATYPE
typedef struct{
	int number_collum, max_character;
}tableBaseSetting;

typedef struct{
	int max_character;
	char *info;
}tableCell;

typedef struct{
	char** CellFields;
}tableBaseRow;

typedef char *row[];

//***********************************************
//			LIST OF PROTOTYPES
void printTableHead(int);
tableBaseRow CreateRow(tableBaseSetting);
void printTableHeader(tableBaseSetting,tableBaseRow);
void printTableSeparators(tableBaseSetting);
void printTableRow(tableBaseSetting,tableBaseRow);

//***********************************************
//       LIST OF ALL FUNCTION DEFENITION	


void printTableHead(int a){
	printf("%d\n", a);
}

tableBaseRow CreateRow(tableBaseSetting base){
	char** head = (char**)malloc(base.number_collum * base.max_character);
	tableBaseRow output;

	output.CellFields = head;

	return output;
}

void printTableSeparators(tableBaseSetting base){
	int i, j;
	putchar('+');
	for(i = 0 ; i<base.number_collum ; i++){
		for(j = 0 ; j<base.max_character; j++) putchar('-');
		putchar('+');		
	}

	putchar('\n');
}

void printTableHeader(tableBaseSetting base,tableBaseRow header){
	printTableSeparators(base);
	printTableRow(base,header);
}

void printTableRow(tableBaseSetting base,tableBaseRow info){
	int i, j;
	putchar('|');
	for(i = 0 ; i<base.number_collum ; i++){
		for(j = 0 ; j<base.max_character; j++) putchar(info.CellFields[i][j]);
		putchar('|');
	}
	putchar('\n');
	printTableSeparators(base);
}