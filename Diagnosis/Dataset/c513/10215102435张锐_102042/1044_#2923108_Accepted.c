#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int right(char a)
{
    if((a>='0'&&a<='9')||(a>='a'&&a<='f')) return 1;
    else return 0;
}
int digit(char a)
{
    if(a>='0'&&a<='9') return a-'0';
    else return a-'a'+10;
}
void cto16(char *s)
{
    int l=strlen(s);unsigned int num=0;
    for(int i=0;i<l;i++)
    {
        num+=digit(s[l-i-1])*(int)pow(16,i);
    }
    printf("%u",num);
}
int main()
{
    char s[1000000];
    scanf("%s",s);
    int len=strlen(s);int b=0;
    for(int i=0;i<len;i++)
    {
        char ans[100]={'0'};int i1=0;//加数进ans里
        if(s[i]=='0'&&s[i+1]=='x')
        {
            i=i+2;int n=0;
            while(right(s[i]))
            {
                ans[i1++]=s[i];i++;
                n=1;
            }
            if(b&&n) printf(" ");
            if(n) {b=1;cto16(ans);}
        }
    }
    if(b==0) printf("-1");
    printf("\n");
    return 0;
}
