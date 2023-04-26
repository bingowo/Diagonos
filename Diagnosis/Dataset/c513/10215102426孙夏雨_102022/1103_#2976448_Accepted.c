#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char zhiling[10]={0};
    char canshu[50]={0};
    int shu[26]={0};
    int biao=0,biao1=0,biao2=0;
    char in[]={"IN"};//AX,number  AX=number
    char out[]={"OUT"};//AX  输出 AX 的值
    char mov[]={"MOV"};//AX,BX  AX=BX
    char xchg[]={"XCHG"};//AX,BX  交换 AX 和 BX 寄存器中储存的值
    char add[]={"ADD"};//AX,BX  AX=AX+BX 或 AX,BX,CX  AX=BX+CX
    char sub[]={"SUB"};//AX,BX  AX=AX-BX 或 AX,BX,CX  AX=BX-CX
    char mul[]={"MUL"};//AX,BX  AX=AX * BX
    char div[]={"DIV"};//AX,BX  AX=AX/BX（整除）
    char mod[]={"MOD"};//AX,BX  AX=AX%BX
    char and[]={"AND"};//AX,BX  AX=AX&BX
    char or[]={"OR"};//AX,BX  AX=AX|BX
    char xor[]={"XOR"};//AX,BX  AX=AX^BX
    while(scanf("%s",zhiling)!=EOF){
        scanf("%s",canshu);
        int len=strlen(canshu);
        if(!strcmp(zhiling,in)){
            int x=0,sig=1,i=0;
            biao=canshu[0]-'A';
            for(;canshu[i]!=',';i++);
            i++;
            if(canshu[i]=='-') {sig=-1;i++;}
            for(;i<len;i++) x=x*10+canshu[i]-'0';
            x*=sig;
            shu[biao]=x;
        }
        else if(!strcmp(zhiling,out)){
            biao=canshu[0]-'A';
            printf("%d\n",shu[biao]);
        }
        else if(!strcmp(zhiling,mov)){
            biao=canshu[0]-'A';
            int i=0;
            for(;canshu[i]!=',';i++);
            i++;
            biao1=canshu[i]-'A';
            shu[biao]=shu[biao1];
        }
        else if(!strcmp(zhiling,xchg)){
            biao=canshu[0]-'A';
            int i=0,x=shu[biao];
            for(;canshu[i]!=',';i++);
            i++;
            biao1=canshu[i]-'A';
            shu[biao]=shu[biao1];
            shu[biao1]=x;
        }
        else if(!strcmp(zhiling,add)){
            biao=canshu[0]-'A';
            int i=0;
            for(;canshu[i]!=',';i++);
            i++;
            biao1=canshu[i]-'A';
            if(len>5){
                for(;canshu[i]!=',';i++);
                i++;
                biao2=canshu[i]-'A';
                shu[biao]=shu[biao1]+shu[biao2];
            }
            else shu[biao]=shu[biao]+shu[biao1];
        }
        else if(!strcmp(zhiling,sub)){
            biao=canshu[0]-'A';
            int i=0;
            for(;canshu[i]!=',';i++);
            i++;
            biao1=canshu[i]-'A';
            if(len>5){
                for(;canshu[i]!=',';i++);
                i++;
                biao2=canshu[i]-'A';
                shu[biao]=shu[biao1]-shu[biao2];
            }
            else shu[biao]=shu[biao]-shu[biao1];
        }
        else if(!strcmp(zhiling,mul)){
            biao=canshu[0]-'A';
            int i=0;
            for(;canshu[i]!=',';i++);
            i++;
            biao1=canshu[i]-'A';
            if(len>5){
                for(;canshu[i]!=',';i++);
                i++;
                biao2=canshu[i]-'A';
                shu[biao]=shu[biao1]*shu[biao2];
            }
            else shu[biao]=shu[biao]*shu[biao1];
        }
        else if(!strcmp(zhiling,div)){
            biao=canshu[0]-'A';
            int i=0;
            for(;canshu[i]!=',';i++);
            i++;
            biao1=canshu[i]-'A';
            if(len>5){
                for(;canshu[i]!=',';i++);
                i++;
                biao2=canshu[i]-'A';
                shu[biao]=shu[biao1]/shu[biao2];
            }
            else shu[biao]=shu[biao]/shu[biao1];
        }
        else if(!strcmp(zhiling,mod)){
            biao=canshu[0]-'A';
            int i=0;
            for(;canshu[i]!=',';i++);
            i++;
            biao1=canshu[i]-'A';
            if(len>5){
                for(;canshu[i]!=',';i++);
                i++;
                biao2=canshu[i]-'A';
                shu[biao]=shu[biao1]%shu[biao2];
            }
            else shu[biao]=shu[biao]%shu[biao1];
        }
        else if(!strcmp(zhiling,and)){
            biao=canshu[0]-'A';
            int i=0;
            for(;canshu[i]!=',';i++);
            i++;
            biao1=canshu[i]-'A';
            if(len>5){
                for(;canshu[i]!=',';i++);
                i++;
                biao2=canshu[i]-'A';
                shu[biao]=shu[biao1]&shu[biao2];
            }
            else shu[biao]=shu[biao]&shu[biao1];
        }
        else if(!strcmp(zhiling,or)){
            biao=canshu[0]-'A';
            int i=0;
            for(;canshu[i]!=',';i++);
            i++;
            biao1=canshu[i]-'A';
            if(len>5){
                for(;canshu[i]!=',';i++);
                i++;
                biao2=canshu[i]-'A';
                shu[biao]=shu[biao1]|shu[biao2];
            }
            else shu[biao]=shu[biao]|shu[biao1];
        }
        else if(!strcmp(zhiling,xor)){
            biao=canshu[0]-'A';
            int i=0;
            for(;canshu[i]!=',';i++);
            i++;
            biao1=canshu[i]-'A';
            if(len>5){
                for(;canshu[i]!=',';i++);
                i++;
                biao2=canshu[i]-'A';
                shu[biao]=shu[biao1]^shu[biao2];
            }
            else shu[biao]=shu[biao]^shu[biao1];
        }
    }
    return 0;
}
