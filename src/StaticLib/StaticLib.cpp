#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
    if (begin == NULL || end == NULL || end <= begin) return false;

    QSort(begin, 0, end - begin - 1);
    return true;
}

void QSort(item* x, int left, int right)
{
    int i, j;
    int pivot;
    item tmp;
    int size = sizeof(tmp);

    i = left;                     
    j = right;                    

    pivot = x[(left + right) / 2].key; 

    while (1) {
        while (x[i].key < pivot)      
            i++;                   
        while (pivot < x[j].key)     
            j--;                  
        if (i >= j)               
            break;                

        memcpy(&tmp, x + i, size);   
        memcpy(x + i, x + j, size);
        memcpy(x + j, &tmp, size);     
        i++;                      
        j--;
    }

    if (left < i - 1)             
        QSort(x, left, i - 1);     
    if (j + 1 < right)           
        QSort(x, j + 1, right);   
}