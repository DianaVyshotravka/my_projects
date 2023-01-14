// Rectangle.h
#ifndef COURSEWORK_RECTANGLE_H
#define COURSEWORK_RECTANGLE_H


#include <string>
#include <ostream>
#include <iostream>

using namespace std;

class Rectangle{
protected:
//    структура, що відповідає за точки прямокутника
    struct point{
        double xCoordinate;
        double yCoordinate;
    };
// верхня та нижня точки відповідно
    point upperLeftAngle{};
    point downRightAngle{};
//    колір заднього фону
    string backgroundColor;
public:


//     стандартний деструктор класу
    virtual ~Rectangle();
// стандартний конструктор
    Rectangle();
//   конструктор, що створює об'єкт через координати точок
    Rectangle(double upperRightAngleXCoordinate, double upperRightAngleYCoordinate,
              double downLeftAngleXCoordinate, double downLeftAngleYCoordinate, string backgroundColor);
//     конструктор, що створює об'єкт через дві точки
    Rectangle(const double* upperLeftAngle,const double downRightAngle[2], string backgroundColor);
//    конструктор копіювання
    Rectangle(const Rectangle& anotherRectangle);
//    геттери для точок прямокутника та кольору заднього фону
    const point &getUpperLeftAngle() const;
    const point &getDownRightAngle() const;
    const string &getBackgroundColor() const;
//    сетери для параметрів прямокутника
    void setBackgroundColor(const string &backgroundColor);
    void setUpperLeftAngle(const double* newAngle);
    void setDownRightAngle(const double* newAngle);
//    оператори кратного збільшення та зменшення прямокутника
    void operator++(int multiplier);
    void operator--(int multiplier);
//    оператор перенесення прямокутника за вектором
    void operator*(const int vector[2]);
    friend ostream &operator<<(ostream &os, const Rectangle &rectangle);
    friend istream &operator>>(istream &is,  Rectangle &rectangle);
//    ператор присвоїння
    Rectangle operator=(const Rectangle* anotherRectangle);
//    віртуальна функція для поліморфного кластера
    virtual void read();

};
#endif
