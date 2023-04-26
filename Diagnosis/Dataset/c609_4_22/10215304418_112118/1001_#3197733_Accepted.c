#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int t,r;
        scanf("%d%d",&t,&r);
        if (t<0) {
            t=-t;
            printf("-");
        }
        char c[10010];
        int j=1;
        while (t!=0){
            int x=t%r;
            if (x>=10){
                c[j]='A'+x-10;
            }
            else c[j]='0'+x;
            j++;
            t=t/r;
        }
        c[j]='\0';
        for (int k=j-1;k>=1;k--){
            printf("%c",c[k]);
        }
        printf("\n");
    }
    return 0;
}
