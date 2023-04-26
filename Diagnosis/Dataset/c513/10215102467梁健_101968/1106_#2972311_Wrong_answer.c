#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define N 1000000007
int main()
{
    char s[1001];scanf("%s",s);
    long var=1;
    int len=strlen(s);
    if(len==1);
    else if(len==2){
        if(s[0]==s[1]);
        else var=4;
    }
    else{
        if(s[0]!=s[1])var*=2;
        for(int i=0;i<len;i++){
            if(s[i]!=s[i-1]&&s[i]!=s[i+1])var*=3;
            if(s[i]==s[i-1]&&s[i]!=s[i+1])var*=2;
            if(s[i]!=s[i-1]&&s[i]==s[i+1])var*=2;
            var%=1000000007;
        }
        if(s[len-1]!=s[len-2])var*=2;
    }
    printf("%lld",var%1000000007);
    return 0;
}
