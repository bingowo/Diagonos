#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st
{
    char chr[20];
};

int cmp(const void*a,const void*b)
{
    return strcmp((*(struct st*)a).chr,(*(struct st*)b).chr);
}

int main()
{
    int T;scanf("%d\n",&T);char c;
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        struct st s[250];int i=0,j=0,k,flag=0;
        while((c=getchar())!='\n')
        {
            if((c==' '||c==','||c=='.'||c=='!'||c=='?')&&flag==0)
            {s[i].chr[j]='\0';i++;j=0;flag=-1;}
            else if(c<='z'&&c>='a')
                {flag=0;s[i].chr[j++]=c;}
        }if(flag==0)s[i].chr[j]='\0';
        qsort(s,i,sizeof(s[0]),cmp);
        printf("%s",s[0].chr);
        for(j=1;j<i;j++)
            if(strcmp(s[j].chr,s[j-1].chr)!=0)printf(" %s",s[j].chr);
        printf("\n");
    }
}
