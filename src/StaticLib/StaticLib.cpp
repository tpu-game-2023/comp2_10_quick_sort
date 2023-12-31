#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

void swap(item* begin, const item* end, int a, int b)
{
	item tmp;
	tmp = *(begin + a);
	*(begin + a) = *(begin + b);
	*(begin + b) = tmp;
}

int partition(item* begin, const item* end, int m, int n)
{
	for (int i = m; i < n; i++)
	{
		if ((begin + i)->key <= (begin + n)->key)
		{
			swap(begin, end, m, i);
			m++;
		}
	}

	swap(begin, end, n, m);

	return m;
}

void sort(item* begin, const item* end, int m, int n)
{
	if (m < n)
	{
		int x = partition(begin, end, m, n);
		sort(begin, end, m, x - 1);
		sort(begin, end, x + 1, n);
	}
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin == NULL || end == NULL || end < begin)
	{
		return false;
	}

	int n = end - begin;
	sort(begin, end, 0, n - 1);

	return true;
}
