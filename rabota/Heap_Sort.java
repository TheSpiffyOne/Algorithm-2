import java.util.Arrays;

class HeapSortJava {
    // Функция для поддержания свойства кучи
    void heapify(int arr[], int n, int i) {
        int largest = i;       // Самый большой элемент
        int left = 2 * i + 1; // Левый потомок
        int right = 2 * i + 2;// Правый потомок

        // Если левый потомок больше корня
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // Если правый потомок больше самого большого элемента
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // Если максимальный элемент не является текущим
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            // Рекурсивно выстраиваем поддерево
            heapify(arr, n, largest);
        }
    }

    // Главная функция для сортировки
    void heapSort(int arr[]) {
        int n = arr.length;

        // Строим max-кучу
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // Извлекаем элементы из кучи один за одним
        for (int i=n-1; i>=0; i--) {
            // Поменяли root с последним элементом
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Превращаем уменьшившийся массив снова в max-кучу
            heapify(arr, i, 0);
        }
    }

    // Вспомогательная функция для вывода массива
    static void printArray(int arr[]) {
        System.out.println(Arrays.toString(arr));
    }

    // Пример использования
    public static void main(String args[]) {
        int arr[] = {12, 11, 13, 5, 6, 7};
        HeapSortJava ob = new HeapSortJava();
        System.out.println("Исходный массив:");
        printArray(arr);

        ob.heapSort(arr);

        System.out.println("Отсортированный массив:");
        printArray(arr);
    }
}
