#include <iostream>
#include <iomanip>
#include "Simply.h"
#include "Double.h"
#include "Ring_buffer.h"
#include "generator.h"
#include <chrono>
#include <list>

using namespace std;

int main() 
{
    try {
        auto t = generate <int>(50);
        cout << "<TEST>" << endl;
        cout << "\t" << t[0] << " | " << t.size() << endl << endl;
        cout << "\t\t\tTest list:\n";
        simply_list <int> our_simply_list;

        cout << "Numbers for push front in list:\n";
        for (int i = 0; i < 10; i++) 
        {
            our_simply_list.Push_front(t[i]);
        }
        cout << "\nList: \n" << our_simply_list << endl;

        cout << "Numbers for push back in list:\n";
        for (int i = 0; i < 2; i++) {
            our_simply_list.Push_back(t[i]);
            cout << i << "\t";
        }
        cout << "\nList: \n" << our_simply_list << endl;

        cout << "List pop front:\n";
        for (int i = 0; i < 5; i++) {
            cout << our_simply_list.Pop_front() << "\t";
        }
        cout << "\n List: \n" << our_simply_list << endl;


        cout << "List pop Back:\n";
        for (int i = 0; i < 5; i++) {
            cout << our_simply_list.Pop_back() << "\t";
        }
        cout << "\n List: \n" << our_simply_list << endl;

        cout << "Insert 11 with index 1\n";
        our_simply_list.Insert(11, 1);
        cout << our_simply_list << endl;

        cout << "Erase with index 2\n";
        our_simply_list.Delete(2);
        cout << our_simply_list << endl;

        cout << "First and last element:\n";
        cout << *our_simply_list.Begin() << "\t" << *our_simply_list.End() << endl;

        cout << "Count simply list:\n" << our_simply_list.Count() << endl;
        ///////////////////////////////////////////////////////
        cout << endl << endl;
        cout << "Test double list:\n";

        double_list <int> our_double_list;

        cout << "number for push front in list:\n";
        for (int i = 0; i < 15; i++) {
            our_double_list.Push_front(i * 2);
            cout << i * 2 << "\t";
        }
        cout << "\nList: \n" << our_double_list << endl;

        cout << "number for push back in list:\n";
        for (int i = 0; i < 5; i++) {
            our_double_list.Push_back(i);
            cout << i << "\t";
        }
        cout << "\nList: \n" << our_double_list << endl;

        cout << "list pop front:\n";
        for (int i = 0; i < 8; i++) {
            cout << our_double_list.Pop_front() << "\t";
        }
        cout << "\n List: \n" << our_double_list << endl;


        cout << "list pop Back:\n";
        for (int i = 0; i < 8; i++) {
            cout << our_double_list.Pop_back() << "\t";
        }
        cout << "\n List: \n" << our_double_list << endl;

        cout << "insert 25 with index 1\n";
        our_double_list.Insert(25, 1);
        cout << our_double_list << endl;

        cout << "Erase 25 with index 1\n";
        our_double_list.Delete(1);
        cout << our_double_list << endl;

        cout << "First and last el-t's:\n";
        cout << *our_double_list.Begin() << "\t" << *our_double_list.End() << endl;

        cout << "Count:\n" << our_double_list.Count() << endl;

        /////////////////////////////
        cout << endl << endl << endl;
        cout << "Test ring buffer:\n";
        ring_buffer<int> our_ring_buffer(5);

        cout << "Element's for input to buffer(size = 5): \n";
        for (int i = 0; i < 8; i++) {
            our_ring_buffer.Push(i * 2);
            cout << i * 2 << "\t";
        }
        cout << "\nbuffer:\n" << our_ring_buffer << endl;

        cout << "head:\n";
        cout << *our_ring_buffer.Begin() << endl;
        cout << "tail:\n";
        cout << *our_ring_buffer.End() << endl;

        cout << "pop 4 el-t's:\n";
        for (int i = 0; i < 4; i++) {
            cout << our_ring_buffer.Pop() << "\t";
        }
        cout << "\n Buffer:\n" << our_ring_buffer << endl;

        cout << "Count: " << our_ring_buffer.Count() << endl;
        cout << endl;

        simply_list <int> sortirovka_simply;
        simply_list <int> sortirovka_simply_2;
        
        cout << "numbers for push front in list:\n";
        cout << endl;
        cout << "Simply_list(sort)" << endl;
        cout << "before sort" << endl;
        for (int i = 0; i < 10; i++)
        {
            sortirovka_simply.Push_back(t[i]);
            cout << t[i] << " ";
        }

        cout << endl << sortirovka_simply << endl;
        cout << "after sort";
        sortirovka_simply.Fast_sort();
        cout << endl << fixed << setprecision(2) << sortirovka_simply << endl;
        cout << endl;
        cout << "Simply_list(merge sort)" << endl;
        cout << "before merge sort" << endl;
        for (int i = 0; i < 10; i++)
        {
            sortirovka_simply_2.Push_back(t[i]);
            cout << t[i] << " ";
        }
        cout << endl << sortirovka_simply_2 << endl;
        cout << "after merge sort";
        sortirovka_simply_2.Merge_sort_func();
        cout << endl << fixed << setprecision(2) << sortirovka_simply_2 << endl;
        cout << endl;

        double_list <int> sortirovka_double_list;
        double_list <int> sortirovka_double_list_2;
        cout << "Double_list(sort)" << endl;
        cout << "before sort" << endl;
        for (int i = 0; i < 20; i++)
        {
            sortirovka_double_list.Push_back(t[i]);
            cout << t[i] << " ";
        }
        cout << endl << sortirovka_double_list << endl;
        cout << "after sort";
        sortirovka_double_list.Fast_sort();
        cout << endl << fixed << setprecision(2) << sortirovka_double_list << endl << endl;
        cout << endl;
        cout << "Double_list(merge sort)" << endl;
        cout << "before sort" << endl;
        for (int i = 0; i < 20; i++)
        {
            sortirovka_double_list_2.Push_back(t[i]);
            cout << t[i] << " ";
        }
        cout << endl << sortirovka_double_list_2 << endl;
        cout << "after sort";
        sortirovka_double_list_2.Merge_sort_func();
        cout << endl << fixed << setprecision(2) << sortirovka_double_list_2 << endl << endl;
        cout << endl;

        ring_buffer <int> sortirovka_ring_buffer(15);
        ring_buffer <int> sortirovka_ring_buffer_2(15);
        cout << "Ring_buffer(sort)" << endl;
        cout << "before sort" << endl;
        for (int i = 0; i < 15; i++)
        {
            sortirovka_ring_buffer.Push(t[i]);
            cout << t[i] << " ";
        }
        cout << endl << "after sort";
        cout << endl << sortirovka_ring_buffer << endl;
        sortirovka_ring_buffer.Fast_sort();
        cout << endl << fixed << setprecision(2) << sortirovka_ring_buffer;
        cout << endl << endl;

        cout << "Ring_buffer(merge sort)" << endl;
        cout << "before merge sort" << endl;
        for (int i = 0; i < 15; i++)
        {
            sortirovka_ring_buffer_2.Push(t[i]);
            cout << t[i] << " ";
        }
        cout << endl << "after merge sort";
        cout << endl << sortirovka_ring_buffer_2 << endl;
        sortirovka_ring_buffer_2.Merge_sort_func();
        cout << endl << fixed << setprecision(2) << sortirovka_ring_buffer_2;

        cout << endl;
        cout << endl << "START Simply" << endl;
        simply_list <int> op1;
        simply_list <int> op2;
        for (int i = 0; i < 18; i++)
        {
            op1.Push_back(t[i]);
            cout << t[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 23; i++)
        {
            op2.Push_back(t[i]);
            cout << t[i] << " ";
        }
        cout << endl;
        if (op1 > op2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op1 == op2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op1 >= op2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op1 <= op2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op1 < op2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op1 != op2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

        cout << endl;
        cout << endl << "START Simply stl" << endl;
        list <int> stl_simply;
        list <int> stl_simply_2;
        for (int i = 0; i < 18; i++)
        {
            stl_simply.push_back(t[i]);
            cout << t[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 23; i++)
        {
            stl_simply_2.push_back(t[i]);
            cout << t[i] << " ";
        }
        cout << endl;
        if (stl_simply > stl_simply_2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (stl_simply == stl_simply_2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (stl_simply >= stl_simply_2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (stl_simply <= stl_simply_2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (stl_simply < stl_simply_2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (stl_simply != stl_simply_2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

        cout << endl << "START Double" << endl;
        double_list <int> op3;
        double_list <int> op4;
        for (int i = 0; i < 25; i++)
        {
            op3.Push_back(t[i]);
            cout << t[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 25; i++)
        {
            op4.Push_back(t[i]);
            cout << t[i] << " ";
        }
        cout << endl;
        if (op3 > op4)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op3 == op4)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op3 >= op4)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op3 <= op4)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op3 < op4)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op3 != op4)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

        cout << endl << "START Ring_buffer" << endl;
        ring_buffer <int> op5(30);
        ring_buffer <int> op6(30);
        for (int i = 0; i < 27; i++)
        {
            op5.Push(t[i]);
            cout << t[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 16; i++)
        {
            op6.Push(t[i]);
            cout << t[i] << " ";
        }
        cout << endl;
        if (op5 > op6)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op5 == op6)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op5 >= op6)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op5 <= op6)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op5 < op6)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        if (op5 != op6)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

        using ns = std::chrono::nanoseconds;

        simply_list<int> our_simply_list2;
        list <int> stl_list;

        cout << endl;

        ////////////////////////////////////////////////
        cout << "Simply list time: " << endl << endl;
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < 100; i++)
        {
            our_simply_list2.Push_back(i);
        }
        auto end = chrono::high_resolution_clock::now();
        auto res = chrono::duration_cast<ns>(end - start).count();
        cout << "Our simply list - push " << res << endl;

        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < 100; i++)
        {
            our_simply_list2.Pop_back();
        }
        end = chrono::high_resolution_clock::now();
        res = chrono::duration_cast<ns>(end - start).count();
        cout << "Our simply list - pop " << res << endl << endl;

        cout << "STL Simple time:" << endl << endl;

        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < 100; i++)
        {
            stl_list.push_back(i);
        }
        end = chrono::high_resolution_clock::now();
        res = chrono::duration_cast<ns>(end - start).count();
        cout << "STL Simple - push " << res << endl;

        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < 100; i++)
        {
            stl_list.pop_back();
        }
        end = chrono::high_resolution_clock::now();
        res = chrono::duration_cast<ns>(end - start).count();
        cout << "STL Simple - pop " << res << endl;
    }
    catch (const std::exception& exp)
    {
        cout << exp.what() << endl;
    }
    return 0;
}