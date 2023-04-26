#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Mystr
{
    char s0[40];
    int digit;
    char s1[40];
}mystr;

int main()
{
    mystr s[100];memset(s,0,100*sizeof(mystr));
    int cnt = 0;
    while(scanf("%s",s[cnt].s0)!=EOF)
    {
        cnt++;
    }

    for(int i = 0;i<cnt;i++)
    {
        printf("%s\n",s[i].s0);
    }
    return 0;
}
