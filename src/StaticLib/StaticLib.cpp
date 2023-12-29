#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"
void swap(item* begin,const item* end,int a,int b)
{
	item copy;
	copy = *(begin + a);
	*(begin + a) = *(begin + b);
	*(begin + b) = copy;
}

int partition(item* begin,const item* end,int p,int r)
{
	for (int i = p; i < r; i++)
	{
		if ((begin + i)->key <= (begin + r)->key)
		{
			swap(begin,end,p,i);
			p++;
		}
	}
	swap(begin,end,r,p);

	return p;
}

void q_sort(item* begin,const item* end,int p,int n)
{
	int x;// 基準値の位置
	if (p < n)
	{
		x = partition(begin,end,p,n);
		q_sort(begin, end,p,x-1);
		q_sort(begin, end,x+1,n);
	}
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin == 0 || end == 0 || begin > end)
		return false;

	else
	{
		int n;
		n = end - begin;
		q_sort(begin,end,0,n-1);

		return true;
	}
}
