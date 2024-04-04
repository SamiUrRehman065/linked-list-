#include<iostream>
using namespace std;

// Node structure to represent a single node in the linked list
struct node {
	int data;   // Data of the node
	node*link;  // Pointer to the next node
};


// Function to insert a node at the beginning of the linked list
void insertAtHead(node* &head, int value) {
	// Creating a new node with the given data
	node* new_node= new node;
	new_node->data= value;
	// Check if the list is empty
	if (head == NULL) {
		new_node->link=NULL;
		head = new_node;
		cout << "List is empty thats why Inserted at the head:" << endl;
	} else {
		// Set the new node's link to the current head
		new_node->link=head;
		// Update the head to the new node
		head=new_node;
		cout<<"Insertion at head done successfully: "<<endl;
	}
}



// Function to insert a node at the end of the linked list
void insertAtTail(node* &head, int value) {
	// Creating a new node with the given data
	node* new_node= new node;
	new_node->data= value;
	new_node->link=NULL;
	// Check if the list is empty
	if (head == NULL) {
		head = new_node;
		cout << "Insertion at tail done successfully:" << endl;
		return;
	}
	// Traverse to the end of the list
	node* temp=head;
	while(temp->link!=NULL) {
		temp= temp->link;
	}
	// Add the new node to the end of the list
	temp->link= new_node;
	cout<<"Insertion at tail done successfully: "<<endl;
}



// Function to insert a node at a specific position in the linked list
void insertAtPosition(node* &head, int value , int pos) {
	// Creating a new node with the given data
	node* new_node= new node;
	new_node->data= value;
	// Check if insertion is at the beginning or if list is empty
	if(head == NULL || pos==0) {
		insertAtHead(head, value);
		return;
	}
	// Traverse to the position before the specified position
	node* temp = head;
	int currentposition=0;
	while(currentposition!=pos-1) {
		temp=temp->link;
		currentposition++;
	}
	// If the list is beyound the given position than insert at tail
	if (temp == NULL) {
		insertAtTail(head, value);
	} else {
		// Insert the new node at the specified position
		new_node->link=temp->link;
		temp->link= new_node;
		cout<<"Insertion at position "<<pos<<" done successfully: "<<endl;
	}
}



// Function to print the elements of the linked list
void print(node* head) {

	node* temp= head;
	while(temp!=NULL) {
		cout<<temp->data<<"->";
		temp= temp->link;
	}
	cout<<"NULL"<<endl;
}



// Function to delete the node at the beginning of the linked list
void deleteAtHead(node* &head) {
	// Check if the list is empty
	if (head==NULL) {
		cout << "List is empty Nothing to delete."<< endl;
		return;
	}
	// Store the head node
	node* temp= head;
	// Update the head to the next node
	head =head->link;
	// Delete the previous head node
	delete temp;
	cout<<"Deletion at head done successfully: "<<endl;
}



// Function to delete the node at the end of the linked list
void deleteAtEnd(node* &head) {
	// Check if the list is empty
	if (head==NULL) {
		cout << "List is empty Nothing to delete."<< endl;
		return;
	}
	// Traverse to the second-last node
	node* second_last_node= head;
	while(second_last_node->link->link!=NULL) {
		second_last_node=second_last_node->link;
	}
	// Store the last node
	node* temp=second_last_node->link;
	// Update the second-last node to nullptr, making it the new last node
	second_last_node->link=NULL;
	// Delete the previous last node
	delete temp;
	cout<<"Deletion at end done successfully: "<<endl;
}



// Function to delete the node at a specific position in the linked list
void deleteAtPosition(node* &head, int pos) {
	// Check if the list is empty
	if (head==NULL) {
		cout << "List is empty Nothing to delete at position "<<pos<<" ."<< endl;
		return;
	}
	// Check if the position is at the head
	if(pos==0) {
		deleteAtHead(head);
		return;
	}
	// Traverse to the node before the specified position
	int current_position=0;
	node* previous=head;
	while(current_position!=pos-1) {
		previous=previous->link;
		current_position++;
	}
	// Store the node to be deleted
	node* temp= previous->link;
	// Update the previous node's link to skip the node to be deleted
	previous->link=previous->link->link;
	// Delete the specified node
	delete temp;
	cout<<"Deletion at position "<<pos<<" done successfully: "<<endl;
}



// Function to delete the node with the given data from the linked list
void deleteByData(node* &head, int data) {
	// Check if the list is empty
	if (head == NULL) {
		cout << "List is empty Nothing to delete:" << endl;
		return;
	}
	// Initialize pointers for traversal
	node* current = head;
	node* previous = NULL;
	// Traverse to find the data in the linked list
	while (current != NULL && current->data != data) {
		previous = current;
		current = current->link;
	}
	// Check if the data was not found
	if (current == NULL) {
		cout << "Data " << data << " not found node not deleted:" << endl;
		return;
	}
	// Adjust pointers to skip the node only if current becomes NULL
	if (previous != NULL) {
		previous->link = current->link;
	} else {
		// The node to be deleted is the head node
		head = current->link;
	}
	// Delete the node
	delete current;
	cout << "Deletion of node with data " << data << " done successfully:" << endl;
}



// Function to search for a given data in the linked list
void search(node* head, int data) {
	// Initialize a pointer for traversal
	node* temp= head;
	// Traverse to find the data in the linked list
	while(temp!=NULL) {
		if(temp->data==data) {
			cout<<"Given data "<<data<<" is found: "<<endl;
			return;
		}
		temp=temp->link;
	}
	// Data not found
	cout<<"Given data "<<data<<" is not found: "<<endl;
}



// Function to delete the entire linked list and free memory
void deleteList(node* &head) {
	node* current = head;
	while (current != NULL) {
		node* temp = current;
		current = current->link;
		delete temp;
	}
	head = NULL;
}



int main() {
	node*head= NULL; // Initialize the linked list
	int choice;
	int data , position;
	do {
		// Display menu for linked list operations
		cout<<"-------------------------------------------"<<endl;
		cout<<"      Linked List Related Operations: "<<endl;
		cout<<"-------------------------------------------"<<endl;
		cout<<"1. Insert at beginning of the list. "<<endl;
		cout<<"2. Insert at end of the list. "<<endl;
		cout<<"3. Insert at specific position of the list. "<<endl;
		cout<<"4. Delete at beginning of the list. "<<endl;
		cout<<"5. Delete at end of the list."<<endl;
		cout<<"6. Delete at specific position of the list. "<<endl;
		cout<<"7. Delete by data of the list. "<<endl;
		cout<<"8. Traverse through the data of the list. "<<endl;
		cout<<"9. Search through the data of the list. "<<endl;
		cout<<"0. Exist from the program. "<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>choice;
		// Switch case to perform the selected linked list operation
		switch(choice) {
			case 1:
				cout<<"Enter the data to insert at beginning of the list."<<endl;
				cin>>data;
				insertAtHead(head, data);
				break;
			case 2:
				cout<<"Enter the data to insert at end of the list."<<endl;
				cin>>data;
				insertAtTail(head, data);
				break;
			case 3:
				cout<<"Enter the position for data to insert at the list."<<endl;
				cin>>position;
				cout<<"Enter the data to insert at the list."<<endl;
				cin>>data;
				insertAtPosition(head, data, position);
				break;
			case 4:
				deleteAtHead(head);
				break;
			case 5:
				deleteAtEnd(head);
				break;
			case 6:
				cout<<"Enter the position for data to delete from the list."<<endl;
				cin>>position;
				deleteAtPosition(head, position);
				break;
			case 7:
				cout<<"Enter the data to delete from the list."<<endl;
				cin>>data;
				deleteByData(head, data);
				break;
			case 8:
				cout<<"Linked list. "<<endl;
				print(head);
				break;
			case 9:
				cout<<"Enter the data to search from the list."<<endl;
				cin>>data;
				search(head, data);
				break;
			case 0:
				cout<<"Existing from the program. "<<endl;
				break;
			default:
				cout<<"Invalid choice . Please enter the valid choice."<<endl;
		}
	} while(choice!=0);	// Repeat until the user chooses to exit
	// Free the memory allocated for the linked list before exiting
	deleteList(head);
	return 0;
}
