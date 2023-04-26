#include<stdio.h>

long long change_to10(int A,char n[],int i); //将任何进制转换为十进制
char change(int N,int B);  //十进制转换至任何进制
int main()
{
    int A,B,i=0;
    long long N;
    char n[100];
    scanf("%d",&A);  //A表示后面数原有的进制
    scanf("%s",n);
    scanf("%d",&B);  //B表示所需要的进制
    N = change_to10(A,n[100],i);
    change(N,B);
    return 0;
}
char change(int N,int R)
{
    char a[100];
    int i = 0,flag = 0;
    if (N<0){
        N = -N;
        flag = 1;
    } 
    while(N){
        a[i]=N%R<10 ? N%R+'0': 'A'+N%R-10;
        N = N/R;
        i++;
    }
    if(flag == 1) a[i]='-';
    else i = i-1;
    for (int n = i;n>= 0;n--){
        printf("%c",a[n]);
    }
    printf("\n");
    return 0;
}
long long change_to10(int A,char n[],int i)//A表示数原有的进制，n[]表示该数，i表示n[]中元素个数
{
    int m,product = 1;
    long long N = 0;
    for(m = i-1;m>=0;m--){
        if(n[m]<='9'&&n[m]>='0'){
            N = N+(n[m]-'0')*product;
            product *= A;
        }else if(n[m]<='f'&&n[m]>='a'){
            N = N + (n[m] -'a'+10)*product;
            product *= A;
        }else if(n[m]<='F'&&n[m]>='A'){
            N = N + (n[m] -'A'+10)*product;
            product *= A;
        }
    }
    return N;
}
