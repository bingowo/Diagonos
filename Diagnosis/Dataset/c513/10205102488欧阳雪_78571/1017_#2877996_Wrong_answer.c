#include<stdio.h>
#include<string.h>
int main()
{
	char s[100]={'\0'};
	int a[1000]={0};//存储罗马数字的值 
	a['I']=1,a['V']=5,a['X']=10,a['L']=50,a['C']=100,a['D']=500,a['M']=1000;
	long long ans=0;
	long long flg=1;
	scanf("%s",s);
	int each[100]={0};
	int count=0,i=0;
	while(s[i])
	{
		if(s[i]=='(')flg*=1000;
		if(s[i]==')')flg/=1000;
		else each[count++]=a[s[i]]*flg;
		i++;
	}
	for(int j=0;j<count;j++){
		if(j==count-1){
			ans+=each[j];
		}
		else{
			ans+=((each[j]<each[j+1])? -each[j]:each[j]);
		}
	}
	printf("%lld",ans);
}