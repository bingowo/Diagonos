#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
//快排有风险，使用需谨慎
typedef struct node{
    int val;
    struct node* next;
}node;
void add(node* head,int num){
    node*p=head;
    while(p->next!=NULL)p=p->next;
    node *temp=(node*)malloc(sizeof(node));
    temp->val=num;
    temp->next=NULL;
    p->next=temp;
}
void clear(node* head){
    node* p=head->next;
    while(p->next!=NULL){
        node* temp=p;
        p=p->next;
        free(temp);
    }
    free(p);
}
void print(node* head){
    node*p=head->next;
    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}
int cmp(const void*a, const void*b){
    node *p1=(node*)a,*p2=(node*)b;
    p1=p1->next;p2=p2->next;
    while(p1!=NULL && p2!=NULL){
        if(p1->val==p2->val){
            p1=p1->next;
            p2=p2->next;
        }
        else{
            return -p1->val+p2->val;
        }
    }
    if(p1==NULL)return 1;
    else return -1;
}
int main()
{
    long long n;scanf("%lld",&n);
    for(int m=0;m<n;m++){
        int size;scanf("%d",&size);
        node table[size];
        for(int i=0;i<size;i++){
            table[i].next=NULL;
            int num;scanf("%d",&num);
            while(num!=-1){
                add(&table[i],num);
                scanf("%d",&num);
            }
        }
        qsort(table,size,sizeof(node),cmp);
        for(int i=0;i<size;i++){
            print(&table[i]);
            clear(&table[i]);
        }
        free(table);
    }
}
