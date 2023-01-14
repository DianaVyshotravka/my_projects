// Rectangle.cpp
#include "string"
#include "iostream"
#include "Rectangle.h"


using namespace std;

// дефолтний деструктор, оскільки динамічну пам'ять не виділяємо
Rectangle::~Rectangle() = default;
// дефолтний конструктор
Rectangle::Rectangle() = default;
// конструктор ініціалізації через два масиви, які відповідають координатам вершин прямокутника
Rectangle::Rectangle(const double* upperLeftAngle,const double downRightAngle[2], string backgroundColor) :backgroundColor(std::move(
        backgroundColor)) {
    this->upperLeftAngle = {upperLeftAngle[0], upperLeftAngle[1]};
    this->downRightAngle = {downRightAngle[0], downRightAngle[1]};
}
// конструктор ініціалізації через окремі координати кожної вершини
Rectangle::Rectangle(double upperRightAngleXCoordinate, double upperRightAngleYCoordinate, double downLeftAngleXCoordinate, double downLeftAngleYCoordinate, string backgroundColor):
        backgroundColor(std::move(backgroundColor)) {
    upperLeftAngle = {upperRightAngleXCoordinate,upperRightAngleYCoordinate };
    downRightAngle = {downLeftAngleXCoordinate,downLeftAngleYCoordinate};
}

// конструктор копіювання
Rectangle::Rectangle(const Rectangle& anotherRectangle) {
    backgroundColor = anotherRectangle.getBackgroundColor();
    for (int i = 0; i < 2; ++i) {
        upperLeftAngle = anotherRectangle.getUpperLeftAngle();
        downRightAngle = anotherRectangle.getDownRightAngle();
    }
}


// тут два const тому що перший вказує на тип даних, що повертає метод, а другий на те, що метод не може нічого змінювати в поточному обєкті класу, щоб безпечно передавати вказівники

const Rectangle::point &Rectangle::getUpperLeftAngle() const {
    return upperLeftAngle;
}

const Rectangle::point &Rectangle::getDownRightAngle() const {
    return downRightAngle;
}

const string& Rectangle::getBackgroundColor() const {
    return backgroundColor;
}

void Rectangle::setBackgroundColor(const string &backgroundColor) {
    Rectangle::backgroundColor = backgroundColor;
}

void Rectangle::setUpperLeftAngle(const double* newAngle){
    upperLeftAngle = {newAngle[0], newAngle[1]};
}

void Rectangle::setDownRightAngle(const double* newAngle){
    downRightAngle = {newAngle[0], newAngle[1]};
}
// для пропорційного збільшення чи зменшення просто змінюємо координати нижнього кута
void Rectangle::operator++(int multiplier){
    this->downRightAngle.xCoordinate *= multiplier;
    this->downRightAngle.yCoordinate *= multiplier;
}

void Rectangle::operator--(int multiplier){
    this->downRightAngle.xCoordinate /= multiplier;
    this->downRightAngle.yCoordinate /= multiplier;
}


void Rectangle::operator*(const int vector[2]){
    downRightAngle.xCoordinate += vector[0];
    downRightAngle.yCoordinate += vector[1];
    upperLeftAngle.xCoordinate += vector[0];
    upperLeftAngle.yCoordinate += vector[1];
}

//  кінці не оголошуємо тип даних щоб уникнути повторень, просто беремо в фігурні дужки
Rectangle Rectangle::operator=(const Rectangle* anotherRectangle){
    return {anotherRectangle->getUpperLeftAngle().yCoordinate,
            anotherRectangle->upperLeftAngle.yCoordinate,
            anotherRectangle->downRightAngle.xCoordinate,
            anotherRectangle->downRightAngle.yCoordinate,
            anotherRectangle->backgroundColor};
}

// віртуальна функція, що повертає колір заднього фону
void Rectangle::read() {
    cout << backgroundColor << endl;
}


ostream &operator<<(ostream &os, const Rectangle &rectangle) {
    os << "upper Left Angle: ("<< rectangle.upperLeftAngle.xCoordinate <<";"<< rectangle.upperLeftAngle.yCoordinate << ")" << endl << " down Right Angle: (" << rectangle.downRightAngle.xCoordinate
     <<";" << rectangle.downRightAngle.yCoordinate <<")"<<endl << " background Color: " << rectangle.backgroundColor<< endl;
    return os;
}
istream &operator>>(istream &is, Rectangle &rectangle){
    double temp[2];
    string color;
    cout<<"Input the coordinates of upper Left Angle of rectangle: "<< endl;
    cout<<"x:"  ;
    is>>temp[0];
    cout<<"y:"  ;
    is>>temp[1];
    rectangle.setUpperLeftAngle(temp);
    cout<<"Input the coordinates of down Right Angle of rectangle: "<< endl;
    cout<<"x:";
    is>>temp[0];
    cout<<"y:";
    is>>temp[1];
    rectangle.setDownRightAngle(temp);
    cout<<"Input the background color: " << endl;
    is>>color;
    rectangle.setBackgroundColor(color);
    return is;
}

