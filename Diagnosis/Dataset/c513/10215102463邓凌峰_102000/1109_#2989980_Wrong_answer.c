#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 50

typedef struct{
    int num[50];
}N;

void add(int*a,int *b){
    for(int i=LEN-1;i;i--){
        a[i]+=b[i];
        for(int k=i;a[k]>9;k--){
            a[k-1]+=a[k]/10;
            a[k]%=10;
        }
    }


}

int main()
{
    int T;scanf("%d",&T);
    for(int i;i<T;i++){
        int nums[9];
        for(int j=0;j<9;j++){
            scanf("%d",&nums[j]);
        }
        printf("case #%d:\n",i);
        int haveNum=0,haveHead=0;
        for(int m=0,n=8;m<9,n>=0;m++,n--){
            if(nums[m]!=0){
                haveNum=1;
                if(nums[m]>0){
                    if(haveHead==1){printf("+");}
                    if(nums[m]==1);
                    else printf("%d",nums[m]);
                }
                haveHead=1;
                if(nums[m]<0){
//                    printf("-");
                    if(nums[m]==-1){
                        if(n==0){printf("-1");}
                        else printf("-");
                    }
                    else printf("%d",nums[m]);
                }
                if(n!=0){
                    if(n==1) printf("x");
                    else printf("x^%d",n);
                }
            }
        }
        if(haveNum==0) printf("0");
        printf("\n");
    }


    return 0;
}

