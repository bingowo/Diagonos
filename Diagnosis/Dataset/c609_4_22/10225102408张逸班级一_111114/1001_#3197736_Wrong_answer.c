#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
     while(a--){
        int b,c;
        scanf("%d %d",&b,&c);
        int d;
        while(b/c){
            if(b/c<10){
            printf("%d",b/c);}
            else 
            printf("%c","A"+b/c-10);    
            b%=c;
            
        }
        if(b<10){
            printf("%d\n",b);
        }
        else printf("%c\n","A"+b/c-10);
     }
     return 0;
}