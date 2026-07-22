#include<iostream>
#include<vector>
using namespace std;
int main(){
	int R,C,K;
	cin>>R>>C>>K;
	vector<vector<int>> grid(R+1,vector<int>(C,0));
	for(int row=1;row<=R;row++){
		string s;
		cin>>s;
		for(int col=1;col<=C;col++){
			grid[row][col]=s[col-1]-'0';
		}
	}
	for(int row=1;row<=R;row++){
		for(int col=2;col<=C;col++){
			grid[row][col]+=grid[row][col-1];	
		}	
	}
	for(int col=1;col<=C;col++){
		for(int row=2;row<=R;row++){
			grid[row][col]+=grid[row-1][col];
		}
	}
	long long int count=0;
	for(int row=1;row<=R;row++){
		for(int col=1;col<=C;col++){
			for(int tr=0;tr<row;tr++){
				for(int tc=0;tc<col;tc++){
					int sms=grid[row][col]-grid[row][tc]-grid[tr][col]+grid[tr][tc];
					if(sms==K){
						count++;
					}
				}
			}
		}
	}
	cout<<count;
}