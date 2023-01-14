// main.cpp
#include <iostream>
#include "Window.h"
#include "ListOfWindows.h"
#include "Iterator.h"
/*
 Тема роботи:Розроблення програм мовою С++ за технологією об’єктно-орієнтованого програмування;
 Розробила: студентка групи СА-21 Вишотравка Діана Вікторівна;
 Дата створення: 17 листопада 2022 р.
 */

using namespace std;



int main() {
    int amount;
    string temp;
    ListOfWindows First;
    cout<<"-------------Start working-------------"<<endl<<"Create your list of windows"<<endl;
    //створення списка вікон
    cout<<"How many windows do you want to creat for your list?"<<endl;
    cin>>amount;
    Window A;
    for(int i = 0; i< amount; i++){
cout<<"Window "<< i+1<<endl;
       cin>>A;
       First.addWindow(A);
    }
    //cтворення ітератора
    Iterator *it = First.CreateIterator();
    cout<<"Show late binding using method for showing menu details?(Y/N)"<<endl;
    cin>>temp;
    if(temp == "Y"){
        //демонстрація пізнього зв'язування
        cout<<"-------Late binding--------"<<endl;
        amount = 1;
        for (it->First(); it->IsDone(); it->Next()) {
            cout << "Window " << amount << ":" << endl;
            Rectangle *B=it->Current();
            B->read();
            amount++;
        }

    }
    cout << "------------Operate your list------------" << endl;
    cout << "Do you want to change the size of your windows?(Y/N) "<< endl;
    cin >> temp;
    if(temp =="Y" or temp == "y"){
        cout << "Do you want to increase or decrease the size of windows?(I- for increase, D - for decrease)" << endl;
        cin >> temp;
        if(temp == "I"){
            //збільшення вікна вдвічі
            for (it->First(); it->IsDone(); it->Next()){
                 it->Current()->operator++(2) ;
            }
        }
        else if (temp == "D"){
            //зменшення вікна вдвічі
            for (it->First(); it->IsDone(); it->Next()){
                 it->Current()->operator--(2) ;
            }
        }
        else{
            cout<<"Wrong input"<<endl;
        }
        amount=1;
        //виведення змінених координат кутів вікон
        cout<<"------------Changed coordinates:------------"<<endl;
        for (it->First(); it->IsDone(); it->Next()){
            cout<<"Window "<<amount<<":"<<endl;
            it->Current()->Coordinates();
            amount++;
        }
    }
cout<<"-----------Mutual arrangement of windows-----------"<<endl;
cout<<"How do you want to arrange the windows? (C - for cascade, T - for tiles)"<<endl;
    cin>>temp;
    cout<<"Initial coordinates of windows:"<<endl;
    amount=1;
    for (it->First(); it->IsDone(); it->Next()) {
        cout << "Window " << amount << ":" << endl;
        it->Current()->Coordinates();
        amount++;
    }
    if(temp == "C"){
        //розміщення вікон каскадом
        First.cascade();
    }
    else if(temp == "T"){
        //розміщення вікон плиткою
        First.titles();
    }
    else{
        cout<<"Wrong input"<<endl;
    }
    amount=1;
    //виведення змінених координат кутів вікон
    cout<<"------------New coordinates:------------"<<endl;
    for (it->First(); it->IsDone(); it->Next()) {
        cout << "Window " << amount << ":" << endl;
        it->Current()->Coordinates();
        amount++;
    }


    return 0;
}


