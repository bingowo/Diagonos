#include <stdio.h>
#include <stdlib.h>
int GCD(int m,int n)
{
    if(n<=m && m%n==0)return n;
    else if(n>m)return GCD(n,m);
    else return GCD(n,m%n);
}
int cmp(const void*a,const void *b)
{
    int *k1=(int *)a;
    int *k2=(int *)b;
    if(*k1!=*k2){if(*k1>*k2)return 1;else return -1;}
    else {if(*(k1+1)>*(k2+1))return 1;else return -1;}
}
int main()
{
    char s[100]={0};
    int i=0,f=1,m=0;int a=0,b=0,c=0;
    scanf("%s",s);
    while(isdigit(s[i])){a=a*10+s[i]-'0';i++;}
    if(a==0)a=1;
    i=i+3;
    for(i=i;s[i];)
    {   f=1;m=0;
        if(s[i]=='-'){f=-1;i++;}if(s[i]=='+'){f=1;i++;}
        while(isdigit(s[i])){m=m*10+s[i]-'0';i++;}m=m*f;
        if(s[i]=='x'){if(m==0)m=1*f;b=m;i++;}
        else c=m;
    }
    int d2=0,k=0,l=0,g=0;
    int d[2][2]={0};
    int h=0;
    double d3=0,d1=0;
    h=b*b-4*a*c;d3=(double)h;
    if(h<0){printf("No Answer!");return 0;}
    d1=sqrt(d3);d2=(int)d1;
    if(d1-d2>0){printf("No Answer!");return 0;}
    d[0][1]=-b+d2;d[1][1]=-b-d2;
    if(d[0][1]%(2*a)==0){d[0][0]=1;d[0][1]=-1*d[0][1]/(2*a);}
    else
    {   g=abs(GCD(abs(d[0][1]),2*a));
        k=2*a/g;d[0][1]=d[0][1]/g;
        if(a%k==0){d[0][0]=k;d[0][1]=-1*d[0][1];l=a/k;}
        else {printf("No Answer!");return 0;}
    }
    k=0;
     if(d[1][1]%(2*a)==0){d[1][0]=1;d[1][1]=-1*d[1][1]/(2*a);}
    else
    {  g=0;g=GCD(abs(d[1][1]),2*a);
        k=2*a/g;d[1][1]=d[1][1]/g;
        if(l%k==0){d[1][0]=k;d[1][1]=-1*d[1][1];}
        else {printf("No Answer!");return 0;}
    }

    qsort(d,2,8,cmp);
    printf("%d %d %d %d",d[0][0],d[0][1],d[1][0],d[1][1]);
    return 0;
}
