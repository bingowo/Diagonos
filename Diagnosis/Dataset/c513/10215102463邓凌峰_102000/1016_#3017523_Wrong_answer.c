#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 100
#define BigNUm 10007
//#define N 100000



int main() {
    int N,R;scanf("%d%d",&N,&R);
    int cnt=0;
    char ans[LEN]={0};
    int tmpN=N;
    int absR=-R;
    while(tmpN){
        int tmp1=tmpN%R;
        int tmp2=tmpN/R;
        if(tmp1<0){
            tmp1+=absR;
            tmp2+=1;
        }
        ans[cnt++]=(tmp1>=10)?(tmp1-10+'A'):(tmp1+'0');
        tmpN=tmp2;
    }
    for(int k=cnt-1;k>=0;k--){
        printf("%c",ans[k]);
    }



    return 0;
}

