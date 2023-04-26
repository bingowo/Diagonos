#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d",&n);
    char s[61];
    int a[128];
    for(int k=0; k<n; k++)
    {
        scanf("%s",s);
        int l=strlen(s);
        for (int i=0; i<128; i++) a[i]=-1;
        int j=1,digit=0;
        a[s[0]]=1;
        for(int i=1;i<l;i++)
        {
            if(a[s[i]]==-1)
            {a[s[i]]=digit;
            digit=digit?digit+1:2;
            j++;
            }
        }
        if (j<2) j=2;
        long long ans=0;
        for(int i=0;i<l;i++)
            ans=ans*j+a[s[i]];
       
        printf("case #%d:\n%lld\n",k,ans);
    }
    return 0;   
}
