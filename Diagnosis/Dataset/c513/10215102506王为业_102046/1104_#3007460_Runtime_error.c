//simu\1104.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    
*/


#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

int REG[28]={0};

int* get_reg(char *reg)
{
    return REG+reg[0]-'A';
}


int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    char order[8];
    char reg1[6],reg2[6],reg3[6]="";
    int *nr1,*nr2,*nr3;
    while(scanf("%s ",order)!=EOF){//eat the blank here
        if(strcmp(order,"IN")==0){
            scanf("%[^,]",reg1);
            scanf(",%d",get_reg(reg1));
            getchar();//deal with \n
        }else if(strcmp(order,"OUT")==0){
            scanf("%s",reg1);
            printf("%d\n",*get_reg(reg1));
            getchar();//deal with \n
        }else {
            scanf("%[^,]",reg1);
            getchar();
            scanf("%[^, \n]",reg2);
            nr1=get_reg(reg1);
            nr2=get_reg(reg2);
            char c=getchar();
            if(c==','){
                scanf("%s",reg3);
                nr3=get_reg(reg3);
            }else{
                reg3[0]='\0';
                nr3=NULL;
            }
            if(strcmp(order,"ADD")==0){
                if(nr3==NULL){
                    (*nr1) += (*nr2);
                }else{
                    (*nr1)=(*nr2) + (*nr3);
                }
            }else if(strcmp(order,"SUB")==0){
                if(nr3==NULL){
                    (*nr1) -= (*nr2);
                }else{
                    (*nr1)=(*nr2) - (*nr3);
                }
            }else if(strcmp(order,"MUL")==0){
                if(nr3==NULL){
                    (*nr1) *= (*nr2);
                }else{
                    (*nr1)=(*nr2) * (*nr3);
                }
            }else if(strcmp(order,"DIV")==0){
                if(nr3==NULL){
                    (*nr1) /= (*nr2);
                }else{
                    (*nr1)=(*nr2) / (*nr3);
                }
            }else if(strcmp(order,"MOD")==0){
                if(nr3==NULL){
                    (*nr1) %= (*nr2);
                }else{
                    (*nr1)=(*nr2) % (*nr3);
                }
            }else if(strcmp(order,"AND")==0){
                if(nr3==NULL){
                    (*nr1) &= (*nr2);
                }else{
                    (*nr1)=(*nr2) & (*nr3);
                }
            }else if(strcmp(order,"OR")==0){
                if(nr3==NULL){
                    (*nr1) |= (*nr2);
                }else{
                    (*nr1)=(*nr2) | (*nr3);
                }
            }else if(strcmp(order,"XOR")==0){
                if(nr3==NULL){
                    (*nr1) ^= (*nr2);
                }else{
                    (*nr1)=(*nr2) ^ (*nr3);
                }
            }
        }
        
    }
}

