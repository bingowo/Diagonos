//1006
#include <stdio.h>
#include <math.h>
int main(){
	int i,T;
	scanf("%d",&T);
	char ch=getchar();
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		char s[1000];
		int l=0;
		while((ch=getchar())!='\n'){
			s[l]=ch;
			l++;
		}
		int n[1000];
		int j,ans=0;
		for(j=l-1;j>=0;j--){
			if(s[j]=='-'){
				n[j]=-1;
			}
			else{
				n[j]=(int)s[j]-48;
			}
			//printf("%d",n[j]);
			ans+=pow(3,l-j-1)*n[j];
		}
		printf("%d\n",ans);
	}
}