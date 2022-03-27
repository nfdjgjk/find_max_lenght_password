#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include <string>
using namespace std;


//���������� ������������ ����� ������
//text[] - ������ �����, ������� ������ �����
//str - ���������� ����� � ������
int maximumlenghtPassword(string text[], int str)
{
    int posSemicolon = text[0].find(';');
    int posEnd = text[0].size();
    int maxlenghtPassword = posEnd - posSemicolon-1;

    for (int i = 0; i < str; i++)
    {
        int posSemicolon = text[i].find(';');
        int posEnd = text[i].size();
        int lenghtPassword = posEnd - posSemicolon-1;

        if (lenghtPassword > maxlenghtPassword)
        {
            maxlenghtPassword = lenghtPassword;

        }
    }

    return maxlenghtPassword;
}




int main()
{
    setlocale(LC_ALL, "RU");

    // ������ ���� �� �����
    //C:\\Users\\Public\\pwd.txt


    cout << "������� ������������ ����� � �������: ";
    string path1;
    cin >> path1;


    string line;
    ifstream in(path1); // �������� ���� ��� ������
    string text[1000];
    int str = 0;

    if (in.is_open())
    {
        while (getline(in, line))
        {
            text[str] = line;
            str++;
        }
    }
    in.close();     // ��������� ����





    //-----------------------------------�������� ������ �����--------------------------------------

    //���������� �� ���� ������� ������ 
    for (int i = 0; i < str; i++)
    {
        //���� ���� ������������������ �� ������ �����
        while (text[i].empty())
        {
            //������� ������ ��������� ������ �� ���� ������� ����� � ������ 
            for (int j = i; j < str - 1; j++)
            {
                text[j] = text[j + 1]; //������� ������� ������� �� ���� ������� 
            }

            //��������� ���������� ����� � ������
            str--;
        }
    }




    //������� �������������� ������� (���������� ������������ ����� ������)
    cout << "����� ������� ������: " << maximumlenghtPassword(text, str) << endl;

    system("PAUSE");
    return 0;
}