#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);

    for(int i=0; i<T; i++)
    {
        char s[100];
        scanf("%s",s);

        int l=strlen(s);
        
        int a[l];
        for(int j=0;s[j];j++)
        {
            if(s[j]=='-') a[j]=-1;
            else if(s[j]=='1') a[j]=1;
            else if(s[j]=='0') a[j]=0;
        }
        int ans=0;
        for(int j=0;j<l;j++)
        {
            ans=ans*3+a[j];//转为十进制
        }
        printf("case #%d:\n",i);
        printf("%d\n",ans);

    }
    return 0;
}
