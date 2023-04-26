#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,cnt = 0,res = 0;
    scanf("%d",&n);
    int *pit = (int *)malloc(4*n);
    do{
        scanf("%d",&pit[cnt++]);
    }while(getchar() != '\n');
    for(int i = 0;i < n - 1;i++){
        int temp = abs(pit[i+1] - pit[i]);
        for(int j = i+2;j < n - 2;j++){
            if (abs(pit[j] - pit[i]) < temp) temp = abs(pit[j] - pit[i]);
        }
        res += temp;
    }
    free(pit);
    printf("%d",res);
    return 0;
}
