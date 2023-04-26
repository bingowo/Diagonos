#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		char s1[81],s2[81],s[81];
		int a1=0,b1=0,a2=0,b2=0;
		scanf("%s%s%s",s1,s2,s);
		int a=0,b=0;
		int sign_a=0,sign_b=0;
		for(int j=0;j<strlen(s);j++){
		if(sign_a==0){
			if(s1[a]==s[j]){
				a++;
			}else{
				a = 0;
			}
			if(a==strlen(s1)){
				a1 = j;sign_a=1;
			}
		}
		if(sign_b==0){
			if(s2[b]==s[j]){
				b++;
			}else{
				b = 0;
			}
			if(b==strlen(s2)){
				b1 = j;sign_b=1;
			}
		}
		if(sign_a==1&&sign_b==1)
			break;	
		}
		a=strlen(s1)-1,b=strlen(s2)-1;
		sign_a=0,sign_b=0;
		for(int j=strlen(s)-1;j>=0;j--){
		if(sign_a==0){
			if(s1[a]==s[j]){
				a--;
			}else{
				a = strlen(s1)-1;
			}
			if(a==-1){
				a2 = j;sign_a=1;
			}
		}
		if(sign_b==0){
			if(s2[b]==s[j]){
				b--;
			}else{
				b = strlen(s2)-1;
			}
			if(b==-1){
				b2 = j;sign_b=1;
			}
		}
		if(sign_a==1&&sign_b==1)
			break;	
		}
		
		//printf("%d %d\n",a1,b1);
		//printf("%d %d\n",a2,b2);
		int n1 = b2 - a1;
		int n2 = a2 - b1;
		printf("case #%d:\n",i);
		if(n1<0||n2<0)
			printf("0\n");
		if(n1>n2)
			printf("%d\n",n1-1);
		else
			printf("%d\n",n2-1);
	}
	
	
	return 0;
}
