#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        int N;
        scanf("%d",&N);
        int ans = 0;
        for(int i = 0; i <= N; i = i + 5){
            int temp = i;
            if(temp == 0){;}
            else{
                while(temp % 5 == 0){
                ans++;
                temp = temp / 5;
                }
            }

        }
        printf("case #%d:\n",t);
        printf("%d\n",ans);
    }
    return 0;
}
