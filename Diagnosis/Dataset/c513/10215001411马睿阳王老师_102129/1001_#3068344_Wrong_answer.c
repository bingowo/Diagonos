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
    s[i+1]=0;
}

int main()
{
    int T,N,R;
    int i,j,k;
    char s[1007];
    scanf("%d",&T);
    for(i=0;i<T;i++)
        scanf("%d%d",&N,&R);
    for(i=0;i<T;i++)
    {
          turn(N,s,R);
          printf("%s\n",s);
    }
    return 0;
}
