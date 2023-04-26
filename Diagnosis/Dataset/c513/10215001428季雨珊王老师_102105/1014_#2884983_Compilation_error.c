#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int x[10]={0},y[10]={0};
    int A,B;
    if(b==0){
        A=a;
        B=b;
    }
    else{
        A=a/b;
        B=a%b;
    }//分离整数小数
    int lx=0,ly=0;
    for(int i=0;A;i++){
        x[i]=A%3;
        A/=3;
        lx++;
    }
    for(int i=0;B;i++){
        y[i]=B%3;
        B/=3;
        ly++;
    }//转化三进制第一步
    int *x1,*x2,*y1,*y2;
    x1=(int *)malloc(sizeof(int)*lx);
    x2=(int *)malloc(sizeof(int)*lx);
    for(int i=0;i<lx;i++){
        x1[i]=x[lx-1-i]+1;
    }
    y1=(int *)malloc(sizeof(int)*ly);
    y2=(int *)malloc(sizeof(int)*ly);
    for(int i=0;i<ly;i++){
        y1[i]=y[ly-1-i]+1;
    }
    for(int i=ly-1;i>=0;i--){
        if(y1[i]>=3&&i>=1){
            y1[i]%=3;
            y1[i-1]+=1;
        }
        else if(y1[i]>=3&&i=0){
            y1[i]%=3;
            x1[lx-1]+=1;
        }
    }
    for(int i=lx-1;i>=0;i--){

    }
    return 0;
}
