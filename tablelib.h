/*
	This Lib is completely free and open Source for the comunity

	Name : c-TableLib
	Company : YurgSoft
	Written by: Simao Gaspar

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//***********************************************
//			LIST OF ALL THE STRUCTS DATATYPE

typedef struct{
	int max_character;
	char *data;
}tableHeader;

typedef struct{
	char *data;
}CellData;

typedef struct{
	int number_row;
	CellData **CellFields;
}tableRow;

typedef struct{
	int number_collum;
	tableHeader *collumSeting;
}tableSetting;

typedef struct{
	tableSetting config;
	tableRow rows;
}Table;

typedef char *row[];

//***********************************************
//			LIST OF PROTOTYPES

void printTableHeader(tableSetting);
void printTableSeparators(tableSetting);
void printTableRow(Table,int);
void printTable(Table);

//***********************************************
//       LIST OF ALL FUNCTION DEFENITION	

//********************************************
void printTableSeparators(tableSetting setting){
	int i, j;
	putchar('\n');
	putchar('+');
	for(i = 0 ; i<setting.number_collum ; i++){
		for(j = 0 ; j<setting.collumSeting[i].max_character; j++) putchar('-');
		putchar('+');		
	}

	putchar('\n');
}


//********************************************
void printTableHeader(tableSetting header){
	int i,j;
	int max_collum = header.number_collum;
	printTableSeparators(header);
	putchar('|');
	for(i = 0 ; i<max_collum ; i++){
		tableHeader current_cell = header.collumSeting[i];
		int extra = current_cell.max_character - strlen(current_cell.data);
		int limit = extra>0?strlen(header.collumSeting[i].data) : header.collumSeting[i].max_character;

		for(j = 0 ; j<limit; j++) putchar(header.collumSeting[i].data[j]);
		while(extra>0) putchar(' '), extra--;
		putchar('|');
	}
	
	printTableSeparators(header);
}

//********************************************
void printTableRow(Table tb, int rowPos){
	int i, j, max_collum;
	max_collum = tb.config.number_collum;

	putchar('|');
	for(i = 0 ; i<max_collum ; i++){
		CellData *current_cell = tb.rows.CellFields[rowPos];
		
		int max_caracter = tb.config.collumSeting[i].max_character;
		int extra = max_caracter - strlen(current_cell[i].data);
		
		int limit = extra>0?strlen(current_cell[i].data) : max_caracter;

		for(j = 0 ; j<limit; j++) putchar(current_cell[i].data[j]);
		while(extra>0) putchar(' '), extra--;
		putchar('|');
		
	}

	printTableSeparators(tb.config);
}


//********************************************
void printTable(Table table){
	int i;
	printTableHeader(table.config);
	for(i=0;i<table.rows.number_row ; i++)
		printTableRow(table,i);
}