#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>
#include <windows.h>

using namespace std;

void createArray(int*& arr, int size);
void fillArray(int* arr, int size);
void deleteArray(int*& arr);
void displayArray(const int* arr, int size);
int* createUniqueArray(const int* arr, int size, int& newSize);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));  // Инициализация генератора случайных чисел

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    if (size <= 0)
    {
        cerr << "Недопустимый размер!" << endl;
        return 1;
    }

    int* arr = nullptr;
    createArray(arr, size);
    fillArray(arr, size);

    cout << "Исходный массив: ";
    displayArray(arr, size);

    int newSize;
    int* uniqueArr = createUniqueArray(arr, size, newSize);

    cout << "Массив без дубликатов: ";
    displayArray(uniqueArr, newSize);

    deleteArray(arr);
    deleteArray(uniqueArr);

    return 0;
}

void createArray(int*& arr, int size)
{
    arr = new int[size];
}

void fillArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (i % 2 == 0)
        {
            arr[i] = rand() % 100;  // Случайное значение от 0 до 99
        }
        else
        {
            cout << "Введите значение для элемента " << i << ": ";
            cin >> arr[i];
        }
    }
}

void deleteArray(int*& arr)
{
    delete[] arr;
    arr = nullptr;
}

void displayArray(const int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* createUniqueArray(const int* arr, int size, int& newSize)
{
    set<int> uniqueElements(arr, arr + size);
    newSize = uniqueElements.size();

    int* uniqueArr = new int[newSize];
    int index = 0;
    for (int elem : uniqueElements)
    {
        uniqueArr[index++] = elem;
    }

    return uniqueArr;
}