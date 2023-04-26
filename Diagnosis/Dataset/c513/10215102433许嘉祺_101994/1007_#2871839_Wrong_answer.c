#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()

{
    int t,a;
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d",&a);
        int max=1,f=a&1,n=1;
        while (a>0){
            a=a>>1;
            if (a&1!=f) n=n+1;
            else n=1;
            f=a&1;
            max=max>n?max:n;

        }
        printf("case #%d:\n",i);
        printf("%d\n",max);
    }
    return 0;
}
