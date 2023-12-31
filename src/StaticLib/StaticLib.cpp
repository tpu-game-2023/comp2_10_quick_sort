#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)//配列と要素集
{
	// ToDo: クイックソートで並び替えてください

	int n = 1;

	item* p = begin; //軸
	item* q = begin + n;//軸のn個先
	
	if (begin == NULL || end < begin)
		return false;

	int pivot = end - begin;
		

	if (p <= q)//大きかったら何する？右に寄せたい。
	{
		n++;
	}
	else//右のほうが小さいから入れ替えて右を大きくしよう。
	{
		item tmp = *p;
		*p = *q;
		*q = tmp;

		n++;
	}
		
	
	
	
	
	return true;
}
