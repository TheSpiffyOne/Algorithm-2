def insertion_sort(arr):
    # Перебираем элементы массива, начиная со второго
    for i in range(1, len(arr)):
        key = arr[i]     # Запоминаем текущий элемент
        j = i - 1        # Рассматриваем предыдущий элемент
        
        # Передвигаем все элементы слева от current_value, которые больше key
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
            
        # Вставляем key на нужное место
        arr[j + 1] = key

# Пример использования
if __name__ == "__main__":
    array = [12, 11, 13, 5, 6]
    print("Исходный массив:", array)
    insertion_sort(array)
    print("Отсортированный массив:", array)
