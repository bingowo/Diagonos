#include <stdio.h>
#define N 1000
//char ans[N];
int main(){
//    printf("7*(-16)%(-16)+15%(-16) = %d\n",7*(-16)%(-16)+15%(-16));
//    printf("7*(-16)+15*1)%(-16) = -97%(-16) = %d\n",(7*(-16)+15*1)%(-16));
    char ans[N] = {0};
    int n; int R;
    scanf("%d%d",&n,&R);
    int r = -R;
    int i = 0;
    while(n){
        int j = n%R;
//        printf("j = %d\n",j);
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
//-8~8
//-1~15
//11~11