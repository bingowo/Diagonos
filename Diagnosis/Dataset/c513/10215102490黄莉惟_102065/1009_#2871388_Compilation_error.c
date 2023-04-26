#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,num,num1;
    num=0;
    char s[1000];
    char c1;
    size_t len;
    scanf("%d",&n);
    int m=0;
    while(m<n){
        while(getchar(c1)!=EOF){
            num++;
            getchar(c1);
        }
        printf("%d\n",num);
        m++;
    }
}