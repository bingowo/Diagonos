#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int xishu[9];
        for(int i=0;i<9;i++) scanf("%d",&xishu[i]);
        printf("case #%d:\n",t);
        int wei=0;
        for(;wei<9;wei++){
            if(xishu[wei]!=0) break;
        }
        if(wei==9) printf("0");
        else{
            int zhishu=0;
            int ke=0;
            for(;wei<9;wei++){
                zhishu=9-wei-1;
                if(xishu[wei]==1){
                    if(ke==1) printf("+");
                    if(zhishu==0) printf("1");
                    else if(zhishu==1) printf("x");
                    else printf("x^%d",zhishu);
                    ke=1;
                }
                else if(xishu[wei]==-1){
                    if(zhishu==0) printf("-1");
                    else if(zhishu==1) printf("-x");
                    else printf("-x^%d",zhishu);
                    ke=1;
                }
                else {
                    if(xishu[wei]>0&&ke==1) printf("+");
                    if(xishu[wei]!=0) {
                        if(zhishu==0) printf("%d",xishu[wei]);
                        else if(zhishu==1) printf("%dx",xishu[wei]);
                        else printf("%dx^%d",xishu[wei],zhishu);
                    }
                    ke=1;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
