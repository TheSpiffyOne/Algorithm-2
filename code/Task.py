# Бинарная куча
import heapq
min_heap = []                               # минимальная куча

# Операции:
heapq.heappush(min_heap, value)             # добавление
heapq.heappop(min_heap)                     # удаление вершины
min_heap[0]                                 # доступ к вершине

# Хеш таблица
hash_table = {}                             # создание словаря

# Операции:
hash_table[key] = value                     # вставка/обновление
hash_table.get(key)                         # поиск
del hash_table[key]                         # удаление
len(hash_table)                             # размер

