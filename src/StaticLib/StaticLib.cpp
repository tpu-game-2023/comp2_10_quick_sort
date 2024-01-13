#ifndef LIB_FUNC_H
#define LIB_FUNC_H
#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


typedef struct item_ {
    int key;
    char value[256];
} item;


// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin,item* end)
{

	if (begin == NULL || end == NULL || begin >= end)
	{
		return false;
	}
	item* pivot = begin + (end - begin) / 2;
	item* i = begin;
	item* j = end - 1;
    while (i <= j)
    {
        // ピボットより小さい要素を左に、大きい要素を右に移動
        while (i->key < pivot->key)
        {
            ++i;
        }
        while (j->key > pivot->key)
        {
            --j;
        }

        if (i <= j)
        {
           
            item temp = *i;
            *i = *j;
            *j = temp;
            ++i;
            --j;
        }
    }

    // 再帰的に左右の部分をソート
    if (begin < j + 1)
    {
        quick_sort(begin, j + 1);
    }
    if (i < end)
    {
        quick_sort(i, end);
    }

    return true;

}
#endif 