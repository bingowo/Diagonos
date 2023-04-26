#include <stdio.h>

int main() {
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n;
        scanf("%d",&n);
        int a[32];
        int i=0;
        while(n!=0)
        {
            a[i++]=n%2;
            n=n/2;
        }//转换为2进制
        int num=1,c=1;
        for(int j=i-1;j>=1;j--)
        {
            if(a[j] != a[j-1])
            {
                num++;
            }
            else
            {
                c=num>c?num:c;
                num=1;
            }
        }
        c=num>c?num:c;
        printf("case #%d:\n%d\n",t,c);
    }
    return 0;
}
