#include<stdio.h>
#include<string.h>
int tongji(char *a,int x)
{
    int y,k=0;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<8;j++)
        {
            y=(a[i]>>j)&1;
		    if(y==1)
			    k++;
        }
    }
    return k;
}
int GCD(int m,int n)
{
    int x,y;
    int z=n;
    if(m<n)
    {
        int t;
        t=m,m=n,n=t;
    }
    while(z>0)
    {
        x=m%z;
        y=n%z;
        if((x==0)&&(y==0))
            return z;
        else
            z=z-1;
    }
}

int main()
{
    int x,y,z,n;
    char b[100];
    scanf("%d",&x);
    gets(b); //tiaoguo kongge
    for(int i=0;i<x;i++)
    {
        char a[150];
        gets(a);
        int x=strlen(a);
        y=tongji(a,x);
        z=8*x;
        n=GCD(y,z)
        printf("%d/%d\n",y/n,z/n);
    }
}