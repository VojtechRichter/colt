#include "colt.h"

ColtTableColumn* create_column(size_t size)
{
	ColtTableColumn* col = (ColtTableColumn*) malloc(sizeof(ColtTableColumn));
	if (col == NULL) {
		printf("Error allocating ColtTableColumn\n");
		exit(1);
	}

	col->cells = (ColtTableCell*) malloc(size * sizeof(COLT_COL_INT));
	if (col->cells == NULL) {
		printf("Error allocating ColtTableCell*\n");
	}

	return col;
}

ColtTable* create_table(char name[], size_t col_count)
{
	ColtTable* table = (ColtTable*) malloc(sizeof(ColtTable));
	table->columns = (ColtTableColumn*) malloc(col_count * sizeof(ColtTableColumn));
	table->column_capacity = col_count;
	strcpy_s(table->name, ARRAY_LEN(table->name), name);

	return table;
}

void print_column_content(ColtTableColumn* col)
{
	for (int i = 0; i < ARRAY_LEN(col->cells); i++) {
		printf("[%d]::%" PRId64 "\n", i, col->cells[i].value);
	}
}

void release_column(ColtTableColumn* col)
{
	free(col->cells);
	free(col);
}

void release_table(ColtTable* table)
{
	free(table->columns);
	free(table);
}

void insert_column(ColtTable* table, ColtTableColumn* col)
{
	table->columns[ARRAY_LEN(table->columns)] = *col;
}

void print_table(ColtTable* table)
{
	printf("\t--------------Table: %s--------------\n", table->name);
}