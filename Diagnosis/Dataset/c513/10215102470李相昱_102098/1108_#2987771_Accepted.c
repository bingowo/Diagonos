#include <stdio.h>
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n0.",i);
        int n,m;
        int a[100]={0};
        int sign[101]={0};
        int j=0,sign1=0;
        scanf("%d%d",&n,&m);
        int end=0,start=0;
        sign[n]=1;
        while(n!=0){
            n = n*10;
            a[j]=n/m;
            n = n%m;
            if(sign[n]!=0) {
                start=sign[n]-1;
                end = j;
                sign1 = 1;
                break;
            }else{
                sign[n]=j+2;
            }
            j++;
        }
        int p=0;
        j=j-1;
        if(sign1){
            j=end;
        }
        for(;p<=j;p++){
            printf("%d",a[p]);
        }
        printf("\n");
        if(sign1){
            printf("%d-%d\n",start+1,end+1);
        }
    }
    return 0;
}
