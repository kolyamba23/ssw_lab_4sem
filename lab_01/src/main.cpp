#include <iostream>
#include "generator.h"
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
#include <chrono>
#include <vector>
#include <queue>
#include <stack>

int main(int argc, char* argv[])
{

    using namespace std;
    setlocale(LC_ALL, "RUS");
    try
    {
        int n;
        cout << "Enter the initial size: ";
        cin >> n;
        auto t1 = generate<int>(n); // t1 is std::vector
        cout << "<TEST>" << endl;
        cout << "\t" << t1[0] << " | " << t1.size() << endl;

        Vector vector1;
        /*cout << "Our vector: " << endl;
        for (int i = 0; i < n; i++)
        {vector1.push(t1[i]);
         vector1.vyvodelementa(i);}
        cout << endl;*/

        Stack stack1;
        /*cout << "Our stack: " << endl;
        for (int i = 0; i < n; i++)
        {  stack1.push(t1[i]);
        stack1.vyvodelementa(i);}
        cout << endl;*/

        Queue queue1;
         /*cout << "Our queue: " << endl;
        for (int i = 0; i < n; i++)
        {queue1.push(t1[i]);
        queue1.vyvodelementa(i);}
        cout << endl << endl;*/

        vector<int > stl_vector;
        queue <int> stl_queue;
        stack <int> stl_stack;

        //push1
        cout << "Comparing the time of inserting elements into vectors:\n ";
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            vector1.push(11);
        auto end = chrono::high_resolution_clock::now();
        auto res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        auto start1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            stl_vector.push_back(11);
        auto end1 = chrono::high_resolution_clock::now();
        auto res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
        cout << "My Vektor=" << res_time << endl;
        cout << "stl vector=" << res_time1 << endl;

        //push2
        cout << "Comparing the time of inserting elements into queue:\n ";
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            queue1.push(11);
        end = chrono::high_resolution_clock::now();
        res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        start1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            stl_queue.push(11);
        end1 = chrono::high_resolution_clock::now();
        res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
        cout << "My Queue=" << res_time << endl;
        cout << "stl queue=" << res_time1 << endl;

        //push3
        cout << "Comparing the time of inserting elements into stack:\n ";
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            stack1.push(11);
        end = chrono::high_resolution_clock::now();
        res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        start1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            stl_stack.push(11);
        end1 = chrono::high_resolution_clock::now();
        res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
        cout << "My Stack=" << res_time << endl;
        cout << "stl stack=" << res_time1 << endl;

        

        //peek1
        cout << "Comparing of the return time of the stack:\n ";
        start = chrono::high_resolution_clock::now();
         for (int i = 0; i < 10000; i++)
            stack1.peek();
        end = chrono::high_resolution_clock::now();
        res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        start1 = chrono::high_resolution_clock::now();
            stl_stack.top();
        end1 = chrono::high_resolution_clock::now();
        res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
        cout << "My Stack=" << res_time << endl;
        cout << "stl stack=" << res_time1 << endl;

        //peek2
        cout << "Comparing of the return time of the queue:\n ";
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            queue1.peek();
        end = chrono::high_resolution_clock::now();
        res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        start1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            stl_queue.front();
        end1 = chrono::high_resolution_clock::now();
        res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
        cout << "My Stack=" << res_time << endl;
        cout << "stl stack=" << res_time1 << endl;



        //counte1
        cout << "Comparing the return time of the number of vector elements:\n ";
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            vector1.countelement();
        end = chrono::high_resolution_clock::now();
        res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        start1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            stl_vector.size();
        end1 = chrono::high_resolution_clock::now();
        res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
        cout << "My Stack=" << res_time << endl;
        cout << "stl stack=" << res_time1 << endl;
        
        //counte2
        cout << "Comparing the return time of the number of stack elements:\n";
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            stack1.countelement();
        end = chrono::high_resolution_clock::now();
        res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "My Vector=" << res_time << endl;

        //counte3
        cout << "Comparing the return time of the number of queue elements:\n ";
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            queue1.countelement();
        end = chrono::high_resolution_clock::now();
        res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "My Queue=" << res_time << endl;



        //method at for vector
        cout << "Comparing the method at time for a vector:\n ";
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            vector1.at(i)=3;
        end = chrono::high_resolution_clock::now();
        res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        start1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            stl_vector.at(i)=3;
        end1 = chrono::high_resolution_clock::now();
        res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
        cout << "My Stack=" << res_time << endl;
        cout << "stl stack=" << res_time1 << endl;

        //method friendly




    }

    catch (const std::exception & exp)
    {
        cout << exp.what() << endl;
    }
}