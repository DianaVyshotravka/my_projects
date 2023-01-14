/*Data on the student's success are recorded in N lines of symbols,
 each of which has the following structure: surname, etc., number of the record book, grades in 5 subjects.
 Data fields are separated by at least one character that is not used to write the specified data.
 Display the names of students who have three or more unsatisfactory grades. The String data type is not allowed.
 The student's last name and initials are entered without a space, initials after a period.
 */
#include <iostream>
#include <malloc.h>
using namespace std;
struct information
{
    char Surname[128];
    int BookNumber;
    int mark1;
    int mark2;
    int mark3;
    int mark4;
    int mark5;
};
void bad_students(int amount_of_students, struct information* information);
int main()
{
    struct  information* info;
    int n;
    cout << "Enter the number of TelPersonInfo elements : ";
    cin >> n;
    info = (information*)malloc(n * sizeof(struct information));
    bad_students(n, info);
    free(info);
    return 0;
}
void bad_students(int amount_of_students, struct information* information) {
    bool* mas = (bool*)malloc(amount_of_students * sizeof(bool));
    int value = 0;
    for (int i = 1; i <= amount_of_students; ++i) {
        cout << "Student #" << i << endl;
        cout << "Input Surname:";
        cin >> information[i - 1].Surname; cin.clear();
        cout << endl << "Input BookNumberr:"; cin >> information[i - 1].BookNumber; cin.clear();
        cout << endl << "Input mark1:"; cin >> information[i - 1].mark1; cin.clear();
        cout << endl << "Input mark2:"; cin >> information[i - 1].mark2; cin.clear();
        cout << endl << "Input mark3:"; cin >> information[i - 1].mark3; cin.clear();
        cout << endl << "Input mark4:"; cin >> information[i - 1].mark4; cin.clear();
        cout << endl << "Input mark5:"; cin >> information[i - 1].mark5; cin.clear();
    }
    for (int i = 0; i < amount_of_students; i++) {
        if (information[i].mark1 < 50) {
            value++;
        }
        if (information[i].mark2 < 50) {
            value++;
        }
        if (information[i].mark3 < 50) {
            value++;
        }
        if (information[i].mark4 < 50) {
            value++;
        }
        if (information[i].mark5 < 50) {
            value++;
        }
        if (value >= 3) {
            mas[i] = true;
        }
        else mas[i] = false;
        value = 0;
    }
    cout << endl << "Answer:" << endl;
    for (int i = 0; i < amount_of_students; ++i) {
        if (mas[i]) cout << information[i].Surname << endl;
    }
    free(mas);
}
