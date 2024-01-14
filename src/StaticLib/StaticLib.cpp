#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin == NULL || end < begin)
	{
		return false;
	}

	item* a = begin;
	//for (int i = 0; a != end; i++) {
	//	a = begin + i;
		for (item* p = begin; p != end - 1; p++) {
			item* q = begin + (end - begin - 1);
			if (a < q) {
				item tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	//}

	return true;
}