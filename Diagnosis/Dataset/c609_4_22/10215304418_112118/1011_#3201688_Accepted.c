#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    char st[100100];
    scanf("%s",st);
    long long ans=0;
    for (int i=0;i<strlen(st);i++){
        if (st[i]=='.') continue;
        ans*=3;
        if (st[i]=='2'){
            ans+=-1;
        }
        else if (st[i]=='1'){
            ans+=1;
        }
    }
    long long ansy=1;
    for (int i=0;i<strlen(st);i++){
        if (st[i]=='.'){
            for (int j=i+1;j<strlen(st);j++)
                ansy*=3;
            break;
        }
    }
    if (ansy==1){
        printf("%lld\n",ans);
    }
    else if (ans/ansy==0){
        printf("%lld %lld\n",ans%ansy,ansy);
    }
    else printf("%lld %lld %lld\n",ans/ansy,abs(ans%ansy),ansy);
    return 0;
}
