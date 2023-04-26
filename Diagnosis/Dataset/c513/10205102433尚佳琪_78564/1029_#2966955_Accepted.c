#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    return *(char *)a-*(char *)b;
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
        char b[205];
        char c[205];
        int k=0;
        int flag[205]={0};
        gets(b);
        int len=strlen(b);
        for(int i=0;i<len;i++)
        {
            if(b[i]>='A'&&b[i]<='Z')
            {
                flag[i]=0;
                c[k++]=b[i];
            }
            else
            {
                flag[i]=1;
            }
        }
       // printf("%s",c);
        qsort(c,k,sizeof(c[0]),cmp);
        int m=0;
        printf("case #%d:\n",i);
        for(int i=0;i<len;i++)
        {
            if(flag[i]==1)
                printf("%c",b[i]);
            else
                printf("%c",c[m++]);
        }
        printf("\n");
    }
}

