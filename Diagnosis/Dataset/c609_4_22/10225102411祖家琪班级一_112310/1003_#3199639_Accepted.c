#include <stdio.h>
#define b 2333
int main()
{
    long long n;
    int res[1000][100],T,j = 0;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        scanf("%lld",&n);
        do{
            res[i][j++] = n % b;
            n /= b;
        }while(n);
        j--;
        for(j;j > -1;j--){
            printf("%d%c",res[i][j],(j == 0)?'\n':' ');
        }
        j = 0;
    }
    return 0;
}
