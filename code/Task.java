// Бинарная куча
import java.util.PriorityQueue;
PriorityQueue<Integer> minHeap = new PriorityQueue<>();    // минимальная куча
PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a,b) -> b-a); // максимальная куча

// Операции:
minHeap.add(value);                         // добавление
minHeap.poll();                            // удаление вершины
minHeap.peek();                            // доступ к вершине

//Хеш таблица
import java.util.HashMap;
HashMap<KeyType, ValueType> hashTable = new HashMap<>();

// Операции:
hashTable.put(key, value);                  // вставка/обновление
hashTable.get(key);                        // поиск
hashTable.remove(key);                     // удаление
hashTable.size();                          // размер


