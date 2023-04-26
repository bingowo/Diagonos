#include <stdio.h>
#include <stdlib.h>

void insert(char *s, int pos)
{
    int i;
    for (i=strlen(s)+1;i>pos;i--) s[i]=s[i-1];
}


void trans(char*in,char*ou)
{
    strcpy(ou,in);
    char *p1 = in;
    while(p1-in+1<strlen(in))
    {
        insert(in,p1-in);
        int cmp=strcmp(in,ou);
        if(cmp<0)strcpy(ou,in),p1++;
        p1++;//printf("%d\t%s\n",p1-in,in);
    }
}

int main()
{
    char in[201];
    char ou[201];
    scanf("%s",in);
    trans(in,ou);
    printf("%s",ou);
    return 0;
}
