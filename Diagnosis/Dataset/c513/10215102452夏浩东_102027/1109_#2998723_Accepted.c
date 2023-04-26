#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int mm=0;mm<cnt;mm++)
    {
        int L[9],flag1=0;
        for(int i=0;i<9;i++) scanf("%d",&L[i]);
        for(int i=0;i<9;i++) if(L[i]!=0) {flag1=1;break;}
        printf("case #%d:\n",mm);
        if(flag1==0) printf("0\n");
        else{
            int k=8,begin=0;
            for(int i=0;i<9;i++){
            	if(L[i]!=0) begin=1;
                if(k>1){
                    if(L[i]!=0 && L[i]!=-1 && L[i]!=1){
                        printf("%dx^%d",L[i],k);
                    }else if(L[i]==-1){
                        printf("-x^%d",k);
                    }else if(L[i]==1){
                    	printf("x^%d",k);
					}
                }else if(k==1){
                    if(L[i]!=0 && L[i]!=-1 && L[i]!=1){
                        printf("%dx",L[i]);
                    }else if(L[i]==-1){
                        printf("-x");
                    }else if(L[i]==1){
                    	printf("x");
					}
                }else if(k==0){
                    if(L[i]!=0 && L[i]!=-1 && L[i]!=1){
                        printf("%d",L[i]);
                    }else if(L[i]==-1){
                        printf("-1");
                    }else if(L[i]==1){
                    	printf("1");
					}
                }
                if(i+1<=8 && L[i+1]>0 && begin==1) printf("+");
                k--;
            }
            printf("\n");
        }
    }
    return 0;
}