#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

int Partitioning(item* begin, const item* end, int a, int b)
{
	item num;

	for (int i = a; i < b; i++)
	{
		if ((begin + i)->key <= (begin + b)->key)
		{
			num = *(begin + a);
			*(begin + a) = *(begin + i);
			*(begin + i) = num;

			a++;
		}
	}

	num = *(begin + b);
	*(begin + b) = *(begin + a);
	*(begin + a) = num;

	return a;
}

void main_sort(item* begin, const item* end, int a, int b)
{
	if (a < b)
	{
		int pivot = Partitioning(begin, end, a, b);

		main_sort(begin, end, a, pivot - 1);
		main_sort(begin, end, pivot + 1, b);
	}
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin != 0 && end != 0 && begin <= end)
	{
		int num = end - begin;
		
		main_sort(begin, end, 0, num - 1);

		return true;
	}
	return false;
}
