#include<stdio.h>
#include<string.h>

void turn(int a,char s[1007],int b)
{
    int i=0,j,sign=1,c;
    char p;
    if(a<0)
    {
        a=-a;
        sign=-1;
    }
    while(a)
    {
        c=a%b;
        if(c<10)   s[i++]=c+'0';
        else       s[i++]=(c-10)+'A';
        a=a/b;
    }
    if(sign==-1) s[i]='-';
    else i--;
    for(j=0;j<=i/2;j++)
    {
        p=s[j];
        s[j]=s[i-j];
        s[i-j]=p;
    }
    s[i+1]='0';
}

int main()
{
    int T,s[1007][2];
    int i,j,k;
    char t[1007];
    scanf("%d",&T);
    for(i=0;i<T;i++)
        scanf("%d%d",&s[i][0],&s[i][1]);
    for(i=0;i<T;i++)
    {
          turn(s[i][0],t,s[i][1]);
          printf("%s\n",t);
    }
    return 0;
}