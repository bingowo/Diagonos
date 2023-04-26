#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char c[1500];scanf("%s",c);
    long long res=1;
    int len=strlen(c);
    if(len==1);
    else if(len==2){
        if(c[0]!=c[1])res=4;
    }
    else{
        for(int i=0;i<len;i++){
            if(c[i]!=c[i-1]&&c[i]!=c[i+1])res*=3;
            else if(c[i]==c[i-1]&&c[i]==c[i+1]);
            else res*=2;
            res%=1000000007;
        }
    }
    printf("%lld",res);
    return 0;
}
