#include <stdio.h>
#include <string.h>

int func(char * s)
{
    int len=strlen(s);
    int num=0;
    int a[130];
    a['0']=0;
    a['1']=1;
    a['-']=-1;
    for(int i=0;i<len;i++)
    {
        num*=3;
        num+=a[s[i]];
    }
    return num;
}

int main()
{
    int T,ans;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[100]={0};
        scanf("%s\n",&s);
        ans=func(s);
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
    return 0;
}
