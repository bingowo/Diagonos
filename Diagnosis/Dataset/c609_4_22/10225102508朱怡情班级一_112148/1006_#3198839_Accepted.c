#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int j=0;j<t;j++){
        int key[200];
        for(int i=0;i<128;i++){
            key[i]=-1;
        }
        char n[70];
        scanf("%s",n);
        int r=0;
        char *p=n;
        key[*p]=1;
        while(*++p){
            if(key[*p]==-1){
                key[*p]=r;
                r=r?r+1:2;
            }
        }
        if(r<2)r=2;
        long long ans=0;
        p=n;
        while(*p){
            ans=ans*r+key[*p++];
        }
        printf("case #%d:\n%lld\n",j,ans);
    }
    return 0;
}
