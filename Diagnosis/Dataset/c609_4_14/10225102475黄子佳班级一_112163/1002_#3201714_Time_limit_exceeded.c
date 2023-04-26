#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    int T;
    int max[100];
    scanf("%d",&T);
    int m[100],a[100];
    for(int count=1,j=0;count<=T;count++)
    {
        scanf("%d",&n);
        max[j]=0;
        for(int i=0;n>0;i++)
    {
        m[i]=n%2;
        n/=2;
    }
        for(int k=strlen(m)-1,i=0;k>0;i++,k--)
        {
            a[k]=m[i];
        }

        for(int i=0,t=1;i<strlen(a)-1;i++)
        {
            while(a[i]!=a[i+1]&&i<strlen(a)-1)t++;
            if(t>max[j])max[j]=t;
            t=1;
        }
        j++;
    }

    for(int j=0;j<T;j++)
    {
             printf("case #%d:\n",j);
             printf("%d\n",max[j]);
     }
    return 0;
}
