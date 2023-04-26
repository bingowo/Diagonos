#include<stdio.h>
#include<stdlib.h>
#define N 10e6
typedef struct num1
{
    int count1;
    int number;
}num;
void qort(struct num1* qrt,int len)
{
    struct num1 num2;
    int i,j;
    for(j=0;j<len-1;j++)
    {
    for(i=0;i<len-j-1;i++)
    {
        if(qrt[i].count1<qrt[i+1].count1)
        {
            num2=qrt[i];
            qrt[i]=qrt[i+1];
            qrt[i+1]=num2;
            
        }
        else if(qrt[i].count1==qrt[i+1].count1)
        {
            if(qrt[i].number>qrt[i+1].number)
            {
                 num2=qrt[i];
            qrt[i]=qrt[i+1];
            qrt[i+1]=num2;
            
            }
        }
    }
    }
}
int Getcount(int num)
{
    int i=0;
    while(num!=0)
    {
        num=num/10;
        i++;
    }
    return i;
}
int main()
{
    num ar[N];
    int n;
    scanf("%d",&n);int i=0;char c;
    ar[i].number=n;ar[i].count1=Getcount(n);
    i=1;
    while((c=getchar())==' ')
    {
        scanf("%d",&n);
        ar[i].number=n;ar[i].count1=Getcount(n);
        i++;
    }
    qort(ar,i);
    int j=0;
    for(j=0;j<i;j++)
    printf("%d ",ar[j].number);
    return 0;
}