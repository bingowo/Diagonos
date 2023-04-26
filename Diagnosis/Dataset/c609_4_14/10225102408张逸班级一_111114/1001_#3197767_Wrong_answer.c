#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
     while(a--){
        int b,c;
        scanf("%d %d",&b,&c);
        int flag=0;
        if(b<0){
            flag=1;
            b=-b;
        }
        while(b/c){
            if (flag){printf("%c","-");}
            if(b/c<10){
            printf("%d",b%c);}
            else 
            {printf("%c","A"+b%c-10);}    
            b%=c;
        
        }
        if(b<10){
            printf("%d\n",b);
        }
        else printf("%c\n","A"+b%c-10);
     }
     return 0;
}