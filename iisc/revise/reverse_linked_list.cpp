#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *next;		
}*head = NULL;

void insert_node(int data){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	if(head == NULL){
		head = new_node;
	} else {
		// append to the end
		struct node *temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new_node;
	}	
}

void print_list(struct node *head){
	struct node *temp = head;
	while(temp != NULL){
		cout << temp->data << endl;
		temp = temp->next;
	}
}

void reverse_list(struct node **head){
	// a pointer to pointer to struct node is needed because the pointer is passed by value
	// so to modify it in function, **head is used
	// reverse the list
	struct node *curr = *head, *prev = NULL, *next = curr->next;
	while(curr->next != NULL){
		curr->next = prev;
		prev = curr;
		curr = next;
		next = curr->next;	
	}
	// to avoid dereferencing a NULL pointer this last step is added outside the loop
	// point the last node to its previous but leave next unmodified
	curr->next = prev;
	// point to new head
	*head = curr; 
}

int main(){
	for(int i=0; i<2; i++){
		insert_node(i);
	}
	print_list(head);
	reverse_list(&head);
	cout << endl;
	print_list(head);
}
