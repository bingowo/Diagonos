#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef long long int lli;

int ishex(char c)
{
    int ret=0;
    if (isdigit(c)||(c>='a'&&c <='f')){
        ret=1;
    }
    return ret;
}

int main()
{
    char s[100001];
    scanf("%s",s);
    char *p1=s,*p2=p1+1;
    lli temp=0;
    int isvalid=0, isnumber=0;
    while (*p1){
        if (*p1=='0'&& *p2=='x'&& isnumber==0){
            isnumber=1;
            p1+=2;
            p2+=2;
            continue;
        }
        if (isnumber){
            if (ishex(*p1)){
                isvalid=1,isnumber+=1;
                temp= temp*16+(isalpha(*p1)?(*p1-'a'+10):(*p1-'0'));
                p1++,p2++;
            }
            else{
                if (isnumber>1){
                    printf("%lld",temp);
                    temp=0;
                    isnumber=0;
                    p1++,p2++;
                }
                else{
                    isnumber=0;
                    p1++,p2++;
                }
            }
        }
        else{
            p1++,p2++;
        }
    }
    if (!isvalid){
        printf("-1");
    }
    else if(isnumber>1){
        printf("%lld",temp);
    }
    return 0;
}