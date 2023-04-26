#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 110
#define BigNUm 1000000007
#define Max 1000000
#define N 100

typedef long long lli;

int isOX(char c){
    if(isdigit(c)||(c>='a' && c<='f')) return 1;
    return 0;
}

int main()
{
    char s[N+1]={0};
    scanf("%s",&s);
    int i=0;
    lli tmp=0,isNum=0,is=0;
    while(i<strlen(s)){
        if(s[i]=='0' && s[i+1]=='x' && isNum==0){
            isNum=1;
            i+=2;
            continue;
        }
        if(isNum){
            if(isOX(s[i])){
                is=1;
                isNum+=1;
                tmp*=16;
                tmp+=(isalpha(s[i]))?(s[i]-'a'+10):(s[i]-'0');
                i++;
            }
            else{
                if(isNum>1){
                    printf("%lld ",tmp);
                    tmp=0;
                    isNum=0;
                    i++;
                }
                else{
                    isNum=0;
                    tmp=0;
                    i++;
                }
            }
        }
        else i++;
    }
    if(is==0) printf("-1");
    else if(isNum>1) printf("%lld ",tmp);


    return 0;
}
