#pragma once
class Stack
{
private:
	int count = 0;
	int size = 20;
	int* Stack;
	int* ptr = Stack;
public:
	void Buffer();
	void push(int t1);
	int pop();
	void peek();
	void countelement();
	int sort();
	int sortdiapazon(int start, int end);
};

void Stack::Buffer()
{
	Stack = new int[size];
};

void Stack::push(int t1)
{

	Stack[count] = t1;
	cout << Stack[count] << " ";
	count++;
};

int Stack::pop()
{
	if (count < 1)
		throw std::range_error("Выход за пределы массива");
	count--;
	return Stack[count];
};

void Stack::peek()
{
	cout << Stack[count-1] << endl;
};

void Stack::countelement()
{

	if (count < 1)
		throw std::range_error("Выход за пределы массива");
	cout << count << endl;
};

int Stack::sort()
{
	for (int i = 0; i < count; i++)
	{
		if (Stack[i] < 0)
		{
			for (int j = i; j < count; j++)
				Stack[j] = Stack[j + 1];
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Stack[i] << " ";
	return count;
};

int Stack::sortdiapazon(int start, int end)
{
	for (int i = 0; i < count; i++)
	{
		if ((Stack[i] >= start) && (Stack[i] <= end))
		{
			for (int j = i; j < count; j++)
			{
				Stack[j] = Stack[j + 1];
			}
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Stack[i] << " ";
	return count;
};