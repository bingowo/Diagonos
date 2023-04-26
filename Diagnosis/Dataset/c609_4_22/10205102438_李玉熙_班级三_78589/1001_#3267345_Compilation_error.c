#include<stdio.h>
#include<string.h>

void transfer(int a, int b){
    if(a<b){
        if(a<10)printf("%d",a);
        if(a>10)printf("%c",'A'+a-10);
    }
    if(a>=b){
        transfer(a/b,b);
        if(a%b<10)printf("%d",a%b);
        if(a%b>=10)printf("%c",'A'+a%b-10);
    }
    
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[2]={0};
    while(n--){
        scanf("%d%d",&a[0],&a[1]);
        transfer(a[0],a[1]);
        printf("\n");
        return 0;
    }