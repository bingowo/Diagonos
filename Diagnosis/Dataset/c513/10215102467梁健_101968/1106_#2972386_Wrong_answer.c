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
        if(c[0]!=c[1])res*=2;
        if(c[len-2]!=c[len-1])res*=2;
        for(int i=1;i<len-1;i++){
            if(c[i]!=c[i-1]&&c[i]!=c[i+1])res*=3;
            else if(c[i]==c[i-1]&&c[i]==c[i+1]);
            else res*=2;
            res%=1000000007;
        }
    }
    printf("%lld",res);
    return 0;
}
