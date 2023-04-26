#include<stdio.h>
#include<string.h>
int cmp(const void*a,const void*b){
	char *x,*y;
	x=(char*)a;
	y=(char*)b;
	if(strlen(a)>strlen(b)) return -1;
	return 1;
} 
int main(){
	int nums[128]={0};
	char c[1001][1001];
	char a;
	int i=0;
	int p=0,t=0; //p表示数组的一维数据，t表示数组的二维数据 
    while(scanf("%c",&a)!=EOF){
    	nums[a]++;
    	if(nums[a]==p+1){
    		c[p][t]=a;
    		t++;
		}
    	else{
    		c[p][t]='\0';
    		t=0;
    		p++;
    		c[p][t]=a;
    		t++;
		}
	}
	c[p][t]='\0';
	qsort(c,p+1,sizeof(c[0]),cmp);
	printf("%s",c[0]);
} 