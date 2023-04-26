#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char s[17];
}charall;

int cmp(const void*a,const void*b)
{
    char x=*(char*)a;
    char y=*(char*)b;
    return x<y?-1:1;
}
int cmp1(const void*a,const void*b)
{
    char* x=(char*)a;
    char*y=(char*)b;
    return strcmp(x,y)<=0?-1:1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[17],ans[17];
        scanf("%s",s);
        int ret1=1;
        char *p1=s;
        ans[0]=*p1;
        ans[1]='\0';
        p1++;
        while(*p1!='\0')
       {
        if(strchr(ans,*p1)==NULL)
        {
           strncat(ans,p1,1);
           ret1++;
        }
        p1++;
        }
        qsort(ans,ret1,sizeof(char),cmp);
        charall ret[(1<<ret1)];

        for(int j=1;j<(1<<ret1);j++)
        {
            int m=0;
            for(int k=0;k<ret1;k++)
            {
                if(j&(1<<k))
                {
                    ret[j-1].s[m++]=ans[k];
                }

            }
            ret[j-1].s[m]='\0';

        }
        qsort(ret,(1<<ret1)-1,sizeof(charall),cmp1);
        printf("case #%d:\n",i);
        for(int j=0;j<((1<<ret1)-1);j++)
        {
            printf("%s\n",ret[j].s);
        }
    }
    return 0;
}
