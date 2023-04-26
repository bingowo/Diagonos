#include<stdio.h>
#include<string.h>
int main(){
	int T ;
	scanf("%d",&T);
	for(int i = 0 ; i < T ; i++ ){
		int table[200] = {'0'} ;
		for(int i=0;i<200;i++)
			table[i]=-1;
		char s[61] = {'0'} ;
		scanf("%s",&s);
		
		
		int l = strlen(s) ;
		table[s[0]]=1;
		int flag = 0 ;
		int R = 2 ;
		int ans[61];int *p=ans;
		ans[0]=1;
		for(int i=1;i<l;i++){
			if(table[s[i]]==-1)
				if(flag==0){
					table[s[i]]=0;
					*(++p)=0;
					flag=2;
				}
				else{
					table[s[i]] = flag ;
					*(++p)=flag;
					flag++;
					R += 1 ;
				}
			else *(++p)=table[s[i]];
			
		int sum = 0 ;
		for(int i=0;i<l;i++){
			sum += R * ans[i] + sum ;
		printf("%d",sum);
			}
		}
	}
}
