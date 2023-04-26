#include <stdio.h>
#include <string.h>

int main()
{
	int T,i,list[122],j,max;
	unsigned long long ret,weight;
	for(i=0;i<123;i++){
		list[i]=-1;
	}
	char str[61];
	scanf("%d",&T);
	for(i=0;i<T;i++){
		max=2;
		ret=0;
		weight=1;
		scanf("%s",str);
		printf("case #%d:\n",i);
		if(str[0]=='0'){
			list[str[0]]=0;
		}
		else{
			list[str[0]]=1;
		}
		if(str[1]!=str[0]){
			list[str[1]]=0;
		}
		for(j=2;j<strlen(str);j++){
			if(list[str[j]]==-1){
				list[str[j]]=max;
				max+=1;
			}
		}
		for(j=1;j<strlen(str);j++){
			weight*=max;
		}
		for(j=0;j<strlen(str);j++){
			ret+=list[str[j]]*weight;
			weight/=max;
		}
		printf("%llu\n",ret);
	}
	return 0;
}