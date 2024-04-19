#pragma ones//���������, ��������������� ������������ ��������� ������������� �����
#include <iostream>
#include <sstream>//���������� ��� ������ � �������� ������
#include <cstring>//���������� ��� ������ � ��������� ��������� �����
using namespace std;
class exmpl// �����, ����������� �������� ��� �������� ����� �����
{
public:
    exmpl(int* arr, size_t len) ://����������� ������, ������� ��������� ��������� �� ������ arr � ��� ������ len
        mas(new int[len]), length(len)//������������� �����(��������� �� ������) � length(����� �������) � ������ �������������
    {
        for (size_t i = 0; i < len; i++)
        {
            mas[i] = arr[i];
        }
    }

    ~exmpl()//���������� ������ ��� ������������ ����������� ���������� ������
    {
        delete[] mas;
    }

    void setLength(int newLength)//����� ��� ��������� ����� ����� ������� � ����������������� ������
    {
        length = newLength;
        resize();
    }

    unsigned int getLength()//����� ��� ��������� ������� ����� �������
    {
        return length;
    }

    const char* result()//����� ��� ���������� ����� � �������� �������� �������, ������������ ������ � ����������� � �������� ��������� �� ��� ������
    {
        int sum = calcSummOfValue();
        int middle = calcMiddleValue();
        stringstream ss;//�����, ������� ��������� ������� ����� �����-������ �� ������� � ������
        ss << "�����: " << sum << ", ������� ��������: " << middle;
        resultString = ss.str();//����������� ������ � ������
        return resultString.c_str();// ������� ��������� �� ������ ss
    }

protected://������� ������� ��� ���������� ������� ������
    int calcMiddleValue()//����� ��� ���������� �������� �������� ��������� �������
    {
        int sum = 0;
        for (size_t i = 0; i < length; i++)
        {
            sum += mas[i];
        }
        return sum / length;
    }

    int calcSummOfValue()//����� ��� ���������� ����� ��������� �������
    {
        int sum = 0;
        for (size_t i = 0; i < length; i++)
        {
            sum += mas[i];
        }
        return sum;
    }

private://������� ������� ��� ��������� ����� � ������� ������
    int* mas;//��������� �� ������
    size_t length;//����� �������
    string resultString;//������ ��� ����������

    void resize()//����� ��� ��������� ������� �������
    {
        int* newMas = new int[length];
        memcpy(newMas, mas, sizeof(int) * length);// �������, ������� �������� ���������� ������ ��  mas � newMas.
        delete[] mas;
        mas = newMas;
    }
};
