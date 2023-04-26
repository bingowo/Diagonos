#include<stdio.h>
char table[]="01";
int length(int num)
{
    int j=0;
    char a[100];
    do{int r=num%2;
    a[j++]=table[r];
    num=num/2;
    }while(num);
    int x=1,b=1,y=0;
    for(j=j-1;j>=0;j--)
    {
        if (a[j]!=a[j--])
       b++;
        else if(a[j]==a[j--])
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



