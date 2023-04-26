#include<stdio.h>
int tentotwo(unsigned int x)
{
    int a[50];
    int i=0;
    int b=0;
    if(x==0)
        return 0;
    else
    {

        while (x)
        {
            a[i]=x%2;
            x=x/2;
            i+=1;
        }
    }
    for (int j=0;j<i;j++)
    {
        if (a[j+1]=a[j])
            b=b+1;
    }
    return b;
}
int main()
{
    int a;
    unsigned int n[10];
    scanf("%d",&a);
    for (int i=0;i<a;i++)
    {
        scanf("%u\n",&n[i]);
    }
    for (int j=0;j<a;j++)
    {
        int c=tentotwo(n[j]);
        printf("case #%d\n",j);
        printf("%d",c);
    }
}
