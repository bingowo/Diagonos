#include<stdio.h>

struct group{
    int num[10000],l;
};

int add(int* a,int* b,int la,int lb){
    int carry=0,l,i;
    if(la>lb)l=la;
    else l=lb;
    for(i=0;i<l;i++){
        a[i]+=carry;
        a[i]+=b[i];
        carry=a[i]/10;
        a[i]%=10;
    }
    while(carry>0){
        a[i++]=carry%10;
        carry/=10;
    }
    return i;
}

int main(){
    int k,n;
    scanf("%d %d",&k,&n);
    struct group t[n];
    for(int i=0;i<n;i++){
        t[i].l=0;
        memset(t[i].num,0,sizeof(t[i].num));
    }
    t[0].num[0]=0;t[1].num[0]=1;
    t[0].l=1;t[1].l=1;
    for(int i=2;i<n;i++){
        for(int j=i-1;j>=0&&j>=i-k;j--){
            t[i].l=add(t[i].num,t[j].num,t[i].l,t[j].l);
        }
    }
    for(int i=t[n-1].l-1;i>=0;i--)printf("%d",t[n-1].num[i]);
}