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
        int n,m;
        scanf("%d%d",&n,&m);
        double ans=1;
        for (int i=1;i<=m;i++){
            ans*=(n-i+1)/(i*1.0);
        }
        printf("case #%d:\n",l);
        printf("%0.0lf\n",ans);
    }
    return 0;
}
