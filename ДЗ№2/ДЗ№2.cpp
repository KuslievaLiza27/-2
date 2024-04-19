#include <iostream>
#include <sstream>//Библиотека для работы с потоками данных
#include <cstring>//Библиотека для работы с функциями обработки строк
#include "someclass.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int arr[] = { 1, 2, 3, 4, 5 };//Инициализация массива
    exmpl obj(arr, sizeof(arr) / sizeof(arr[0]));//Создание объекта класса с заданным массивом и его длиной
    cout << "Текущая длина: " << obj.getLength() << endl;
    cout << "Результат: " << endl << obj.result() << endl;

    obj.setLength(3);//Изменение длины массива
    cout << "Новая длина: " << obj.getLength() << endl;
    cout << "Результат: " << endl << obj.result() << endl;

    return 0;
}