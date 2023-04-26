#include <stdio.h>
#include <stdlib.h>

const int ABO[4][4][4]=
{
    1,0,0,1,  1,1,1,0,  1,1,1,1,  1,0,0,1,
    1,1,1,0,  1,1,1,0,  1,1,1,0,  1,0,1,0,
    1,1,1,1,  1,1,1,0,  0,0,1,1,  0,0,1,1,
    1,0,0,1,  1,0,1,0,  0,0,1,1,  0,0,0,1
};


int ans_ABO[4];

int read(){
    char s[2];
    scanf("%s",s);
    if(!strcmp(s,"A"))return 1;
    else if(!strcmp(s,"AB"))return 2;
    else if(!strcmp(s,"B"))return 3;
    else if(!strcmp(s,"O"))return 4;
    else if(!strcmp(s,"?"))return 0;
}

void print(int x,int y){
    if(y == 1)printf("{");
    else if(y > 1)printf(",");
    if(x == 1)printf("A");
    if(x == 2)printf("AB");
    if(x == 3)printf("B");
    if(x == 4)printf("O");
}

void write(){
    int flag = 0;
    int count = 0;
    for(int i = 0;i < 4;i++){
        if(ans_ABO[i]){
            count++;
            flag = 1;
            print(i + 1,count);
        }
    }
    if(flag)printf("}");
    else printf("impossible");
}

int main()
{
    int father,mother,child;
    father = read();
    mother = read();
    child = read();
    if(father == 0){
        int m = mother -1,c = child - 1;
        for(int i = 0;i < 4;i++)
            ans_ABO[i] = ABO[i][m][c];
    }
    if(mother == 0){
        int f = father -1,c = child - 1;
        for(int i = 0;i < 4;i++)
            ans_ABO[i] = ABO[f][i][c];
    }
    if(child == 0){
        int f = father -1,m = mother -1;
        for(int i = 0;i < 4;i++)
            ans_ABO[i] = ABO[f][m][i];
    }
    if(father!=0) print(father,0);
    else write();
    printf(" ");
    if(mother!=0) print(mother,0);
    else write();
    printf(" ");
    if(child!=0) print(child,0);
    else write();
    printf("\n");

    return 0;
}
