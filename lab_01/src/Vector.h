#pragma once
using namespace std;

class Vector
{
private:
	int count;
	int size = 20;
	int* Vector;
	int* ptr = Vector;
public:
	void Buffer();
	void push(int t1, int index);
	int pop();
	int sort();
	int at(int index);
	void countelement();
	void peek();
	void vyvodelementa(int index);
	int sortdiapazon(int start, int end);
};

void Vector::vyvodelementa(int index)
{
	cout << Vector[index] << " ";;
}
void Vector::Buffer()
{
	Vector = new int[size];
};

void Vector::push(int t1, int index)
{
	count++;
	Vector[index] = t1;
};

int Vector::pop()
{
	if (size < 1)
		throw std::range_error("Выход за пределы массива");
	count--;
	return Vector[count];
	
};

int Vector::at(int index)
{
	if (index > count)
		throw std::range_error("Выход за пределы массива");
	cin >> Vector[index];

};

void Vector::peek()
{
	if (count <1)
		throw std::range_error("Выход за пределы массива");
	cout << Vector[0] << endl;
};

void Vector::countelement()
{
	cout << count << endl;
};

int Vector::sort()
{
	for (int i = 0; i < count; i++)
	{
		if (Vector[i] < 0)
		{
			for (int j = i; j < count; j++)
				Vector[j] = Vector[j + 1];
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Vector[i] << " ";
	return count;
};

int Vector::sortdiapazon(int start, int end)
{
	for (int i = 0; i < count; i++)
	{
		if ((Vector[i] >= start) && (Vector[i] <= end))
		{
			for (int j = i; j < count; j++)
			{
				Vector[j] = Vector[j + 1];
			}
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Vector[i] << " ";
	cout << endl;
	return count;
};
