#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
	int data;
	Node* prev;
	Node* next;
	
	Node(int val){
		data=val;
		prev=nullptr;
		next=nullptr;
	}
};

Node* head=nullptr;

void insert_begin(int val){
	Node* newnode= new Node(val);
	
	if(head==nullptr){
		head=newnode;
	}	
	else{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
}

void insert_mid(int val,int pos){
    if(head==nullptr || pos==1){
    	insert_begin(val);
    	return;
    }
    Node* temp=head;
    int cnt=1;
    
    while(cnt<pos-1 && temp->next!=nullptr){
    	temp=temp->next;
    	cnt++;
    }
    Node* newnode=new Node(val);
    
    newnode->next=temp->next;
    newnode->prev=temp;
    
    if(temp->next!=nullptr){
    	temp->next->prev=newnode;
    }
    
    temp->next=newnode;
}
void insert_end(int val){
	Node* newnode=new Node(val);
    if(head==nullptr){
    	head=newnode;
    }
    
    Node* temp=head;
    
    while(temp->next!=nullptr){
    	temp=temp->next;
    }
    
    newnode->next=temp->next;
    newnode->prev=temp;
}
void del_begin(){
    if(head==nullptr){
    	return;
    }
    Node *temp=head;
    head=head->next;
    
    if(head!=nullptr){
    	head->prev=nullptr;
    }
    delete temp;
}
void del_mid(int pos){
    if(head==nullptr){
    	return;
    }
    if(pos==1){
    	del_begin();
    	return;
    }
    
    Node *temp=head;
    int cnt=1;
    
    while(cnt<pos && temp!=nullptr){
    	temp=temp->next;
    	cnt++;
    }
    if(temp==nullptr){
    	return;
    }
    if(temp->next!=nullptr){
    	temp->next->prev=temp->prev;
    }
    if(temp->prev!=nullptr){
    	temp->prev->next=temp->next;
    }
    delete temp;
}
    
void del_end(){
	if(head==nullptr){
		return;
	}
	if(head->next==nullptr){
		delete head;
		head=nullptr;
		return;
	}
	
	Node *temp=head;
	
	while(temp->next!=nullptr){
		temp=temp->next;
	}
	temp->prev->next=nullptr;
	delete temp;
}
void display(){
	if(head==nullptr){
		return;
	}
	Node* temp=head;
	if(temp!=nullptr){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	int ch,pos,val;
	while(1){
		cout<<"enter choice"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"enter val";
				cin>>val;
				insert_begin(val);
				break;
			case 2:
				cin>>pos>>val;
				insert_mid(val,pos);
				break;
			case 3:
				cin>>val;
				insert_end(val);
				break;
			case 4:
				del_begin();
				break;
			case 5:
				cin>>pos;
				del_mid(pos);
				break;
			case 6:
				del_end();
				break;
			case 7:
				display();
				break;
			case 8:
				exit(0);
		}
	}
}