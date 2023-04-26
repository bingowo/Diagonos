#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int st[2234];

int main(){
    int t;
    scanf("%d",&t);
    for (int l=0;l<t;l++){
        int x,y;
        scanf("%d%d",&x,&y);
        st[0]=x;
        if (y==0) st[0]=1;
        int cnt=0;
        for (int i=1;i<y;i++){
            int sum=0;
            for (int j=0;j<=cnt;j++){
                int xx=sum+st[j]*x;
                sum=xx/10;
                st[j]=xx%10;
            }
            if (sum!=0) {
                cnt++;
                st[cnt]=sum;
            }
        }
        printf("case #%d:\n",l);
        for (int i=cnt;i>=0;i--)
            printf("%d",st[i]);
        printf("\n");
    }
    return 0;
}
