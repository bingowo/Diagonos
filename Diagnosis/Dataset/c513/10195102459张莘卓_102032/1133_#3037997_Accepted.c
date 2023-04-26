#include <stdio.h>
#include <stdlib.h>

int a[1<<15]={0};
int main()
{
    int i, cnt=1;
    scanf("%d",&i);
    for(int j=0; j<i; ++j, cnt*=2)
        for(int k=cnt; k<2*cnt; ++k)
            a[k] = !a[k-cnt];
    for(int j=0; j<cnt; ++j) printf("%d",a[j]);
    printf("\n");
    return 0;
}
