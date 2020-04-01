#pragma once
#include <iostream>
using namespace std;

class Vector
{
private:
	int count = 0;
	int size = 5;
	int* Vectorr;
public:
	void push(int t1);
	int pop();
	int& at(int index);
	int countelement();
	int peek();
	void vyvodelementa(int index);
	void Delete_Negative_Element();
	void Delete_IN_Diapazon(int start, int end);
	~Vector();
	friend bool operator ==(const Vector& struct1, const Vector& struct2) 
	{
		if (struct1.count == struct2.count)
		{
			int i = 0;
			do
			{
				if (struct1.Vectorr[i] != struct2.Vectorr[i]) return false;
				i++;
			} while ((struct1.Vectorr[i] == struct2.Vectorr[i]) && (i < struct1.count));
		return true;
		};
		return false;
	};

	friend bool operator !=(const Vector& struct1, const Vector& struct2)
	{
		return !(struct1 == struct2);
	};

	friend bool operator > (const Vector& struct1, const Vector& struct2)
	{
		int i = 0;
		if (struct1.count >= struct2.count) 
		{
			do 
			{
				if (struct1.Vectorr[i] < struct2.Vectorr[i]) return false;
				else if (struct1.Vectorr[i] > struct2.Vectorr[i]) return true;
				i++;
			} while ((struct1.Vectorr[i] == struct2.Vectorr[i]) && (i < struct2.count));
			if (struct1.count > struct2.count) return true;
			else return false;
		}
		else
		{
			do
			{
				if (struct1.Vectorr[i] < struct2.Vectorr[i]) return false;
				else if (struct1.Vectorr[i] > struct2.Vectorr[i]) return true;
				i++;
			} while ((struct1.Vectorr[i] == struct2.Vectorr[i]) && (i < struct2.count));
		}
		return false;
	};

	friend bool operator < (const Vector& struct1, const Vector& struct2) 
	{

		int i = 0;
		if (struct1.count >= struct2.count)
		{
			do
			{
				if (struct1.Vectorr[i] < struct2.Vectorr[i]) return true;
				else if (struct1.Vectorr[i] > struct2.Vectorr[i]) return false;
				i++;
			} while ((struct1.Vectorr[i] == struct2.Vectorr[i]) && (i < struct2.count));
			if (struct1.count > struct2.count) return false;
			else return true;
		}
		else
		{
			do
			{
				if (struct1.Vectorr[i] < struct2.Vectorr[i]) return false;
				else if (struct1.Vectorr[i] > struct2.Vectorr[i]) return true;
				i++;
			} while ((struct1.Vectorr[i] == struct2.Vectorr[i]) && (i < struct1.count));
		}
		return false;
	};

	friend bool operator <= (const Vector& struct1, const Vector& struct2) 
	{
		return !(struct1 > struct1);
	};

	friend bool operator >= (const Vector& struct1, const Vector& struct2) 
	{
		return !(struct1 < struct1);
	};

};


void Vector::vyvodelementa(int index)
{
	if (index > (count-1))//If we want to call an element that doesn't exist
		throw std::range_error("No this element");
	cout << Vectorr[index] << " ";
}

void Vector::push(int t1)
{
	if ((count + 1) > size)
	{
		if (count==0)
			Vectorr = new int[size];
		int* Mass;
		size = size + 5;
		Mass = new int[size];
		for (int i = 0; i < size; i++)
			Mass[i] = Vectorr[i];
		Mass[count] = t1;
		delete[]Vectorr;
		Vectorr = Mass;
		count++;
	}
	else { 
		if (count == 0)
			Vectorr = new int[size];
		Vectorr[count] = t1; 
		count++;
	}
	
};

int Vector::pop()
{
	if (count < 1)
		throw std::range_error("Going beyond the vector");
	int vozvrat = Vectorr[count-1];
	size--;//No cleanup of memory used
	int* Mass;
	Mass = new int[size];
	for (int i = 0; i < size; i++)
		Mass[i] = Vectorr[i];
	delete[]Vectorr;
	Vectorr = Mass;
	count--;
	return vozvrat;
};

int& Vector::at(int index)
{
	if (index > count)
		throw std::range_error("Going beyond the vector");
	return Vectorr[index];
};

int Vector::peek()
{
	if (count < 1)
		throw std::range_error("Going beyond the vector");
	return Vectorr[0];
};

int Vector::countelement()
{
	return count;
};

void Vector::Delete_Negative_Element()
{
	for (int i = 0; i < count; i++)
	{
		if (Vectorr[i] < 0)
		{
			if (i == count)
			{
				count--;
			}//Preventing out-of-bounds
			else {
				for (int j = i; j < count; j++)
				{
					Vectorr[j] = Vectorr[j + 1];
				}
			}
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Vectorr[i] << " ";
};

void Vector::Delete_IN_Diapazon(int start, int end)
{
	for (int i = 0; i < count; i++)
	{
		if ((Vectorr[i] >= start) && (Vectorr[i] <= end))
		{
			for (int j = i; j < count; j++)
			{
				if (j = count)
				{
					count--;
				}
				Vectorr[j] = Vectorr[j + 1];
			}
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Vectorr[i] << " ";
	cout << endl;
};



Vector::~Vector()
{
	delete[] Vectorr;
};