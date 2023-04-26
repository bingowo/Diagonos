#include <stdio.h>

int main(){
	unsigned long long A,B;
	scanf("%lld %lld",&A,&B);
	int a[100],b[100];
	unsigned long long T=A/B;
	unsigned long long S=A-T*B;
	int m=0,n=0;
	if (T==0){
		a[0]=0;
		m++;
	}
	while(T){
		a[m]=T%3;
		T/=3;
		m++;
	}
	while (S){
		S*=3;
		if(S<B) b[n]=0;
		else if (S==B){
			b[n]=1;
			S-=B;
		}
		else if (S>B){
			b[n]=S/B;
			S=S-B*b[n];
		}
		n++;
	}
	for (int i=n-1;i>-1;i--){
		b[i]+=1;
		if (b[i]>=3){
			b[i]-=3;
			if(i==0) a[0]+=1;
			else b[i-1]+=1;
		}
		b[i]-=1;
		if (b[i]==-1) b[i]=2;
	}
	for (int i=0;i<m;i++){
		a[i]+=1;
		if (a[i]>=3){
			a[i]-=3;
			if(i!=m-1) a[i+1]+=1;
			else {
				a[m]=1;
			}
		}
		a[i]-=1;
		if (a[i]==-1) a[i]=2;
	}
	m++;
	while(a[m-1]==0&&m-1!=1) m--;
	while(b[n-1]==0&&n!=0) n--;
	for (int i=m-1;i>-1;i--) printf("%d",a[i]);
	if (n!=0) printf(".");
	for (int i=0;i<n;i++) printf("%d",b[i]);
	return 0;
} 