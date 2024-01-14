#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

int partition(item array[], int low, int high) {
    int pivot = array[high].key;
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (array[j].key < pivot) {
            ++i;
            item temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    item temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}

// クイックソートの再帰的な実装
void quickSort(item array[], int low, int high) {
    if (low < high) {

        int partitionIndex = partition(array, low, high);
        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}

bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
    if (begin == NULL || end == NULL || end < begin)return false;

	quickSort(begin, 0, end - begin - 1);

	return true;
}