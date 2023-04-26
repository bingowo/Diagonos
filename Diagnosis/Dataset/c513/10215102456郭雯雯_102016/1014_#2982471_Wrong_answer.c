#include<stdio.h>

int main(){
    int A,B,log3[20],n;
    scanf("%d %d",&A,&B);
    log3[0]=1;
    for(int i=1;i<20;i++)log3[i]=3*log3[i-1];
    for(int i=0;i<20;i++)if(B==log3[i]){n=i;break;}
    int a=A/B,b=A%B,ite[20]={0},xia[20]={0},ans[50]={0};
    for(int i=0;b>0;i++){
        xia[i]=b%3;b/=3;
    }
    for(int i=0;a>0;i++){
        ite[i]=a%3;a/=3;
    }
    for(int i=0;i<n;i++)ans[i]=xia[i];
    for(int i=n,j=0;j<20;i++,j++)ans[i]=ite[j];
    for(int i=0;i<50;i++){//+1
        ans[i]++;
        if(ans[i]==3){
            ans[i]=0;ans[i+1]++;
        }
        if(ans[i]==4){
            ans[i]=1;ans[i+1]++;
        }
    }
    for(int i=0;i<50;i++){
        ans[i]--;
        if(ans[i]==-1)ans[i]=2;
    }
    int l=49;
    while(ans[l]==0&&l>n)l--;
    l++;
    for(int i=l-1;i>=n;i--)printf("%d",ans[i]);
    if(l==n)printf("0");
    if(n!=0){
        printf(".");
        for(int i=n-1;i>=0;i--)printf("%d",ans[i]);
    }
    printf("\n");
}
