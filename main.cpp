//
//  main.cpp
//  лаба 8 сем 2
//
//  Created by Andrey Scherbakov on 26.02.2024.
//


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct student {
    string surname;
    string name;
    string patronymic;
    string date_of_birth;
    string adress;
    float rating;
    void enter_info(string s, string n, string p, string d, string a, float r) {
        surname = s;
        name = n;
        patronymic = p;
        date_of_birth = d;
        adress = a;
        rating = r;
    }
};
int main() {
    setlocale(LC_ALL, "RU");

    int kol_st;
    student mass[50];
    cout << "Введите количество студентов: ";
    cin >> kol_st;
    for (int i = 0; i < kol_st; i++) {
        string s, n, p, d, a;
        float r;
        cout << "Введите ФИО, дату рождения, адрес, рейтинг студента № " << i + 1 << endl;
        cin >> s >> n >> p >> d >> a >> r;
        mass[i].enter_info(s, n, p, d, a, r);
    }
    int imass[50];
    int k = 0;
    for (int i = 0; i < kol_st - 1; i++) {
        for (int j = i + 1; j < kol_st; j++) {
            if (mass[i].date_of_birth == mass[j].date_of_birth) {
                imass[k] = i;
                imass[k + 1] = j;
                k += 2;
            }
        }
    }
    bool f = false;
    int ifam;
    string fam;
    cout << "Введите фамилию человека, перед которым надо поставить другого: ";
    cin >> fam;
    for (int i = 0; i < kol_st; i++) {
        if (mass[i].surname == fam) {
            ifam = i;
            f = true;
        }
    }
    if (f == true) {
        for (int i = kol_st; i > ifam; i--) {
            mass[i] = mass[i - 1];
        }
        string s1, n1, p1, d1, a1;
        float r1;
        cout << "Введите ФИО, дату рождения, адрес, рейтинг нового студента " << endl;
        cin >> s1 >> n1 >> p1 >> d1 >> a1 >> r1;
        mass[ifam].enter_info(s1, n1, p1, d1, a1, r1);
        kol_st += 1;
        for (int i = 0; i < k; i++) {
            if (imass[i] >= ifam) {
                imass[i] += 1;
            }
        }
    }
    ofstream f1("f1.txt");
    for (int i = 0; i < kol_st; i++) {
        bool fl = true;
        for (int j = 0; j < k; j++) {
            if (i == imass[j]) {
                fl = false;
            }
        }
        if (fl) {
            f1 << mass[i].surname << " " << mass[i].name << " " << mass[i].patronymic <<
                " " << mass[i].adress << " " << mass[i].date_of_birth << " " << mass[i].rating << endl;
        }
    }
    f1.close();
    return 0;
}
