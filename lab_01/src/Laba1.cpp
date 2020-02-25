#include <iostream>
#include "generator.h"
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"



int main(int argc, char* argv[])
{
    using namespace std;
    setlocale(LC_ALL, "RUS");
    try
    {
        int n;
        cout << "Введите начальный размер: ";
        cin >> n;
        auto t1 = generate<int>(n); // t1 is std::vector
        cout << "<TEST>" << endl;
        cout << "\t" << t1[0] << " | " << t1.size() << endl;

        Vector vector1;
        vector1.Buffer();
        cout << "Полученный вектор: " << endl;
        for (int i = 0; i < n; i++)
        { vector1.push(t1[i], i);
        vector1.vyvodelementa(i);}
        cout << endl;

        Stack stack1;
        stack1.Buffer();
        cout << "Полученный стек: " << endl;
        for (int i = 0; i < n; i++)
            stack1.push(t1[i]);
        cout << endl;

        Queue queue1;
        queue1.Buffer();
        cout << "Полученная очередь: " << endl;
        for (int i = 0; i < n; i++)
            queue1.push(t1[i]);
        cout << endl << endl;

        int c = 1;
        while (c != 6)
        {
            cout << "Выберите желаемое действие: \n 1) Возврат вершины  \n 2) Возврат размера \n 3) Выбор условия задачи \n 4) Добавление элементов \n 5) Дополнительные дейстия с вектором  \n 6) Выход \n";
            cin >> c;
            switch (c)
            {
            case 1:
                cout << " Какой структуры: \n 1) Вектор \n 2) Очередь \n 3) Стек \n 4) Выход \n";
                int c1;
                cin >> c1;
                switch (c1)
                {
                case 1:
                    vector1.peek();
                    break;
                case 2:
                    queue1.peek();
                    break;
                case 3:
                    stack1.peek();
                    break;
                case 4:
                    break;
                }
                break;
            case 2:
                cout << " Какой структуры: \n 1) Вектор \n 2) Очередь \n 3) Стек \n 4) Выход \n";
                int c12;
                cin >> c12;
                switch (c12)
                {
                case 1:
                    vector1.countelement();
                    break;
                case 2:
                    queue1.countelement();
                    break;
                case 3:
                    stack1.countelement();
                    break;
                case 4:
                    break;
                }
                break;
            case 3:
                cout << "Выбор: \n 1) Удаление отрицательных элементов \n 2) Удаление элементов по диапазону \n";
                int c2;
                cin >> c2;
                switch (c2)
                {
                case 1:
                    cout << " Какой структуры: \n 1) Вектор \n 2) Очередь \n 3) Стек \n 4) Выход \n";
                    int c3;
                    cin >> c3;
                    switch (c3)
                    {
                    case 1:
                       n= vector1.sort();
                        cout << endl;
                        break;
                    case 2:
                        queue1.sort();
                        cout << endl;
                        break;
                    case 3:
                        stack1.sort();
                        cout << endl;
                        break;
                    case 4:
                        break;
                    }
                    break;
                case 2:
                    cout << "Введите диапазон: \n От: ";
                    int ot, end;
                    cin >> ot;
                    cout << " До: ";
                    cin >> end;
                    cout << endl;
                    cout << " Какой структуры: \n 1) Вектор \n 2) Очередь \n 3) Стек \n 4) Выход \n";
                    int c4;
                    cin >> c4;
                    switch (c4)
                    {
                    case 1:
                        n=vector1.sortdiapazon(ot, end);
                        break;
                    case 2:
                        queue1.sortdiapazon(ot, end);
                        break;
                    case 3:
                        stack1.sortdiapazon(ot, end);
                        break;
                    case 4:
                        break;
                    }
                    break;
                }
                break;
            case 4:
                cout << " Какой структуры: \n 1) Вектор \n 2) Очередь \n 3) Стек \n 4) Выход \n";
                int c5;
                cin >> c5;
                switch (c5)
                {
                case 1:
                    cout << "Введите значение элемента: ";
                    int znach;
                    cin >> znach;
                    vector1.push(znach, n + 1);
                    n++;
                    break;
                case 2:
                    cout << "Введите значение: ";
                    int znach1;
                    cin >> znach1;
                    queue1.push(znach1);
                    break;
                case 3:
                    cout << "Введите значение: ";
                    int znach2;
                    cin >> znach2;
                    stack1.push(znach2);
                    break;
                case 4:
                    break;
                }
                break;
            case 5:
                cout << "Введите индекс нужного элемента: ";
                int ind;
                cin >> ind;
                if (ind > n)
                    throw std::range_error("Выход за пределы вектора");
                vector1.vyvodelementa(ind-1);
                cout << endl;
                int c6;
                cout << "Изменить значение: \n 1) Да \n 2) Нет \n";
                cin >> c6;
                if (c6 == 1)
                {
                    cout << "Введите значение: ";
                    vector1.at(ind-1);
                    cout << endl;
                }
                break;
            }
        }
    }

    catch (const std::exception & exp) 
    {
        cout << exp.what() << endl;
    }
}