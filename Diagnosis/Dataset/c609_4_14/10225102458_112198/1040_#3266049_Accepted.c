#include <stdio.h>
#include <stdlib.h>

void collect(char *a,int *a1)
{
    char *c=a;
    while(*c){
        int flag=1,factor=0,ifone=1,m=0;
        if((*c)=='-'){flag=-1;c++;}
        while('0'<=(*c)&& (*c)<='9'){
            ifone=0;
            factor=factor*10+(*c)-'0';
            c++;
        }
        if(ifone)factor=1;
        if((*c)=='x'){
            c++;
            if((*c)=='^'){
                c++;
                while('0'<=(*c)&& (*c)<='9'){
                    m=m*10+(*c)-'0';
                    c++;
            }
                a1[m]=flag*factor;
            }
            else a1[1]=flag*factor;
        }
        else a1[0]=flag*factor;
        if((*c)=='+')c++;
    }
}
void mul(char *a,char *b,int* num)
{
    int a1[1000]={0};
    int b1[1000]={0};
    collect(a,a1);
    collect(b,b1);
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            num[i+j]+=a1[i]*b1[j];
        }
    }
}
int main()
{
    char a[1000],b[1000];

    while(scanf("%s%s",a,b)==2){
        int num[10000]={0};
        mul(a,b,num);
        for(int i=9999;i>=0;i--){
            if(num[i])printf("%d ",num[i]);
        }
        printf("\n");
    }
    return 0;
}
