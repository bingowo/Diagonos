#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const char In[2]={'0','1'};
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
void csh(char *a){
	int len = 64;
	for(int i=0;i<len;i++){
		a[i] = '0';//置零函数
	}
}
void bum(char *a, int b){//将a字符串转化为b的补码形式
	int i = 0;
	int p = 0;//判断b是否为负数
	if(b<0){
		p = 1;
		b = -b;
	}
	while(b>0){
		a[i] = In[b%2];
		b /= 2;
	}//输入原码
	if(p==1){//负数转化为补码
		for(int i=0;i<64;i++){
			if(a[i]=='0'){
				a[i] = '1';
				continue;
			}
			a[i] = '0';
		}
		for(int i=0;i<64;i++){
			if(a[i]=='0'){
				a[i] = '1';
				break;
			}
			a[i] = '0';
		}
	}
}
int num1(char *a){//统计1的个数
	int num = 0;
	for(int i=0;i<64;i++){
		if(a[i]=='1')num++;
	}
	return num;
}
int find(int *b, int num){//返回b中最大值的位置，并把最大值置为-1
	int bi = b[0];
	int ret = 0;
	for(int i=1;i<num;i++){
		if(bi<b[i]){
			bi = b[i];
			ret = i;
		}
	}
	b[ret] = -1;
	return ret;
}
void sort(int *a, int *b, int num, int *c){//排序//按b[i]中从大到小排序，同时对应的a[i]也随之排序，b[i]相同，按a[i]从小到大排序，返回排好序的a于c中
	int d[10000] = {0};
	for(int i=0;i<num;i++){
		d[i] = find(b, num);
	}
	for(int i=0;i<num;i++){
		c[i] = a[d[i]];
	}
}

int main(){
	int num = 0;
	int inp[10000] = {0};//处理一个问题中的数的存储空间
	int outnum[10] = {0};//问题中的输入个数
	int ret[10][10000] = {0};//返回值数组
	char s[64] = {'0'};//作为补码运算的暂存空间
	int nu[10000] = {0};//存储1位数
	scanf("%d", &num);
	for(int i = 0;i<num;i++){
		scanf("%d", &outnum[i]);
		for(int j = 0;j<outnum[i];j++){
			scanf("%d", &inp[j]);
		}
		qsort(inp, outnum[i],sizeof(int), cmpfunc);
		for(int k=0;k<outnum[i];k++){
			bum(s, inp[k]);
			nu[k] = num1(s);
			csh(s);
		}
		sort(inp,nu,outnum[i],ret[i]);
	}
	for(int i=0;i<num;i++){
		printf("case #%d:\n", i);
		for(int j=0;j<outnum[i];j++){
			printf("%d ", ret[i][j]);
		}
		printf("\n");
	}
	return 0;
}