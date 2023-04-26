#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int st[123][2234];
int cnt[123];

int main(){
    int t;
    scanf("%d",&t);
    for (int l=0;l<t;l++){
        int x;
        scanf("%d",&x);
        int ans=0;
        for (int i=1;i<=x;i++){
            int t=i;
            while (t%5==0) ans++,t/=5;
        }
        printf("case #%d:\n",l);
        printf("%d\n",ans);
    }
    return 0;
}
