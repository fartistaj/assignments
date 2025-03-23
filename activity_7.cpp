#include <iostream>

struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node* head;

public:
	LinkedList()
	{
		head = nullptr;
	}

	~LinkedList()
	{
		Node* current = head;
		while (current != nullptr)
		{
			Node* next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
	}
	
	void insertAtbeginning(int value)
	{
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = head;

		head = newNode;

		std::cout << "Inserted " << value << " at the beginning\n";
	}

	void deleteFromBeginning()
	{
		if (head == nullptr)
		{
			std::cout << "List is emtpy. Nothing to delete.\n";
			
			return;
		}

		Node* temp = head;
		head = head->next;
		std::cout << "Deleted " << temp->data << " from the beginning\n";
		delete temp;
	}

	void display()
	{
		if (head == nullptr)
		{
			std::cout << "List is empty\n";
			return;
		}

		Node* current = head;
		std::cout << "List: ";
		while (current != nullptr)
		{
			std::cout << current->data << " -> ";
			current = current->next;
		}
		std::cout << "NULL\n";
	}
};

int main()
{
	LinkedList list;

	list.display();

	list.insertAtbeginning(10);
	list.insertAtbeginning(20);
	list.insertAtbeginning(30);

	list.display();
	
	list.deleteFromBeginning();

	list.display();

	list.deleteFromBeginning();
	list.deleteFromBeginning();

	list.deleteFromBeginning();

	list.insertAtbeginning(40);
	list.display();

	return 0;
}