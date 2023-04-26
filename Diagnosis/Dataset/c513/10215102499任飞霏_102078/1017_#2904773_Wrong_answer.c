#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toint(char a)
{
    switch(a)
    {
        case 'I':return 1;break;
        case 'V':return 5;break;
        case 'X':return 10;break;
        case 'L':return 50;break;
        case 'C':return 100;break;
        case 'D':return 500;break;
        case 'M':return 1000;break;
        case '(':return -1;break;
        case ')':return -2;break;
    }
    return 0;
}


int main()
{
    long long int ans = 0,flag = 0,temp = 0,n=1;
    char s[100];
    scanf("%s",s);
    for(int i = 0;i < strlen(s);i++){
        int a = toint(s[i]);
        if(toint(s[i])==-1){
            flag++;
            n*=1000;
            continue;
        }
        if(toint(s[i])==-2){
            flag--;
            temp*=1000;
            ans = temp;
            continue;
        }
        if(flag==0){
            if(i == strlen(s) - 1||toint(s[i+1])<=a){
            ans += a;
        }
            else{
                ans -= a;
            }
        }
        if(flag > 0){
            if((i == strlen(s) - 1||toint(s[i+1])<=a) && s[i+1]=='('){
                temp += a;
            }
            else{
                temp -= a;
            }
        }

        //printf("ans = %d\n",ans);
    }
    printf("%lld",ans);
    return 0;
}
