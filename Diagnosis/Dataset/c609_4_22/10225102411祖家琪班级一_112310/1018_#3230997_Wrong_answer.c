#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,j = 0;
    scanf("%d",&n);
    int *p = (int *)malloc(4 * n);
    do{
        scanf("%d",p+j);
        j++;
    }while(getchar() != '\n');
    int res = abs(*(p+1) - *p);
    for(int i = 2;i < n;i++){
        if(abs(*p+i - *((p+i)-1)) < res){
            res = abs(*p+i - *(p+i-1));
        }
    }
    printf("%d",res);
    return 0;
}
