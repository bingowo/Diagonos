#include<stdio.h>
#include<string.h>
int main()
{
    int T,i,j,ans,weight,t;
    char s[1000];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",s);
        int l=strlen(s);
        weight=1;
        ans=0;
        for(j=l-1;j>=0;j--)
        {
            if(s[j]=='-')  t=-1;
            else  t=s[j]-'0';
            ans+=t*weight;
            weight*=3;
        }
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}