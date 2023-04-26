#include <stdio.h>
#include <stdlib.h>
long long climb(int n)
{
    static long long mmry[50] = {0};
    if(n == 1) return 1;
    else if(n == 2) return 2;
    else if(n == 3) return 4;
    else if(n == 4) return 8;
    else{
        if(!mmry[n]){
            mmry[n] = climb(n-1)+climb(n-2)+climb(n-3)+climb(n-4);
            return mmry[n];
        }
        else return mmry[n];
    }

}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld%c",i,climb(n),(i == T-1)?'\0':'\n');
    }
    return 0;
}
