def linear_search(arr, target):
    for index, element in enumerate(arr):
        if element == target:
            return index
    return -1

# Пример использования
if __name__ == "__main__":
    array = [3, 5, 2, 7, 9, 1, 4]
    target = 7
    result = linear_search(array, target)
    if result != -1:
        print(f'Элемент найден на позиции: {result}')
    else:
        print('Элемент не найден')
