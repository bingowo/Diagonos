#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int pro;
    scanf("%d",&pro);
    for(int index=0;index<pro;index++){

        int num[9];
        int iszero=1,firstplace=0;
        for(int i=8;i>=0;i--) scanf("%d",&num[i]);
        printf("case #%d:\n",index);

        for(int i=8;i>=1;i--){
            if(num[i]!=0){
                iszero=0;
                if(num[i]<0){
                    printf("-");
                    num[i]=-num[i];
                    firstplace=1;
                }
                else if(num>0) {
                        if(firstplace!=0) printf("+");
                        else firstplace=1;
                }
                if(num[i]!=1 && i!=1) printf("%dx^%d",num[i],i);
                else if(num[i]==1 && i!=1) printf("x^%d",i);
                else if(num[i]!=1 && i==1) printf("%dx",num[i]);
                else printf("x");
            }
        }
        if(!iszero || num[0]!=0){
            if(num[0]!=0){
                if(num[0]<0){
                    printf("-");num[0]=-num[0];
                }
                else {
                    if(firstplace!=0)printf("+");
                }
                printf("%d",num[0]);
            }
        }
        else printf("0");
        printf("\n");
    }
    return 0;
}
