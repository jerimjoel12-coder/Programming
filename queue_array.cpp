/* Queue : FIFO
   In array,
   Two Pointers: Rear, Front
   Rear: Insertion
   Front: Deletion
   Two opertion: Enqueue and Dequeue whereas in stack push and pop
*/

#include<iostream>
using namespace std;
class Queue{
public:
	int *arr;
	int size;
	int front;
	int rear;
	
	Queue(int N){
		size=N;
		arr=new int[size];
		rear=front=-1;
	}


	void enqueue(int x){
		if(rear==size-1){
			cout<<"Not possible"<<endl;
		}
		else if(front==-1 && rear==-1){
			front=rear=0;
			arr[rear]=x;
		}
		else{
			rear++;
			arr[rear]=x;
		}
	}

	void dequeue(){
		if(front==-1){
			cout<<"No element in queue"<<endl;
		}
		else if(front==rear ){
			cout<<arr[front]<<" Deleted"<<endl;
			front=rear=-1;
		}
		else{
			cout<<arr[front]<<" Deleted"<<endl;
			front++;
		}
	}
	
	void display(){
		if(rear==-1){
			cout<<"Queue is empty"<<endl;
		}	
		else{
			cout<<"Queue:"<<endl;
			for(int i=front;i<=rear;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
	}
};
int main(){
	int N;
	cin>>N;
	Queue q(N);
	int ch,val;
	while(1){
		cout<<"Enter choice:"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter value:"<<endl;
				cin>>val;
				q.enqueue(val);
				break;
			case 2:
				q.dequeue();
				break;
			case 3:
				q.display();
				break;	
			case 4:
				return 0;
			default:
				cout<<"Invalid"<<endl;
				exit(0);
		}
	}
}