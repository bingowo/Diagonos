#include<stdio.h>
#include<string.h>
int ans[4];
int read(){
    char s[10];
    scanf("%s",s);
    int flag=0;
    if(!strcmp(s,"A")) flag=1;
    else if(!strcmp(s,"B")) flag=3;
    else if(!strcmp(s,"AB")) flag=2;
    else if(!strcmp(s,"O")) flag=4;
    else if(!strcmp(s,"?")) flag=0;
    return flag;
}
void print(int x,int type){
    if(type==1){
        printf("{");
    }
    else if(type>1) printf(",");
    if(x==1) printf("A");
    if(x==2) printf("AB");
    if(x=3) printf("B");
    if(x==4) printf("O");
}
void write(){
    int ABO=0;
    for(int i=0;i<4;i++){
        ABO+=ans[i];
    }
    if(ABO==0){
        printf("impossible");
    }
    else{
        int cut=0;
        for(int i=0;i<4;i++){
            if(ans[i]){
                cut++;
                print(i+1,cut);
            }
        }
        printf("}");
    }
}
int main(){
    const int abo[4][4][4]={1,0,0,1,  1,1,1,0,  1,1,1,1,  1,0,0,1,
1,1,1,0,   1,1,1,0,   1,1,1,0,  1,0,1,0,
 1,1,1,1,  1,1,1,0,    0,0,1,1,  0,0,1,1, 
1,0,0,1,   1,0,1,0,    0,0,1,1,  0,0,0,1};
    int father,mother,child;
    father=read();
    mother=read();
    child=read();
    if(father==0){
        int m1,c1;
        m1=mother-1;
        c1=child-1;
        for(int i=0;i<4;i++){
            ans[i]=abo[i][m1][c1];
        }
    }
    if(mother==0){
        int m1=father-1;
        int c1=child-1;
        for(int i=0;i<4;i++){
            ans[i]=abo[m1][i][c1];
        }
    }
    if(child==0){
        int m1=father-1;
        int c1=mother-1;
        for(int i=0;i<4;i++){
            ans[i]=abo[m1][c1][i];
        }
    }
    if(father!=0){
        print(father,0);
    }
    else{
        write();
    }
    printf(" ");
    if(mother!=0){
        print(mother,0);
    }
    else{
        write();
    }
    printf(" ");
    if(child!=0){
        print(child,0);
    }
    else{
        write();
    }
    printf("\n");
    return 0;
}