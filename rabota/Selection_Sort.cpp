#include <iostream>
#include <vector>
using namespace std;

// Функция сортировки выборкой
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    
    // Внешний цикл проходит по каждому элементу массива
    for(int i = 0; i < n; ++i) {
        // Индекс минимального элемента начинаем считать равным текущему индексу
        int minIndex = i;
        
        // Внутренний цикл ищет минимальный элемент среди оставшихся элементов
        for(int j = i+1; j < n; ++j) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Если нашли меньший элемент, меняем местами элементы
        swap(arr[i], arr[minIndex]);
    }
}

// Основная программа для тестирования
int main() {
    vector<int> testArray = {64, 25, 12, 22, 11};
    
    cout << "Исходный массив: ";
    for(auto num : testArray) {
        cout << num << ' ';
    }
    cout << endl;
    
    // Выполняем сортировку
    selectionSort(testArray);
    
    cout << "Отсортированный массив: ";
    for(auto num : testArray) {
        cout << num << ' ';
    }
    cout << endl;
    
    return 0;
}
