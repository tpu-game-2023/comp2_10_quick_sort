#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"
void Swap(item* p1,item* p2)
{
	item temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void Sort(item* begin, const item* end)
{
	if (begin == NULL || end - begin < 1)
		return;
	int pivot = begin[0].key;
	for (int i = 0; i < end - begin; i++)
	{
		if (pivot != begin[i + 1].key)
			break;
		if (i == end - begin - 1)
			return;
	}
	for (int i = 0; i < end - begin; i++)
	{
		if (pivot > begin[i + 1].key)
			break;
		if (i == end - begin - 1)
		{
			for (int j = 0; j < end - begin; j++)
			{
				if (pivot < begin[j + 1].key)
				{
					pivot = begin[j + 1].key;
					break;
				}
			}
		}
		if (pivot != begin[0].key)
			break;
	}

	int prev = 0, next = end - begin;
	while (1)
	{
		while (begin[prev].key < pivot)
			prev++;
		while (begin[next].key >= pivot)
			next--;
		if (prev > next)
		{
			Sort(begin, &begin[next]);
			Sort(&begin[prev], &begin[end - begin]);
			return;
		}
		else
			Swap(&begin[prev], &begin[next]);
	}
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
