#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int a, n;
        scanf("%d %d",&a, &n);
        int len = 1, num[100] = {1};
        for(int k=0; k<n; ++k) {
            int carry = 0;
            for(int i=0; i<len; ++i) {
                int t = num[i] * a + carry;
                num[i] = t % 10;
                carry = t / 10;
            }
            if(carry) num[len++] = carry;
        }
        printf("case #%d:\n",j);
        for(int i=len-1; i>=0; --i)
            printf("%d",num[i]);
        printf("\n");
    }
    return 0;
}