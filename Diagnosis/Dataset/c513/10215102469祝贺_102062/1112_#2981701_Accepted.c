#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(){
    int pro;scanf("%d",&pro);
    for(int index=0;index<pro;index++){
        unsigned long long ans=0;
        int n;scanf("%d",&n);
        for(int x=0;x*3<=n;x++){
            int p=n-3*x;
            for(int j=0;j*2<=p;j++){
                ans+=j/2+1;
            }
        }
        printf("%llu\n",ans);
    }
    return 0;
}
