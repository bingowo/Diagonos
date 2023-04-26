#include <stdio.h>
#include <stdlib.h>
long long stairs(int m)
{
    if(m==1)return 1;
    else if(m==2)return 2;
    else if(m==3)return 4;
    else if(m==4)return 8;
    else return stairs(m-1)+stairs(m-2)+stairs(m-3)+stairs(m-4);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int m;
        scanf("%d",&m);
        printf("%lld\n",stairs(m));
    }
    return 0;
}
