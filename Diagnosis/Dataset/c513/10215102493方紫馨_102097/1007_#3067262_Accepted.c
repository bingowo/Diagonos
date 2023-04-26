#include<stdio.h>
//转化为二进制并返回字符串长度 
int binary(int n,char* s){
	int i=0;
	while(n>0){
		if(n%2==1)
			s[i]='1';
		else
			s[i]='0';
		n/=2;
		i++;
	}
	return i;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		int n,cnt=1,a;
		scanf("%d",&n);
		char s[32]={0};
		a=binary(n,s);
		int max=1;
		for(int i=0;i<a-1;i++){
			if(s[i+1]!=s[i]){
				cnt++;
			}else{
				if(cnt>max)
					max=cnt;
				cnt=1;
			}
		}
		if(cnt>max)
			max=cnt;
		printf("case #%d:\n",k);
		printf("%d\n",max);	
	}	
	return 0;
}