#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    scanf("%d",&n);
    int w[20000]={0};
    int zero[20000]={0},one[20000]={0};
    int ling=0,yi=0;
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
        if(w[i]==0){
            zero[ling++]=i;
        }
        else one[yi++]=i;
    }
    int ans[20000]={0};
    int k=0;
    for(int i=0;i<ling;i++) ans[k++]=zero[i];
    for(int j=0;j<yi;j++) ans[k++]=one[j];
    int aaa=0;
    int anw[20000]={0};
    int ss=0;
    for(int s=0;s<n;s++){
        aaa=ans[aaa];
        anw[s]=w[aaa];
        if(w[aaa]==1) ss++;
    }
    if(ss!=yi) {
        printf("-1\n");
        return 0;
    }
    for(int q=0;q<n;q++) printf("%d ",anw[q]);
    printf("\n");
    return 0;
}