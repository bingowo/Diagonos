#include<stdio.h>

void fileio(){
    #ifdef FILEIO
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
}
#define false 0
#define true 1
int stk[35];
int stklen;

void initialize(){
    stklen=0;
}
char change(int num){//according to
    if(num<10){
        return num+'0';
    }else{
        return num-10+'A';
    }
}

int main(){
    fileio();//used for LOCAL test
    
    int T;
    scanf("%d",&T);
    while(T--){
        initialize();
        int isnegative;
        int N,R;
        
        scanf("%d%d",&N,&R);
        if(N<0){
            N=-N;
            isnegative=true;
        }else{
            isnegative=false;
        }

        while(N!=0){//转换为R进制数
            stk[stklen++]=N%R;//store a_i
            N/=R;
        }
        
        if(isnegative){//输出部分
            putchar('-');
        }
        while(stklen--){
            putchar(change(stk[stklen]));
        }
        putchar('\n');
    }
}