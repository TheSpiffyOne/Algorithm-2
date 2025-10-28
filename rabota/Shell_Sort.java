def shell_sort(arr):
    n = len(arr)
    gap = n // 2   # Начальное расстояние между элементами

    # Уменьшаем gap на каждом шаге
    while gap > 0:
        # Рассмотрим группы элементов с расстоянием gap
        for i in range(gap, n):
            temp = arr[i]
            j = i
            # Передвигаем элементы вперёд, если они больше temp
            while j >= gap and arr[j-gap] > temp:
                arr[j] = arr[j-gap]
                j -= gap
            # Ставим temp на нужное место
            arr[j] = temp
        gap //= 2

# Пример использования
if __name__ == "__main__":
    arr = [12, 34, 54, 2, 3]
    print("Исходный массив:", arr)
    shell_sort(arr)
    print("Отсортированный массив:", arr)
