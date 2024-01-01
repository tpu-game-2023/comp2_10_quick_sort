#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"
void Swap(item* p1,item* p2)
{
	item temp;
	memcpy(&temp, p1, sizeof(item));
	memcpy(p1, p2, sizeof(item));
	memcpy(p2, &temp, sizeof(item));
}
void Sort(item* begin, const item* end)
{
	if (begin == NULL ||end == NULL|| end - begin < 1)
		return;
	int pivot = begin->key;
	for (int i = 1; i < end - begin + 1; i++)
	{
		if (pivot != (begin + i)->key)
			break;
		if (begin + i == end)
			return;
	}
	for (int i = 1; i < end - begin + 1; i++)
	{
		if (pivot > (begin + i)->key)
			break;
		if (begin + i == end)
		{
			for (int j = 1; j < end - begin + 1; j++)
			{
				if (pivot < (begin + j)->key)
				{
					pivot = (begin + j)->key;
					break;
				}
			}
		}
		if (pivot != begin->key)
			break;
	}

	int prev = 0, next = end - begin;
	while (1)
	{
		while ((begin + prev)->key < pivot)
			prev++;
		while ((begin + next)->key >= pivot)
			next--;
		if (prev > next)
		{
			break;
		}
		else
			Swap((begin + prev), (begin + next));
	}
	Sort(begin, begin + next);
	Sort(begin + prev, end);
	return;
}
// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	if (begin == NULL || end == NULL || end - begin < 1) return false;
	Sort(begin, end - 1);
	// ToDo: クイックソートで並び替えてください
	return true;
}