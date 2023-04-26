#include<stdlib.h>
#include<stdio.h>

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int cmp(const void* a,const void* b){
    int c=*(int *)a,d=*(int *)b,t=c-d;
    return t;
}

int main(){
    int n,s;
    scanf("%d %d",&n,&s);
    int h[n+1];
    for(int i=0;i<n;i++)scanf("%d",&h[i]);
    qsort(h,n,sizeof(int),cmp);
    h[n]=10000000;
    int it=0,zi=0,mu=1,i=1,v;
    //if(n==1)it+=s;
    while(s>=0&&i<=n){
        v=(h[i]-h[i-1])*i;
        if(s<v){
            it=h[i-1]+s/i;
            mu=i;
            zi=s%i;
            s=0;
        }
        else{
            s-=v;
        }
        i++;
    }
    int g=gcd(zi,mu);
    mu/=g;
    zi/=g;
    if(it==0)printf("%d/%d",zi,mu);
    else if(zi==0)printf("%d",it);
    else printf("%d+%d/%d",it,zi,mu);
}