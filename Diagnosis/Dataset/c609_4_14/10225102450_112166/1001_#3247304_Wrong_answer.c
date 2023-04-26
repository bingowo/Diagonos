#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    int a,b;
    int aaa[100],bbb[100];
    scanf("%d\n",&a);
    b = a;
    while(a--,a>0)
    {
        scanf("%d %d\n",&aaa[a],&bbb[a]);
    }
    while(b--,b>0)
    {
        int n=aaa[b];
        int r=bbb[b];
        if(n==0){printf("0\n");continue;}
        int c=0,a[100];
        while(n)
        {
            a[c]=(n%r);
            c++;
            n/=r;
        }
        for(i=c-1;i>=0;i--)
        {
            if(a[i]>=10)
            {
                printf("%c\n",'A'+a[i]-10);
            }
            else printf("%d\n",a[i]);
        }
    }
}
