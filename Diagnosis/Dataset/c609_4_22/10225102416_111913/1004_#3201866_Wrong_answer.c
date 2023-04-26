#include<stdio.h>
#include<string.h>

int change_to10(int A,char *p,int i); //将任何进制转换为十进制
char change(int N,int B);  //十进制转换至任何进制
int main()
{
    int A,B,i,N;
    char n[100];
    scanf("%d",&A);  //A表示后面数原有的进制
    scanf("%s",n); //n表示要转换的数字
    scanf("%d",&B);  //B表示所需要的进制
    i = strlen(n);  //i表示元素个数
    N = change_to10(A,n,i);
    change(N,B);
    return 0;
}
char change(int N,int R)
{
    char a[1000];
    int i = 0;
    while(N){
        a[i]=N%R<10 ? N%R+'0': 'A'+N%R-10;
        N = N/R;
        i++;
    }
    if(N == 0) a[i] = '0';
    for (int n = i;n>= 0;n--){
        printf("%c",a[n]);
    }
    printf("\n");
    return 0;
}
int change_to10(int A,char *p,int i)//A表示数原有的进制，n[]表示该数，i表示n[]中元素个数
{
    int N = 0,product = 1,m;
    for(m = i-1;m>=0;m--){
        if(p[m]<='9'&&p[m]>='0'){
            N = N+(p[m]-'0')*product;
            product *= A;
        }else if(p[m]<='f'&&p[m]>='a'){
            N = N + (p[m] -'a'+10)*product;
            product *= A;
        }else if(p[m]<='F'&&p[m]>='A'){
            N = N + (p[m] -'A'+10)*product;
            product *= A;
        }
    }
    return N;
}
