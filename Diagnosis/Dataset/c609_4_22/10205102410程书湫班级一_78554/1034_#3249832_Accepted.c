#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isHex(char digit)
{
    if((digit>='0'&&digit<='9')||
(digit>='a'&&digit<='f'))
         return 1;
     else return 0;
}

int main()
{
    char s[100001];
    scanf("%s",s);
    char *p,*start=s;
    int state=0;
    while((p=strstr(start,"0x"))!=NULL)
{
    unsigned int decimal=0;
    int flag=0;
    p=p+2;
    while(isHex(*p))
    {
        decimal=decimal*16+(isdigit(*p)?(*p- '0'):(*p- 'a'+10));
        flag=1;
        state=1;
        p=p+1;
    }
    if(flag) printf("%u ",decimal);
    start=p;
}
    if(state==0) printf("-1");
    printf("\n");
    return 0;
}