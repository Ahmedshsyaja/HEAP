#include<iostream> 
#include<climits> u
using namespace std; 
void swap(int* x, int* y);
class MinHeap
{
	int* Node; int size; int heapSize; public:
		MinHeap(int n)
		{
			heapSize = 0; size = n;
			Node = new int[n];
		}
		void decreaseKey(int a, int n)
		{
			Node[a] = n;
			while (a != 0 && Node[parent(a)] > Node[a])
			{
				swap(&Node[a], &Node[parent(a)]);
				a = parent(a);
			}
		}
		void MinHeapify(int a)
		{
			int l = left(a); int r = right(a); int smallest = a;
			if (l < heapSize && Node[l] < Node[a])
			{
				smallest = l;
			}
			if (r < heapSize && Node[r] < Node[smallest])
			{
				smallest = r;
			} if (smallest != a)
			{
				swap(&Node[a], &Node[smallest]);
				MinHeapify(smallest);
			}
		} int parent(int a)
		{
			return (a - 1) / 2;
		} int left(int a)
		{
			return (2 * a + 1);
		} int right(int a)
		{
			return (2 * a + 2);
		} int extractMin()
		{
			if (heapSize <= 0)
			{
				return INT_MAX;
			} if (heapSize == 1)
			{
				heapSize--; return Node[0];
			}
			int root = Node[0];
			Node[0] = Node[heapSize - 1];
			heapSize--; MinHeapify(0); return root;
		} int getMin()
		{
			if (heapSize == 0)
			{
				return -1;
			}
			else
			{
				return Node[0];
			}
		}
		void deleteKey(int a)
		{
			decreaseKey(a, INT_MIN);
			extractMin();
		}
		void insertKey(int a)
		{
			if (heapSize == size)
			{
				cout << "Size has been increased\n";
				return;
			} heapSize++; int i = heapSize - 1;
			Node[i] = a;
			while (i != 0 && Node[parent(i)] > Node[i])
			{
				swap(&Node[i], &Node[parent(i)]);
				i = parent(i);
			}
		}
};
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
	int choose, p, val;
	cout << "Enter total capacity for the heap?\n";
	cin >> p;
	MinHeap a(p);
	do {
		cout << "1) Get Minimum\n2) Extract Minimum\n3) Decrease Key\n4) Insert\n5) Delete\n6) Exit "; 
		cout << endl; cin >> choose; switch (choose) { case 1:
{ p = a.getMin(); if (p == -1)
		{
			cout << "The Heap is Empty!" << endl;
		}
else
{
	cout << "Minimum Key available in  the heap:" << p << endl;
} break;
} case 2:
		{ cout << "The Minimum extracted value:" << a.extractMin() << endl;
		break;
		} case 3:
		{ cout << "Enter the value you want to decrease?" << endl;
		cin >> p;
		cout << "Enter Your new value to decrease?" << endl;
		cin >> val;
		a.decreaseKey(p, val);
		break;
		} case 4:
		{ cout << "Enter value to insert:" << endl;
		cin >> p;
		a.insertKey(p); break;
		} case 5:
		{ cout << "Enter value to delete:" << endl;
		cin >> p;
		a.deleteKey(p); break;
		} case 6:
		{ choose = 6;
		} default: break;
	}
} while (choose != 6);
return 0;
}
