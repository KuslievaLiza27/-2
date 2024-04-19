#pragma ones//Директива, предотвращающая многократное включение заголовочного файла
#include <iostream>
#include <sstream>//Библиотека для работы с потоками данных
#include <cstring>//Библиотека для работы с функциями обработки строк
using namespace std;
class exmpl// Класс, выполняющий операции над массивом целых чисел
{
public:
    exmpl(int* arr, size_t len) ://Конструктор класса, который принимает указатель на массив arr и его размер len
        mas(new int[len]), length(len)//Инициализация полей(указатель на массив) и length(длина массива) в списке инициализации
    {
        for (size_t i = 0; i < len; i++)
        {
            mas[i] = arr[i];
        }
    }

    ~exmpl()//Деструктор класса для освобождения динамически выделенной памяти
    {
        delete[] mas;
    }

    void setLength(int newLength)//Метод для установки новой длины массива и перераспределения памяти
    {
        length = newLength;
        resize();
    }

    unsigned int getLength()//Метод для получения текущей длины массива
    {
        return length;
    }

    const char* result()//Метод для вычисления суммы и среднего значения массива, формирования строки с результатом и возврата указателя на эту строку
    {
        int sum = calcSummOfValue();
        int middle = calcMiddleValue();
        stringstream ss;//Класс, который позволяет связать поток ввода-вывода со строкой в памяти
        ss << "Сумма: " << sum << ", Среднее значение: " << middle;
        resultString = ss.str();//Преобразует объект в строку
        return resultString.c_str();// возврат указателя на строку ss
    }

protected://Область доступа для защищенных методов класса
    int calcMiddleValue()//Метод для вычисления среднего значения элементов массива
    {
        int sum = 0;
        for (size_t i = 0; i < length; i++)
        {
            sum += mas[i];
        }
        return sum / length;
    }

    int calcSummOfValue()//Метод для вычисления суммы элементов массива
    {
        int sum = 0;
        for (size_t i = 0; i < length; i++)
        {
            sum += mas[i];
        }
        return sum;
    }

private://Область доступа для приватных полей и методов класса
    int* mas;//Указатель на массив
    size_t length;//Длина массива
    string resultString;//Строка для результата

    void resize()//Метод для изменения размера массива
    {
        int* newMas = new int[length];
        memcpy(newMas, mas, sizeof(int) * length);// Функция, которая копирует количество байтов из  mas в newMas.
        delete[] mas;
        mas = newMas;
    }
};
