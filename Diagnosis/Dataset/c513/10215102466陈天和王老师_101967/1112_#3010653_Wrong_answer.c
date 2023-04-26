#include <stdio.h>
int dptree[1001]={1,};
void calculate(){
    for(int i=1;i<=4;i++){
        for(int j=i;j<=1000;j++){
            dptree[j]+=dptree[j-i];
        }
    }
}
int main(){
    calculate();
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n;
    scanf("%d",&n);
    printf("%d\n",dptree[n]);
    }
    int n;
    scanf("%d",&n);
    printf("%d",dptree[n]);
    return 0;
}