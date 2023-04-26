#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n=0,m=0;
        scanf("%d %d",&n,&m);
        int jieguo=0,yushu=0,num=0,chong=-1;
        int yu[100];
        printf("case #%d:\n",t);
        printf("0.");
        yushu=n;
        yu[0]=yushu;
        num++;
        while(yushu!=0){
            yushu*=10;
            jieguo=yushu/m;
            yushu=yushu%m;
            printf("%d",jieguo);
            int i=0;
            for(;i<num;i++){
                if(yu[i]==yushu) {
                    chong=i;
                    break;
                }
            }
            if(i==num) yu[num++]=yushu;
            if(chong!=-1) break;
        }
        printf("\n");
        if(chong!=-1) printf("%d-%d\n",chong+1,num);
    }
    return 0;
}
