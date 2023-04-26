#include<stdio.h>
#include<math.h>
#include<string.h>
char M(int a,int b){
    int temp=0,i=0,k=0;
    char arr[]="0123456789ABCDEF";
    char brr[33];
    char* p =arr;
    while(a!=0){
        temp=abs(a%b);
        brr[i++]=*(p+temp);
        a=a/b;
    }
    return brr[33];
}
int main(){
    int N,R,L ;
    L=-R;
    char arr[]="abcdef";
    scanf("%d %d",&N,&L);
    if(L<-16){L=-16;}
    printf("%s",M(N,L));
    return 0 ;
}