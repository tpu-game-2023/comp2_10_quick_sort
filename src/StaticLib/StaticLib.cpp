#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"
void swap(item* p, item* q)
{
	item temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin == NULL || end < begin)
		return false;
	item* pivot;
	pivot = begin;
	item* p = begin;
	item* q = begin + (end - begin - 1);
	while (p->key<q->key) {
		while (p->key < pivot->key)
		{
			p->key++;
		}
		while (q->key > pivot->key)
		{
			q->key--;
		}
			item temp = *p;
			*p = *q;
			*q = temp;
			
	}
	
	quick_sort(p, pivot-1);
	quick_sort(pivot+1,q);
	return true;
}
