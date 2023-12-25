#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

int median(item* head, int len) {
	int array[] = {
		head->key,
		(head + len / 2)->key,
		(head + len - 1)->key
	};
	
	if (array[0] < array[1]) {
		if (array[0] < array[2] && array[1] < array[2])
			return array[1];
		else if (array[0] > array[2] && array[1] > array[2])
			return array[0];
		else
			return array[2];
	}
	else {
		if (array[1] < array[2] && array[0] < array[2])
			return array[0];
		else if (array[1] > array[2] && array[0] > array[2])
			return array[1];
		else
			return array[2];
	}

	return 0;
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (!begin || !end)
		return false;

	int length = end - begin;
	if (length <= 0)
		return false;
	else if (length == 1)
		return true;

	item* head = begin;
	item* tail = begin + length - 1;
	int pivot = median(head, length); // begin->key;//

	bool touch = false;
	while (!touch) {
		for (; head->key < pivot; head++);
		for (; tail->key >= pivot && tail > head; tail--);
		int l = tail - head;

		if (head == tail) {
			touch = true;
			if (head + 1 == end)
				head--;
			else
				tail++;
		}

		if(head < tail && head->key > tail->key) {
			item tmp = *head;
			*head = *tail;
			*tail = tmp;
		}
	}
	
	quick_sort(begin, tail);
	quick_sort(tail, end);

	return true;
}
