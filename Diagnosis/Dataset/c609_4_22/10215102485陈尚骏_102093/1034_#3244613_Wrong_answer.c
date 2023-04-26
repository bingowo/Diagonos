#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    char c,s,t;
    while(1)
    {
        c=getchar();
        if(c==EOF) break;
        s=getchar();
        if(s==EOF) break;
        t=getchar();
        if(t==EOF) break;
        if(c=='0'&&s=='x'&&((t<='9'&&t>='0')||(t<='f'&&t>='a')))
        {
            ungetc(c,stdin);
            ungetc(s,stdin);
            ungetc(t,stdin);
            if(n++) printf(" ");
            unsigned a;
            scanf("%x",&a);
            printf("%u",a);
        }
        else
        {
            ungetc(s,stdin);
            ungetc(t,stdin);
        }
    }
    if(!n) printf("-1\n");
    else printf("\n");
    return 0;
}
