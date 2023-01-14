// Iterator.h
#ifndef COURSEWORK_ITERATOR_H
#define COURSEWORK_ITERATOR_H
#include "vector"
#include "string"
#include "ListOfWindows.h"

using namespace std;
// оголошуємо клас списка вікон, щоб компілятор знав про його існування
// (тому що код компілюється почергово і в деяких місцях компілятор ще не знає про існування іншого класу)
class ListOfWindows;
// клас зовнішнього ітератора для класу ListOfWindows
class Iterator {
private:
//    інформація про дані поточного об'єкта класу, для якого створений ітератор
    ListOfWindows *data;
// поточна позиція ітератора в масиві
    int current;
public:
// єдиний конструктор, для створення ітератора для конкретного об'єкта класу ListOfWindows
    Iterator(ListOfWindows *p_data);
// метод, що змінює позицію ітератора на перший елемент нашого вектора
    void First();
// перехід до наступного елемента об'єкта ListOfWindows
    void Next();
// перевірка на наявність наступних елементів
    bool IsDone();
// метод для повернення поточного вікна в масиві
    Window * Current();
// деструктор класу
    virtual ~Iterator();
};


#endif //COURSEWORK_ITERATOR_H
