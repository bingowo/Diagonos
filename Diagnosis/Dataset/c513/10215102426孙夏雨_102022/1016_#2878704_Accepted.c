#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,R;
    scanf("%d %d",&N,&R);
    int arr[1000];
    int n=0;
    if (N==0) printf("0");
    while(N!=0){
        int k=0;
        if(N<0){
            k=(abs(N))%((-1)*R);
            N= (k!=0) ? N/R+1 : N/R;
            k= (k!=0) ? (-1)*R-k : 0;
        }
        else {
            k=N%((-1)*R);
            N=N/R;
        }
        arr[n]=k;
        n++;
    }
    for (int i=0;i<n;i++){
        if(arr[n-1-i]>=10) printf("%c",'A'+arr[n-1-i]-10);
        else printf("%d",arr[n-1-i]);
    }
    return 0;
}
