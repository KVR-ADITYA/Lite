#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ll
{
	int data;
	struct ll* next;
}ll;

void printll(ll*head){
	ll* temp;
	temp=head;
	while(temp->next!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("%d\t",temp->data );
	return;
}
void addnode(ll* hea,int val){
	ll* new;
	ll* head=hea;
	new=(ll*)malloc(sizeof(ll));
	new->data=val;
	new->next=NULL;
	while(head->next!=NULL){
		head=head->next;
	}
	head->next=new;
	return;
}

void reverse(ll** x){
	ll *q,*r,*s ;
	q=*x;
	r=NULL;

	while(q!=NULL){
		s=r;
		r=q;
		q=q->next;
		r->next = s;
	}
	*x = r;
	return;
}

ll* shuffle(ll* head,int k){
	ll*new_head = (ll*)malloc(sizeof(ll));
	ll* temp;
	temp =head;
	new_head->next = NULL;
	new_head->data = 0; 
	int i =1;
	while(temp->next!=NULL){
		if(i%k == 0){
			addnode(new_head,temp->data);
			temp->data = 0;
		}
		temp = temp->next;
		i++;
	}
	reverse(&temp);
	ll* rev = temp;
	printf("%p\n",rev->next);
	while(rev->next!=NULL){
		printf("HI\n");
		if(rev->data!=0){
			addnode(new_head,rev->data);
		}
		rev = rev->next;
	}
	addnode(new_head,rev->data);
	return new_head;
}

int main(int argc, char const *argv[])
{
	ll* head = (ll*) malloc (sizeof(ll));
	head->next = NULL;
	int k;
	scanf("%d",&k);
	printf("Enter 0 to quit\n");
	int a;
	scanf("%d",&a);
	head->data = a;
	while(a!=0){
		scanf("%d",&a);
		if(a!=0){
			addnode(head,a);
		}
	}
	ll* new_head = shuffle(head,k);
	printll(new_head);
	return 0;
}