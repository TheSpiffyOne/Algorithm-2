#include <iostream>
#include <vector>
using namespace std;

// Функция для объединения двух отсортированных подмассивов
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Создание временных массивов
    vector<int> L(n1), R(n2);

    // Копирование данных в временные массивы
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Индексы первых элементов каждого временного массива
    int i = 0, j = 0;
    int k = l;

    // Объединение временных массивов обратно в основной
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Кладём оставшиеся элементы
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Функция для сортировки слиянием
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
