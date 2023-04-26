#include<stdio.h>
int length(int num)
{
    int j=0;
    char a[100];
   for(;num>0;j++)
   {
       a[j]=num%2;
       num=num/2;
   }
    int x=1,b=1,y=0;
    for(;y<j-1;y++)
    {
        if (a[y]!=a[y+1])
       b++;
        else if(a[y]==a[y+1])
        {
            b=1;continue;
        }
        if(b>x)x=a;
    }
return x;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   int num;
        scanf("%d\n",&num);
    printf("case #%d\n:",i);
    printf("%d",length(num));
    }
    return 0;
}



