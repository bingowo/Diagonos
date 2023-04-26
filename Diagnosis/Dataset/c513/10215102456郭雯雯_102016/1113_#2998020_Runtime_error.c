#include<stdio.h>

struct group{
    int num[10000],l;
};

int add(struct group* a,struct group b){
    struct group sum=*(a);
    int carry=0,l,i;
    if(sum.l>b.l)l=sum.l;
    else l=b.l;
    for(i=0;i<l;i++){
        sum.num[i]+=carry;
        sum.num[i]+=b.num[i];
        carry=sum.num[i]/10;
        sum.num[i]%=10;
    }
    while(carry>0){
        sum.num[i++]=carry%10;
        carry/=10;
    }
    sum.l=i;
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
            t[i].l=add(&(t[i]),t[j]);
        }
    }
    for(int i=t[n-1].l-1;i>=0;i--)printf("%d",t[n-1].num[i]);
}