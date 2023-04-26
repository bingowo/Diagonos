#include <stdio.h>
#define N 95

int main() {
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int a,n;int s[N]={0};
        scanf("%d",&a); s[0]=a;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        if(n==0) {printf("1");continue;}
        else{
            int cnt=0; int carry=0;
            for(int j=0;j<n;j++){
                for(int m=0;m<cnt;m++){
                    s[m]=s[m]*a+carry;
                    if(s[m]>9){
                        carry=s[m]/10; s[m]=s[m]%10;
                    }

                }
                cnt++;
            }
            cnt=cnt-2;
            for(;cnt>=0;cnt--) { printf("%d",s[cnt]);}
            printf("\n");
        }
    }
    return 0;
}
