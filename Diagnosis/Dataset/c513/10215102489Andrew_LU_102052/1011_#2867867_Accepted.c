#include<stdio.h>
#include<string.h>
int main(){
	char u[10005];
	int a[10005]={0};
	int i,j=0;
	long long ans1=0,ans2=0;
	long long t1=1,t2=1;
	int tt;
	scanf("%s",u);
	int l=0;
	for(i=strlen(u)-1;i>1;i--){
		if(u[i]=='1') a[j*4]=1;
		if(u[i]=='2'){
			a[j*4+1]=1;
		}
		if(u[i]=='3'){
			a[j*4]=1;
			a[j*4+1]=1;
		}
		if(u[i]=='4'){
			a[j*4+2]=1;
		}
		if(u[i]=='5'){
			a[j*4]=1;
			a[j*4+2]=1;
		}
		if(u[i]=='6'){
			a[j*4+1]=1;
			a[j*4+2]=1;
		}
		if(u[i]=='7'){
			a[j*4]=1;
			a[j*4+2]=1;
			a[j*4+1]=1;
		}
		if(u[i]=='8'){
			a[j*4+3]=1;
		}
		if(u[i]=='9'){
			a[j*4]=1;
			a[j*4+3]=1;
		}
		if(u[i]=='A'){
			a[j*4+1]=1;
			a[j*4+3]=1;
		}
		if(u[i]=='B'){
			a[j*4]=1;
			a[j*4+1]=1;
			a[j*4+3]=1;
		}
		if(u[i]=='C'){
			a[j*4+2]=1;
			a[j*4+3]=1;
		}
		if(u[i]=='D'){
			a[j*4]=1;
			a[j*4+2]=1;
			a[j*4+3]=1;
		}
		if(u[i]=='E'){
			a[j*4+1]=1;
			a[j*4+2]=1;
			a[j*4+3]=1;
		}
		if(u[i]=='F'){
			a[j*4]=1;
			a[j*4+2]=1;
			a[j*4+1]=1;
			a[j*4+3]=1;
		}
		l+=4;
		j++;
	} 
	for(i=0;i<l;i++){
		//printf("%d\n",a[i]);
		if(i%4!=2){
			ans1+=a[i]*t1;
			if(i%4==0) t1*=-1;
			else t1*=-2;
		}
		if(i%4!=0){
			ans2+=a[i]*t2;
			if(i%4==2) t2*=-1;
			else t2*=-2;
		}
	}
	if(ans2<0){
		if(ans2!=-1){
			if(ans1!=0)
			 printf("%lld%lldi",ans1,ans2);
			else printf("%lldi",ans2);
		}
		else{
			if(ans1!=0)
			 printf("%lld-i",ans1);
			else printf("-i");
		}
	}
	else if(ans2>0){
		if(ans2!=1){
			if(ans1!=0)
			 printf("%lld+%lldi",ans1,ans2);
			else printf("%lldi",ans2);
		}
		else{
			if(ans1!=0)
			 printf("%lld+i",ans1);
			else printf("i");
		}
	}
	else printf("%lld",ans1);
}
/*
1  0  0
-1 1  1
0  -2 2
2  2  3
-4 0  0
4 -4  1
0  8  2
-8 -8 3
*/
