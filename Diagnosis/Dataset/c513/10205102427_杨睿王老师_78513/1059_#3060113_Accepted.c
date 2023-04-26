#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int cmp(const void*a, const void* b){
	int x=*(int*)a;
	int y=*(int*)b;
	if(x>y) return 1;
	else return -1;
}
int cal(int x,int y,int z){
	if(x%y==0){
		printf("%d\n",z+x/y);
		return 0;
	}
	else{
		for(int i=x;i>0;i--){
			if(x%i==0 && y%i==0){
				x/=i;
				y/=i;
				break;
			}
		}
		if(x>y){
			printf("%d+%d/%d\n",z+x/y,x%y,y);
			//cout<<z+x/y<<"+"<<x%y<<"/"<<y<<endl;
			return 0;
		}
		else if(z!=0){
			printf("%d+%d/%d\n",z,x,y);
			//cout<<z<<"+"<<x<<"/"<<y<<endl;
			return 0;
		}
		else if(z==0){
			printf("%d/%d\n",x,y);
			//cout<<x<<"/"<<y<<endl;
			return 0;
		}	
	}
}
int main()
{
	int n,s,p=1,i,ans;
	int a[1010];
	scanf("%d %d",&n,&s);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
	/*printf("\n");
	for(int o=0;o<n;o++){
		printf("%d",a[o]);
	}
	printf("\n");*/
	a[n]=100000;
	i=0;
	if(n==1){
		printf("%d\n",a[i]+s);
		return 0;
	}
	ans=a[0];
	while(s>0 && p<=n){
		if(p<n){
			if(((a[i+1]-a[i])*p)<s){
				s-=(a[i+1]-a[i])*p;
				ans=a[i+1];
				i++;
				p++;
			}
			else{
				cal(s,p,ans);
				return 0;
			}
		}
		else{
			if(s>0){
				cal(s,p,a[n-1]);
				return 0;
			}
			else{
				printf("%d\n",a[n-1]);
				return 0;
			}
		}
	}
	return 0;
}