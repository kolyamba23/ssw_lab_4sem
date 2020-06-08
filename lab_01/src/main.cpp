#include <iostream>
# include "generator.h"
# include "Vector.h"
# include "Stack.h"
# include "Queue.h"
# include <chrono>
#include <vector>
#include <queue>
#include <stack>

int main(int argc, char* argv[])
{

    using namespace std;
    setlocale(LC_ALL, "RUS");
    try
    {
        

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
            vector1.at(i) = 3;
        end = chrono::high_resolution_clock::now();
        res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        start1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; i++)
            stl_vector.at(i) = 3;
        end1 = chrono::high_resolution_clock::now();
        res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
        cout << "My Stack=" << res_time << endl;
        cout << "stl stack=" << res_time1 << endl;
        /////////////////////////////////////////////////////////////////
        //method comparison
        auto t1 = generate<int>(60); // t1 is std::vector
        cout << "<TEST>" << endl;
        cout << "\t" << t1[0] << " | " << t1.size() << endl;

        Vector vector2;
        Queue queue2;
        Stack stack2;
        Vector vector3;
        Queue queue3;
        Stack stack3;
        cout << "Vector2: \n";
        for (int i = 0; i < 20; i++)
        {
            vector2.push(t1[i]);
            vector2.vyvodelementa(i);
        }
        cout << endl;
        cout << "Queue2: \n";
        for (int i = 0; i < 20; i++)
        {
            queue2.push(t1[i]);
            queue2.vyvodelementa(i);
        }
        cout << endl;
        cout << "Stack2: \n";
        for (int i = 0; i < 20; i++)
        {
            stack2.push(t1[i]);
            stack2.vyvodelementa(i);
        }
        cout << endl;
        cout << "Vector3: \n";
        for (int i = 0; i < 25; i++)
        {
            vector3.push(t1[i]);
            vector3.vyvodelementa(i);
        }
        cout << endl;
        cout << "Queue3: \n";
        for (int i = 0; i < 25; i++)
        {
            queue3.push(t1[i]);
            queue3.vyvodelementa(i);
        }
        cout << endl;
        cout << "Stack3: \n";
        for (int i = 0; i < 25; i++)
        {
            stack3.push(t1[i]);
            stack3.vyvodelementa(i);
        }
        cout << endl;
        /////////////////////////////////////////////////////////////////
        if (vector2 == vector3)
            cout << "Vector2 is equally to vector3\n";
        else cout << "Vector2 is not equally to vector3\n";

        if (vector2 <= vector3)
            cout << "Vector2 is equal to or less than to vector3\n";
        else cout << "Vector2 is not equal to or not less than vector3\n";

        if (vector2 >= vector3)
            cout << "Vector2 is equal or greater than to vector3\n";
        else cout << "Vector2 is not equal to or not greater than vector3\n";

        if (vector2 != vector3)
            cout << "Vector2 is not equally to vector3\n";
        else cout << "Vector2 is equally to vector3\n";

        if (vector2 > vector3)
            cout << "Vector2 is greater than to vector3\n";
        else cout << "Vector2 is not greater than to vector3\n";

        if (vector2 < vector3)
            cout << "Vector2 is less than to vector3\n";
        else cout << "Vector2 is not less than to vector3\n";
        /////////////////////////////////////////////////////////////////
        if (queue2 == queue3)
            cout << "Queue2 is equally to queue3\n";
        else cout << "Queue2 is not equally to queue3\n";

        if (queue2 <= queue3)
            cout << "Queue2 is equal to or less than to queue3\n";
        else cout << "Queue2 is not equal to or not less than queue3\n";

        if (queue2 >= queue3)
            cout << "Queue2 is equal or greater than to queue3\n";
        else cout << "Queue2 is not equal to or not greater than queue3\n";

        if (queue2 != queue3)
            cout << "Queue2 is not equally to queue3\n";
        else cout << "Queue2 is equally to queue3\n";

        if (queue2 > queue3)
            cout << "Queue2 is greater than to queue3\n";
        else cout << "Queue2 is not greater than to queue3\n";

        if (queue2 < queue3)
            cout << "Queue2 is less than to queue3\n";
        else cout << "Queue2 is not less than to queue3\n";
        //////////////////////////////////////////////////////////////////////
        if (stack2 == stack3)
            cout << "Stack2 is equally to stack3\n";
        else cout << "Stack2 is not equally to stack3\n";

        if (stack2 <= stack3)
            cout << "Stack2 is equal to or less than to stack3\n";
        else cout << "Stack2 is not equal to or not less than stack3\n";

        if (stack2 >= stack3)
            cout << "Stack2 is equal or greater than to stack3\n";
        else cout << "Stack2 is not equal to or not greater than stack3\n";

        if (stack2 != stack3)
            cout << "Stack2 is not equally to stack3\n";
        else cout << "Stack2 is equally to stack3\n";

        if (stack2 > stack3)
            cout << "Stack2 is greater than to stack3\n";
        else cout << "Stack2 is not greater than to stack3\n";

        if (stack2 < stack3)
            cout << "Stack2 is less than to stack3\n";
        else cout << "Stack2 is not less than to stack3\n";
        ////////////////////////////////////////////////////////////////////
        vector<int > stl_vector1;
        queue <int> stl_queue1;
        stack <int> stl_stack1;
        vector<int > stl_vector2;
        queue <int> stl_queue2;
        stack <int> stl_stack2;
        ////////////////////////////////////////////////////////////////////
        for (int i = 0; i < 20; i++)
        {
            stl_vector1.push_back(t1[i]);
        }
        for (int i = 0; i < 20; i++)
        {
            stl_queue1.push(t1[i]);
        }
        for (int i = 0; i < 20; i++)
        {
            stl_stack1.push(t1[i]);
        }
        for (int i = 0; i < 25; i++)
        {
            stl_vector2.push_back(t1[i]);
        }
        for (int i = 0; i < 25; i++)
        {
            stl_queue2.push(t1[i]);
        }
        for (int i = 0; i < 25; i++)
        {
            stl_stack2.push(t1[i]);
        }
        cout << "STL container:\n";
        ////////////////////////////////////////////////////////////////////////
        if (stl_vector1 == stl_vector2)
            cout << "Vector2 is equally to vector3\n";
        else cout << "Vector2 is not equally to vector3\n";

        if (stl_vector1 <= stl_vector2)
            cout << "Vector2 is equal to or less than to vector3\n";
        else cout << "Vector2 is not equal to or not less than vector3\n";

        if (stl_vector1 >= stl_vector2)
            cout << "Vector2 is equal or greater than to vector3\n";
        else cout << "Vector2 is not equal to or not greater than vector3\n";

        if (stl_vector1 != stl_vector2)
            cout << "Vector2 is not equally to vector3\n";
        else cout << "Vector2 is equally to vector3\n";

        if (stl_vector1 > stl_vector2)
            cout << "Vector2 is greater than to vector3\n";
        else cout << "Vector2 is not greater than to vector3\n";

        if (stl_vector1 < stl_vector2)
            cout << "Vector2 is less than to vector3\n";
        else cout << "Vector2 is not less than to vector3\n";
        ///////////////////////////////////////////////////////////////
        if (stl_queue1 == stl_queue2)
            cout << "Queue2 is equally to queue3\n";
        else cout << "Queue2 is not equally to queue3\n";

        if (stl_queue1 <= stl_queue2)
            cout << "Queue2 is equal to or less than to queue3\n";
        else cout << "Queue2 is not equal to or not less than queue3\n";

        if (stl_queue1 >= stl_queue2)
            cout << "Queue2 is equal or greater than to queue3\n";
        else cout << "Queue2 is not equal to or not greater than queue3\n";

        if (stl_queue1 != stl_queue2)
            cout << "Queue2 is not equally to queue3\n";
        else cout << "Queue2 is equally to queue3\n";

        if (stl_queue1 > stl_queue2)
            cout << "Queue2 is greater than to queue3\n";
        else cout << "Queue2 is not greater than to queue3\n";

        if (stl_queue1 < stl_queue2)
            cout << "Queue2 is less than to queue3\n";
        else cout << "Queue2 is not less than to queue3\n";
        //////////////////////////////////////////////////////////////////
        if (stl_stack1 == stl_stack2)
            cout << "Stack2 is equally to stack3\n";
        else cout << "Stack2 is not equally to stack3\n";

        if (stl_stack1 <= stl_stack2)
            cout << "Stack2 is equal to or less than to stack3\n";
        else cout << "Stack2 is not equal to or not less than stack3\n";

        if (stl_stack1 >= stl_stack2)
            cout << "Stack2 is equal or greater than to stack3\n";
        else cout << "Stack2 is not equal to or not greater than stack3\n";

        if (stl_stack1 != stl_stack2)
            cout << "Stack2 is not equally to stack3\n";
        else cout << "Stack2 is equally to stack3\n";

        if (stl_stack1 > stl_stack2)
            cout << "Stack2 is greater than to stack3\n";
        else cout << "Stack2 is not greater than to stack3\n";

        if (stl_stack1 < stl_stack2)
            cout << "Stack2 is less than to stack3\n";
        else cout << "Stack2 is not less than to stack3\n";
    }

    catch (const std::exception& exp)
    {
        cout << exp.what() << endl;
    }
}