#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
}
 
int main()
{
    char sign; scanf("%c",&sign);
    int n, num[1001] = {0}, a[100], cnt=0;
    while(scanf("%d",&n)){
        if(num[n] == 0){
            num[n] = 1;
            a[cnt++] = n;
        }
    }
    qsort(a, cnt, sizeof(int), cmp);
    if(sign == 'A') {
        for(int i=0; i<cnt; ++i)
            printf("%d%s",a[i],i<cnt-1?" ":"\n");
    }else {
        for(int i=cnt-1; i>=0; --i)
            printf("%d%s",a[i],i?" ":"\n");
    }
    return 0;
}
