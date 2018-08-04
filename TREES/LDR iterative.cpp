#include<iostream>
using namespace std;
typedef
struct LDR{
	struct LDR *LC;
	char data;
	struct LDR *RC;
}*LDRptr;
struct stack{
	int top;
	int size;
	LDRptr element[50];
}s;
void push(struct stack &s, LDRptr x){
	if(s.top == s.size-1)
	cout<<"stack is full ";
	else
		s.element[++s.top] = x;	
}
LDRptr pop(struct stack &s){
	if(s.top == -1)
	cout<<"stack is empty";
	else
	return s.element[s.top--];
}
void creat(LDRptr &t, char d){
	if(t== NULL){
		t = new LDR;
		t->data = d;
		t->LC = NULL;
		t->RC = NULL;
	}
	cout<<"Leftchild of "<<t->data<<" ";
	cin>>d;
	if(d != '0')
		creat(t->LC, d);
	cout<<"Rightchild of "<<t->data<<" ";
	cin>>d;
	if(d!= '0')
		creat(t->RC, d);
}
void printLDR(LDRptr &L){
	if(L == NULL)
		return;
	LDRptr temp;
	temp = NULL;
	push(s,temp);
	do{
		if(L->LC == NULL && L->RC == NULL){
			cout<<L->data;
			 L = pop(s);
			if(L->RC != NULL){
				push(s,L->RC);
				L->RC = NULL;
			}
		}
		else{
			if(L->RC != NULL){
				push(s,L->RC);
				L->RC = NULL;
			}
			LDRptr T;
			T = new LDR;
			T->data = L->data;
			T->LC = NULL;
			T->RC = NULL;
			push(s,T);
			L = L->LC;	
		}
	}while(s.element[s.top] != NULL);
	cout<<L->data;
	return;
}
int main(){
	struct stack s;
	s.top = -1;
	s.size = 50;
	LDRptr	T;
	T = NULL;
	cout<<"\nEnter root";
	char c;
	cin>>c;
	creat(T,c);
	printLDR(T);
}

