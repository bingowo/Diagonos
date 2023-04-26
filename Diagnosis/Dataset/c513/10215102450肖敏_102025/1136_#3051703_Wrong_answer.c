#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int bits[20001], next[20001];
    int zeronum = 0, zeropos = 0, onepos ;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &bits[i]);
        if (bits[i] == 0)
            zeronum++;//总的0的个数
    }
    onepos = zeronum;
    for (int i = 1; i <= n; i++) {
        if (bits[i] == 0)
            next[++zeropos] = i;//按顺序记录0的位置;
        else
            next[++onepos] = i;//1的位置
    }
    int k=1;
    for(int i=1;i<=n;i++)
    {
        k=next[k];
        if(k==1 && i<n)
        {
            printf("-1\n");
            return 0;
        }
    }
    int pos = 1;
    for (int i = 1; i <= n; i++) {
        pos = next[pos];
        printf("%d%c", bits[pos], i < n ? ' ' : '\n');
    }
    return 0;
}
