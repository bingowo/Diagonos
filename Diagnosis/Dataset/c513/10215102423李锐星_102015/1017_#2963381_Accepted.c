#include <stdio.h>
#include <string.h>
int main()
{
	int list[92];
	list['I']=1;
	list['V']=5;
	list['X']=10;
	list['L']=50;
	list['C']=100;
	list['D']=500;
	list['M']=1000;
	char s[51];
	scanf("%s",s);
	int i;
	long long data[100];
	for (i=0;i<100;i++){
		data[i]=0;
	}
	int cnt=0;
	long long weight=1;
	for (i=0;i<strlen(s);i++){
		if(s[i]=='('){
			weight*=1000;
		}
		else if(s[i]==')'){
			weight/=1000;
		}
		else{
			data[cnt]=weight*list[s[i]];
			cnt++;
		}
	}
	long long sum=0;
	for (i=0;i<cnt-1;i++){
		if(data[i]<data[i+1]){
			sum-=data[i];
		}
		else{
			sum+=data[i];
		}
	}
	sum+=data[i];
	printf("%lld\n",sum);
	return 0;
}