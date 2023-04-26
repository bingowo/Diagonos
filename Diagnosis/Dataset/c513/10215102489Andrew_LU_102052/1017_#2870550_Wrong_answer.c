#include<stdio.h>
#include<string.h>
int main(){
	char a[1005];
	int i;
	long long ans[1005]={0};
	scanf("%s",a);
	int f=0;
	for(i=0;i<strlen(a);i++){
		if(a[i]=='(') f++;
		else if(a[i]==')'){
			ans[f-1]=ans[f-1]+ans[f]*1000;
			ans[f]=0;
			f--;
		}
		else if(a[i]=='I'){
			if(a[i+1]=='X')
				ans[f]-=1;
			else ans[f]+=1;
		}
		else if(a[i]=='V'){
			ans[f]+=5;
		}
		else if(a[i]=='X'){
			if(a[i+1]=='C')
				ans[f]-=10;
			else ans[f]+=10;
		}
		else if(a[i]=='L'){
			ans[f]+=50;
		}
		else if(a[i]=='C'){
			//if(a[i+1]=='D')
			//	ans[f]-=100;
			ans[f]+=100;
		}
		else if(a[i]=='D'){
			ans[f]+=500;
		}
		else if(a[i]=='M'){
			if(a[i+1]=='(') ans[f]-=1000;
			else ans[f]+=1000;
		}
	}
	printf("%lld",ans[0]);
}