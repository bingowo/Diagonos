#include<stdio.h>

int num(long long int a)//判断数据a中1的个数
{
    int n=0,i=64;
    long long int m=1;
    while(i>0){
        if(a&m)n++;
        m=m<<1;
        i--;
    }
    return n;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t>0){
        char c;
        int m=0,z=0;
        while(scanf("%c",&c)!=EOF){
            int a=(int)c;
            z+=num(a);
            m+=8;
        }
        if(m%z==0){
            m/=z;
            z=1;
        }
        t--;
        printf("%d/%d",z,m);
    }
    
}