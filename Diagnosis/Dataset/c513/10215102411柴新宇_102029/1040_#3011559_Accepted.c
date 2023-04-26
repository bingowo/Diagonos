#include<stdio.h>
#include<string.h>

const int ABO[4][4][4]={
1,0,0,1,  1,1,1,0,   1,1,1,1,  1,0,0,1,
1,1,1,0,  1,1,1,0,   1,1,1,0,  1,0,1,0,
1,1,1,1,  1,1,1,0,   0,0,1,1,  0,0,1,1, 
1,0,0,1,  1,0,1,0,   0,0,1,1,  0,0,0,1};

int ans_ABO[4]={0};

int read(){
    char s[5]={};
    scanf("%s", s);
    int res = 0;
    if (!strcmp(s, "A")) res=1;
    else if (!strcmp(s, "AB")) res=2;
    else if (!strcmp(s, "B")) res=3;
    else if (!strcmp(s, "O")) res=4;
    return res;
}
void myprint(int x, int t){
    if (t==1) printf("{");
    else if (t>1) printf(",");
    switch(x){
        case 1:printf("A");break;
        case 2:printf("AB");break;
        case 3:printf("B");break;
        case 4:printf("O");break;
    }
    return;
}
void mywrite(){
    int temp=0;
    for (int i=0; i<4; i++) temp+=ans_ABO[i];
    if (temp==0) printf("impossible");
    else{
        int count=0;
        for (int i=0; i<4; i++){
            if (ans_ABO[i]){
                count++;
                myprint(i+1, count);
            }
        }
        printf("}");
    }
    return;
}
int main(){
    int dad=read(), mom=read(), child=read();
    if (dad==0){
        int m1=mom-1, c1=child-1;
        for (int i=0; i<4; i++) ans_ABO[i] = ABO[i][m1][c1];
    }
    else if (mom==0){
        int d1=dad-1, c1=child-1;
        for (int i=0; i<4; i++) ans_ABO[i] = ABO[d1][i][c1];
    }
    else if (child==0){
        int d1=dad-1, m1=mom-1;
        for (int i=0; i<4; i++) ans_ABO[i] = ABO[d1][m1][i];
    }
    if (dad==0){mywrite();}
    else myprint(dad, 0);
    printf(" ");
    if (mom==0){mywrite();}
    else myprint(mom, 0);
    printf(" ");
    if (child==0){mywrite();}
    else myprint(child, 0);
    printf("\n");
    return 0;
}