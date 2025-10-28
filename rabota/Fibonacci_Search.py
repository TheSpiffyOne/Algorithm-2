def fibonacci_search(arr, target):
    def generate_fib(n):
        a, b = 0, 1
        while True:
            yield a
            a, b = b, a+b
            if a > n:
                break

    fib_gen = list(generate_fib(len(arr)))
    fib_m = len(fib_gen)-1

    offset = -1
    while fib_m > 0:
        i = min(offset+fib_gen[fib_m-1], len(arr)-1)
        if arr[i] < target:
            offset = i
            fib_m -= 1
        elif arr[i] > target:
            fib_m -= 2
        else:
            return i
    return -1

# Пример использования
if __name__ == "__main__":
    array = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
    target = 85
    result = fibonacci_search(array, target)
    if result != -1:
        print(f'Элемент найден на позиции: {result}')
    else:
        print('Элемент не найден')
