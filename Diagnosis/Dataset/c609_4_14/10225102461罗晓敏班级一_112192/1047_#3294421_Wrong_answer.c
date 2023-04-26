#include <stdio.h>
int main(){
    int t;scanf("%d",&t);
    int i;
    for(i=0;i<t;i++){
        int a,n;scanf("%d%d",&a,&n);
        int j,k;int ret[120]={1,-1};
        for(j=0;j<n;j++){
            int temp=0;
            for(k=0;ret[k]!=-1;k++){
                t=ret[k];
                ret[k]=(temp+a*t)%10;
                temp=(temp+a*t)/10;
            }
            if(temp){
                ret[k]=temp;
                ret[k+1]=-1;
            }
        }
        printf("case #%d:\n",i);
        for(j=0;ret[j]!=-1;j++);
		for(k=j-1;k>=0;k--){
            printf("%d",ret[k]);
        }
        printf("\n");
    }
}