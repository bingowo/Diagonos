#include <stdio.h>
#define N 1000
int main(){
    char ans[N] = {0};
    int n; int R;
    scanf("%d%d",&n,&R);
    if(!n) printf("0");
    int r = -R;
    int i = 0;
    while(n){
        int j = n%R;
        j = j>=0?j:r+j;
        if(r>10){
            if(j>9){
                ans[i++] = j+'A'-10;
            }
            else ans[i++] = j+'0';
        }
        else{
            ans[i++] = j+'0';
        }
        n = (n-j)/R;
    }
    for(int k = 0,j = i-1; k<=j; k++,j--){
        char c;
        c = ans[k];
        ans[k] = ans[j];
        ans[j] = c;
    }
    for(int j = 0; j<i; j++){
        printf("%c",ans[j]);
    }
    return 0;
}