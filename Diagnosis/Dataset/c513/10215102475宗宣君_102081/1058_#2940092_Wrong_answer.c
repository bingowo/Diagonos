#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000];
    while(gets(s)!=NULL)
    {
        char *a,*b,*e;
        a = strstr(s,"//");
        b = strchr(s,'"');
        e = strrchr(s,'"');
        if(a!=NULL&&(b==NULL||a<b||(e>b&&e<a))) {*a ='\0';}
        char *c;
        c = strstr(s,"/*");
        if(c!=NULL&&(b==NULL||c<b||(e>b&&e<a))) continue;
        char *d;
        d = strstr(s,"*/");
        if(d!=NULL&&(b==NULL||d<b||(e>b&&e<a))){printf("%s\n",d+2);continue;}
        printf("%s\n",s);
    }
    return 0;
}
