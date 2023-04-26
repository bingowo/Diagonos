#include<stdio.h>
#include<math.h>
#include<string.h>
char M(int a,int b){
    int temp=0,i=0,k=0;
    char arr[]="0123456789ABCDEF";
    char brr[50];
    char crr[50];
    char* p =arr;
    while(a!=0){
        temp=a%b;
        brr[i++]=*(p+temp);
        a=a/b;
    }
    for (int j=strlen(brr)-1;j>=0;j--){
        crr[k++]=brr[j];
    }
    return crr[50];
}
int main(){
    int N,R ;
    char arr[]="abcdef";
    scanf("%d %d",&N,&(-R));
    if(-R<-16){-R=-16;}
    printf("%c",M(N,-R));
    return 0 ;
}