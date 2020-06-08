# pragma once
#include <iostream>
using namespace std;

class Vector
{
private:
	unsigned int count { 0 };
	unsigned int size { 1 };
	int* buffer;
public:
	Vector();
	~Vector();
	void push(int t1);
	int pop();
	int& at(int index);
	int countelement();
	int peek();
	void vyvodelementa(int index);
	void Delete_Negative_Element();
	void Delete_IN_Diapazon(int start, int end);
	bool operator == (const Vector & struct2)
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

	bool operator !=(const Vector& struct2)
	{
		return !(*this==struct2);
	};

	bool operator > (const Vector& struct2)
	{
		int i = 0;
		if (count >= struct2.count)
		{
			do
			{
				if (buffer[i] < struct2.buffer[i]) return false;
				else if (buffer[i] > struct2.buffer[i]) return true;
				i++;
			} while ((buffer[i] == struct2.buffer[i]) && (i < (struct2.count-1)));
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

	bool operator < (const Vector& struct2)
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

	bool operator <= (const Vector& struct2)
	{
		return !(*this > struct2);
	};

	bool operator >= (const Vector& struct2)
	{
		return !(*this < struct2);
	};

};

Vector::Vector()
{};

Vector::~Vector()
{delete[] buffer;};

void Vector::vyvodelementa(int index)
{
	if (index > (count - 1))//If we want to call an element that doesn't exist
		throw std::range_error("No this element");
	cout << buffer[index] << " ";
}

void Vector::push(int t1)
{
	if ((count + 1) > size)
	{
		if (count == 0)
			buffer = new int[size];
		int* Mass;
		size = size + 5;
		Mass = new int[size];
		for (int i = 0; i < size; i++)
			Mass[i] = buffer[i];
		Mass[count] = t1;
		delete[]buffer;
		buffer = Mass;
		count++;
	}
	else {
		if (count == 0)
			buffer = new int[size];
		buffer[count] = t1;
		count++;
	}

};

int Vector::pop()
{
	if (count < 1)
		throw std::range_error("Going beyond the vector");
	int vozvrat = buffer[count - 1];
	size--;//No cleanup of memory used
	int* Mass;
	Mass = new int[size];
	for (int i = 0; i < size; i++)
		Mass[i] = buffer[i];
	delete[]buffer;
	buffer = Mass;
	count--;
	return vozvrat;
};

int& Vector::at(int index)
{
	if (index > count)
		throw std::range_error("Going beyond the vector");
	return buffer[index];
};

int Vector::peek()
{
	if (count < 1)
		throw std::range_error("Going beyond the vector");
	return buffer[0];
};

int Vector::countelement()
{
	return count;
};

void Vector::Delete_Negative_Element()
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

	for (int i = 0; i < count; i++)
		cout << buffer[i] << " ";
};

void Vector::Delete_IN_Diapazon(int start, int end)
{
	for (int i = 0; i < count; i++)
	{
		if ((buffer[i] >= start) && (buffer[i] <= end))
		{
			for (int j = i; j < count; j++)
			{
				if (j = count)
				{
					count--;
				}
				buffer[j] = buffer[j + 1];
			}
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << buffer[i] << " ";
	cout << endl;
};



