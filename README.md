# c-tablelib
This lib is for printing table in the screen.

List of the data type used in this lib
- Table
- tableSetting
- tableRow
- tableHeader
- CellData



* Here is one example of how to use the lib

* Demostration 1


#include "tableLib.h"

int main(int argc, char **argv){

	Table tabela;
	tableRow row;

	tableHeader headerConfig[] = {
		{
			.max_character = 10,
			.data = "Numero"
		},
		{
			.max_character = 20,
			.data = "Nome Aluno"
		},
		{
			.max_character = 15,
			.data = "Diagnostico"
		}
	};

	tabela.config.number_collum = 3;
	tabela.config.collumSeting = headerConfig;

	CellData linha1[] = {
		"1",
		"Simao gaspar",
		"Aprovou"
	};
	CellData linha2[] = {
		"2",
		"YurgSoft",
		"Aprovou"
	};

	CellData linha3[] = {
		"25",
		"Fulano da silva Sim",
		"Reprovado"
	};

	CellData *groupLinha[3];
	groupLinha[0] = linha1;
	groupLinha[1] = linha2;
	groupLinha[2] = linha3;

	row.number_row = 3;
	row.CellFields = groupLinha;

	tabela.rows = row;
	
	printTable(tabela);	
	return 0;
}



Or you can use this way


* Demostration 2

#include "tableLib.h"

int main(int argc, char **argv){

	Table tabela;
	tableRow row;

	tableHeader headerConfig[] = {
		{
			.max_character = 10,
			.data = "Numero"
		},
		{
			.max_character = 20,
			.data = "Nome Aluno"
		},
		{
			.max_character = 15,
			.data = "Diagnostico"
		}
	};

	tabela.config.number_collum = 3;
	tabela.config.collumSeting = headerConfig;

	CellData *lista[] = {
		(CellData []){
			"1",
		  "Simao gaspar",
		  "Aprovou"
		},
		(CellData []){
			"5",
			"Silva ak Listado",
			"Passou"
		},
		(CellData []){
			"8",
			"Lunguagem liqh",
			"Passou"
		},
		(CellData []){
			"10",
			"Antonio fulado 2",
			"Passou"
		}
	};

	row.number_row = 4;
	row.CellFields = lista;

	tabela.rows = row;
	
	printTable(tabela);
  
	return 0;
}
