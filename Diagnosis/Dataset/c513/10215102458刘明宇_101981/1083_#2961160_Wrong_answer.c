#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

int main()
{
    int T,cnt=0;
    scanf("%d",&T);
    while(T-->0){
        int cnt2 = 0,cnt5 = 0;
        int N;
        scanf("%d",&N);
        for(int i = 1;i <= N;i++){
            if(i%2 == 0) cnt2++;
            if(i%5 == 0) cnt5++;
        }
        int max = cnt2>cnt5?cnt5:cnt2;
        printf("case #%d:\n",cnt);
        printf("%d\n",max);
    }
}