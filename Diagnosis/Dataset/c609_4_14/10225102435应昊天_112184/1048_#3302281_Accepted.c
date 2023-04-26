#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
int* ADD(int*a,int*b);
int main(){
	int T,n;
	scanf("%d",&T);
	for(int i = 0;i < T;i++){
		scanf("%d",&n);
		int* p = (int*)malloc(sizeof(int) * 240);
		int* a = (int*)malloc(sizeof(int) * 240);//temp
		int* b = (int*)malloc(sizeof(int) * 240);
		for(int j = 0;j < 240;j++){
			p[j] = a[j] = b[j] = 0;
		}
		p[0] = 1;
		int cnt = 1;
		for(int exp = 2;exp <= n;exp++){
			for(int j = 0;j <= cnt;j++){
				a[j] = p[j];
				//printf("%d:%d ",exp,p[j]);
			}
			//printf("\n");
			int up = 0;
			for(int j = 0;j <= cnt;j++){
				p[j] += b[j] + up;
				up = p[j] / 10;
				p[j] = p[j] % 10;
			}
			/*for(int k = 0;k < 119;k++){
				printf("%d",p[k]);
			}	
			putchar('\n');*/
			for(int j = 0;j <= cnt;j++){
				b[j] = a[j];
			}
			cnt++;
		}
		printf("case #%d:\n",i);
		int flag = 0;
		if(n == 0)
			printf("%d",0);
		else if(n == 1)
			printf("%d",1);
		else{
			for(int k = cnt;k >= 0;k--){
				if(p[k] != 0 || flag){
					printf("%d",p[k]);
					flag = 1;	
				}
			}	
		}
		printf("\n");
		free(p);
		free(a);
		free(b);			
	}
	return 0;
}
/*int* fibbonacci(int*p){
	int* a = (int*)malloc(sizeof(int) * 1000000);
	int* b = (int*)malloc(sizeof(int) * 1000000);
	
}
int* ADD(int*a,int*b){
	int* res = (int*)malloc(sizeof(int) * 1000000);
	memset(res,'\0',sizeof(res));
	int remainder = 0;
	int i = 0;
	for(i = 0;a[i] && b[i];i++){
		res[i] = a[i] + b[i] + remainder;
		remainder = res[i] % 10;
		res[i] /= 10;
	}
	for(;a[i];i++){
		res[i] = a[i];
	}
	for(;a[i];i++){
		res[i] = b[i];
	}
	return res;
}*/