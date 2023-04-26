#include<stdio.h>
void transfer(int N,int R)
{
    char s[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int a[]={0};
    int i=0,j=0;
    while(N)
    {
        if(N%R<10)
        {
            a[i]=N%R;
        }
        else
        {
            j=N%R-10;
            a[i]=s[j];
        }
        N/=R;
        i+=1;
    }
    for(int k=0;k<i;k++)
    {
        printf("%d",a[k]);
    }
}
int main()
{
    int N,T,R;
    int to_trans[] = {0};
    int base[]={0};
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        to_trans[i]=N;
        scanf("%d",&R);
        base[i]=R;
    }
    for(int i=0;i<T;i++)
    {
        transfer(to_trans[i],base[i]);
        printf("/n");
    }
    return 0;
}
