#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int n;int r;
}Input;

void change(int n,int r)
{
    int k;
    char res[33];
    char sys[36]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (n<0)
    {
        k = 1;
        n = - n;
        for(int i=0;n!=0;i++)
        {
            res[i]=sys[n%r];
            n=n/r;
            k++;
        }
        res[k-1]='-';
    }
    else
    {
        k=0;
        for(int i=0;n!=0;i++)
        {
            res[i]=sys[n%r];
            n=n/r;
            k++;
        }
    }
    for(int i = k-1;i>-1;i--)
    {
        printf("%c",res[i]);
    }
}

int main()
{
    int t;
    scanf("%d\n",&t);
    Input num[t];
    for(int i=0;i<t;i++)
    {
        scanf("%d %d\n",&num[i].n,&num[i].r);
    }
    for(int i=0;i<t;i++)
    {
        change(num[i].n,num[i].r);
        printf("\n");
    }
    return 0;
}
