#include<stdio.h>
#include<math.h>
int main(){
	int n,r;
	int x=r;
	scanf("%d%d",&n,&r);
	//printf("%d\n",-1%-2);
/*	while(x<abs(n) || x*n<0) x*=r;
	int ans=x;
	while(abs(x)>=1){		
	}*/
	int t[50]={0},f=0;
	int cnt=0;
	while(abs(n)>=1){	
		t[cnt]=n%r;
		if(t[cnt]<0){
			f=1;
			t[cnt]=abs(r)+t[cnt];
		}	
		
		n=n/r;
		if(f==1){
			n++;
			//else n--;
			f=0;
		}
		cnt++;
		//printf("n=%d\n",n);
	}
	int i;
	for(i=cnt-1;i>=0;i--){
		printf("%X",t[i]);
	}
}
//-25000 -16
//7FB8