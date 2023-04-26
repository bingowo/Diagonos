#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[20005];
    int nz=0,no=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i])no++;
        else nz++;
    }
    int next[20005];
    int first[20005]={0};
    for(int i=nz;i<n;i++){
        first[i]=1;
    }
    int pz=0,po=0;
    for(int i=0;i<n;i++){
        if(first[i]){
            while(a[po]!=1)po++;
            next[i]=po;
            po++;
        }
        else {
            while(a[pz]!=0)pz++;
            next[i]=pz;
            pz++;
        }
    }
    int output[20005];
    int order=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        output[i]=first[order];
        order=next[order];
        if(output[i])cnt1++;
        else cnt2++;
    }
    if(cnt1==no&&cnt2==nz){
        for(int i=0;i<n;i++){
            printf("%d",output[i]);
            if(i!=n-1)printf(" ");
        }
    }
    else printf("-1");
	return 0;
}