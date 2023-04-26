#include<stdio.h>

int main(){
    int n,m,k,ans=0;
    scanf("%d %d %d",&n,&m,&k);
    int num[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",%num[i][j])
    for(int i=0;i<n-1;i++){
        int sum=0;
        for(int j=0;j<n-1;j++){
            int s;
            if(i>j)s=n-i;
            else s=n-j;
            for(int a=0;a<s;a++){
                for(int b=0;b<s;b++)sum+=num[i+a][j+b];
                if(sum>=k)break;
            }
            if(sum>=k)ans++;
        }
    }
    printf("%d",ans);
}