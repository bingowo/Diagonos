#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a,const void *b){
	return *(int *)a>*(int *)b;
}
int gcd(int a,int b){
	return a%b==0? b:gcd(b,a%b);

}
int ma(int a,int b){
	return a>b ? a:b;
}
int main(){
	int ansz,n,s,a[1005]={0};
	scanf("%d%d",&n,&s);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort((void *)a,n,sizeof(a[0]),cmp1);
	while(s>=0){	
		for(int i=0;i<n;i++){
		//	printf("%d	",a[i]);
		}
		//printf("\n%d\n",s);
		int t=-1;
		for(int i=1;i<n;i++){
			if(a[0]!=a[i]){
				t=i;
				break;
			}
		}
		if(t==-1) t=n;
		if(t==n){
			ansz=a[0];
			ansz+=s/n;
			s=s-s/n*n;
			if(s!=0) printf("%d+%d/%d",ansz,s/gcd(s,n),n/gcd(s,n));
			else printf("%d",ansz);
			return 0;
		}
		if(s>=t){
			if((s/t)<(a[t]-a[0])){
				ansz=a[0];
				ansz+=s/t;
				s=s-s/t*t;
				if(s!=0){
					if(ansz!=0)
					 printf("%d+%d/%d",ansz,s/gcd(s,t),t/gcd(s,t));
					else printf("%d/%d",s/gcd(s,t),t/gcd(s,t));
				}
				else printf("%d",ansz);
				return 0;
			}
			else{
				s-=(a[t]-a[0])*t;
				for(int i=0;i<t;i++){
					a[i]=a[t];
				} 
			}
		}
		else{
			if(s!=0){
				if(a[0]!=0)
				 printf("%d+%d/%d",a[0],s/gcd(s,t),t/gcd(s,t));
				else
				 printf("%d/%d",s/gcd(s,t),t/gcd(s,t));
			}
			 
			else printf("%d",a[0]);
			return 0;
		}
	}
}