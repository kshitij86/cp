#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *next;	
} *head = NULL;

void insert_node(int data){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	
	if(head == NULL){
		head = new_node;		
	} else {
		struct node *temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new_node;
	}
}

void print_list(){
	struct node *temp = head;
	while(temp != NULL){
		cout << temp ->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void reverse_list(struct node *curr, struct node *prev, struct node *next){
	if(curr->next == NULL){
		curr->next = prev;
		head = curr;
		return;
	}
	curr->next = prev;
	prev = curr;
	curr = next;
	next = curr->next;
	reverse_list(curr, prev, next);
}

void reverse_helper(){
	struct node *curr = head, *prev = NULL, *next = curr->next;
	reverse_list(curr, prev, next);
}

int main(){
	for(int i=0; i<5; i++){
		insert_node(i);
	}
	print_list();
	reverse_helper();
	cout << endl;
	print_list();
}
