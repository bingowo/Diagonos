#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char str[21];
	int cnt;
}ch;
int cmp(const void *p1,const void *p2){
	ch *a = (ch *)p1;
	ch *b = (ch *)p2;
	if(a->cnt!=b->cnt)
		return b->cnt-a->cnt;
	int i=0;
	if(a->str[0]>b->str[0])
		return 1;
	if(a->str[0]<b->str[0])
		return -1;
	while(a->str[i]==b->str[i]){
		if(a->str[i+1]>b->str[i+1])
			return 1;
		if(a->str[i+1]<b->str[i+1])
			return -1;
		i++;
	}	
}
int main()
{
	int T,n;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&n);
		ch s[n];
		
		for(int j=0;j<n;j++){
			char c[128]={'\0'};			
			for(int k=0;k<21;k++){
				s[j].str[k]='\0';
			}
			s[j].cnt=0;
			scanf("%s",s[j].str);
			for(int k=0;k<strlen(s[j].str);k++){
				c[s[j].str[k]]=1;
			}
			for(int k=0;k<128;k++){
				if(c[k]==1)
					s[j].cnt++;
			}
		}
		qsort(s,n,sizeof(ch),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<n;j++){
			printf("%s\n",s[j].str);
		}
	}
	return 0;
}