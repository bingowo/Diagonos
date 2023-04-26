#include <stdio.h>
#include <string.h>
int a[1000];
int han(long long int n)
{
    int i=0;
    int flag=1,x=10;
    while(n){
        a[i]=n%x;
        if(a[i]==9){
            flag=0;
            break;
        }
        i++;
        n/=10;
    }
    return flag;


}
int main()
{
    long long int n,i;
    scanf("%lld",&n);

    for(i=n+1;;i++){
        if(i%9!=0&&han(i)!=0){
            break;
        }
    }
    printf("%lld",i);

}
