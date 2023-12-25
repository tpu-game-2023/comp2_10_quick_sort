#include <iostream>
#include <stdlib.h>

#include "../include/lib_func.h"
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	const int NUM = 100;
	item items[NUM];

	for (int i = 0; i < NUM; i++) {
		items[i].key = rand();
	}

	quick_sort(items, items + NUM);

	for (int i = 0; i < NUM; i++) {
		printf_s("%d\n", items[i].key);
		if (i + 1 < NUM && items[i].key > items[i+1].key)
			printf("	bad\n");
	}
}
