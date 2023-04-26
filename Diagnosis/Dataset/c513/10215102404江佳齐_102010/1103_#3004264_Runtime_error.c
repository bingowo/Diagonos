#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int ax=0,bx=0,cx=0,dx=0;
    while(1)
    {
        char s[4];
        if(scanf("%s",s)==EOF) break;
        if(strcmp(s,"IN")==0)
        {
            char str[3];
            int n;
            scanf("%[^,]",str);
            scanf("%c%d",&n,&n);
            if(strcmp(str,"AX")==0) ax=n;
            if(strcmp(str,"BX")==0) bx=n;
            if(strcmp(str,"CX")==0) cx=n;
            if(strcmp(str,"DX")==0) dx=n;
        }
        else if(strcmp(s,"OUT")==0)
        {
            char str[3];
            scanf("%s",str);
            if(strcmp(str,"AX")==0) printf("%d\n",ax);
            if(strcmp(str,"BX")==0) printf("%d\n",bx);
            if(strcmp(str,"CX")==0) printf("%d\n",cx);
            if(strcmp(str,"DX")==0) printf("%d\n",dx);
        }
        else
        {
            char str1[3],str2[3];
            scanf("%[^,]%c%s",str1,str2,str2);
            int* s1;int* s2;
            if(strcmp(str1,"AX")==0) s1=&ax;
            if(strcmp(str1,"BX")==0) s1=&bx;
            if(strcmp(str1,"CX")==0) s1=&cx;
            if(strcmp(str1,"DX")==0) s1=&dx;
            if(strcmp(str2,"AX")==0) s2=&ax;
            if(strcmp(str2,"BX")==0) s2=&bx;
            if(strcmp(str2,"CX")==0) s2=&cx;
            if(strcmp(str2,"DX")==0) s2=&dx;

            if(strcmp(s,"MOV")==0) *s1=*s2;
            if(strcmp(s,"ADD")==0) *s1=(*s1)+(*s2);
            if(strcmp(s,"SUB")==0) *s1=(*s1)-(*s2);
            if(strcmp(s,"MUL")==0) *s1=(*s1)*(*s2);
            if(strcmp(s,"DIV")==0) *s1=(*s1)/(*s2);
        }
    }
    return 0;
}
