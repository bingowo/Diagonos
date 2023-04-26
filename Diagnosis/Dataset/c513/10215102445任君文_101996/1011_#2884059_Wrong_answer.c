#include <stdio.h>
#define M 400
int main()
{
    int num,i=0, n[M]={0},L=0;
    long a1=0, a2=0, b1=0, b2=0;
    char c;
    c=getchar();
    c=getchar();
    while((c=getchar())!='\n')
    {
        num=0;
        L=L+1;
        if(('0'<=c)&&(c<='9'))
        {
            num=c-'0';
        }
        else
        {
            num=10+c-'A';
        }
        i=1;
        while(num!=0)
        {
            n[L*4-i]=num%2;
            num=num/2;
            i++;
        }
    }
    for(i=0;i<L*4;i++)
    {
        a2=n[i]-(a1+b1);
        b2=(a1-b1);
        a1=a2;
        b1=b2;
    }
    if(a1==0)
        printf("%ld\n",b1);
    else
    {
        if(b1<0)
            printf("%ld-%ldi\n",a1,-b1);
        else if(b1==0)
            printf("%ld\n",a1);
        else if(b1==1)
            printf("%ld+i\n",a1);
        else
            printf("%ld+%ldi\n",a1,b1);
    }
    return 0;
}