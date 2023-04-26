#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int num=0;
    int n;
    for (num=0;num<T;num++){
        scanf("%d",&n);
        int a[50000]={0};
        int i=0;
        do{
            a[i]=n%2;
            i++;
            n=n/2;
        }while(n!=0);
        int j,count,max;
        count=1;
        max=1;
        for(j=i-1;j>0;j--){
            if(a[j]!=a[j-1]){
                count++;
                if(count>max){
                    max=count;
                }
            }
            else{
                count=1;
            }

            }
        printf("case #%d:\n%d\n",num,max);

    }
    return 0;
}

