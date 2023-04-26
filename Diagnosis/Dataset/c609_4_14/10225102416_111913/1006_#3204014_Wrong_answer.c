#include<stdio.h>
#include<string.h>

long long change_to10(char *p,int i); //将任何进制转换为十进制
int main()
{
    int T,m,i,a;
    char n[50][50];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%s",n[i]);
    }
    for(i=0;i<T;i++){
        a = strlen(n[i]);
        printf("case #%d:\n",i);
        printf("%lld\n",change_to10(n[i],a));
    }
    return 0;
}
long long change_to10(char *p,int i)//*p表示该数，i表示*p中元素个数
{
    long long N = 0;
    int a[50];
    int product = 1,m,n=1;
    if(i == 1){
        a[0]=1;
    }else if(i == 2){
        a[0]=1;
        if(p[0]!=p[1]) a[1]=0;
        else a[1] = 1;
    }else if(i>2){
        for(m = 0;m<i;m++){
            if(p[m]==p[0]) a[m]=1;
        }
        m = 1;
        while((p[m++]==p[0])) n++;
        for(m = 0;m<i;m++){
            if(p[m]==p[1]) a[m]=0;
        }
        m = 1;
        while((p[m++]==p[0])) n++;
    }
    for(m = i-1;m>=0;m--){
            N = N + a[m]*product;
            product *= i;
    }
    return N;
}
