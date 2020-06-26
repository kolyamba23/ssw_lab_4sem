#pragma once
#include <iostream>
using namespace std;

class Queue
{
private:
	
	unsigned int count { 0 };
	unsigned int size { 0 };
	int* buffer{ nullptr };
public:
	Queue() = default;
	~Queue();
	void push(int t1);
	int pop();
	int peek();
	int countelement();
	void Delete_Negative_Element();
	void Delete_IN_Diapazon(int start, int end);
	void vyvodelementa(int index);
	bool operator == (const Queue & struct2)
	{ 
		if (count == struct2.count)
		{
			int i = 0;
			do
			{
				if (buffer[i] != struct2.buffer[i]) return false;
 i++;
 } while ((buffer[i] == struct2.buffer[i]) && (i < count));
		return true;
		};
		return false;
	};

	bool operator !=(const Queue& struct2)
	{
		return !(*this == struct2);
	};

	bool operator > (const Queue& struct2)
	{
		int i = 0;
		if (count >= struct2.count)
		{
			do
			{
				if (buffer[i] < struct2.buffer[i]) return false;
				else if (buffer[i] > struct2.buffer[i]) return true;
				i++;
			} while ((buffer[i] == struct2.buffer[i]) && (i < struct2.count));
			if (count > struct2.count) return true;
			else return false;
		}
		else
		{
			do
			{
				if (buffer[i] < struct2.buffer[i]) return false;
				else if (buffer[i] > struct2.buffer[i]) return true;
				i++;
			} while ((buffer[i] == struct2.buffer[i]) && (i < struct2.count));
		}
		return false;
	};

	bool operator < (const Queue& struct2)
	{

		int i = 0;
		if (count >= struct2.count)
		{
			do
			{
				if (buffer[i] < struct2.buffer[i]) return true;
				else if (buffer[i] > struct2.buffer[i]) return false;
				i++;
			} while ((buffer[i] == struct2.buffer[i]) && (i < struct2.count));
			if (count > struct2.count) return false;
			else return true;
		}
		else
		{
			do
			{
				if (buffer[i] < struct2.buffer[i]) return true;
				else if (buffer[i] > struct2.buffer[i]) return false;
				i++;
			} while ((buffer[i] == struct2.buffer[i]) && (i < count));
		}
		return true;
	};

	bool operator <= (const Queue& struct2)
	{
		return !(*this > struct2);
	};

	bool operator >= (const Queue& struct2)
	{
		return !(*this < struct2);
	};
};

Queue::~Queue()
{
	delete[] buffer;
};

void Queue::vyvodelementa(int index)
{
	if (index > (count - 1))//If we want to call an element that doesn't exist
		throw std::range_error("No this element");
	cout << buffer[index] << " ";
}

void Queue::push(int t1)
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
		for (int i = 0; i < count; i++)
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

int Queue::pop()
{
	if (count < 1)
		throw std::range_error("Leaving the queue");
	int ourelement = buffer[0];
	if (size != 1)
	size--;//No cleanup of memory used
	int* Mass;
	Mass = new int[size];
	for (int i = 0; i < count; i++)
		Mass[i] = buffer[i + 1];
	delete[]buffer;
	buffer = Mass;
	count--;
	return ourelement;
};

int Queue::peek()
{
	if (count < 1)
		throw std::range_error("Leaving the queue");
	return buffer[0];
};

int Queue::countelement()
{
	return count;
}

void Queue::Delete_Negative_Element()
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

void Queue::Delete_IN_Diapazon(int start, int end)
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
