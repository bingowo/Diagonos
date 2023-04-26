#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    int a,b,m;
    scanf("%d ",&a);
    int p[100],q[100];
    for(int i=0;i<a;i++)
    {
        scanf("%d ",&p[i]);
    }
    scanf("%d ",&b);
    for(int i=0;i<b;i++)
    {
        for(int j=0;j<a;j++)
        {
            scanf("%d ",&m);
            if(m==p[j])
            {
                q[i]=m;
                break;
            }
        }
    }
    for(int i=0;i<strlen(q);i++)
    {
        printf("%d ",q[i]);
    }
    return 0;
}