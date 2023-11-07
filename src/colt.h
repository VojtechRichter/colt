#ifndef COLT_COLT_H_
#define COLT_COLT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <string.h>

#define INTERNAL static
#define PERSISTENT static

#define ARRAY_LEN(x) (sizeof(x) / sizeof(x[0]))

#define MAX_NAME_SIZE 64
#define MAX_COLUMN_COUNT 1024
#define COLT_COL_INT int64_t

#pragma warning(disable: 5045)

typedef struct {
	int64_t value;
} ColtTableCell;

typedef struct {
	char name[MAX_NAME_SIZE];
	ColtTableCell* cells;
} ColtTableColumn;

typedef struct {
	char name[MAX_NAME_SIZE];
	ColtTableColumn* columns;
	size_t column_capacity;
} ColtTable;

ColtTableColumn* create_column(size_t size);
ColtTable* create_table(char name[], size_t col_count);
void print_column_content(ColtTableColumn* col);
void release_column(ColtTableColumn* col);
void release_table(ColtTable* table);
void insert_column(ColtTable* table, ColtTableColumn* col);
void print_table(ColtTable* table);

#endif