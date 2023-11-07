
#include "colt.h"

#include <stdio.h>

INTERNAL inline void preload(void)
{
	printf("\n");
}

int main(void) {
	preload();

	ColtTable* table = create_table("test_table", 5);

	ColtTableColumn* col = create_column(20);
	col->cells[0].value = 10;
	col->cells[2].value = 50;

	printf("%zd\n", sizeof(col->cells));

	printf("%"PRId64"\n", col->cells[0].value);
	printf("%"PRId64"\n", col->cells[1].value);
	printf("%"PRId64"\n", col->cells[2].value);

	// insert_column(table, col);

	// print_table(table);

	// print_column_content(col);

	// printf("Size: %zd\n", ARRAY_LEN(table->columns));
	// printf("Capacity: %zd\n", table->column_capacity);

	release_column(col);
	release_table(table);

	return 0;
}