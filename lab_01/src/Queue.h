#pragma once
class Queue
{
private:
	int size = 20;
	int count = 0;
	int* ptr = Queue;
	int* Queue;
public:
	void Buffer();
	void push(int t1);
	int pop();
	void peek();
	void countelement();
	int sort();
    int sortdiapazon(int start, int end);
};

void Queue::Buffer()
{
	Queue = new int[count];
}

void Queue::push(int t1)
{

	Queue[count] = t1;
	cout << Queue[count] << " ";
	count++;
};

int Queue::pop()
{
	if (count < 1)
		throw std::range_error("Выход за пределы массива");
	return Queue[0];
	for (int i = 0; i < count; i++)
	{
		Queue[i] = Queue[i + 1];
	}
};

void Queue::peek()
{
	if (count<1)
		throw std::range_error("Выход за пределы массива");
	cout << Queue[0] << endl;
};

void Queue::countelement()
{
	cout << count << endl;
}

int Queue::sort()
{
	for (int i = 0; i < count; i++)
	{
		if (Queue[i] < 0)
		{
			for (int j = i; j < count; j++)
				Queue[j] = Queue[j + 1];
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Queue[i] << " ";
	return count;
};

int Queue::sortdiapazon(int start, int end)
{
	for (int i = 0; i < count; i++)
	{
		if ((Queue[i] >= start) && (Queue[i] <= end))
		{
			for (int j = i; j < count; j++)
			{
				Queue[j] = Queue[j + 1];
			}
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Queue[i] << " ";
	return count;
};