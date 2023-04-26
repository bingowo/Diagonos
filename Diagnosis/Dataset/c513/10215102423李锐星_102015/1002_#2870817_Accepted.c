#include <stdio.h>
#include <string.h>

int main()
{
	int T,i,list[122],j,max;
	unsigned long long ret,weight;
	char str[61];
	scanf("%d",&T);
	for(i=0;i<T;i++){
		for(j=0;j<123;j++){
			list[j]=-1;
		}
		max=1;
		ret=0;
		weight=1;
		scanf("%s",str);
		printf("case #%d:\n",i);
		for (j=0;j<strlen(str);j++){
			if (j==0){
				list[str[j]]=1;
			}
			else{
				if (str[j]==str[j-1]){
					continue;
				}
				else if(list[str[j]]!=-1){
					continue;
				}
				else if(max==1){
					list[str[j]]=0;
					max+=1;
				}
				else{
					list[str[j]]=max;
					max+=1;
				}
			}
		}
		if(max==1){
			max+=1;
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