//1017
#include <stdio.h>
int main()
{
	//printf("test\n");
	char s[52];
	int l=0;
	char ch;
	int i,j;
	int cnt;
	int flag=1;
	unsigned long long data[52];
	int roma[128];
	roma['I']=1;
	roma['V']=5;
	roma['X']=10;
	roma['L']=50;
	roma['C']=100;
	roma['D']=500;
	roma['M']=1000;	
	unsigned long long  ans=0;
	while((ch=getchar())!='\n'){
		s[l]=ch;
		switch (s[l]){
			case'(':flag=flag*1000;break;
			case')':flag=flag/1000;break;
			default:data[cnt++]=roma[s[l]]*flag;break;
		}
		l++;		
	}
	for(i=0;i<cnt-1;i++){
		if(data[i]<data[i+1]) ans-=data[i];
		else ans+=data[i];
	}
	ans+=data[cnt-1];
	printf("%lld",ans);
}