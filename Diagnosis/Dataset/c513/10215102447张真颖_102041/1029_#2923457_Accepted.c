#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void*b)
{
    char aa=*(char*)a,bb=*(char*)b;
    return aa-bb;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[201]={0},ss[201]={0};
        int t[200]={0},tt[200]={0},count=0;
        do
        {
            char st[201]={0};
            scanf("%s",st);
            t[count++]=strlen(st);
            strcat(s,st);
        }while(getchar()!='\n');
        for(int i=0,j=0;i<strlen(s);i++)
        {
            if(s[i]<='Z'&&s[i]>='A') ss[j]=s[i],j++;
            else tt[i]=1;
        }
        qsort(ss,strlen(ss),sizeof(ss[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0,j=0,m=0;m<strlen(s);j++)
        {
            for(int x=0;x<t[j];x++)
            {
                if(tt[m]) printf("%c",s[m]),m++;
                else printf("%c",ss[i]),i++,m++;
            }
            if(m==strlen(s)) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
