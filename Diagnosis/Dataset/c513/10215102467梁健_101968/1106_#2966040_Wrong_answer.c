#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char s[1001];scanf("%s",s);
    unsigned long long var=1,res=1;
    int len=strlen(s);
    if(len==1);
    else if(len==2){
        if(s[0]==s[1]);
        else res=4;
    }
    else{
        if(s[0]!=s[1])var*=2;
        if(s[len-1]!=s[len-2])var*=2;
        for(int i=1;i<len-1;i++){
            if(s[i]!=s[i-1]&&s[i]!=s[i+1])var*=3;
            else if(s[i]==s[i-1]&&s[i]==s[i+1]);
            else var*=2;
            if(var>(18446744073709551615+1)/4){
                res=(res%1000000007)*var%1000000007;var=1;
            }
        }
        res=(res%1000000007)*var%1000000007;
    }
    printf("%lld",res);
    return 0;
}
