#include <iostream>
using namespace std;

class heap
{
private:
	int* arr;
	int size, count;
	void max_heapify_down(int root) {
		int largest = root;
		int left = (root * 2) + 1;
		int right = (root * 2) + 2;

		if (left < count && arr[left] > arr[largest])
		{
			largest = left;
		}
		if (right < count && arr[right] > arr[largest])
		{
			largest = right;
		}
		if (largest != root)
		{
			swap(arr[largest], arr[root]);
			max_heapify_down(largest);
		}

	}
	void max_heapify_up(int root) {
		int largest = root;
		int parent = (root - 1) / 2;
		if (arr[parent] < arr[largest])
		{
			largest = parent;
		}
		if (largest != root)
		{
			swap(arr[root], arr[largest]);
			max_heapify_up(largest);
		}
	}
public:
	heap(int s)
	{
		size = s;
		arr = new int[size];
		count = 0;
	}
	bool isEmpty()
	{
		return (count == 0);
	}
	bool isFull()
	{
		return (count == size);
	}
	int getMini()
	{
		if (isEmpty())
		{
			return -1;
		}
		return arr[0];
	}
	int extractMax()
	{
		int temp = arr[0];

		swap(arr[0], arr[count - 1]);
		count--;
		max_heapify_down(0);
		return temp;
	}
	void insert(int value)
	{
		if (isFull())
		{
			cout << "Heap is Full" << endl;
		}
		else
		{
			count++;
			arr[count - 1] = value;
			max_heapify_up(count - 1);
		}
	}
	void display()
	{
		for (int i = 0; i < count; i++)
		{
			cout << arr[i] << " ";
		}
	}
	void Find_K(int *& arr)
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = extractMax();
		}
		int K;
		cout << "Enter number of largest elements to find: ";
		cin >> K;
		if (K > size)
		{
			cout << "Wrong input" << endl;
			return;
		}
		else
		{
			for (int i = 0; i < K; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
};
int main()
{
	int size, val;
	cout << "Enter size: ";
	cin >> size;
	heap H(size);
	cout << "Enter Values: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> val;
		H.insert(val);
	}
	cout << "\nHeap is: ";
	H.display();

	int* arr;
	arr = new int[size];

	cout << endl;
	H.Find_K(arr);

	system("pause");
	return 0;
}
