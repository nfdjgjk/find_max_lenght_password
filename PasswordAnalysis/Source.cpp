#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include <string>
using namespace std;


//Определяет максимальную длину пароля
//text[] - массив строк, который хранит текст
//str - количество строк в тексте
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

    // Пример пути до файла
    //C:\\Users\\Public\\pwd.txt


    cout << "Введите расположение файла с данными: ";
    string path1;
    cin >> path1;


    string line;
    ifstream in(path1); // окрываем файл для чтения
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
    in.close();     // закрываем файл





    //-----------------------------------Удаление пустых строк--------------------------------------

    //Проходимся по всем строкам текста 
    for (int i = 0; i < str; i++)
    {
        //Пока есть последовательность из пыстых строк
        while (text[i].empty())
        {
            //Смещаем каждую следующую строку на одну позицию ближе к началу 
            for (int j = i; j < str - 1; j++)
            {
                text[j] = text[j + 1]; //Смещаем текущий элемент на одну позицию 
            }

            //Уменьшаем количество строк в тексте
            str--;
        }
    }




    //Главная вычислительная функция (определяет максимальную длину пароля)
    cout << "Самый длинный пароль: " << maximumlenghtPassword(text, str) << endl;

    system("PAUSE");
    return 0;
}