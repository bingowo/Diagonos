#include <stdio.h>
int dptree[1001]={1,};
void calculate(){
    for(int i=1;i<=4;i++){
        for(int j=i;j<=n;j++){
            dptree[j]+=dptree[j-i];
        }
    }
}
int main(){
    calculate();
    int n;
    scanf("%d",&n);
    printf("%d",dptree[n]);
    return 0;
}