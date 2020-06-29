#ifndef LAB2V2_SIMPLE_LIST_H
#define LAB2V2_SIMPLE_LIST_H
#include <iostream>
using namespace std;
template<class T>
class simply_list {
private:
    class node 
    {
    public:
        T value {0};
        node *next_pointer {nullptr};

        explicit node(T val, node* link = nullptr) 
        {
            value = val;
            next_pointer = link;
        }

        ~node() = default;
    };
    
    node *head {nullptr};
    size_t size {0};

public:
    simply_list () = default;
    ~simply_list ();
    int Count ();
    void Push_back (T data);
    void Push_front (T data);
    void Insert (T value, unsigned int index);
    void Delete (int index);
    void Fast_sort ();
    void Merge_sort (unsigned int l, unsigned int r);
    void Merge (unsigned int l, unsigned int r);
    void Merge_sort_func();

    T Pop_back();
    T Pop_front();
   
    T *Begin()
    {
        return &head->value;
    }

    T *End()
    {
        node* current = head;
        while (current->next_pointer != nullptr)
        {
            current = current->next_pointer;
        }
        return &current->value;
    }


    friend std::ostream& operator<< (std::ostream& out, const simply_list<T>& m) {
        if (m.head == nullptr) throw std::out_of_range ("Simply list is empty.");
        node* current = m.head;

        out << "(";
        while (current->next_pointer != nullptr) {
            out << current->value << ", ";
            current = current->next_pointer;
        }
        out << current->value << ")";

        return out;
    };

    bool operator > (const simply_list<T>& m)
    {
        node* cur1 = this->head;
        node* cur2 = m.head;

        while ((cur1->next_pointer != nullptr) && (cur2->next_pointer != nullptr))
        {
            if (cur1->value < cur2->value) return false;
            if (cur1->value > cur2->value) return true;
            cur1 = cur1->next_pointer;
            cur2 = cur2->next_pointer;
        }

        if (cur1->value > cur2->value) return true;
        if (cur1->value < cur2->value) return false;
        return (this->size > m.size);
    }

    bool operator < (const simply_list<T>& m)
    {
        return !(*this >= m);
    }

    bool operator == (const simply_list<T>& m)
    {
        node* cur1 = this->head;
        node* cur2 = m.head;

        while ((cur1->next_pointer != nullptr) && (cur2->next_pointer != nullptr))
        {

            if (cur1->value != cur2->value)
            {
                return false;
            }

            cur1 = cur1->next_pointer;
            cur2 = cur2->next_pointer;
        }
        if (cur1->value != cur2->value)
        {
            return false;
        }
        return (this->size == m.size);
    }

    bool operator != (const simply_list<T>& m)
    {
        return !(*this == m);
    }

    bool operator >= (const simply_list<T>& m)
    {
        return ((*this > m) || (*this == m));
    }

    bool operator <= (const simply_list<T>& m)
    {
        return !(*this > m);
    }
};

template <typename T>
simply_list<T>::~simply_list() 
{
    while (size) 
    {
        Pop_front();
    }
    head = nullptr;
}

template<class T>
void simply_list<T>::Push_back(T data) 
{
    if (head == nullptr) 
    {
        head = new node(data);
    }
    else 
    {
        node* current = this->head;

        while (current->next_pointer != nullptr) 
        {
            current = current->next_pointer;
        }
        current->next_pointer = new node(data);
    }

    size++;
}

template<class T>
void simply_list<T>::Push_front(T data) 
{
    if (head == nullptr) 
    {
        head = new node(data);
    }
    else 
    {
        
        node* current = new node(data, head);
        head = current;
    }
    size++;
}

template<class T>
int simply_list<T>::Count() 
{
    return size;
}

template <class T>
T simply_list <T>::Pop_back() 
{
    if (head == nullptr) 
        throw std::out_of_range("Simply list is empty.");

    node* pop = nullptr;
    node* current = this->head;
    T ret;

    while (current->next_pointer != nullptr) 
    {
        pop = current;
        current = current->next_pointer;
    }

    if (pop != nullptr) 
        pop->next_pointer = nullptr;
    ret = current->value;
    delete current;
    size--;
    if (size == 0) head = nullptr;
    return ret;
}

template <class T>
T simply_list <T>::Pop_front() 
{
    if (head == nullptr) 
        throw std::out_of_range("Simply list is empty.");
    node* del = head;
    T ret = head->value;
    head = head->next_pointer;
    delete del;
    size--;
    if (size == 0) head = nullptr;

    return ret;
}

template <class T>
void simply_list<T>::Insert(T value, unsigned int index)
{
    if (index >= size) 
        throw std::out_of_range("Index is more then size of simply list.");
    if (index < 0) 
        throw std::out_of_range("The index must be positive.");

    if (index == 0) 
    {
        Push_front(value);
    }
    else 
    {
        node* prev = head;

        for (int i = 0; i < index - 1; i++) 
        {
            prev = prev->next_pointer;
        }
        node* nextNode = new node(value, prev->next_pointer);
        prev->next_pointer = nextNode;

        size++;
    }

}

template <class T>
void simply_list<T>::Delete(int index) 
{
    if (index >= size) 
        throw std::out_of_range("Index is more then size of simply list.");
    if (index < 0) 
        throw std::out_of_range("The index must be positive.");

    if (index == 0) 
    {
        Pop_front();
    }
    else 
    {
        node* prev = head;
        node* del = nullptr;
        for (int i = 0; i < index - 1; i++) 
        {
            prev = prev->next_pointer;
        }
        del = prev->next_pointer;
        prev->next_pointer = del->next_pointer;
        delete del;
        size--;
    }
    if (size == 0) 
        head = nullptr;
}

template <class T>
void simply_list<T>::Fast_sort()
{
    if (head == nullptr)
        throw std::out_of_range("Simply list is empty.");
    node* t, * m, * a, * b;
    if (head == nullptr)
        return;

    for (bool go = true; go; )
    {
        go = false;
        a = t = head;
        b = head->next_pointer;

        while (b != NULL)
        {
            if (a->value > b->value)
            {
                if (t == a)
                    head = b;
                else
                    t->next_pointer = b;

                a->next_pointer = b->next_pointer;
                b->next_pointer = a;

                m = a, a = b, b = m;
                go = true;
            }
            t = a;
            a = a->next_pointer;
            b = b->next_pointer;
        }
    }
}

template <class T>
void simply_list<T>::Merge_sort_func()
{
    if (head == nullptr)
        throw std::out_of_range("Double list is empty.");
    unsigned int start { 0 };
    unsigned int end { 0 };
    end = 0;
    start = (size-1);
    Merge_sort(end, start);
}

template<typename T>
void simply_list<T>::Merge_sort (unsigned int end, unsigned int start)
{
    if (end < start) 
    {
        Merge_sort(end, (end + start) / 2);
        Merge_sort((end + start) / 2 + 1, start);
        Merge (end, start);
    }
}

template<typename T>
void simply_list<T>::Merge (unsigned int end, unsigned int start)
{
    T result [20];
    unsigned int mid { (end + start) / 2 };
    unsigned int left_one { end };
    unsigned int left_two { mid + 1 };
    unsigned int search_1 { 0 };
    node* head_class = head;
    while (search_1 < end)
    {
        head_class = head_class->next_pointer;
        search_1++;
    }
    unsigned int search_2 { search_1 };
    node* var_head = head_class;
    while (search_2 < left_two)
    {
        var_head = var_head->next_pointer;
        search_2++;
    }

    while (search_1 < start + 1)
    {
        if ((left_one <= mid) && ((left_two > start) || head_class->value < var_head->value))
        {
            result[search_1] = head_class->value;
            left_one++;
            if (search_1 != start)
                head_class = head_class->next_pointer;
        }
        else {
            result[search_1] = var_head->value;
            left_two++;
            if (search_1 != start)
                var_head = var_head->next_pointer;
        }
        search_1++;
    }
    unsigned int search_3 { 0 };
    node* tmp = this->head;
    while (search_3 < end) 
    {
        tmp = tmp->next_pointer;
        search_3++;
    }
    while (search_3 < start + 1)
    {
        tmp->value = result [search_3];
        tmp = tmp->next_pointer;
        search_3++;
    }
}
#endif //LAB2V2_SIMPLE_LIST_H