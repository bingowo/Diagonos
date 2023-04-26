#include <stdio.h>
#include <string.h>
#define L 500
//第L位是小数点位，1～L有500位是整数位，L+1～2L有500位是小数位，一共2L+1位,第0位空着
void input(int a[]);
void minus(int a[],int b[],int N);
void output(int a[],int N);
int main(){
    int A[2*L+2]={0},B[2*L+2]={0};//多搞一位用来存放符号，嘿嘿
    int N;
    input(A);
    input(B);
    scanf("%d\n",&N);
    minus(A,B,N);
    output(A,N);
    return 0;
}
void minus(int a[],int b[],int N){
    int i=0,*da,*xiao;
    while(a[i]==b[i]) i++;
    if(a[i]>b[i]){
        a[2*L+1]=1;//符号位
        da=a,xiao=b;
    }
    else{
        a[2*L+1]=-1;//符号位
        da=b,xiao=a;
    }
    int m=0;
    while(*(da+m)==0) m++;//跳过前置0
    int j;
    for(j=0;j<=L+N+1;j++){
        if(*(da+m+j+1)<*(xiao+m+j+1)){
            *(da+m+j+1)+=10;
            *(da+m+j)-=1;//借位操作
        }
        *(da+m+j)-=*(xiao+m+j);
    }
    if(*(da+m+j)>=5){
        int k=1;
        while(*(da+m+j-k)==9){
            *(da+m+j-k)=0;
            k++;
        }
        *(da+m+j-k)+=1;
    }
    for(int cnt=0;cnt<=2*L+1;cnt++){
        a[cnt]=*(da+cnt);
    }

}

void input(int a[])   //input a float number
{
    char s[L+1];
    scanf("%s",s);
    int i=0,j,k;
    while(s[i] && s[i]!='.') i++; //定位小数点

    for(j=i-1,k=L;j>=0;j--,k--)
        a[k] = s[j]-'0';  //整数部分
    for(j=i+1,k=L+1;j<strlen(s);j++,k++)
        a[k] = s[j]-'0';   //小数部分
}


void output(int a[], int N){
    int i=0;
    if(a[2*L+1]==-1) printf("-"); 
    while(i<=L && a[i]==0) i++;//跳过前置零
    if(i>L) printf("0");//整数部分为零
    else{
        while(i<L){
            printf("%d",a[i]);//整数部分
            i++;
        }
    }
    printf(".");
    while(i<=L+N){
        printf("%d",a[i]);//小数部分
        i++;
    }
    printf("\n");
}