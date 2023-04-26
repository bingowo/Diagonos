#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[50];
    while(scanf("%s",s)!=EOF)
    {
        int m=0;
        char* p=(char*)(&m);
        double e;int t;
        if(strchr(s,'.'))
        {
           e=atof(s);
           m=sizeof(e);
           p=(char*)(&e);
        }
        else
        {
            t=atof(s);
            m=sizeof(t);
            p=(char*)(&t);
        }
        while(m>0)
        {
            printf("%02x",*p);
            p++;m--;
        }
        return 0;
    }
}