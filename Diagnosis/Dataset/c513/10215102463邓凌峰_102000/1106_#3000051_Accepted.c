#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 1000
#define BigNUm 1000000007
#define Max 1000000

typedef long long lli;

int main() {

    char W[1100]={0};
    scanf("%s",W);
    int len=strlen(W);
    lli ans=1;
    if(len==1);
    else{
        for(int idx=0;idx<len;idx++){
            if(idx==0){
                if(W[0]==W[1]) ans=(ans*1)%BigNUm;
                else if(W[0]!=W[1]) ans=(ans*2)%BigNUm;
            }
            else if(idx==len-1){
                if(W[idx]==W[idx-1]) ans=(ans*1)%BigNUm;
                else if(W[idx]!=W[idx-1]) ans=(ans*2)%BigNUm;
            }
            else{
                if(W[idx]==W[idx-1] && W[idx]==W[idx+1]) ans=(ans*1)%BigNUm;
                else if(W[idx]!=W[idx-1] && W[idx]!=W[idx+1]&& W[idx-1]!=W[idx+1]) ans=(ans*3)%BigNUm;
                else ans=(ans*2)%BigNUm;
            }
        }
    }
    printf("%lld",ans);



    return 0;

}

