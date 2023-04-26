#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int st[123][2234];
int cnt[123];

int main(){
    int t;
    scanf("%d",&t);
    st[0][0]=0;
    cnt[0]=0;
    st[1][0]=1;
    cnt[1]=0;
    for (int i=2;i<=120;i++){
        int left=0;
        for (int j=0;j<=cnt[i-1];j++){
            st[i][j]=left+st[i-2][j]+st[i-1][j];
            left=st[i][j]/10;
            st[i][j]=st[i][j]%10;
        }
        if (left!=0){
            cnt[i]=cnt[i-1]+1;
            st[i][cnt[i]]=left;
        }
        else cnt[i]=cnt[i-1];
    }
    for (int l=0;l<t;l++){
        int x;
        scanf("%d",&x);
        printf("case #%d:\n",l);
        for (int i=cnt[x];i>=0;i--)
            printf("%d",st[x][i]);
        printf("\n");
    }
    return 0;
}
