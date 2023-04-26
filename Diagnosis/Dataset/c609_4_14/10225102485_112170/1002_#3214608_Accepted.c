#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int maxn=1,cnt=1;
        int temp=n%2;
        n/=2;
        while(n>0){
            if(n%2!=temp)cnt++;
            else{
                maxn=cnt>maxn?cnt:maxn;
                cnt=1;
            }
            temp=n%2;
            n/=2;
        }
        maxn=cnt>maxn?cnt:maxn;
        printf("case #%d:\n%d\n",i,maxn);
	}
	return 0;
}
