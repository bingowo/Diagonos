#include<stdio.h>
#include<string.h>

long long change_to10(char *p); //将任何进制转换为十进制
int main()
{
    int T,m,i;
    char n[50][100];
        scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%s",n[i]);
    }
    for(i=0;i<T;i++){
        printf("case #%d:\n",i);
        printf("%lld\n",change_to10(n[i]));
    }
    return 0;
}
long long change_to10(char *p)//*p表示该数
{
    long long N = 0;
    int a[50],i;
    char b[50];
    int product = 1,n=0,m;
    for(m = 0;m<strlen(p);m++){
        if(strchr(b,p[m])) continue;
        else {b[n]=p[m];n++;}
    }
    n = n-1;
    if(n == 0){
        a[0]=1;
        for(m = strlen(p)-1;m>=0;m--){
        N = N + a[m]*product;
        product *= 2;
        return 0;
        }
    }else if(n == 1){
        for(m = 0;m<strlen(p);m++){
            if(p[m]==b[0]) a[m]=1;
            else if(p[m]==b[1]) a[m]=0;
        }
    }else if(n>=2){
        for(m = 0;m<strlen(p);m++){
            if(p[m]==b[0]) a[m]=1;
            else if(p[m]==b[1]) a[m]=0;
        }
        for(i = 2;i<=n;i++){
            for(m = 0;m<strlen(p);m++){
                if(p[m]==b[i]) a[m]=i;}
        }
    }
    for(m = strlen(p)-1;m>=0;m--){
        N = N + a[m]*product;
        product *= (n+1);
        }
    return N;
}
