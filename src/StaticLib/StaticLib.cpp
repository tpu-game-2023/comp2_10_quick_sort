#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	
		item* p = begin;
		item* q = end;
		item* pivot = (p + q) / 2;
		while (1)
		{
			while (p < pivot)
				p++;
			while (pivot < q)
				q--;
			if (p >= q)
				break;
			item tmp = *p;
			*p = *q;
			*q = tmp;
			p++;
			q--;
		}
	}
	// ToDo: クイックソートで並び替えてください

	return true;
}
