#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int a[129]={0};
        char b[18],c[18];
        scanf("%s\n",b);
        int lenb=strlen(b),l=0,k;
        for(k=0;k<lenb;k++)
        {
            if(a[b[k]]==0) {c[l]=b[k];l++;a[b[k]]=1;}
        }
        qsort(c,l,sizeof(char),strcmp);
        printf("case #%d:\n",i);
        for(int e=0;e<l;l++)
        {printf("%d\n",c[e]);
        for(int f=e+1;f<l;f++)
        printf("%d%d\n",c[e],c[f]);
        }
        return 0;
}