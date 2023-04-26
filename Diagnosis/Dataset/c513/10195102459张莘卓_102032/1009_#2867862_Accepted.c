#include <stdio.h>
#include <stdlib.h>

int count1(char c) {
    int cnt = 0;
    for(int i=0; i<8; ++i)
        if((c>>i) & 1) ++cnt;
    return cnt;
}

void process(int i, int j) {
    if(i == 0) {
        printf("0/%d\n",j);
        return;
    }
    int a=i, b=j;
    while(b) {
        int t = a % b;
        a = b;
        b = t;
    }
    printf("%d/%d\n",i/a, j/a);
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int t=0; t<n; ++t) {
        char c;
        int c1=0, cnt=0;
        while((c=getchar())!='\n' && c!=EOF) {
            c1 += count1(c);
            cnt += 8;
        }
        process(c1, cnt);
    }
    return 0;
}
