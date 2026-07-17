#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node *next;
	Node(int val){
		data=val;
		next=nullptr;
	}
};

Node *top=nullptr;

void push(int val){
	Node *newnode=new Node(val);
	newnode->next=top;
	top=newnode;
	cout<<val;
}

void pop(){
	if(top==nullptr){
		cout<<"stack underflow";
		return;
	}
	
	Node *temp=top;
	cout<<temp->data<<" deleted";
	top=top->next;
	delete temp;
}

void display(){
	if(top==nullptr){
		cout<<"Stack is empty";
		return;
	}
	
	Node *temp=top;
	while(temp!=nullptr){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main(){
	int ch,val;
	
	while(1){
		cout<<"enter choice";
		cin>>ch;
		switch(ch){
			case 1:
				cin>>val;
				push(val);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				cout<<"Invalid";
				exit(0);
		}
	}
}