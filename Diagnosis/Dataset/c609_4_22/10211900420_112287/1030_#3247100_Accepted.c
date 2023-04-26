#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
double fl[26]={0};
double ord(char x)
{
    if(x>='A' && x<='Z')
    {
        return fl[x-'A'];
    }
    else
        return fl[x-'a'];
}
int cmp(const void* a,const void* b)
{
    char c=*(char*)a,d=*(char*)b;
    double x=ord(c),y=ord(d);
    if(x>y) return -1;
    else if(x<y) return 1;
    else
    {
        if(tolower(c)==tolower(d))
        {
            return d-c;
        }
        return c-d;
    }
}
int main()
{
    int len,j,T,i;
    char x[101];
    scanf("%d",&T);
    for(j=0;j<T;j++)
    {
        for(i=0;i<26;i++)
        {
            scanf("%f",&fl[i]);
        }
        scanf("%s",x);
        len=strlen(x);
        qsort(x,len,sizeof(x[0]),cmp);
        printf("case #%d:\n",j);
        for(i=0;i<len;i++)
            printf("%c",x[i]);
        printf("\n");
    }
    return 0;
}
