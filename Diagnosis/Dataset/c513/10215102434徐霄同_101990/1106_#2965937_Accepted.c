#include <stdio.h>
#include <string.h>

int main()
{
    char w[1001];
    int a[1000];
    int i,l;
    long long ans;
    scanf("%s",w);
    l=strlen(w);
    if(l==1)
        printf("1\n");
    else{
        if(w[0]!=w[1])
            a[0]=2;
        else
            a[0]=1;
        if(w[l-1]!=w[l-2])
            a[l-1]=2;
        else
            a[l-1]=1;
        for(i=1;i<l-1;i++)
            if(w[i]!=w[i-1]&&w[i]!=w[i+1]&&w[i-1]!=w[i+1])
                a[i]=3;
            else if((w[i]!=w[i-1]&&w[i]==w[i+1])||(w[i]!=w[i+1]&&w[i]==w[i-1])||(w[i]!=w[i-1]&&w[i]!=w[i+1]&&w[i-1]==w[i+1]))
                a[i]=2;
            else
                a[i]=1;
        ans=1;
        for(i=0;i<l;i++)
            ans=(ans*a[i])%1000000007;
        printf("%lld\n",ans);
    }
    return 0;
}
