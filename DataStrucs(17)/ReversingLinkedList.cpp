#include <iostream>
#include <vector>
#include <array>
#include <math.h>

using namespace std;

struct Node
{
	int data;
	Node* next = nullptr;
};

//template <class T>

Node* revList(Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	if (head->next->next == NULL)
	{
		head->next->next = head;
		return head->next;
	}
	else

	revList(head->next);
	head->next->next = head;
}

void realRev(Node* head)
{
	revList(head);

	head->next = NULL;
}


void displayList(Node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

int main()
{
	Node one;
	one.data = 1;	
	Node two;
	two.data = 2;
	Node three;
	three.data = 3;
	Node four;
	four.data = 4;

	one.next = &two;
	two.next = &three;
	three.next = &four;
	
	realRev(&one);

	displayList(&four);

	cin.get();
}