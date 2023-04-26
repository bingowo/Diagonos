#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,cnt=0,ans=0;
    int num[1000];
    scanf("%d%d",&m,&n);
    if(m!=0){
    while(m){
        num[cnt]=m%3;
        m/=3;
        cnt++;
    }
    num[cnt]=0;
    while(n!=1){n/=3;ans++;}
    for(int j=0;j<cnt;j++){
        num[j]++;
        num[j+1]+=num[j]/3;
        num[j]%=3;
    }

    for(int i=0;i<cnt;i++)num[i]--;
    if(num[cnt]>0)cnt++;
    int f=0;
    if(num[0]==0){f++;}
    if(cnt>ans){
    for(int k=cnt-1;k>=f;k--){

        printf("%d",num[k]==-1?2:num[k]);
        if(k==ans&& ans!=0)printf(".");
    }}
    else {
        printf("0.");
        for(int i=0;i<ans-cnt;i++)printf("0");
        for(int k=cnt-1;k>=f;k--){
            printf("%d",num[k]==-1?2:num[k]);
        }
    }
    printf("\n");}
    else printf("0\n");
    return 0;
}
