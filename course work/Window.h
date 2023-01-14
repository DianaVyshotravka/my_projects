// Window.h
#ifndef COURSEWORK_WINDOW_H
#define COURSEWORK_WINDOW_H

#include <ostream>
#include <iostream>
#include "Rectangle.h"
#include "vector"
#include "string"

using namespace std;

class Window: public Rectangle{
protected:
//    назва вікна та його меню, реалізований через вектор
    string title;
    vector<string>* menu;
public:
//   стандартні конструктор та деструктор
    ~Window() override = default;
    Window() = default;
//   конструктор обєкта класу через вже готовий прямокутник
    Window(const Rectangle &anotherRectangle, const string &title, vector<string> *menu);
//    геттери та сетери для параметрів класу
    const string &getTitle() const;
    void setTitle(const string &title);
    vector<string> *getMenu() const;
    void setMenu(vector<string> *menu);
//    перевизначення віртуального методу для поліморфного кластеру
    void read() override;
    // метод для отримання координат кутів вікна
    void Coordinates();
//    перевантажені операції вводу-виводу
    friend ostream &operator<<(ostream &os, const Window &window);
    friend istream &operator>>(istream &is, Window &window);
};


#endif
