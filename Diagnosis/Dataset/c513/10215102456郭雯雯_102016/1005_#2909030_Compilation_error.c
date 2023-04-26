#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);
    int n=0;
    char x[51],d[149];
    d[0]=0;d[1]='.';
    while(n<t){
        scanf("%s",x);
        int l=strlen(x);
        for(;l>1;){
            int i=2,chu=x[l]-'0';chu*=10;
            while(yu!=0){
                d[i]=chu/8+'0';
                yu=chu%8;
                i++;
            }
            d[0]=x[--l];
        }
        printf("case #%d:\n%s\n",n,d);
        n++;
    }
}