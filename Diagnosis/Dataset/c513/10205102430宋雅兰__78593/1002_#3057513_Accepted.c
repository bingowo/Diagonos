#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    char s[61];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%s",s);
        int l=strlen(s);
        char a[128];
        for(int j=0;j<128;j++)a[j]=-1;
        int k=1,digit=0;
        a[s[0]]=1;
        for(int j=1;j<l;j++)
        {
            if(a[s[j]]==-1){
                a[s[j]]=digit;
                if(digit==0)digit=2;
                else digit+=1;
                k++;
            }
        }
        if(k<2)k=2;
        long long ans=0;
        for(int j=0;j<l;j++)
        ans=ans*k+a[s[j]];
        printf("case #%d:\n%lld\n",i,ans);
    }
    return 0;
}