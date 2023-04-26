#include <stdio.h>
#include <stdlib.h>

long long int jump(int n);

int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    long long int s[51];
    s[0] = 1;
    s[1] = 1;
    s[2] = 2;
    s[3] = 4;
    for(int i = 4;i < 51;i++){
        s[i] = s[i-1] + s[i-2] + s[i-3] + s[i-4];
    }
    while(T-- > 0){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",cnt);
        printf("%lld\n",s[n]);
        cnt++;
    }
}

