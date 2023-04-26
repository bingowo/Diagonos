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
int main()
{
    int x,y,z;
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
        printf("%d %d\n",y,z);
    }
}