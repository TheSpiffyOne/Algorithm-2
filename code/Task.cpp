// Бинарная куча:
#include <queue>
std::priority_queue<int> maxHeap;           // максимальная куча
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // минимальная куча

// Операции:
maxHeap.push(value);                        // добавление элемента
maxHeap.pop();                             // удаление вершины
maxHeap.top();                             // доступ к вершине

//Хеш таблица
#include <unordered_map>
std::unordered_map<KeyType, ValueType> hashTable;

// Операции:
hashTable[key] = value;                     // вставка/обновление
hashTable.find(key);                       // поиск
hashTable.erase(key);                      // удаление
hashTable.size();                          // размер

