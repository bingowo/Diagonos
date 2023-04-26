#include<stdio.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    int a,b,k=0;
    int m[100],n[100],p[100];
    scanf("%d ",&a);
    for(int i=0;i<a;i++)
    {
        scanf("%d ",&m[i]);
    }
    scanf("%d ",&b);
    for(int j=0;j<b;j++)
    {
        scanf("%d ",&n[j]);
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(m[i]==n[j])
            {
                p[k]=n[j];
                k++;
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        printf("%d ",p[i]);
    }
    return 0;
}