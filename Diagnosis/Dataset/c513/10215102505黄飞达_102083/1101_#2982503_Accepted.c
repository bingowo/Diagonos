//1101 abo+rh版本
#include<stdio.h>
#include<string.h>

const int ABO[4][4][4]={
1,0,0,1,  1,1,1,0,   1,1,1,1,  1,0,0,1,
1,1,1,0,  1,1,1,0,   1,1,1,0,  1,0,1,0,
1,1,1,1,  1,1,1,0,   0,0,1,1,  0,0,1,1, 
1,0,0,1,  1,0,1,0,   0,0,1,1,  0,0,0,1};

int ans_ABO[4]={0}, rh[3]={0}, may_rh[3]={0};


int read(int i){
    char s[5]={};
    scanf("%s", s);
    rh[i]=s[strlen(s)-1]=='+'?1:0;
    s[strlen(s)-1]='\0';
    int res = 0;
    if (!strcmp(s, "A")) res=1;
    else if (!strcmp(s, "AB")) res=2;
    else if (!strcmp(s, "B")) res=3;
    else if (!strcmp(s, "O")) res=4;
    return res;
}
void myprint(int x, int t, int flag){
    if (flag&&t==1) printf("{");
    else if (t>1) printf(",");
    switch(x){
        case 1:printf("A");break;
        case 2:printf("AB");break;
        case 3:printf("B");break;
        case 4:printf("O");break;
    }
    return;
}
void mywrite(int index){
    int temp=0;
    for (int i=0; i<4; i++) temp+=ans_ABO[i];
    if (temp==0) printf("impossible");
    else{
        int count=0, flag=(temp>1 || may_rh[index]==2);
        for (int i=0; i<4; i++){
            if (ans_ABO[i]){
                count++;
                if (may_rh[index]==2){
                    myprint(i+1, count++, flag);printf("+");
                    myprint(i+1, count++, flag);printf("-");
                }
                else if (may_rh[index]==1) {myprint(i+1, count++, flag);printf("+");}
                else {myprint(i+1, count++, flag);printf("-");}
            }
        }
        if (temp>1 || may_rh[index]==2) printf("}");
    }
    return;
}
int main(){
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++){
        memset(ans_ABO, 0, 16);memset(rh,0,3);memset(may_rh,0,3);
        int dad=read(0), mom=read(1), child=read(2);
        if (dad==0){
            int m1=mom-1, c1=child-1;
            for (int i=0; i<4; i++) ans_ABO[i] = ABO[i][m1][c1];
            if (rh[1]==0 && rh[2]==1) may_rh[0]=1;
            else may_rh[0]=2;
        }
        else if (mom==0){
            int d1=dad-1, c1=child-1;
            for (int i=0; i<4; i++) ans_ABO[i] = ABO[d1][i][c1];
            if (rh[0]==0 && rh[2]==1) may_rh[1]=1;
            else may_rh[1]=2;
        }
        else if (child==0){
            int d1=dad-1, m1=mom-1;
            for (int i=0; i<4; i++) ans_ABO[i] = ABO[d1][m1][i];
            if (rh[0]==0 && rh[1]==0) may_rh[2]=0;
            else may_rh[2]=2;
        }
        if (dad==0) mywrite(0);
        else {myprint(dad, 0, 1);printf("%c", rh[0]==0?'-':'+');}
        printf(" ");
        if (mom==0) mywrite(1);
        else {myprint(mom, 0, 1);printf("%c", rh[1]==0?'-':'+');}
        printf(" ");
        if (child==0) mywrite(2);
        else {myprint(child, 0, 1);printf("%c", rh[2]==0?'-':'+');}
        printf("\n");
    }
    return 0;
}