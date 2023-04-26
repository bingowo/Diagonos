#include<stdio.h>
#include<string.h>
int main(){
	int t;
	scanf("%d",&t);
	for(int k=0;k<t;k++){
		char s[61];
	    int a[128]={0};
	    char c;
	    int R=2;
	    scanf("%s",s);
	    int len=strlen(s);
	    for(int i=0;i<128;i++){
	    	a[i]=-1;
		}
		c=s[0];
		a[c]=1;
		int data=0;
		if(len>=2){
			R--;
			for(int j=1;j<len;j++){
				c=s[j];
				if(a[c]==-1){ 
					a[c]=data;
					if(data==0) data=2;
					else data++;
					R++;
				}
			}
		}
		if(R<2) R=2;
		long long x=0;
		for(int i=0;i<len;i++){
			c=s[i];
			x=x*R+a[c];
		}
		printf("case #%d:\n",k);
		printf("%lld\n",x);
	}
	return 0;	
}