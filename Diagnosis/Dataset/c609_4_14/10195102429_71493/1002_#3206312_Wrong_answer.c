#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        int num[1000];
        int j=0;
        if(n==0){printf("0\n");continue;}
        while(n){
            num[j]=n%2;
            j++;
            n=n/2;
        }
        int tmp=1;
        int maxn=1;
        for(int i=1;i<j;i++){
            if(num[i]!=num[i+1]){
                tmp+=1;
            }
            else{
                if(num[i]==1) {tmp=0;continue;}
                else tmp=1;
            }
            if(tmp>maxn) maxn=tmp;
        }
        printf("case #%d:\n",i);
        printf("%d\n",maxn);

    }
    return 0;
}
