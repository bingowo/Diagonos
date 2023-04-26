#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct 
{
    int sta;
    int pp,pq;
    int upp,upq;
}sub;
int main(){
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    sub *my=(sub*)malloc(sizeof(sub)*(n+1));
    my[1].pp=1,my[1].pq=0;
    my[1].upp=1,my[1].upq=0;
    my[2].pp=1,my[2].pq=0;
    my[2].upp=0,my[2].upq=1;
    for(int i=3;i<n;i++){
        my[i].pp=my[i-1].pp+my[i-2].upp;
        my[i].pq=my[i-1].pq+my[i-2].upq;
        my[i].upp=my[i-1].upp+my[i-2].upp;
        my[i].upq=my[i-1].upq+my[i-2].upq;
    }
    int b=(m-a*my[n-1].pp)/my[n-1].pq;
    my[1].pp=a,my[1].pq=0;
    my[1].upp=a,my[1].upq=0;
    my[2].pp=a,my[2].pq=0;
    my[2].upp=0,my[2].upq=b;
    for(int i=3;i<n;i++){
        my[i].pp=my[i-1].pp+my[i-2].upp;
        my[i].pq=my[i-1].pq+my[i-2].upq;
        my[i].upp=my[i-1].upp+my[i-2].upp;
        my[i].upq=my[i-1].upq+my[i-2].upq;
    }
    my[n].pp=m;my[n].pq=0;
    printf("%d",my[x].pp+my[x].pq);
}