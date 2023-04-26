#include <stdio.h>

void set_array(int* a) {
    int cnt = -1, num[25];
    do{
        scanf("%d",&num[++cnt]);
    }while(getchar() == ',');
    for(int i=0; i<=cnt; ++i)
        a[i] = num[cnt-i];
}

int main()
{
    int prime[27] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int T;
    scanf("%d",&T);
    for(int k=0; k<T; ++k) {
        int a[26]={0}, b[26]={0}, carry = 0, i;
        set_array(a);  set_array(b);
        for(i=0; i<25; ++i) {
            a[i] += b[i] + carry;
            carry = a[i] / prime[i];
            a[i] %= prime[i];
        }
        if(carry) a[i] = carry;
        while(i>=0 && a[i]==0) --i;
        printf("case #%d:\n",k);
        if(i < 0) printf("0\n");
        else for(; i>=0; --i)
            printf("%d%s",a[i],i?",":"\n");
    }
    return 0;
    
}
