
#include<iostream>
#include<queue>
using namespace std;
struct Node {
	Node* left, * right;
	int data;
};
class heap {
public:
	Node* root;
	int size;
	heap();
	void Insertion(int);
	void insertion(int val);
	Node* findNode(int data);
	void preOrder(Node*);
	void conversing(int*);
	bool isCompleat(int*);
	void decreaseKey(int*);
};

heap::heap() {
	root = NULL;
}
void heap::Insertion(int  data) {
	Node* Ptr = new Node;
	Ptr->data = data;
	Ptr->left = NULL;
	Ptr->right = NULL;
	if (root == NULL) {
		root = Ptr;
	}
	else {
		if (findNode(data) == NULL)
		{
			Node* P = root;
			while (P != NULL) {
				if (data > P->data) {
					if (P->right == NULL)
					{
						P->right = Ptr; break;

					}
					P = P->right;
				}
				else {
					if (P->left == NULL) {
						P->left = Ptr; break;
					}
					P = P->left;
				}
			}

		}
		else cout << "\nThis element is also present in BST\n";
	}
}
void heap::insertion(int val) {
	Node* newnode = new Node;
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	queue<Node*> q;
	if (root == NULL)
		root = newnode;
	else
	{
		q.push(root); while (q.size()) {
			Node* temp = q.front();
			q.pop();

			if (temp->left == NULL) {
				temp->left = newnode;
				break;
			}
			else
			{
				q.push(temp->left);
			}
			if (temp->right == NULL) {
				temp->right = newnode; break;

			}
			else
			{
				q.push(temp->right);
			}
		}
	}
}
Node* heap::findNode(int data)
{
	if (root != NULL) {
		if (root->data == data)
			return root;
		else
		{
			queue<Node*> q;
			q.push(root);
			while (!q.empty()) {
				Node* temp = q.front();
				q.pop();
				if (temp->data == data) { return temp; }
				if (temp->left != NULL)
				{
					q.push(temp->left); if (temp->right != NULL)
						q.push(temp->right);
				}
			}
		}
	}
	return NULL;
} void heap::preOrder(Node* root)
{
	if (root == NULL) return;
	cout << root->data << "\t";
	preOrder(root->left);
	preOrder(root->right);
} void heap::conversing(int* ptr)
{

	if (root == NULL) { return; }
	else
	{
		queue<Node*> q;
		q.push(root);
		ptr[size] = root->data;
		size++;
		while (!q.empty()) {
			Node* temp = q.front();
			q.pop(); if (temp->left != NULL)
			{
				q.push(temp->left); ptr[size] = temp->left->data;
				size++;
			}
			else {
				ptr[size] = 0;
				size++;
			}
			if (temp->right != NULL)
			{
				q.push(temp->right);
				ptr[size] = temp->right->data;
				size++;
			}
			else {
				ptr[size] = 0;
				size++;
			}
		}


	}
} bool heap::isCompleat(int* ptr)
{
	bool check = false;
	for (int i = 0; i < size; i++) {
		if (ptr[i] != 0) {
			if (ptr[(i * 2) + 1] == 0) {
				if (ptr[(i * 2) + 2] != 0)
				{
					cout << "\nYour Bst is not compleat\n"; check = true; break;
				}
			}
		}

	} if (check == false) for (int i = 0; i < size; i++)
	{
		if (ptr[i] == 0) {
			for (int j = i + 1; j < size; j++)
			{
				if (ptr[j] != 0) {
					check = true; cout << "\nYour Bst is not compleat\n"; break;
				}
			} if (check == true) break;
		}
	} return check;
} void heap::decreaseKey(int* ptr)
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (ptr[i] < ptr[((i - 1) / 2)])
		{
			swap(ptr[i], ptr[((i - 1) / 2)]);

		}
	}

} int main() {
	int data, choice = 0;
	heap obj;
	int* ptr = new int[obj.size];
	bool check = false;
	while (choice != 4)
	{
		cout << "Press 1 to Add Element\nPress 2 for Min heap\nPress 3 to Display in PreOrder \nPress 4 to End the Program" << endl; cout << "Enter Choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
		{
			cout << "Enter data in BST  :: ";
			cin >> data; obj.Insertion(data);
			break;
		}
		case 2:
		{
			obj.conversing(ptr);
			for (int i = 0; i < obj.size; i++) {
				cout << ptr[i] << "  ";
			}
			check = obj.isCompleat(ptr);
			if (check == false) {
				int z;
				for (z = 0; z < obj.size; z++) {
					if (ptr[z] == 0)
						break;
				}
				obj.size = z;
				obj.decreaseKey(ptr);
				obj.root = NULL;
				for (int i = 0; i < obj.size; i++) {
					obj.insertion(ptr[i]);
				}

			}

			break;
		}
		case 3:
		{
			cout << "Data PreOrder: \n";
			obj.preOrder(obj.root);
			break;
		}
		case 4:
		{
			cout << "Program is ended\n";
			break;
		}
		default:
			cout << "You press wrong key\n";
			break;
		}
		cout << endl << endl;
	}
	system("pause");
}

 
 
Task-5
using namespace std;
class HEAP {
	int heap_size;
	int* arr = NULL;
public:
	HEAP(int size) {
		heap_size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			cout << "Enter value:";
			cin >> arr[i];
		}
	}
	void minheap(int arr[], int i) {
		int left, right, parent = i;
		left = (i * 2) + 1;
		right = (i * 2) + 2;
		if (left < heap_size && arr[left] < arr[parent]) {
			parent = left;
		}
		if (right < heap_size && arr[right] < arr[parent]) {
			parent = right;
		}
		if (parent != i) {
			swap(arr[parent], arr[i]);
			minheap(arr, parent);
		}
	}

	void heapify(int arr[], int i) {
		int left, right, parent = i;
		left = (i * 2) + 1;
		right = (i * 2) + 2;
		if (left < heap_size && arr[left] > arr[parent]) {
			parent = left;
		}
		if (right < heap_size && arr[right] > arr[parent]) {
			parent = right;
		}
		if (parent != i) {
			swap(arr[parent], arr[i]);
			heapify(arr, parent);
		}
	}
	void built_maxHeap(int size) {
		for (int i = size; i >= 0; i--) {
			heapify(arr, i);
		}
	}
	void built_minHeap(int size) {
		for (int i = size; i >= 0; i--) {
			minheap(arr, i);
		}
	}
	void display() {
		for (int i = 0; i < heap_size; i++)
		{
			cout << arr[i] << ", ";
		}
	}
};
int main() {
	int size;
	cout << "Enter size of an array:";
	cin >> size;
	int* arr = new int[size];
	HEAP hp(size);
	hp.built_minHeap(size);
	cout << "min heap:";
	hp.display();
	cout << endl;
	hp.built_maxHeap(size);
	cout << "max heap conversion:";
	hp.display();
	return 0;
}
 
