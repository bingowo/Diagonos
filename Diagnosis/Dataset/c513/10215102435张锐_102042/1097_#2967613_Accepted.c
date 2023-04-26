#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
        int len=strlen(s);
        int *a=(int *)malloc(len*sizeof(int));
        int *b=(int *)malloc(2*len*sizeof(int));
        int min=len,max=len;
        for(int i=0;i<len;i++) a[i]=len;
        for(int i=1;i<len;i++)
        {
            if(s[i]>s[i-1])
            {
                a[i]=a[i-1]-1;
                if(a[i-1]-1<min) min=a[i-1]-1;
                b[a[i-1]-2]=i;
            }
            if(s[i]<s[i-1])
            {
                a[i]=a[i-1]+1;b[a[i-1]]=i;
                if(a[i-1]+1>max) max=a[i-1]+1;
            }
            if(s[i]==s[i-1]) a[i]=a[i-1],b[a[i-1]-1]=i;
        }
        for(int i=min;i<=max;i++)
        {
            for(int j=0;j<=b[i-1];j++)
            {
                if(a[j]==i) printf("%c",s[j]);
                else printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
