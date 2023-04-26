//1017
//I=1、V=5、X=10、L=50、C=100、D=500、M=1000
#include <stdio.h>
int main()
{
	printf("test\n");
	char s[52];
	int l=0;
	char ch;
	while((ch=getchar())!='\n'){
		s[l]=ch;
		l++;
	}
	int i,j;
	int cnt;
	long long flag=1;
	long long data[100];
	int roma[128];
	roma['I']=1;
	roma['V']=5;
	roma['X']=10;
	roma['L']=50;
	roma['C']=100;
	roma['D']=500;
	roma['M']=1000;
	for(i=0;i<l;i++){
		switch (s[i]){
			case'(':flag=flag*1000;break;
			case')':flag=flag/1000;break;
			default:data[cnt++]=roma[s[i]]*flag;break;
		}
	}
	long long ans=0;
	for(i=0;i<cnt-1;i++){
		if(data[i]<data[i+1]) ans-=data[i];
		else ans+=data[i];
	}
	
	ans+=data[cnt-1];
	printf("%d",ans);
}