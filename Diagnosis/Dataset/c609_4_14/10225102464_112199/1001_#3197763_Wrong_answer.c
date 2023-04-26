#include <stdio.h>
#include <stdlib.h>
char s[40]={"123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
int main()
{
    int n;
    int num;
    int x;
    int re;
    int q;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",num,x);
        char a[100];
        for(int j=x;j>=0;re/=j)
        {
            int next;
            next=num%j;
            a[q++]=s[next];
        }
        for(int u=0,y=q-1;u<y;u++,y--)
        {
            int temp;
            temp=a[y];
            a[y]=a[u];
            a[u]=temp;
        }
        puts(a);

    }

    return 0;
}