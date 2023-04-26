#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b)
{
    char aa=*(char*)a,bb=*(char**)b;
    return strcmp(a,b);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int a[123]={0},count=0;
        char s[16]="",ss[16]="";
        scanf("%s",s);
        for(int i=0;i<strlen(s);i++)
        {
            if(a[s[i]]==0)
            {
                a[s[i]]=1;
                ss[count++]=s[i];
            }
        }
        qsort(ss,count,sizeof(ss[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;ss[i];)
        {
            for(int j=0;ss[j];j++)
            {
                char t[16]="";
                strncpy(t,ss,j+1);
                printf("%s\n",t);
            }
            char tt[16]="";
            int j=0;
            for(int i=1;ss[i];)
                tt[j++]=ss[i++];
            tt[j]=0;
            strcpy(ss,tt);
        }
    }
    return 0;
}
