#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char s[1001];scanf("%s",s);
    unsigned long long var=1;
    int len=strlen(s);
    if(len==1);
    else if(len==2){
        if(s[0]==s[1]);
        else var=4;
    }
    else{
        if(s[0]!=s[1])var*=2;
        if(s[len-1]!=s[len-2])var*=2;
        for(int i=1;i<len-1;i++){
            var=var%1000000007;
            if(s[i]!=s[i-1]&&s[i]!=s[i+1])var*=3;
            else if(s[i]==s[i-1]&&s[i]==s[i+1]);
            else var*=2;
            var=var%1000000007;
        }
    }
    printf("%lld",var);
    return 0;
}
