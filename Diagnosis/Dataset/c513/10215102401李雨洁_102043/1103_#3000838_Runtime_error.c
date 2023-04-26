#include <stdio.h>
#include <string.h>

int main()
{
    int ax = 0, bx = 0, cx = 0, dx = 0;
    while(1)
    {
        char ch[10];
        if(scanf("%s ",ch) == EOF) break;
        if(strcmp(ch,"IN") == 0)
        {
            char s[10];
            int n;
            scanf("%s,%d\n",s,&n);
            if(strcmp(s,"AX") == 0) ax = n;
            else if(strcmp(s,"BX") == 0) bx = n;
            else if(strcmp(s,"CX") == 0) cx = n;
            else if(strcmp(s,"DX") == 0) dx = n;
        }
        else if(strcmp(ch,"OUT") == 0)
        {
            char s0[10];
            scanf("%s\n",s0);
            if(strcmp(s0,"AX") == 0) printf("%d\n",ax);
            if(strcmp(s0,"BX") == 0) printf("%d\n",bx);
            if(strcmp(s0,"CX") == 0) printf("%d\n",cx);
            if(strcmp(s0,"DX") == 0) printf("%d\n",dx);
        }
        else
        {
            char s1[10],s2[10];
            scanf("%s,%s\n",s1,s2);
            int *r1;
            int *r2;
            if(strcmp(s1,"AX") == 0) r1 = &ax;
            else if(strcmp(s1,"BX") == 0) r1 = &bx;
            else if(strcmp(s1,"CX") == 0) r1 = &cx;
            else if(strcmp(s1,"DX") == 0) r1 = &dx;

            if(strcmp(s2,"AX") == 0) r2 = &ax;
            else if(strcmp(s2,"BX") == 0) r2 = &bx;
            else if(strcmp(s2,"CX") == 0) r2 = &cx;
            else if(strcmp(s2,"DX") == 0) r2 = &dx;

            if(strcmp(ch,"MOV") == 0) *r1 = *r2;
            else if(strcmp(ch,"ADD") == 0) *r1 = (*r1) + (*r2);
            else if(strcmp(ch,"SUB") == 0) *r1 = (*r1) - (*r2);
            else if(strcmp(ch,"MUL") == 0) *r1 = (*r1) * (*r2);
            else if(strcmp(ch,"DIV") == 0) *r1 = (*r1) / (*r2);
        }
    }
    return 0;
}
