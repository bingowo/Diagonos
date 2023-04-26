#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int max(int a,int b)
{
    return a>b?a:b;
}

char *rstr(char*s1,char*s2)
{
    int ls1=strlen(s1);
    int ls2=strlen(s2);
    char*s;
    if(ls2>ls1) return NULL;
    for(s=s1+ls1-ls2;s>=s1;s--)
    {
        if(strncmp(s,s2,ls2)==0)
            return s;
    }
    return NULL;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char a[256],b[256],s[256];
        scanf("%s%s%s",a,b,s);
        char*ia=strstr(s,a);
        char*ira=rstr(s,a);
        char*ib=strstr(s,b);
        char*irb=rstr(s,b);
        int la=strlen(a),lb=strlen(b);
        int r=0;
        if(ia!=NULL&&ib!=NULL)
        {
            r=max((int)(irb-ia-la),(int)(ira-ib-lb));
        }
        printf("case#%d:\n",i);
        printf("%d\n",max(r,0));
    }
    return 0;
}
