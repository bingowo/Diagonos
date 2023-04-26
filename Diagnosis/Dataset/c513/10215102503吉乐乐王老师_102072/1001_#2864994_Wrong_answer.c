#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int de,base;
        scanf("%d %d",&de,&base);
        int idx=0;
        do{
            char temp=de%base;
            if(temp>=10)temp+='A';
            else temp+='0';
            de/=base;
            putchar(temp);
        }while(de!=0);
        putchar('\n');
    }
}