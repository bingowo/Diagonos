#include<stdio.h>
#include<string.h>
int main(){
	int t,i,cnt=0;
	char a[501];
	int ans[5000]={0};
	int u[5000]={0};
	scanf("%s",a);
	printf("0001");
	t=strlen(a);
	int l=0;
	while(t>0){
		u[l]=t%2;
		l++;
		t=t/2;
	}
	for(i=9;i>=0;i--)
	 printf("%d",u[i]);
	for(i=0;i<strlen(a)-strlen(a)%3;i+=3){
		cnt++;
		l=1;
		t=(a[i]-'0')*100+(a[i+1]-'0')*10+(a[i+2]-'0');
		while(t>0){
			ans[cnt*10-l]=t%2;
			t=t/2;
			l++;
		}
	}
	l=1;
	if(strlen(a)%3==1){
		t=a[strlen(a)]-'0';
		while(t>0){
			ans[cnt*10+4-l]=t%2;
			t=t/2;
			l++;
		}
		for(i=0;i<cnt*10+4;i++){
			printf("%d",ans[i]);
		}
	}
	else if(strlen(a)%3==2){
		t=(a[strlen(a)-1]-'0')*10+a[strlen(a)]-'0';
		while(t>0){
			ans[cnt*10+7-l]=t%2;
			t=t/2;
			l++;
		}
		for(i=0;i<cnt*10+7;i++){
			printf("%d",ans[i]);
		}
	}
	else{
		for(i=0;i<cnt*10;i++){
			printf("%d",ans[i]);
		}
	}
}