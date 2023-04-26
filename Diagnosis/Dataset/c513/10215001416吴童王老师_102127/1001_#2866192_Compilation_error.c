#include<stdio.h>
int main()
{
    char hex[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int T;
    int a[100];
    int b[100];
    scanf(“%d\n",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d%d\n",&a[i],&b[i]);
    }
    int j;
    for(int j=0;j<T;j++);
    {
        char d[100];
        int k;
        for(k=0;;k++)
        {
            d[k]=a[j]%b[j];
            a[j]=a[j]/b[j];
            if(a[j]<=b[j]){break;}
        }
        for(;k>=0;k--)
        {
            printf("%c",hex[d[k]]);
        }
    }
    return 0;
}