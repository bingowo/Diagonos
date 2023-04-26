#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[55];
    scanf("%s",&s);
    int len=strlen(s);
    int ans=0;//得分
    int a[55]={0};//栈
    int p=-1;//栈指针

    for(int i=0;i<len;i++)
    {
        if(s[i]=='(') a[++p]=0;
        else
        {
            int x=0;//局部得分
            while(p>=0 && a[p]!=0)
            {
                x+=a[p--];
            }
            --p;

            if(x==0) a[++p]=1;
            else a[++p]=x*2;
        }
    }
    while(p>=0) ans+=a[p--];

    printf("%d\n",ans);
    return 0;
}