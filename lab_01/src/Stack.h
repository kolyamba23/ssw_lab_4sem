#pragma once
#include <iostream>
using namespace std;

class Stack
{
private:
	int count = 0;
	int size = 1;
	int* Stackk;
public:
	void push(int t1);
	int pop();
	int peek();
	int countelement();
	void Delete_Negative_Element();
	void Delete_IN_Diapazon(int start, int end);
	void vyvodelementa(int index);
	~Stack();
	friend bool operator ==(const Stack& struct1, const Stack& struct2)
	{
		if (struct1.count == struct2.count)
		{
			int i = struct1.count;
			do
			{
				if (struct1.Stackk[i] != struct2.Stackk[i]) return false;
				i--;
			} while ((struct1.Stackk[i] == struct2.Stackk[i]) && (i != 0));
			return true;
		}
		else return false;
	};

	friend bool operator !=(const Stack& struct1, const Stack& struct2)
	{
		return !(struct1 == struct2);
	};

	friend bool operator > (const Stack& struct1, const Stack& struct2)
	{
		int i= struct2.count;
		if (struct1.count >= struct2.count)
		{
			i = struct1.count;
			do
			{
				if (struct1.Stackk[i] < struct2.Stackk[i]) return false;
				else if (struct1.Stackk[i] > struct2.Stackk[i]) return true;
				i--;
			} while ((struct1.Stackk[i] == struct2.Stackk[i]) && (i !=0));
			if (struct1.count > struct2.count) return true;
			else return false;
		}
		else
		{
			do
			{
				if (struct1.Stackk[i] < struct2.Stackk[i]) return false;
				else if (struct1.Stackk[i] > struct2.Stackk[i]) return true;
				i--;
			} while ((struct1.Stackk[i] == struct2.Stackk[i]) && (i!=0));
		}
		return false;
	};

	friend bool operator < (const Stack& struct1, const Stack& struct2)
	{

		int i = struct2.count;
		if (struct1.count >= struct2.count)
		{
			do
			{
				if (struct1.Stackk[i] < struct2.Stackk[i]) return true;
				else if (struct1.Stackk[i] > struct2.Stackk[i]) return false;
				i++;
			} while ((struct1.Stackk[i] == struct2.Stackk[i]) && (i != 0));
			if (struct1.count > struct2.count) return false;
			else return true;
		}
		else
		{
			i = struct1.count;
			do
			{
				if (struct1.Stackk[i] < struct2.Stackk[i]) return false;
				else if (struct1.Stackk[i] > struct2.Stackk[i]) return true;
				i++;
			} while ((struct1.Stackk[i] == struct2.Stackk[i]) && (i != 0));
		}
		return false;
	};

	friend bool operator <= (const Stack& struct1, const Stack& struct2)
	{
		return !(struct1 > struct1);
	};

	friend bool operator >= (const Stack& struct1, const Stack& struct2)
	{
		return !(struct1 < struct1);
	};
};

void Stack::vyvodelementa(int index)
{
	if (index > (count - 1))//If we want to call an element that doesn't exist
		throw std::range_error("No this element");
	cout << Stackk[index] << " ";
}

void Stack::push(int t1)
{
	if ((count + 1) > size)
	{
		if (count == 0)
			Stackk = new int[size];
		int* Mass;
		size=size+5;
		Mass = new int[size];
		for (int i = 0; i < size; i++)
			Mass[i] = Stackk[i];
		Mass[count] = t1;
		delete[]Stackk;
		Stackk = Mass;
		count++;
	}
	else {
		if (count == 0)
			Stackk = new int[size];
		Stackk[count] = t1;
		count++;
		}
};

int Stack::pop()
{
	if (count < 1)
		throw std::range_error("Going beyond the vector");
	int vozvrat = Stackk[count - 1];
	size--;//No cleanup of memory used
	int* Mass;
	Mass = new int[size];
	for (int i = 0; i < size; i++)
		Mass[i] = Stackk[i];
	delete[]Stackk;
	Stackk = Mass;
	count--;
	return vozvrat;
};

int Stack::peek()
{
	return Stackk[count-1];
};

int Stack::countelement()
{

	if (count < 1)
		throw std::range_error("Going off the stack");
	return count;
};

void Stack::Delete_Negative_Element()
{
	for (int i = 0; i < count; i++)
	{
		if (Stackk[i] < 0)
		{
			if (i == count)
			{
				count--;
			}//Preventing out-of-bounds
			else {
				for (int j = i; j < count; j++)
				{
					Stackk[j] = Stackk[j + 1];
				}
			}
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Stackk[i] << " ";
};

void Stack::Delete_IN_Diapazon(int start, int end)
{
	for (int i = 0; i < count; i++)
	{
		if ((Stackk[i] >= start) && (Stackk[i] <= end))
		{
			if (i == count)
			{
				count--;
			}//Preventing out-of-bounds
			else {
				for (int j = i; j < count; j++)
				{
					Stackk[j] = Stackk[j + 1];
				}
			}
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Stackk[i] << " ";
};
Stack::~Stack()
{
	delete [] Stackk;
};