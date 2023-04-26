#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int subint(char* s,int l,int r)
{
    int w=0;
    for(int i=l;i<=r;i++){
        w*=10;
        w+=(s[i]-'0');
        w%=1000000007;
    }
    return w;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s[101];
        scanf("%s",s);
        int f[100][210]={0};
        int len=strlen(s);
        for(int i=0;i<len;i++){
            f[i][subint(s,0,i)%210]+=1;
            f[i][subint(s,0,i)%210]%=1000000007;
            for(int j=0;j<i;j++){
                int tmp=subint(s,j+1,i);
                for(int k=0;k<210;k++){
                    f[i][(k+210+tmp)%210]+=f[j][k];
                    f[i][(k+210+tmp)%210]%=1000000007;
                    f[i][(k+210-tmp)%210]+=f[j][k];
                    f[i][(k+210-tmp)%210]%=1000000007;
                }
            }
        }
        long long int ans=0;
        for(int i=0;i<210;i++){
            if(!(i%2)||!(i%3)||!(i%5)||!(i%7)){
                ans+=f[len-1][i];
                ans%=1000000007;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
