#include<stdio.h>
#include<string.h>
int main()
{
    char a[1005];
    scanf("%s",a);
    long long inte=0,u=0,d=1;
    int i=0;
    for(;a[i]!='\0'&&a[i]!='.';i++){
        inte*=3;
        if(a[i]=='2')inte--;
        else inte+=a[i]-'0';
    }//整数部分
    int l=strlen(a);
    if(a[i]=='.'){
        for(int j=i+1;j<l;j++){
            u*=3;
            if(a[j]=='2')u--;
            else u+=(a[j]-'0');
            d*=3;
        }//小数部分
            printf("%lld\n",u);
        if(u<0){
            if(inte>0)inte--;
            else inte++;
            u=d+u;
        }
        if(inte<0){
                u=d-u;
                inte++;
        }
        if(inte==0)printf("%lld %lld",u,d);
        else printf("%lld %lld %lld",inte,u,d);
    }
    else printf("%lld",inte);
    return 0;
}
