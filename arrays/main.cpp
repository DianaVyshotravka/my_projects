/*a two-dimensional array of integers from the section (-41,...,48) is given.
 Find all elements except negative multiples of 4*/
#include<iostream>
#include<stdio.h>
#include <iomanip>
using namespace std;
double** MALLOC(int lines, int column);
double** CALLOC(int lines, int column);
double** NEW(int lines, int column);
void from_Console(int lines, int column, double** mas);
void from_Random(int lines, int column, double** mas);
void NEW_ARRAY_index(int lines, int column, double** mas);
void NEW_ARRAY_vkasivnyk(int lines, int column, double** mas);
int main() {
    int n, k; double s_rand, s_consol, lines, column, m, c; double** array_from_consol; double** array_from_random;
    system("chcp 1251");
    system("cls");
    cout << endl << "Enter the number of rows of the array:"; cin >> lines;
    cout << endl << "Enter the number of columns of the array:"; cin >> column;
    cout << endl << "With which function to allocate memory?(1-malloc,2-calloc,3-new)"; cin >> n;
    if (n == 1) {
        array_from_consol = MALLOC(lines, column);
        array_from_random = MALLOC(lines, column);
    }
    else if (n == 2) {
        array_from_consol = CALLOC(lines, column);
        array_from_random = CALLOC(lines, column);
    }
    else {
        array_from_consol = NEW(lines, column);
        array_from_random = NEW(lines, column);
    }
    from_Console(lines, column, array_from_consol);
    cout << "How to access array elements? (Indices - 1; Pointers - 2)"; cin >> c;
    if (c == 1) {
        NEW_ARRAY_index(lines, column, array_from_consol);
    }
    else {
        NEW_ARRAY_vkasivnyk(lines, column, array_from_consol);
    }
    from_Random( lines, column, array_from_random);
    cout << "How to access array elements? (Indices - 1; Pointers - 2) "; cin >> m;
    if (m == 1) {
        NEW_ARRAY_index(lines, column, array_from_random);
    }
    else {
        NEW_ARRAY_vkasivnyk(lines, column, array_from_random);
    }
    //очищення пам'яті
    if (n == 1 or n == 2) {
        for (int i = 0; i < lines; i++) free(array_from_consol[i]);
        free(array_from_consol);
        for (int i = 0; i < lines; i++)free(array_from_random[i]);
        free(array_from_random);

    }
    else if (n == 3) {
        for (int i = 0; i < lines; i++) delete[]array_from_consol[i];
        delete[] array_from_consol;
        for (int i = 0; i < lines; i++) delete[]array_from_random[i];
        delete[] array_from_random;
    }
    return 0;
}
double** MALLOC(int lines, int column) {
    double** p = (double**)malloc(lines * sizeof(double*));
    for (int i = 0; i < lines; i++) {
        p[i] = (double*)malloc(column * sizeof(double));
    }
    return p;
}
double** CALLOC(int lines, int column) {
    double** p = (double**)calloc(lines, sizeof(double*));
    for (int i = 0; i < lines; i++) {
        p[i] = (double*)calloc(column, sizeof(double));
    }
    return p;
}
double** NEW(int lines, int column) {
    double** p = new double* [lines];
    for (int i = 0; i < lines; i++) {
        p[i] = new double[column];
    }
    return p;
}
void from_Console(int lines, int column, double** mas) {
    int i, j;
    for (i = 0; i < lines; i++) {
        for (j = 0; j < column; j++) {
            cout << "b[" << i << "][" << j << "]=";
            cin >> mas[i][j];
            while (mas[i][j] < -41||  mas[i][j]>48)
            {
                cout<<"Element b ["<<i<<"]["<<j<<"] out of range (-41,...,48), try again:"<<endl << "b[" << i << "][" << j << "]=";
                cin >> mas[i][j];
            }
        }
    }
    cout << "The array that is entered from the keyboard:: " << endl;
    int k;
    cout << "What to use to display the array?(Indices - 1; Pointers - 2) ";
    cin >> k;
    if (k == 1) {
        cout << "Output using indexes:" << endl;
        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < column; j++) {
                cout << setw(7) << mas[i][j];
            }
            cout << endl;
        }
    }
    else {
        cout << endl << "Output using pointers:" << endl;
        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < column; j++) {
                cout << setw(7) << *(*(mas + i) + j);
            }
            cout << endl;
        }
    }
}
void from_Random(int lines, int column, double** mas) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < column; j++) {
            mas[i][j] = rand() % (90) -41;
        }
    }
    cout <<endl<< "An array of random numbers: " << endl;
    int k;
    cout << "What to use to display the array?(Indices - 1; Pointers - 2) ";
    cin >> k;
    if (k == 1) {
        cout << "Output using indexes:" << endl;
        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < column; j++) {
                cout << setw(7) << mas[i][j];
            }
            cout << endl;
        }
    }
    else {
        cout << endl << "Output using pointers:" << endl;
        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < column; j++) {
                cout << setw(7) << *(*(mas + i) + j);
            }
            cout << endl;
        }
    }
}

void NEW_ARRAY_index(int lines, int column, double** mas) {
    int* new_mas; int k = 0; int n = lines * column;
    new_mas = new int [n];
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < column; j++) {
            if (mas[i][j] >= 0 && ((int)mas[i][j] % 4) != 0) {
                new_mas[k] = mas[i][j];
                k++;
            }
        }
    }
    cout << endl << "Шукані елементи: ";
    for (int i = 0; i < k; i++) {
        cout << new_mas[i] << "\t";
    }
    delete[] new_mas;
}
void NEW_ARRAY_vkasivnyk(int lines, int column, double** mas) {
    int *new_mas;
    int k = 0;
    int n = lines * column;
    new_mas = new int[n];
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < column; j++) {
            if (*(*(mas + i) + j) >= 0 && ((int) *(*(mas + i) + j) % 4) != 0) {
                *(new_mas + k) = *(*(mas + i) + j);
                k++;
            }
        }
    }
    cout << endl << "Wanted items: ";
    for (int i = 0; i < k; i++) {
        cout << *(new_mas + i) << "\t";
    }
    delete[] new_mas;
}