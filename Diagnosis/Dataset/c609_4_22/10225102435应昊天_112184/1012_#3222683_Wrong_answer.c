#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int T;
	scanf("%d",&T);
	char s[52];
	double ans;
	double a = 0,b = 1;
	int n = 0;
	int len;
	char t[200];
	for(int i = 0;i < T;i++){
		scanf("%s",s);
		for(int j = 2;s[j] != '\0';j++){
			ans += (s[j] - '0') * pow(8,-j+1);
		}
		memset(t,0,sizeof(t));	
		sprintf(t,"%.150lf",ans);
		len = strlen(t);
		for(int k = len - 1;k > 2;k--){
			if(t[k] == '0')
				t[k] = '\0';
			else
				break;
		}
		printf("case #%d:\n",i);
		printf("%s\n",t);
		a = 0;
		b = 1;
		ans = 0;
	}
	return 0;
}