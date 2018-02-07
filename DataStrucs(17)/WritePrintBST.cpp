#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};

void display(Node* head)
{
	if (head == nullptr)
		return;
	display(head->left);
	cout << head->data << " ";
	display(head->right);
}

int main()
{
	Node grandpa;
	grandpa.data = 23;
	Node dad;
	dad.data = 54;
	Node mom;
	mom.data = 17;
	Node child1;
	child1.data = 10;
	Node child2;
	child2.data = 20;
	Node child3;
	child3.data = 32;
	Node child4;
	child4.data = 65;


	grandpa.left = &mom;
	grandpa.right = &dad;
	mom.left = &child1;
	mom.right = &child2;
	dad.left = &child3;
	dad.right = &child4;

	display(&grandpa);
	cin.get();
}