#include<iostream>
#include<iomanip>

using namespace std;
typedef int Info;

struct Node
{
	Node *next,
		 *prev;
	Info info;
};

void enqueue(Node*& first, Node*& last, Info info)
{
	Node* tmp = new Node;
	tmp->info = info;
	tmp->next = NULL; 
	if (last != NULL)
		last->next = tmp; 
	tmp->prev = last; 
	last = tmp;
	if (first == NULL)
		first = tmp;
}


bool isSublist(Node* L1, Node* L2)
{
	Node* curr1 = L1;
	Node* curr2 = L2;

	// Перебір елементів у списку L2
	while (curr2 != NULL)
	{
		// Зберігаємо початкові позиції
		Node* temp = curr2;

		// Перевірка, чи збігаються елементи списків L1 та L2
		while (curr1 != NULL && curr2 != NULL && curr1->info == curr2->info)
		{
			curr1 = curr1->next;
			curr2 = curr2->next;
		}

		// Якщо досягнуто кінця L1, то L1 є підсписком L2
		if (curr1 == NULL)
			return true;

		// Повертаємо curr2 та curr1 до початкових позицій
		curr1 = L1;
		curr2 = temp->next;
	}

	// L1 не є підсписком L2
	return false;
}

void printList(Node* head) {
	Node* currNode = head;
	while (currNode != NULL) {
		cout << currNode->info << " ";
		currNode = currNode->next;
	}
	cout << endl;
}


int main()
{
	Node* FirstL1 = NULL; // Список L1
	Node* LastL1 = NULL; 

	Node* FirstL2 = NULL; // Список L2
	Node* LastL2 = NULL; 

	// Заповнення списків L1 та L2
	enqueue(FirstL1, LastL1, 1);
	enqueue(FirstL1, LastL1, 2);
	enqueue(FirstL1, LastL1, 3);

	enqueue(FirstL2, LastL2, 1);
	enqueue(FirstL2, LastL2, 2);
	enqueue(FirstL2, LastL2, 3);
	enqueue(FirstL2, LastL2, 4);
	enqueue(FirstL2, LastL2, 5);
	
	//Друкування списків L1 і L2
	cout << "List 1: "; 
	printList(FirstL1);

	cout << "List 2: ";
	printList(FirstL2);

	// Перевірка, чи є L1 частиною L2
	if (isSublist(FirstL1, FirstL2))
		cout << "L1 is a part of L2" << endl;
	else
		cout << "L1 is not a part of L2" << endl;

	return 0;
}