#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isMathOperation(char* s){
    if(strcmp(s,"ADD")==0||strcmp(s,"SUB")==0||strcmp(s,"MUL")==0||strcmp(s,"DIV")==0){
        return 1;
    }
    return 0;
}

int main()
{
    int ax = 0, bx = 0, cx = 0, dx = 0;
    while(1){
        char curOperation[4] = {0,0,0,0};
        if(scanf("%s ",curOperation)==EOF){
            break;
        }
        //printf("curOperation = %s\n",curOperation);
        if(strcmp(curOperation,"IN")==0){
            char reg[3] = {0,0,0};//register
            int n = 0;
            scanf("%[^,],%d",reg,&n);
            //printf("reg = %s, n = %d\n",reg,n);
            if(strcmp(reg,"AX")==0){ax = n;}
            else if(strcmp(reg,"BX")==0){bx = n;}
            else if(strcmp(reg,"CX")==0){cx = n;}
            else if(strcmp(reg,"DX")==0){dx = n;}
        }
        else if(strcmp(curOperation,"OUT")==0){
            char reg[3] = {0,0,0};
            scanf("%s",reg);
            //printf("reg = %s\n",reg);
            if(strcmp(reg,"AX")==0){printf("%d\n",ax);}
            else if(strcmp(reg,"BX")==0){printf("%d\n",bx);}
            else if(strcmp(reg,"CX")==0){printf("%d\n",cx);}
            else if(strcmp(reg,"DX")==0){printf("%d\n",dx);}
        }
        else if(isMathOperation(curOperation)){
            char reg1[3] = {0,0,0};
            char reg2[3] = {0,0,0};
            scanf("%[A-Z],%[A-Z]",reg1,reg2);
            int *n1, *n2;
            if(strcmp(reg1,"AX")==0){n1 = &ax;}
            else if(strcmp(reg1,"BX")==0){n1 = &bx;}
            else if(strcmp(reg1,"CX")==0){n1 = &cx;}
            else if(strcmp(reg1,"DX")==0){n1 = &dx;}
            if(strcmp(reg2,"AX")==0){n2 = &ax;}
            else if(strcmp(reg2,"BX")==0){n2 = &bx;}
            else if(strcmp(reg2,"CX")==0){n2 = &cx;}
            else if(strcmp(reg2,"DX")==0){n2 = &dx;}

            if(strcmp(curOperation,"ADD")==0){*n1 = *n1 + *n2;}
            else if(strcmp(curOperation,"SUB")==0){*n1 = *n1 - *n2;}
            else if(strcmp(curOperation,"MUL")==0){*n1 = *n1 * *n2;}
            else if(strcmp(curOperation,"DIV")==0){*n1 = *n1 / *n2;}
        }

    }
    return 0;
}
