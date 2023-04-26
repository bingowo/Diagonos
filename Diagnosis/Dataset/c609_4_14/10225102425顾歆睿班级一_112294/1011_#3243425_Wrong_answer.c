#include<stdio.h>
#include<string.h>
int main()
{
    char a[1005];
    scanf("%s",a);
    long long inte=0;
    int position;
    for(int i=0;a[i]!='\0'&&a[i]!=".";i++){
        inte*=3;
        if(a[i]=='2')inte--;
        else inte+=a[i]-'\0';
        position=i;
    }//整数部分
    if(a[++position]!='\0'){
        long long u=0,d=1;
        for(int i=position;a[i]!='\0';i++){
            u*=3;
            if(a[i]=='2')u--;
            else u+=a[i]-'\0';
            d*=3;
        }//小数部分
    printf("%lld %lld %lld",inte,u,d);
    }
    else printf("%lld",inte);
    return 0;
}