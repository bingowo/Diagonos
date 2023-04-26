#include<stdio.h>
#include<string.h>

int change_to10(char *p,int i); //将任何进制转换为十进制
int main()
{
    int T,m,i,a;
    char n[100];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%s",n+i);
    }
    for(i=0;i<T;i++){
        a = strlen(n);
        m = change_to10(n,a);
        printf("case#%d\n",i);
        printf("%d\n",m);
    }
    return 0;
}
int change_to10(char *p,int i)//*p表示该数，i表示*p中元素个数
{
    int N = 0,product = 1,m;
    for(m = i-1;m>=0;m--){
        if(p[m]=='-'){
            N = N+(-1)*product;
            product *= 3;
        }else if(p[m]=='1'){
            N = N + 1*product;
            product *= 3;
        }else if(p[m]=='0'){
            N = N + 0*product;
            product *= 3;
        }
    }
    return N;
}