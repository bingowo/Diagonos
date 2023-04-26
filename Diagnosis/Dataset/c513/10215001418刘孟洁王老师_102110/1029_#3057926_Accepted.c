#include<stdio.h>
#include<string.h>
#include<math.h>

int cmp(const void*a,const void*b)
{
    char c=*(char*)a;
    char d=*(char*)b;
    return c-d;
}

int main()
{
    int T,i,j,l,k;
    char s[205],t[205];
    scanf("%d",&T);
    gets(t);
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        gets(t);
        l=strlen(t);
        for(j=0,k=0;j<l;j++)
        {
            if(t[j]!='\0'&&t[j]>='A'&&t[j]<='Z')
            {
                 s[k]=t[j];
                 k++;
            }
        }
        qsort(s,k,sizeof(char),cmp);
        for(j=0,k=0;j<l;j++)
        {
            if(t[j]!='\0'&&t[j]>='A'&&t[j]<='Z')
            {
                t[j]=s[k];
                k++;
            }
        }
        printf("%s\n",t);
        for(j=0;j<k;j++)
            s[j]='\0';
    }
    return 0;
}
