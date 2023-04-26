#include <stdio.h>
typedef struct {
    int a[2600];
    int len;
    int cnt;
}MUL;
MUL b[1000]={0};
int main() {
    b[0].a[0]=1;
    b[0].len=1;
    b[0].cnt=0;
    for(int j=1;j<1000;j++){
        for(int q=0;q<b[j-1].len;q++){
            b[j].a[q]=b[j-1].a[q]*(j+1);
        }
        int carry=0,p=0,cnt1=0,sign=0;
        for(;p<b[j-1].len;p++){
            b[j].a[p]=b[j].a[p]+carry;
            carry = b[j].a[p]/10;
            b[j].a[p] = b[j].a[p]%10;
            if((b[j].a[p]==0)&&(sign==0)){
                cnt1++;
            }else{
                sign=1;
            }
        }
        if(carry){
            b[j].a[p] = carry;
            p++;
        }
        b[j].len=p;
        b[j].cnt=cnt1;
    }
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;
        scanf("%d",&N);
        printf("case #%d:\n",i);
        printf("%d\n",b[N-1].cnt);
    }
    return 0;
}
