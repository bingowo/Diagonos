#include<stdio.h>
#include<stdlib.h>

int main()
{
    char letter[37];
    int figure[10],d='A';
    for(int i=10;i<36;i++) letter[i]=d++;
    for(int i=0;i<10;i++) figure[i]=i;
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,r,le[100],l=0;
        scanf("%d %d",&n,&r);
        if(n<0)
        {
            printf("-");
            n=abs(n);
        }
        while (n!=0)
        {
            le[l++]=n%r;
            n/=r;
        }
        for(int p=l-1;p>=0;p--)
        {
            if(le[p]<10) printf("%d",figure[le[p]]);
            else printf("%c",letter[le[p]]);
        }
        printf("\n");
    }

    return 0;
}