#include<iostream>

using namespace std;
#define size 5
int stack[size];
int top=-1;
void push(int val){
	if(top==size-1){
		cout<<"stack overflow";
	}
	else{
		top++;
		stack[top]=val;
	}
}

void pop(){
	if(top==-1){
		cout<<"stack underflow";
	}
	else{
		cout<<stack[top]<<" deleted";
		top--;
	}
}

void display(){
	if(top==-1){
		cout<<"stack is empty";
	}
	else{
		for(int i=top;i>=0;i--){
			cout<<stack[i]<<" ";
		}
	}
}
int main(){
	int ch,val;
	while(1){
		cout<<"enter choice:";
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
		}
	}
}