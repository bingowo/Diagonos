#include <stdio.h>
#include <string.h>

int main()
{
    int ax = 0, bx = 0, cx = 0, dx = 0;
    while(1)
    {
        char ch[4];
        if(scanf("%s",ch) == EOF)
            break;
        if(strcmp(ch,"IN") == 0)
        {
            char s[5];
            int n;
            scanf("%s",s);
            scanf("%c %d",&n,&n);
            if(strcmp(s,"AX") == 0) ax = n;
            if(strcmp(s,"BX") == 0) bx = n;
            if(strcmp(s,"CX") == 0) cx = n;
            if(strcmp(s,"DX") == 0) dx = n;
        }
        else if(strcmp(ch,"OUT") == 0)
        {
            char s[3];
            scanf("%s",s);
            if(strcmp(s,"AX") == 0) printf("%d\n",ax);
            if(strcmp(s,"BX") == 0) printf("%d\n",bx);
            if(strcmp(s,"CX") == 0) printf("%d\n",cx);
            if(strcmp(s,"DX") == 0) printf("%d\n",dx);
        }
        else
        {
            char s1[3],s2[3];
            scanf("%s %s %s",s1,s2,s2);
            int *r1;
            int *r2;
            if(strcmp(s1,"AX") == 0) r1 = &ax;
            if(strcmp(s1,"BX") == 0) r1 = &bx;
            if(strcmp(s1,"CX") == 0) r1 = &cx;
            if(strcmp(s1,"DX") == 0) r1 = &dx;
            if(strcmp(s2,"AX") == 0) r2 = &ax;
            if(strcmp(s2,"BX") == 0) r2 = &bx;
            if(strcmp(s2,"CX") == 0) r2 = &cx;
            if(strcmp(s2,"DX") == 0) r2 = &dx;
            if(strcmp(ch,"MOV") == 0) *r1 = *r2;
            if(strcmp(ch,"ADD") == 0) *r1 = (*r1) + (*r2);
            if(strcmp(ch,"SUB") == 0) *r1 = (*r1) - (*r2);
            if(strcmp(ch,"MUL") == 0) *r1 = (*r1) * (*r2);
            if(strcmp(ch,"DIV") == 0) *r1 = (*r1) / (*r2);
        }
    }
    return 0;
}
