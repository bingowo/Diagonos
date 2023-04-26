#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int cnt,unsigned char *p)
{
    while(cnt--) printf("%02x ",*p++);
    printf("\n");
}
int main()
{
    char s[31];
    while(scanf("%s",s)!=EOF)
        if(strchr(s,'.'))
        {
            double d=atof(s);
            unsigned char *p=(unsigned char*)&d;
            int cnt=sizeof(d);
            print(cnt,p);
        }
        else{
            int d=atoi(s);
            unsigned char *p=(unsigned char*)&d;
            int cnt=sizeof(d);
            print(cnt,p);
        }
    return 0;
}
