// Window.cpp
#include <iomanip>
#include <iostream>
#include "Window.h"
#include "iostream"

using namespace std;

// конструктор через готовий прямокутний
Window:: Window(const Rectangle &anotherRectangle, const string &title, vector<string> *menu) :
        Rectangle(anotherRectangle), title(title), menu(menu) {}
// гетери й сетери для параметрів класу
const string &Window::getTitle() const {
    return title;
}

void Window::setTitle(const string &title) {
    this->title = title;
}

vector<string> *Window::getMenu() const {
    return menu;
}

void Window::setMenu(vector<string> *menu) {
    this->menu = menu;
}

ostream &operator<<(ostream &os, const Window &window) {
    cout << "----------------Window:----------------" << endl;
    os << "upperLeftAngle: ("<< window.upperLeftAngle.xCoordinate <<";"<< window.upperLeftAngle.yCoordinate << ")" << endl << "downRightAngle: (" << window.downRightAngle.xCoordinate
       <<";" << window.downRightAngle.yCoordinate <<")"<<endl << "backgroundColor: " << window.backgroundColor<< endl;
    cout << endl << "title: " << window.title<<endl;
    cout <<"menu"<<endl;
    for (int i = 0; i< window.menu->size(); i++){
        cout << i+1 << ": " << window.menu->operator[](i) << endl;
    }
    return os;
}
istream &operator>>(istream &is, Window &window){

    cin >> *static_cast <Rectangle*>(&window);
    window.menu = new vector<string>;
    cout << "Input the title of menu:" << endl;
    string temp;
    cin >> temp;
    window.setTitle(temp);
    int amount;
    cout << endl << "Input the amount of menu options:" << endl;
    cin >> amount;
    cout << "Input menu options:" << endl;
    vector<string> menu1;
    for(int i = 0 ;i < amount; i++) {
        cout << i + 1 << ": " << endl;
        cin >> temp;
        window.menu->push_back(temp);
    }
return is;
}
// метод для отримання координат кутів вікна
void Window:: Coordinates(){
    cout<<"-------Coordinates-------" << endl;
    cout << "upper Left Angle: ("<<upperLeftAngle.xCoordinate <<";"<< upperLeftAngle.yCoordinate << ")" << endl << " down Right Angle: (" << downRightAngle.xCoordinate
       <<";" << downRightAngle.yCoordinate <<")"<<endl;
}
// виведення меню на екран
void Window::read() {
    cout<<"Menu title"<<endl<<title<<endl;
    cout << "Window menu options:" << endl;
    for (int i = 0; i < menu->size(); ++i) {
        cout << setw(10) << menu->operator[](i);
    }
    cout<<endl;


}



