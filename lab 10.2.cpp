#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structure to store information about students
struct Student {
    string surname;   // Surname
    string name;      // First name
    int mathGrade;    // Grade in Mathematics
    int physicsGrade; // Grade in Physics
};

// Функція для введення даних
void Create(Student* students, const int n) {
    for (int i = 0; i < n; i++) {
        cout << "Student #" << i + 1 << ":" << endl;
        cout << "  Surname: ";
        cin >> students[i].surname;
        cout << "  Name: ";
        cin >> students[i].name;
        cout << "  Grade in Mathematics: ";
        cin >> students[i].mathGrade;
        cout << "  Grade in Physics: ";
        cin >> students[i].physicsGrade;
    }
}

// Функція для виведення масиву студентів
void Print(Student* students, const int n) {
    cout << "=============================================" << endl;
    cout << "|  #  |     Surname    |    Name   | Math  | Physics |" << endl;
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "| " << setw(3) << i + 1 << " | " << setw(15) << left << students[i].surname
            << "| " << setw(10) << left << students[i].name
            << "| " << setw(6) << students[i].mathGrade
            << "| " << setw(7) << students[i].physicsGrade << " |" << endl;
    }
    cout << "=============================================" << endl;
}

// Функція для сортування за прізвищем (за алфавітом)
void Sort(Student* students, const int n) {
    Student temp;
    for (int i0 = 0; i0 < n - 1; i0++) {
        for (int i1 = 0; i1 < n - i0 - 1; i1++) {
            if (students[i1].surname > students[i1 + 1].surname) {
                temp = students[i1];
                students[i1] = students[i1 + 1];
                students[i1 + 1] = temp;
            }
        }
    }
}

// Функція для виконання бінарного пошуку
int BinSearch(Student* students, const int n, const string keySurname) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (students[mid].surname == keySurname) {
            return mid; // Знайдено
        }
        else if (students[mid].surname < keySurname) {
            left = mid + 1; // Пошук у правій половині
        }
        else {
            right = mid - 1; // Пошук у лівій половині
        }
    }
    return -1; // Не знайдено
}

// Main function
int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student* students = new Student[n];

    Create(students, n); // Input data
    cout << "\nList of students before sorting:\n";
    Print(students, n);

    Sort(students, n); // Sorting
    cout << "\nList of students after sorting by surname:\n";
    Print(students, n);

    string keySurname;
    cout << "\nEnter the surname to search for: ";
    cin >> keySurname;

    int index = BinSearch(students, n, keySurname);
    if (index != -1) {
        cout << "Student found: " << endl;
        cout << "Surname: " << students[index].surname
            << ", Name: " << students[index].name
            << ", Mathematics: " << students[index].mathGrade
            << ", Physics: " << students[index].physicsGrade << endl;
    }
    else {
        cout << "Student with surname \"" << keySurname << "\" not found." << endl;
    }

    delete[] students; // Free memory
    return 0;
}
