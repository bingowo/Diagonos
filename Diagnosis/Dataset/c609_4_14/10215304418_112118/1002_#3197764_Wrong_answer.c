#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        int n;
        int a[10010];
        scanf("%d",&n);
        int i=1;
        while (n!=0){
            a[i]=n%2;
            n=n/2;
            i++;
        }
        i--;
        int ans=0;
        int num=1;
        for (int j=1;j<=i-1;j++){
            if (a[j+1]==a[j]){
                if (ans<num) ans=num;
                num=1;
            }
            else num++;
        }
        if (ans<num) ans=num;
        printf("case #%d:\n%d\n",l,ans);
    }
    return 0;
}
