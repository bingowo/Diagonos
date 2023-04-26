#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    char x=*(char *)a;
    char y=*(char *)b;
    return x-y;
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int m=0;m<t;m++)
    {
        char s[250];
        int i=0;
        int j=0;
        int count=0;
        gets(s);
        char a[250];
        char k[200];
        for(int p=0;p<250;p++)
            a[p]='a';
        int len= strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                a[j]=s[i];
                j++;
                count++;
            }
            else
                k[i]=s[i];
        }
        qsort(a,count,sizeof(a[0]),cmp);
        i=0,j=0;
        for(int d=0;d<len;d++)
        {
            if(a[d]=='a')
            {
                a[d]=k[j];
                j++;
            }
        }
        printf("case #%d:\n",m);
        for(int h=0;h<len;h++)
            printf("%c",a[h]);
        printf("\n");
    }
}