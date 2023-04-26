#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c,s,t;
    int n=0;
    do{
        c=getchar();
        if(c=EOF) break;
        s=getchar();
        if(s==EOF) break;
        t=getchar();
        if(t==EOF) break;
        if(c=='0'&&s=='x'&&(t>='0'&&t<='9'||t>='a'&&t<='f'))
        {
            ungetc(t,stdin);
            ungetc(s,stdin);
            ungetc(c,stdin);
            if(n++) printf(" ");
            unsigned a;
            scanf("%x",&a);
            printf("%u",a);
        }
        else
        {
            ungetc(t,stdin);
            ungetc(s,stdin);
        }
    }while(1);
    if(!n) printf("-1");
    printf("\n");
    return 0;
}
