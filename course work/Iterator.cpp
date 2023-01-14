// Iterator.cpp
#include "Iterator.h"

// переміщуємо позицію ітератора на 0 індекс для нової ітерації
void Iterator::First() {
    current = 0;
}
// додаємо одиничку до індекса
void Iterator::Next() {
    current++;
}
// перевіряємо, чи не вийшли за межі вектору
bool Iterator::IsDone() {
    return current < data->windows.size();
}
// повертаємо поточне вікно
Window *Iterator::Current() {
    return &data->windows[current];
}
// простий констуктор, в якому получаємо інформацію про масив
Iterator::Iterator(ListOfWindows *p_data) {
    data = p_data;
    current = 0;
}
// оскільки сам ітератор це вказівник, то видаляє він сам себе при закінченні роботи
Iterator::~Iterator(){
    delete this;
}

