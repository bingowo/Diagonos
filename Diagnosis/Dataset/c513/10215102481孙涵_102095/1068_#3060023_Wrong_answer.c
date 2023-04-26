#include <stdio.h>
#include <stdlib.h>

int count(int t);
int f(int n,int m);

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    while(n != -1 && m != -1){
        int ans;
        ans = f(n,m);
        printf("%d\n",ans);
        scanf("%d %d",&n,&m);
    }
    return 0;
}


int f(int n,int m){
    if(n < m){
        return 0;
    }else if(n == m){
        return 1;
    }else{
        return 2 * f(n-1,m) - f(n - m - 1, m) + count(n-1+m);
    }
}

int count(int t){
    int ans = 1;
    for(int i = 0; i < t; i++){
        ans = ans * 2;
    }
    return ans;
}
