#include<stdio.h>
#include<stdlib.h>
#include<string.h>
union DOUBLE{
	double num;
	unsigned char nums[8];
};
int main()
{
	char *s,*ans;
	s=(char*)malloc(sizeof(char)*100);
	ans=(char*)malloc(sizeof(char)*100);
	int flag=1;
	int num1;
	union DOUBLE num2;
	while(scanf("%s",s)!=EOF){
		if(!strchr(s,'.')){
			num1=atoi(s);
		} 
		else{
			 num2.num=atof(s);
			 flag=2;
		}
		if(flag==1){
			sprintf(ans,"%08x",num1);
			int i=6;
			for(;i>=0;i-=2){
				printf("%c%c ",ans[i],ans[i+1]); 
			}
		}
		else{
			int j=0;
			for(;j<8;j++){
				printf("%02x ",num2.nums[j]);
			}
		}
		printf("%c",'\n');
	}
	free(s);
	free(ans);
	return 0;
}