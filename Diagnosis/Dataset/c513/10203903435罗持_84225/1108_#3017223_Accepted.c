#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int T,a,b;
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		scanf("%d %d",&a,&b);
		char res[110] = {0};
		int pos[110] = {0};
		memset(pos,-1,sizeof(pos));
		int len = 0;
		int ret = -1;
		while(1){
			if(a%b==0){
				res[len++] = a/b+'0';
				break;
			}
			else{
				int t = a/b;
				int k = a%b;
				if(pos[k]==-1){
					res[len++] = t+'0'; 
					pos[k] = len-1;	
				}
				else{
					res[len++] = t+'0'; 
					ret = pos[k];
					pos[k] = len-1;	
					break;
				}
				a = k*10;
			}
		}
		res[len] = '\0';
		printf("case #%d:\n",kase);
		res[0] = '.';
		if(ret==-1) printf("0%s\n",res);
		else{
			printf("0%s\n",res);
			printf("%d-%d\n",ret+1,len-1);
		}
	}
	return 0;
} 