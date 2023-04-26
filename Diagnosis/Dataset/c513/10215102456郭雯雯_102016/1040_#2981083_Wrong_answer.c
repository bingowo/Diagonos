#include<stdio.h>
#include<string.h>
const int g[4][4][4]={
    0,3,4,4,0,1,2,4,0,1,2,3,0,3,4,4,
    0,1,2,4,0,1,2,4,0,1,2,4,0,2,4,4,
    0,1,2,3,0,1,2,4,2,3,4,4,2,3,4,4,
    0,3,4,4,0,2,4,4,2,3,4,4,3,4,4,4
};

int t1(char* c){
    int t;
    if(!strcmp(c,"A"))t=0;
    else if(!strcmp(c,"AB"))t=1;
    else if(!strcmp(c,"B"))t=2;
    else if(!strcmp(c,"O"))t=3;
    else if(!strcmp(c,"?"))t=4;
    return t;
}

void t2(int a){
    if(a==0)printf("A");
    else if(a==1)printf("AB");
    else if(a==2)printf("B");
    else if(a==3)printf("O");
}

int main(){
    char fa[2],mo[2],ch[2];
    scanf("%s %s %s",fa,mo,ch);
    int f=t1(fa),m=t1(mo),c=t1(ch);
    int ans[4]={4,4,4,4};
    if(c==4){
        printf("%s %s ",fa,mo);
        for(int i=0;i<4;i++)ans[i]=g[f][c][i];
        if(ans[0]!=4)printf("{");
        for(int i=0;i<3;i++){
            if(ans[i]!=4){
                t2(ans[i]);
                if(ans[i+1]!=4)printf(",");
            }
        }
        if(ans[3]!=4)t2(ans[3]);
        printf("}");
    }
}