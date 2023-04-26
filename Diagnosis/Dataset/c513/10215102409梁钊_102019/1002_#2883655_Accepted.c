#include<stdio.h>
#include<string.h>
int main(){
	int T ;
	scanf("%d",&T);
	int count=0;
	for(; count < T ; count++ ){
		int table[200];
		for(int i=0;i<200;i++)
			table[i]=-1;
		char s[61] = {'0'} ;
		scanf("%s",&s);
		
		
		int l = strlen(s) ;
		table[s[0]]=1;
		int flag = 0 ;
		int R = 2 ;
		for(int i=1;i<l;i++){
			if(table[s[i]]==-1)
				if(flag==0){
					table[s[i]]=0;
					flag = 2;
				}
				else{
					table[s[i]] = flag ;
					flag++;
					R += 1 ;
				}
		}
		long long sum = 0 ;
		for(int i=0;i<l;i++){
			sum = R * sum + table[s[i]] ;
		}
		printf("case #%d:\n",count);
		printf("%lld\n",sum);
	}
}
