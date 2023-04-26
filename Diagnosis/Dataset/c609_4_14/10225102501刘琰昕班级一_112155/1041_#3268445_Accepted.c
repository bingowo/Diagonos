#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void comb(char *s,char *char_comb)
{
    if(*s)
    {
        char left[17]={0};
        sprintf(left,"%s%c",char_comb,s[0]);
        printf("%s\n",left);
        comb(s+1,left);
        comb(s+1,char_comb);
    }
}

int cmp(const void *p,const void *q)
{
    char *a=(char *)p;
    char *b=(char *)q;
    return *a-*b;
}

int main()
{
    int T;
    scanf("%d", &T);
    char s[20],x[20];
    for(int Case=0;Case<T;Case++)
    {
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(char),cmp);
        int i=0,k=0;
        for(i=0,k=0;i<len-1;i++)
            if(s[i]!=s[i+1])x[k++]=s[i];
        x[k++]=s[len-1];x[k]='\0';
        char t[20]={};
        printf("case #%d:\n",Case);
        comb(x,t);
    }
    return 0;
}
