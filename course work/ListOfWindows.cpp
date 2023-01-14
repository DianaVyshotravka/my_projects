// ListOfWindows.cpp
#include "Window.h"
#include "ListOfWindows.h"
#include "Iterator.h"


using namespace std;
// default constructor
ListOfWindows::ListOfWindows()= default;;
// default destructor
ListOfWindows::~ListOfWindows() = default;

// додаємо в наш вектор новий елемент використовуючи push_back
void ListOfWindows::addWindow(const Window& newWindow){
    windows.push_back(newWindow);
}
// метод для очищення списка
void ListOfWindows::Clear(){
    windows.clear();
}

// метод для розміщення вікон каскадом
void ListOfWindows::cascade() {
//    тимчасові змінні, в які будемо записувати майбутню позицію правого верхнього кута та
// відстань між верхнім та нижнім кутами, щоб після переміщення верхнього, перемістити нижній
    double temp[2];
    double tempVector[2];
//    для розміщення каскадом верхній кут ставимо на середину попереднього вікна
    for (int i = 1; i < windows.size(); ++i) {
        temp[0] = (windows[i-1].getUpperLeftAngle().xCoordinate + windows[i - 1].getDownRightAngle().xCoordinate)/2;
        temp[1] = (windows[i-1].getUpperLeftAngle().yCoordinate + windows[i - 1].getDownRightAngle().yCoordinate)/2;
        tempVector[0] = windows[i].getDownRightAngle().xCoordinate - windows[i].getUpperLeftAngle().xCoordinate;
        tempVector[1] = windows[i].getDownRightAngle().yCoordinate - windows[i].getUpperLeftAngle().yCoordinate;
        windows[i].setUpperLeftAngle(temp);
        temp[0] += tempVector[0];
        temp[1] += tempVector[1];
        windows[i].setDownRightAngle(temp);
    }

}
// метод для розміщення вікон плитками на весь екран

void ListOfWindows::titles() {
    // для початку верхній першого вікна переносимо на (0;0)
    double zero[] = {0 , 0};
    double temp[2];
    double tempVector[2];
    int amount = 0;
    temp[0] = windows[0].getDownRightAngle().xCoordinate -windows[0].getUpperLeftAngle().xCoordinate;
    temp[1] = windows[0].getDownRightAngle().yCoordinate -windows[0].getUpperLeftAngle().yCoordinate;
    windows[0].setUpperLeftAngle(zero);
    windows[0].setDownRightAngle(temp);

    // Шукаємо найкраще розміщення для плиток(чи це буде 2 х 2, чи 3 х 3 і т. д.)
    while (true){
        if ((amount * amount) >= windows.size()){
            break;
        }
        amount++;
    }
    // розміщуємо 1 стовпець на лівому краю екрану
    for (int i = 1; i < amount ; ++i) {
//        знаходимо у координату правого кута, та після чого знаходимо відстань між кутами
        temp[0] = 0;
        temp[1] = windows[(i - 1) * amount ].getDownRightAngle().yCoordinate;
        tempVector[0] = windows[i * amount].getDownRightAngle().xCoordinate -windows[i * amount].getUpperLeftAngle().xCoordinate;
        tempVector[1] = windows[i * amount].getDownRightAngle().yCoordinate -windows[i * amount].getUpperLeftAngle().yCoordinate;
        windows[i * amount].setUpperLeftAngle(temp);
        temp[0] += tempVector[0];
        temp[1] += tempVector[1];
        windows[i * amount].setDownRightAngle(temp);
    }

//    розміщуємо рядки відносно розсташування 1 елемента в кожному рядку
    for (int i = 0; i < amount; ++i) {
        for (int j = 1; j < amount; ++j) {
// записуємо координати верхнього кута відносно елемента справа
            temp[0] = windows[i * amount + j - 1].getDownRightAngle().xCoordinate;
            temp[1] = windows[i * amount + j - 1].getUpperLeftAngle().yCoordinate;
//  записуємо відстань між точками поточної вершини
            tempVector[0] = windows[i * amount + j ].getDownRightAngle().xCoordinate -windows[i * amount + j ].getUpperLeftAngle().xCoordinate;
            tempVector[1] = windows[i * amount + j ].getDownRightAngle().yCoordinate -windows[i * amount + j ].getUpperLeftAngle().yCoordinate;

            windows[i * amount + j].setUpperLeftAngle(temp);
            temp[0] += tempVector[0];
            temp[1] += tempVector[1];

            windows[i * amount + j].setDownRightAngle(temp);


        }
    }
}

// для згортання вікна обидва кути ставимо в т. 0. 0
void ListOfWindows::minimize(int index) {
    double point[] = {0, 0};
    windows[index].setDownRightAngle(point);
    windows[index].setUpperLeftAngle(point);
}
// для розгортання правий верхній кут ставимо в ноль, лівий нижній на протилежний край екрану(1920; 1080 для Full HD)
void ListOfWindows::maximize(int index) {
    double point[] = {0, 0};
    windows[index].setUpperLeftAngle(point);
    point[0] = 1920;
    point[1] = 1080;
    windows[index].setDownRightAngle(point);
}
// створюємо вказівник на ітератор для поточного об'єкта
Iterator *ListOfWindows::CreateIterator() {
    return new Iterator(this);
}



