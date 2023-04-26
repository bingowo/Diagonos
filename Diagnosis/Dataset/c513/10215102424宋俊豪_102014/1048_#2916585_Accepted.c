#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

#define N 100
void read(char s[],int n[])
{
    while(*s)
    {
        int f=1,a=0,i=0;
        if(*s=='+')s++;
        else if(*s=='-') f=-1,s++;
        while(isdigit(*s)){a=a*10+*s-'0';s++;}
        if(a==0)a=1;
        if(*s!='x'){n[0]=a*f;return;}
        else s++;
        if(*s=='^') s++;
        while(isdigit(*s)){i=i*10+*s-'0';s++;}
        if(i==0)i=1;
        n[i]=a*f;

    }
}
void slo(char s1[],char s2[],int a[])
{
    int t1[N]={0},t2[N]={0};
    read(s1,t1);
    read(s2,t2);
    for(int i=0;i<N/2;i++)
        for(int j=0;j<N/2;j++)
          a[i+j]+=t1[i]*t2[j];

}
int main()
{
    char s1[N+1],s2[N+1];
    while(scanf("%s%s",s1,s2)==2)
    {
        int a[N]={0},t[N],n=0;
        slo(s1,s2,a);
        for(int i=0;i<N;i++)
            if(a[i])
            t[n++]=a[i];
        for(int i=n-1;i>=0;i--)
           {

           printf("%d",t[i]);
            if(i==0)
            printf("\n");
            else
            printf(" ");
           }
    }
    return 0;
}
