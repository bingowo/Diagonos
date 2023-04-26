#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int ax=0,bx=0,cx=0,dx=0;
    while(1){
        char ch[4];
        if(scanf("%s ",ch)==EOF) break;
        if(strcmp(ch,"IN")==0){
            char reg_str[3];
            int n;
            scanf("%[^,]",reg_str);
            scanf("%c%d",&n,&n);
            if(strcmp(reg_str,"AX")==0) ax=n;
            if(strcmp(reg_str,"BX")==0) bx=n;
            if(strcmp(reg_str,"CX")==0) cx=n;
            if(strcmp(reg_str,"DX")==0) dx=n;
        }
        else if(strcmp(ch,"OUT")==0){
            char reg_str[3];
            scanf("%s",reg_str);
            if(strcmp(reg_str,"AX")==0) printf("%d\n",ax);
            if(strcmp(reg_str,"BX")==0) printf("%d\n",bx);
            if(strcmp(reg_str,"CX")==0) printf("%d\n",cx);
            if(strcmp(reg_str,"DX")==0) printf("%d\n",dx);

        }
        else{
            char reg_str1[3],reg_str2[3];
            scanf("%[^,]%c%s",reg_str1,reg_str2,reg_str2);
            int* reg1;
            int* reg2;
            if(strcmp(reg_str1,"AX")==0) reg1=&ax;
            if(strcmp(reg_str1,"BX")==0) reg1=&bx;
            if(strcmp(reg_str1,"CX")==0) reg1=&cx;
            if(strcmp(reg_str1,"DX")==0) reg1=&dx;
            if(strcmp(reg_str2,"AX")==0) reg2=&ax;
            if(strcmp(reg_str2,"BX")==0) reg2=&bx;
            if(strcmp(reg_str2,"CX")==0) reg2=&cx;
            if(strcmp(reg_str2,"DX")==0) reg2=&dx;

            if(strcmp(ch,"MOV")==0) *reg1=*reg2;
            if(strcmp(ch,"ADD")==0) *reg1=(*reg1)+(*reg2);
            if(strcmp(ch,"SUB")==0) *reg1=(*reg1)-(*reg2);
            if(strcmp(ch,"MUL")==0) *reg1=(*reg1)*(*reg2);
            if(strcmp(ch,"DIV")==0) *reg1=(*reg1)/(*reg2);

        }

    }
    return 0;
}
