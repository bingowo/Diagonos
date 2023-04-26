#include<stdio.h>
int l(int s,int r){
	int length=0;
	while(s){
        s/=r;
        length+=1;
    }
	return length;
}
int main(){
    int T=1,n=3,r=2,sum=0,len=0;
    char digit[16]="0123456789ABCDEF",ans[100];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d%d",&n,&r);
        while(n){
            sum+=n%r;
            n/=r;
        }
		//printf("%d\n",sum);
		len=l(sum,r);
		//printf("%d\n",sum);
        while(len>=0){
            ans[len]=sum%r;
			sum/=r;
			len-=1;
        }
        printf("case #%d\n",i);
        for(int j=0;j<len;j++){
            printf("%s",ans[j]);
        }
    }
    return 0;
}