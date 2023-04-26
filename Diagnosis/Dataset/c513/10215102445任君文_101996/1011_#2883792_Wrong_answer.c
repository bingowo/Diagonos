#include <stdio.h>
#define M 100
int main()
{
    int num,i=0, n[M]={0};
    long a1=0, a2=0, b1=0, b2=0;
    char c;
    c=getchar();
    c=getchar();
    while((c=getchar())!='\n')
    {
        num=0;
        if(('0'<=c)&&(c<='9'))
        {
            num=c-'0';
        }
        else
        {
            num=10+c-'A';
        }
        while(num!=0)
        {
            n[i]=num%2;
            num=num/2;
            i++;
        }
    }
    for(i=0;i<M;i++)
    {
        a2=n[i]-(a1+b1);
        b2=(a1-b1);
        a1=a2;
        b1=b2;
    }
    if(b1<0)
        printf("%ld-%ldi\n",a1,-b1);
    else if(b1==0)
        printf("%ld\n",a1);
    else
        printf("%ld+%ldi\n",a1,b1);
    
    return 0;
}