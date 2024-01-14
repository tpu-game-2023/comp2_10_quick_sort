#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

static void swap(item* i1, item* i2)
{
	item tmp = *i1;
	*i1 = *i2;
	*i2 = tmp;
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	
	if (begin == NULL || end == NULL)return false;
	if (end - begin < 1)return false;

	if (end - begin <= 1)return true;

	int pivot = begin->key;

	item* front = begin + 1;
	item* back = begin + (end - begin) - 1;
	
	// ToDo: クイックソートで並び替えてください
	while (true)
	{
		while (front->key <= pivot && front < end)
			front++;
		while (pivot <= back->key && begin < back)
			back--;

		if (back < front)
			break;

		swap(front, back);
	};

	if (back != begin)
		swap(begin, back);

	quick_sort(begin, back);
	quick_sort(back + 1, end);

	return true;
}
