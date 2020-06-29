#ifndef LAB2V2_MY_RING_BUFFER_H
#define LAB2V2_MY_RING_BUFFER_H
#include <iostream>
using namespace std;
template<class T>
class ring_buffer {
private:

    class node {
    public:
        T value { 0 };
        node* pointer{ nullptr };

        explicit node(T val, node* link = nullptr) {
            value = val;
            pointer = link;
        }
        ~node() = default;
    };

    node* head {nullptr};
    node* tail {nullptr};
    size_t valid_size {0};
    size_t input_size {0};

public:
    ring_buffer (int size);
    ~ring_buffer();
    void Push (T data);
    void Insert (T data, int index);
    void Merge_sort(unsigned int l, unsigned int r);
    void Merge(unsigned int l, unsigned int r);
    void Merge_sort_func();
    void Fast_sort();
    T Pop();
    T* Begin() 
    { return &head->value; }
    T* End() 
    { return &tail->value; }
    int Count() 
    {
        return valid_size;
    }

    friend ostream& operator << (ostream& out, const ring_buffer <T> &m) {
        if (m.valid_size == 0) throw std::out_of_range("Buffer is empty");
        node* current = m.head;
        int count = m.valid_size;

        out << "(";
        while (count != 0) 
        {
            out << current->value << ", ";
            current = current->pointer;
            count--;
        }
        out << ")";
        return out;
    }

    bool operator > (const ring_buffer<T>& m)
    {
        node* cur1 = this->head;
        node* cur2 = m.head;
        int count = this->valid_size;

        while (((cur1 != this->tail) || (count != 0)) && ((cur2 != m.tail) || (count != 0))) {
            if (cur1->value < cur2->value) return false;
            if (cur1->value > cur2->value) return true;

            cur1 = cur1->pointer;
            cur2 = cur2->pointer;
            count--;
        }
        if (cur1->value > cur2->value) return true;
        if (cur1->value < cur2->value) return false;

        return (this->valid_size > m.valid_size);
    }

    bool operator < (const ring_buffer<T>& m)
    {
        return !(*this >= m);
    }

    bool operator == (const ring_buffer<T>& m)
    {
        node* cur1 = this->head;
        node* cur2 = m.head;
        int count = this->valid_size;

        while (((cur1 != this->tail) || (count != 0)) && ((cur2 != m.tail) || (count != 0)))
        {

            if (cur1->value != cur2->value)
            {
                return false;
            }

            cur1 = cur1->pointer;
            cur2 = cur2->pointer;
            count--;
        }
        if (cur1->value != cur2->value)
        {
            return false;
        }
        return (this->valid_size == m.valid_size);
    }

    bool operator != (const ring_buffer<T>& m)
    {
        return !(*this == m);
    }

    bool operator >= (const ring_buffer<T>& m)
    {
        return ((*this > m) || (*this == m));
    }

    bool operator <= (const ring_buffer<T>& m)
    {
        return !(*this > m);
    }
};

template<class T>
ring_buffer<T>::ring_buffer(int size) {
    if (size <= 0) 
        throw std::out_of_range("The size must be positive.");

    this->input_size = size;
    head = new node(0);
    node* current = head;
    for (int i = 1; i < input_size; i++) {
        current->pointer = new node(0);
        current = current->pointer;
    }
    current->pointer = head;
    tail = head;
    head = tail->pointer;
}

template<class T>
ring_buffer<T>::~ring_buffer() {
    node* current = head;
    node* del = nullptr;
    while (input_size > 0) {
        del = current;
        current = current->pointer;
        delete del;
        input_size--;
    }
    head = nullptr;
    tail = nullptr;
}

template<class T>
void ring_buffer<T>::Push (T data) 
{
    if (valid_size == 0) 
    {
        tail->value = data;
    }
    else {
        if (tail->pointer == head)
            head = head->pointer;
        tail = tail->pointer;
        tail->value = data;
    }
    if (valid_size != input_size) 
        valid_size++;
    else cout << endl << "Values are being overwritten." << endl;
}

template<class T>
T ring_buffer<T>::Pop() 
{
    if (valid_size == 0) 
        throw std::out_of_range("The ring buffer is empty.");

    T ret = head->value;
    head = head->pointer;
    valid_size--;
    return ret;
}

template<class T>
void ring_buffer<T>::Insert(T data, int index) {
    if (index >= valid_size) 
        throw std::out_of_range("Index is more the size of buffer.");
    if (index < 0) 
        throw std::out_of_range("The index must be positive.");

    node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->pointer;
    }
    current->value = data;
}

template <class T>
void ring_buffer<T>::Fast_sort()
{
    if (head == nullptr)
        throw std::out_of_range("Ring buffer is empty.");
    node* t, * m, * a, * b;
    if (head == nullptr)
        return;

    for (bool go = true; go;)
    {
        go = false;
        a = t = head;
        b = head->pointer;

        for (int i = 0; i < (input_size-1); i++)
        {
            if (a->value > b->value)
            {
                if (t == a)
                    head = b;
                else
                    t->pointer = b;

                a->pointer = b->pointer;
                b->pointer = a;

                m = a, a = b, b = m;
                go = true;
            }
            t = a;
            a = a->pointer;
            b = b->pointer;
        }
    }
}

template <class T>
void ring_buffer<T>::Merge_sort_func()
{
    if (head == nullptr)
        throw std::out_of_range("Ring buffer is empty.");
    unsigned int start{ 0 };
    unsigned int end{ 0 };
    end = 0;
    start = (valid_size - 1);
    Merge_sort (end, start);
}

template<typename T>
void ring_buffer<T>::Merge_sort(unsigned int end, unsigned int start)
{
    if (end < start)
    {
        Merge_sort(end, (end + start) / 2);
        Merge_sort((end + start) / 2 + 1, start);
        Merge(end, start);
    }
}

template<typename T>
void ring_buffer<T>::Merge(unsigned int end, unsigned int start)
{
    T result[20];
    unsigned int mid{ (end + start) / 2 };
    unsigned int left_one{ end };
    unsigned int left_two{ mid + 1 };
    unsigned int search_1{ 0 };
    node* head_class = head;
    while (search_1 < end)
    {
        head_class = head_class->pointer;
        search_1++;
    }
    unsigned int search_2{ search_1 };
    node* var_head = head_class;
    while (search_2 < left_two)
    {
        var_head = var_head->pointer;
        search_2++;
    }

    while (search_1 < start + 1)
    {
        if ((left_one <= mid) && ((left_two > start) || head_class->value < var_head->value))
        {
            result[search_1] = head_class->value;
            left_one++;
            if (search_1 != start)
                head_class = head_class->pointer;
        }
        else {
            result[search_1] = var_head->value;
            left_two++;
            if (search_1 != start)
                var_head = var_head->pointer;
        }
        search_1++;
    }
    unsigned int search_3{ 0 };
    node* tmp = this->head;
    while (search_3 < end)
    {
        tmp = tmp->pointer;
        search_3++;
    }
    while (search_3 < start + 1)
    {
        tmp->value = result[search_3];
        tmp = tmp->pointer;
        search_3++;
    }
}
#endif //LAB2V2_MY_RING_BUFFER_H
