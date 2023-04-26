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

    //对N+L+1位进行计算
    int j=2*L;
    while(da[j]==0 && xiao[j]==0 && j>L+N) j--;
    for(;j>L+N;j--){
        if(da[j]>=xiao[j])
            da[j]-=xiao[j];
        else{
            da[j-1]-=1;
            da[j]+=(10-xiao[j]);
        }
    }

    //四舍五入
    if(da[L+N+1]>=5){
        int k=1;
        while(da[L+N+1-k]==9){
            k++;
            da[L+N+1-k]=0;
        }
        da[L+N+1-k]+=1;
    }

    //之后一口气算到0
    for(;j>=0;j--){
        if(da[j]>=xiao[j])
            da[j]-=xiao[j];
        else{
            da[j-1]-=1;
            da[j]+=(10-xiao[j]);
        }
    }

    //最后把da里除了符号为都放进a里
    for(int cnt=0;cnt<=2*L;cnt++){
        a[cnt]=da[cnt];
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
        while(i<=L){
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