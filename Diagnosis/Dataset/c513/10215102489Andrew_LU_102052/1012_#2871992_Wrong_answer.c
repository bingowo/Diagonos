#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h> 
int main(){
	int i,ans[5005]={0};
	char a[5005],zz[5005],xx[5005],t[5005];
	long long z=0,x=0;
	scanf("%s",a);
	int ff=0;
	for(i=1;i<strlen(a);i++){
		if(a[i]=='+' || a[i]=='-'){
			ff=i;
		}
	}
	//printf("%d=ff\n",ff);
	if(ff==0 && a[strlen(a)-1]=='i'){
		for(i=ff;i<strlen(a)-1;i++){
			xx[i-ff]=a[i];
		}
		x=atoll(xx);
	}
	else if(ff==0 && a[strlen(a)-1]!='i'){
		z=atoll(a);
	}
	else{
		for(i=0;i<ff;i++){
			zz[i]=a[i];
		}
		for(i=ff;i<strlen(a)-1;i++){
			xx[i-ff]=a[i];
		}
		z=atoll(zz);
		x=atoll(xx);
	}
	if(ff==0 && a[strlen(a)-1]=='i'){
		if(a[0]=='-' && x==0) x=-1;
		else if(a[0]=='i') x=1;
	}
	if(ff!=0 && x==0){
		if(a[ff]=='-') x=-1;
		else x=1;
	}
	//printf("%d",strlen(a));
	/*for(i=1;i<strlen(a);i++){
		t[i]=a[i]; ///
	}
	if(a[0]=='-' && a[1]=='i'){
		x=-1;
	}
	else if(a[0]=='0'){
		x=0;
		z=0;
	}
	else if(strchr(a,'+')==0 && strchr(a,'-')==0){
		if(a[strlen(a)-1]!='i'){
			z=atoll(a);
		}
		else{
			x=atoll(a);
			if(x==0 && a[0]=='-') x=-1;
			else if(x==0) x=1;
		}
	}
	else{
		int f=0;
		for(i=0;i<strlen(a);i++){
			if(a[i]=='+' || (a[i]=='-' && i!=0)) f=i;
			if(f==0) zz[i]=a[i];
			else xx[i-f]=a[i];
		}
		z=atoll(zz);
		x=atoll(xx);
		if(f==strlen(a)-2 && a[f]=='-' && f!=0) x=-1;
		else if(f==strlen(a)-2 && a[f]=='+' && f!=0) x=1; 
		if(f==0 && a[strlen(a)]=='i'){
			x=z;
			z=0;
		}
	}
	//if(strchr(a,'i')!=0 && x==0) */
	int cnt=0;
//	printf("%d %d\n",z,x);
	while(abs(z)>0 || abs(x)>0){
		
		if(abs(z)%2==abs(x)%2) ans[cnt]=0;
		else {
			z--;
			ans[cnt]=1;
		}
		long long a=z,b=x;
		if(a>0 && b>0)
		x=-(a+b)/2;
		z=(b-a)/2;
		cnt++;
	}
	if(cnt==0) printf("0");
	for(i=cnt-1;i>=0;i--){
		printf("%d",ans[i]);
	}
//	printf("%lld %lld",z,x);
}