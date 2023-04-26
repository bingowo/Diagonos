#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void judge(char *a,char *b){
    if(strcmp("A",a)==0){
        b[0]='A',b[1]='O';
    }
    if(strcmp("AB",a)==0){
        b[0]='A',b[1]='B';
    }
    if(strcmp("B",a)==0){
        b[0]='B',b[1]='O';
    }
    if(strcmp("O",a)==0){
        b[0]='O',b[1]='O';
    }
}
void child(char fa[],char mo[],char ret[]){
    char f[2],m[2];
    judge(fa,f);
    judge(mo,m);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){//C代表AB血型
            if((f[i]=='A'&&m[j]=='A')||(f[i]=='A'&&m[j]=='O')||(f[i]=='O'&&m[j]=='A'))ret[0]=1;
            if((f[i]=='A'&&m[j]=='B')||(f[i]=='B'&&m[j]=='A'))ret[1]=1;
            if(f[i]=='O'&&m[j]=='O')ret[3]=1;
            if((f[i]=='B'&&m[j]=='B')||(f[i]=='B'&&m[j]=='O')||(f[i]=='O'&&m[j]=='B'))ret[2]=1;
        }
    }
}
char find(char c0,char c1,char p0,char p1){
    if(c0==p0||c0==p1)return c1;
    if(c1==p0||c1==p1)return c0;
}
void par(char ch[],char pa[],char ret[]){
    char c[2],p[2];
    judge(ch,c);
    judge(pa,p);
    if((c[0]!=p[0]&&c[0]!=p[1])&&(c[1]!=p[0]&&c[1]!=p[1]))ret[0]=-1;
    else{
        char oth=find(c[0],c[1],p[0],p[1]);
        if(oth=='A'){
            ret[0]=1;ret[1]=1;
        }
        if(oth=='B'){
            ret[1]=1;ret[2]=1;
        }
        if(oth=='O'){
            ret[3]=1;ret[0]=1;ret[2]=1;
            if(strcmp(ch,"O")!=0)ret[1]=1;
        }
    }
}
void prt(char ret[],int n){
    if(ret[0]&&n>0){n--;printf("A%c",n==0?'}':',');}
    if(ret[1]&&n>0){n--;printf("AB%c",n==0?'}':',');}
    if(ret[2]&&n>0){n--,printf("B%c",n==0?'}':',');}
    if(ret[4]&&n>0){n--;printf("O%c",n==0?'}':',');}
}
int main(){
    char fa[5],mo[5],ch[5];
    scanf("%s %s %s",fa,mo,ch);
    char ret[4]={0};
    if(strcmp("?",ch)==0){
        child(fa,mo,ret);int n=0;
        for(int i=0;i<4;i++){
            if(ret[i])n++;
        }
        printf("%s %s {",fa,mo);
        prt(ret,n);
    }
    if(strcmp("?",fa)==0){
        par(ch,mo,ret);
        if(ret[0]==-1){
            printf("impossible %s %s",mo,ch);
        }
        else{
            if(strcmp(ch,"AB")==0&&strcmp(mo,"AB")==0)ret[1]=1;
            int n=0;
            for(int i=0;i<4;i++){
            if(ret[i])n++;
            }
            putchar('{');
            prt(ret,n);
            printf(" %s %s",mo,ch);
        }
    }
    if(strcmp("?",mo)==0){
        par(ch,fa,ret);
        if(ret[0]==-1){
            printf("%s impossible %s",fa,ch);
        }
        else{
            if(strcmp(ch,"AB")==0&&strcmp(fa,"AB")==0)ret[1]=1;
            int n=0;
            for(int i=0;i<4;i++){
            if(ret[i])n++;
            }
            printf("%s {",fa);
            prt(ret,n);
            printf(" %s",ch);
        }
    }
    return 0;
}