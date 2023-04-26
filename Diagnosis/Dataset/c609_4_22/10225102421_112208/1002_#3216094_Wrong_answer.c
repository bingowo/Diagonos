#include<stdio.h>
int tentotwo(unsigned int x)
{
    int a[500];
    int i=0;
    int b[1000];
    int y=0;
    for (int z=0;z<1000;z++)
        b[z]=1;
    if(x==0)
        a[0]=0;
    else
    {

        while (x)
        {
            a[i]=x%2;
            x=x/2;
            i+=1;
        }
    }
    for (int j=0;j<i-1;j++)
    {
        if (a[j+1]!=a[j])
            b[y]=b[y]+1;
        else
            y+=1;
    }
    int d;
    d=b[0];
    for (int n=1;n<y;n++)
    {
        if (b[n]>d)
            d=b[n];
    }
    return d;
}
int main()
{
    int a;
    unsigned int n[10];
    scanf("%d",&a);
    for (int i=0;i<a+1;i++)
    {
        scanf("%u\n",&n[i]);
    }
    for (int j=0;j<a;j++)
    {
        int c=tentotwo(n[j]);
        printf("case #%d:\n",j);
        printf("%d\n",c);
    }
}
