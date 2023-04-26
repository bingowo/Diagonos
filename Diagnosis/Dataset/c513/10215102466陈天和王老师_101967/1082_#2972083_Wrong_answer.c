#include <stdio.h>
#include <string.h>
#define L 500
//第L位是小数点位，0～L有500位是整数位，L+1～2L有500位是小数位，一共2L+1位
void input(int a[]);
void add(int a[],int b[]);//这个一定不能返回结果啊，因为结果还是高精，只能存在数组里
void output(int a[],int N);
int main(){
    int A[2*L+1]={0},B[2*L+1]={0};
    int N;
    input(A);
    input(B);
    scanf("%d\n",&N);
//    int i=0;
//    while(A[i]==0) i++;
//    for(;i<2*L+1;i++){
//        printf("%d ",A[i]);
//    }
//    printf("\n");
//    i=0;
//    while(B[i]==0) i++;
//    for(;i<2*L+1;i++){
//        printf("%d ",B[i]);
//    }//测试行
    add(A,B);
    output(A,N);
    return 0;
}


void input(int a[]){
    char s[2*L+1];
    scanf("%s",s);
    int i=0;
    while(s[i]!='.' && s[i]) i++;
    if(s[i]=='.'){
        for(int j=1;i-j>=0;j++){
            a[L-j]=s[i-j]-'0';
        }
        for(int k=1;i+k<=strlen(s)-1;k++){
            a[L+k]=s[i+k]-'0';
        }
    }
    else{
        for(int m= strlen(s)-1,n=1;m>=0;n++,m--){
            a[L-n]=s[m]-'0';
        }
    }
}

void add(int a[],int b[]){
    int i;
//    for(i=2*L;i>L+N;i--)
//    {
//        a[i]+=b[i];
//        a[i-1]+=a[i]/10;
//        a[i]%=10;
//    }//一直运算到i=L+N，即小数点后第N位
    for(i=2*L;i>0;i--) {
        a[i] += b[i];
        a[i - 1] += a[i] / 10;
        a[i] %= 10;
    }
    a[i]+=b[i];//第零位当然也要运算
}

void output(int a[], int N){
    if(a[L+N+1]>=5){
        a[L+N]+=1;
        if(a[L+N]==10){
            a[L+N]=0;
            int c=1;
            while(a[L+N-c]==9){
                a[L+N-c]=0;
                c++;
            }
            if(N!=c) a[L+N-c]++;
            else{
                c=1;
                while(a[L-c]==9){
                    a[L-c]=0;
                    c++;
                }
                a[L-c]++;
            }
        }
    }
    int i=0;
    while(i<=L && a[i]==0) i++;
    if(i==L+1) printf("0.");
    else{
        while(i<L){
            printf("%d",a[i]);
            i++;
        }
    }
    printf(".");
    i++;
    while(i<=L+N){
        printf("%d",a[i]);
        i++;
    }
    printf("\n");
}