#pragma once
#include <iostream>
using namespace std;

class Queue
{
private:
	int count = 0;
	int size = 1;
	int* Queuee;
public:
	void push(int t1);
	int pop();
	int peek();
	int countelement();
	void Delete_Negative_Element();
	void Delete_IN_Diapazon(int start, int end);
	void vyvodelementa(int index);
	~Queue();
	friend bool operator ==(const Queue& struct1, const Queue& struct2)
	{
		if (struct1.count == struct2.count)
		{
			int i = 0;
			do
			{
				if (struct1.Queuee[i] != struct2.Queuee[i]) return false;
				i++;
			} while ((struct1.Queuee[i] == struct2.Queuee[i]) && (i < struct1.count));
		return true;
		};
		return false;
	};

	friend bool operator !=(const Queue& struct1, const Queue& struct2)
	{
		return !(struct1 == struct2);
	};

	friend bool operator > (const Queue& struct1, const Queue& struct2)
	{
		int i = 0;
		if (struct1.count >= struct2.count)
		{
			do
			{
				if (struct1.Queuee[i] < struct2.Queuee[i]) return false;
				else if (struct1.Queuee[i] > struct2.Queuee[i]) return true;
				i++;
			} while ((struct1.Queuee[i] == struct2.Queuee[i]) && (i < struct2.count));
			if (struct1.count > struct2.count) return true;
			else return false;
		}
		else
		{
			do
			{
				if (struct1.Queuee[i] < struct2.Queuee[i]) return false;
				else if (struct1.Queuee[i] > struct2.Queuee[i]) return true;
				i++;
			} while ((struct1.Queuee[i] == struct2.Queuee[i]) && (i < struct2.count));
		}
		return false;
	};

	friend bool operator < (const Queue& struct1, const Queue& struct2)
	{

		int i = 0;
		if (struct1.count >= struct2.count)
		{
			do
			{
				if (struct1.Queuee[i] < struct2.Queuee[i]) return true;
				else if (struct1.Queuee[i] > struct2.Queuee[i]) return false;
				i++;
			} while ((struct1.Queuee[i] == struct2.Queuee[i]) && (i < struct2.count));
			if (struct1.count > struct2.count) return false;
			else return true;
		}
		else
		{
			do
			{
				if (struct1.Queuee[i] < struct2.Queuee[i]) return false;
				else if (struct1.Queuee[i] > struct2.Queuee[i]) return true;
				i++;
			} while ((struct1.Queuee[i] == struct2.Queuee[i]) && (i < struct1.count));
		}
		return false;
	};

	friend bool operator <= (const Queue& struct1, const Queue& struct2)
	{
		return !(struct1 > struct1);
	};

	friend bool operator >= (const Queue& struct1, const Queue& struct2)
	{
		return !(struct1 < struct1);
	};
};

void Queue::vyvodelementa(int index)
{
	if (index > (count-1))//If we want to call an element that doesn't exist
		throw std::range_error("No this element");
	cout << Queuee[index] << " ";
}

void Queue::push(int t1)
{
	if ((count+1) > size)
	{
		if (count == 0)
			Queuee = new int[size];
		int *Mass;
		size = size + 5;
		Mass = new int[size];
		for (int i = 0; i < size; i++)
		Mass[i] = Queuee[i];
		Mass[count] = t1;
		delete[]Queuee;
		Queuee = Mass;
		count++;
	}
	else {
			if (count == 0)
				Queuee = new int[size];
			Queuee[count] = t1;
			count++;
		}
};

int Queue::pop()
{
	if (count < 1)
		throw std::range_error("Leaving the queue");
	int ourelement=Queuee[0];
	size--;//No cleanup of memory used
	int* Mass;
	Mass = new int[size];
	for (int i = 0; i < size; i++)
		Mass[i] = Queuee[i+1];
	delete[]Queuee;
	Queuee = Mass;
	count--;
	return ourelement;
};

int Queue::peek()
{
	if (count < 1)
		throw std::range_error("Leaving the queue");
	return Queuee[0];
};

int Queue::countelement()
{
	return count;
}

void Queue::Delete_Negative_Element()
{
	for (int i = 0; i < count; i++)
	{
		if (Queuee[i] < 0)
		{
			if (i == count)
			{
				count--;
			}//Preventing out-of-bounds
			else {
				for (int j = i; j < count; j++)
				{
					Queuee[j] = Queuee[j + 1];
				}
			}
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Queuee[i] << " ";
};

void Queue::Delete_IN_Diapazon(int start, int end)
{
	for (int i = 0; i < count; i++)
	{
		if ((Queuee[i] >= start) && (Queuee[i] <= end))
		{
			if (i == count)
			{
				count--;
			}//Preventing out-of-bounds
			else {
				for (int j = i; j < count; j++)
				{
					Queuee[j] = Queuee[j + 1];
				}
				}
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Queuee[i] << " ";
};
Queue::~Queue()
{
	delete [] Queuee;
};