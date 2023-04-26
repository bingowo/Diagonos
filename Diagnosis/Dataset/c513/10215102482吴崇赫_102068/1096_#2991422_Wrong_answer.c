#include<stdio.h>
#define N 105
int main()
{
    int T;
    scanf("%d\n",&T);
    while(T--){
        int ord_num,ord1[N],ord2[N];
        scanf("%d",&ord_num);
        for(int i=0;i<N;++i)ord1[i]=ord2[i]=0;
        int p=1;
        while(ord_num--){
            int a,b;
            scanf("%d %d",&a,&b);
            ord1[a]++;ord2[b]++;
        }
        for(int i=0;i<N;++i){
            if(ord1[i]&&ord2[i]){
                printf("Poor dxw!\n");
                p=0;break;
            }
        }
        if(p)printf("Lucky dxw!\n");
    }
    return 0;

}