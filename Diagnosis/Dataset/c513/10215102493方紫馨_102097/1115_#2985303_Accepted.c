#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void*p1,const void * p2){
	return *(int*)p1 -*(int*)p2;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		printf("case #%d:\n",i);
		//将数字数组储存在n中，因为N的大小太大 
		int n[30] = {0};
		char s[30];
		scanf("%s",s);
		int len = strlen(s);
		for(int j=0;j<len;j++){
			n[j+1] = s[j] - '0';
		}
		int p1,p2;
		for(int j = len - 1;j>=0;j--){
			if(n[j] < n[j+1]){
				p1 = j;
				break;
			}
		}
		p2 = p1 + 1;
		for(int j = len;j>=p1;j--){
			if(n[j]>n[p1]&&n[j]<=n[p2])
				p2 = j;
		}
		int t;
		t = n[p2];
		n[p2] = n[p1];
		n[p1] = t;
		qsort(n+p1+1,len-p1,sizeof(int),cmp);
		int index = 0;
		while(n[index]==0)
			index++;
		for(;index<=len;index++){
			printf("%d",n[index]);
		}
		printf("\n");
	}
	
	return 0;
}