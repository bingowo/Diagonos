#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct{
    int num[100];
    int p;
}bint;

bint mul2(bint *t){
    bint ret={{0},0};
    for(int i=0;i<t->p;i++){
        ret.num[ret.p++]=t->num[i]*2;
    }
    int carry=0,i=0;
    while(carry!=0 || i<ret.p){
        int tmp=ret.num[i]+carry;
        ret.num[i]=tmp%10;
        carry=tmp/10;
        i++;
    }
    ret.p=i;
    return ret;
}

void sub(bint* a,bint*b){
    for(int i=0;i<a->p;i++){
        if(a->num[i]>b->num[i])a->num[i]-=b->num[i];
        else{
            a->num[i]=a->num[i]+10-b->num[i];
            a->num[i+1]--;
        }
    }
    while(a->p>1 && a->num[a->p]==0)a->p--;
}
int main(){
    int k,n;
    scanf("%d%d",&k,&n);
    bint tab[n+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<100;j++){
            tab[i].num[j]=0;
        }
    }
    tab[1].num[0]=0;tab[1].p=1;
    if(n>=2){tab[2].num[0]=1;tab[2].p=1;}
    if(n>=3){tab[3].num[0]=1;tab[3].p=1;}
    if(n>=4){tab[4].num[0]=2;tab[4].p=1;}

    for(int i=5;i<=k;i++){
        tab[i]=mul2(&tab[i-1]);
    }

    if(n>=5  && n>k){
        int p=k+1>5?k+1:5;
        for(int i=p;i<=n;i++){
            tab[i]=mul2(&tab[i-1]);
            if(i-k-1>1)sub(&tab[i],&tab[i-k-1]);
        }
    }
    for(int i=tab[n].p-1;i>=0;i--){
        printf("%d",tab[n].num[i]);
    }
    return 0;
}
