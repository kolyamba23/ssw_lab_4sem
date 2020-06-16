# pragma once
#include <iostream>
using namespace std;

class Stack
{
private:
	unsigned int count { 0 };
	unsigned int size { 0 };
public:
	Stack() = default;
	~Stack();
	int* buffer{ nullptr };
	void push(int t1);
	int pop();
	int peek();
	int countelement();
	void Delete_Negative_Element();
	void Delete_IN_Diapazon(int start, int end);
	void vyvodelementa(int index);
	bool operator == (const Stack & struct2)
	{
		if (count == struct2.count)
		{
			int i = count;
			do
			{
				if (buffer[i] != struct2.buffer[i]) return false;
				i--;
			} while ((buffer[i] == struct2.buffer[i]) && (i != 0));
			return true;
		}
		else return false;
	};

	bool operator !=(const Stack& struct2)
	{
		return !(*this == struct2);
	};

	bool operator > (const Stack& struct2)
	{
		int i = count-1;
		int j = struct2.count-1;
		if (count >= struct2.count)
		{	
			do
			{
				if (buffer[i] < struct2.buffer[j]) return false;
				else if (buffer[i] > struct2.buffer[j]) return true;
				i--;
				j--;
			} while ((buffer[i] == struct2.buffer[j]) && (j != 0));
			if (count > struct2.count) return true;
			else return false;
		}
		else
		{
			do
			{
				if (buffer[i] < struct2.buffer[j]) return false;
				else if (buffer[i] > struct2.buffer[j]) return true;
				i--;
				j--;
			} while ((buffer[i] == struct2.buffer[j]) && (i != 0));
			return false;
		}
		
	};

	bool operator < (const Stack& struct2)
	{
		int i = count-1;
		int j = struct2.count-1;
		if (count >= struct2.count)
		{
			
			do
			{
				if (buffer[i] < struct2.buffer[j]) return true;
				else if (buffer[i] > struct2.buffer[i]) return false;
				i--;
				j--;
			} while ((buffer[i] == struct2.buffer[i]) && (i != 0));
			if (count > struct2.count) return false;
			else return true;
		}
		else
		{
			do
			{
				if (buffer[i] < struct2.buffer[j]) return true;
				else if (buffer[i] > struct2.buffer[j]) return false;
				i--;
				j--;
			} while ((buffer[i] == struct2.buffer[j]) && (j != 0));
			return true;
		}
		
	};

	bool operator <= ( const Stack& struct2)
	{
		return !(*this > struct2);
	};

	bool operator >= (const Stack& struct2)
	{
		return !(*this < struct2);
	};
};


Stack::~Stack()
{delete[] buffer;};

void Stack::vyvodelementa(int index)
{
	if (index > (count - 1))//If we want to call an element that doesn't exist
		throw std::range_error("No this element");
	cout << buffer[index] << " ";
}

void Stack::push(int t1)
{
	if (count == 0 && size == 0)
	{
		size = size + 1;
		buffer = new int[size];
	}

	if ((count + 1) > size)
	{
		int* Mass;
		size = size + 2;
		Mass = new int[size];
		for (int i = 0; i < size; i++)
			Mass[i] = buffer[i];
		Mass[count] = t1;
		delete[]buffer;
		buffer = Mass;
		count++;
	}
	else 
	{
		buffer[count] = t1;
		count++;
	}
};

int Stack::pop()
{
	if (count < 1)
		throw std::range_error("Going beyond the vector");
	int vozvrat = buffer[count - 1];
	if (size != 1)
	size--;//No cleanup of memory used
	int* Mass;
	Mass = new int[size];
	for (int i = 0; i < count; i++)
		Mass[i] = buffer[i];
	delete[]buffer;
	buffer = Mass;
	count--;
	return vozvrat;
};

int Stack::peek()
{
	return buffer[count - 1];
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
		if (buffer[i] < 0)
		{
			if (i == count)
			{
				count--;
			}//Preventing out-of-bounds
			else {
				for (int j = i; j < count; j++)
				{
					buffer[j] = buffer[j + 1];
				}
			}
			count--;
			i--;
		}
	}
};

void Stack::Delete_IN_Diapazon(int start, int end)
{
	for (int i = 0; i < count; i++)
	{
		if ((buffer[i] >= start) && (buffer[i] <= end))
		{
			if (i == count)
			{
				count--;
			}//Preventing out-of-bounds
			else {
				for (int j = i; j < count; j++)
				{
					buffer[j] = buffer[j + 1];
				}
			}
			count--;
			i--;
		}
	}
};