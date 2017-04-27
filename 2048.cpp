//  2048 :AAG
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<deque>
using namespace std;
vector< vector<int> > v;
vector<int> r;

int display(int n){
	cout<<endl<<endl;
	int max=0;
	for(int i=0;i<n;i++){
		cout<<"|";
		for(int j=0;j<n;j++){
			cout<<" ";
			if(v[i][j]!=0){
				cout<<v[i][j];
				if(v[i][j]>max)
					max=v[i][j];
			}
			else           cout<<" ";  
			cout<<" |";
		} cout<<endl;
		for(int j=0;j<n;j++){
			cout<<"----";
		} 
		cout<<endl;	
	}
	return max;
}
int check(int n){
	int flag=0;
	r.clear();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(v[i][j]==0){
				r.push_back(n*i+j);
				flag++;
			}
	return flag;		
}
void process(int n,char move){
	deque<int> d;
	for(int i=0;i<n;i++){
		d.clear();
		for(int j=0;j<n;j++){
			if(v[i][j]!=0){
				if(move=='d')
					d.push_front(v[i][j]);
				else if(move=='a')
					d.push_back(v[i][j]);
					if(move=='a'||move=='d')
						v[i][j]=0;
			}
			if(v[j][i]!=0){
				if(move=='w')
					d.push_back(v[j][i]);
				else if(move=='s')
					d.push_front(v[j][i]);	
				if(move=='w'||move=='s')			
					v[j][i]=0;
			}
			
		} 
	//	for(int j=0;j<d.size();j++){
	//		cout<<"#"<<i<<"!"<<d[j]<<" ";
	//	} 
 
		int count=0;
		if(move=='d'||move=='s') 
			count=n-1;
		while(!d.empty()){
			int x=d.front();
				d.pop_front();
			int y=d.front();
			if(x==y){
				d.pop_front();
				if(move=='w'||move=='s')
					v[count][i]=x*2;
				else	
					v[i][count]=x*2;
			}
			else{
				if(move=='w'||move=='s')
					v[count][i]=x;
				else	
					v[i][count]=x;
			}
			if(move=='d'||move=='s') 
				count--;
			else
				count++;	
		}				
	}
}
int main(void)
{  	int n;
	srand(time(NULL));
	printf("Enter the size :- "); 
	cin>>n;
	
	v.resize(n);
	for(int i=0;i<n;i++){
		v[i].assign(n,0);
	}
	int tmp=rand()%(n*n);
	v[tmp/n][tmp%n]=2;
	int max=display(n);

	while(1){	
		char move;
		cout<<endl<<"Enter your move: ";
		//fflush(stdin);
		cin>>move;
		system("cls");
		process(n,move);
		if(!check(n))
			break;			
		tmp=rand()%(r.size()); 
		tmp=r[tmp];
		v[tmp/n][tmp%n]=2;				
	    max=display(n);	
	} cout<<endl<<"\t\t ***** GAME OVER ***** "<<endl<<"Your Score is: "<<max;
	return 0;
}
