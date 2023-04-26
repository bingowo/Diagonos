#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Gcd(int a, int b){
    if(b%a==0) return a;
    else return Gcd(b, a%b);
}
int main(){
    char s[31];
    scanf("%s", s);
    int A=0, B=0, C=1;
    int temp, len=strlen(s), ret=0;
    for(int i=0; i<len; i++){ //计算A
        if(s[i]=='.'){
            ret = i;
            break;
        }
        if(s[i]=='1')  temp=1;
        else if(s[i]=='2') temp=-1;
        else temp=0;
        A = A*3+temp;
    }
    if(ret!=0){
        for(int i=ret+1; i<len; i++){  //计算BC
            if(s[i]=='1')  temp=1;
            else if(s[i]=='2') temp=-1;
            else temp=0;
            B = B*3+temp;
            C = C*3;
        }
        temp = Gcd(abs(B), C);  //求最大共因子
        if(A==0){  //A==0情况
            printf("%d %d", B/temp, C/temp);
        }else{ //A！=0
            if((A>0&&B>0)||(A<0&&B<0)){  //AB同号
                printf("%d %d %d", A, abs(B/temp), C/temp);
            }else{
                if(A>0){
                    A -= 1;
                    B = B+C;
                    temp = Gcd(B, C);
                    if(A!=0) printf("%d %d %d", A, B/temp, C/temp);
                    else printf("%d %d", B/temp, C/temp);
                }else{
                    A += 1;
                    B = C-B;
                    temp = Gcd(B, C);
                    if(A!=0) printf("%d %d %d", A, B/temp, C/temp);
                    else printf("%d %d", B/temp, C/temp);
                }
            }
        }
    }else{
        printf("%d", A);
    }
    return 0;
}