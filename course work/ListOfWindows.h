// ListOfWindows.h
#ifndef COURSEWORK_LISTOFWINDOWS_H
#define COURSEWORK_LISTOFWINDOWS_H
#include "Window.h"
#include "Iterator.h"
// тут оголошуємо ітератор, щоб компілятор знав що він такий існує взагалі
class Iterator;

class ListOfWindows{
private:
//    вектор, в якому будуть міститися наші вікна
    vector<Window> windows;
// дружній клас ітератора, щоб мати доступ до private
    friend class Iterator;
public:
//    метод, що створює ітератор для поточного об'єкта класу ListOf Windows
    Iterator* CreateIterator();
// default constructor
    ListOfWindows();
//    default destructor
    virtual ~ListOfWindows();
//    метод додавання нових вікон в наш список
    void addWindow(const Window&);
    // метод для очищення списка
    void Clear();
//    розміщення вікон каскадом
    void cascade();
//    розміщенння вікон плитками
    void titles();
//    згортання конкретного вікна
    void minimize(int index);
//    розгортання конкретного вікна
    void maximize(int index);
};


#endif
