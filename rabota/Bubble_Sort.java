import java.util.Arrays;

class BubbleSortJava {
    // Функция для сортировки массива методом пузырька
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        boolean swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Меняем местами элементы
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            // Если на данном этапе не было ни одной замены, значит массив уже отсортирован
            if (!swapped) break;
        }
    }

    // Функция для печати массива
    public static void printArray(int[] arr) {
        System.out.println(Arrays.toString(arr));
    }

    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("Исходный массив:");
        printArray(arr);

        bubbleSort(arr);

        System.out.println("\nОтсортированный массив:");
        printArray(arr);
    }
}
