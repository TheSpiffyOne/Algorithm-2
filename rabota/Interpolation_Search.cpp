#include <iostream>
#include <vector>

// Функция интерполирующего поиска
int interpolationSearch(const std::vector<int>& arr, int x) {
    int n = arr.size();
    int lo = 0;        // Левая граница
    int hi = n - 1;    // Правая граница

    // Условие для продолжения поиска
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        // Если границы равны, проверяем этот элемент
        if (lo == hi) {
            if (arr[lo] == x) return lo;
            return -1; // Элемент не найден
        }

        // Вычисляем предполагаемую позицию (pos) на основе интерполяции
        // pos = lo + [ (x - arr[lo]) / (arr[hi] - arr[lo]) ] * (hi - lo)
        int pos = lo + (((double)(x - arr[lo]) / (arr[hi] - arr[lo])) * (hi - lo));

        // Состояние, если цель найдена
        if (arr[pos] == x) {
            return pos;
        }
        // Если x больше, x находится в правом подмассиве
        else if (arr[pos] < x) {
            lo = pos + 1;
        }
        // Если x меньше, x находится в левом подмассиве
        else {
            hi = pos - 1;
        }
    }
    return -1; // Элемент не найден
}

int main() {
    std::vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int x = 18; // Искомое значение

    std::cout << "Массив: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\nИщем: " << x << std::endl;

    int result = interpolationSearch(arr, x);

    if (result != -1) {
        std::cout << "Элемент найден на позиции: " << result << std::endl;
    } else {
        std::cout << "Элемент не найден" << std::endl;
    }

    return 0;
}
