#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000];
    while(gets(s)!=NULL)
    {
        char *a,*b;
        a = strstr(s,"//");
        b = strchr(s,'"');
        if(a!=NULL&&(b==NULL||a<b)) {*a ='\0';}
        char *c;
        c = strstr(s,"/*");
        if(c!=NULL) continue;
        char *d;
        d = strstr(s,"*/");
        if(d!=NULL&&(b==NULL||d<b)){printf("%s\n",d+2);continue;}
        printf("%s\n",s);
    }
    return 0;
}
