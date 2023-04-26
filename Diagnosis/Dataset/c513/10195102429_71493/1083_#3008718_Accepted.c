#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,N;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
            scanf("%d",&N);
            int count=0;
            for(int j=1;j<=N;j++){
                    int tmp=j;
                    while(tmp%5==0){
                            tmp/=5;
                            count++;
                }

            }
            printf("case #%d:\n",i);
            printf("%d\n",count);

    }
    return 0;
}
