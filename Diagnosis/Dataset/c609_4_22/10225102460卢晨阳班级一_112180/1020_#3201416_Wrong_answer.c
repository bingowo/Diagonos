#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct data{
	char a[31];
	int idx;//是否有数字 
	int number;//数字大小 
}data;

int cmp(const void*p,const void *q){
	data *pp=(data*)p;
	data *qq=(data*)q;
	if(pp->idx==1&&qq->idx==0)
		return 1;
	else if(qq->idx==1&&pp->idx==0)
		return -1;
	else if(qq->idx==1&&pp->idx==1)
		return pp->number-qq->number;
	else if(qq->idx==0&&pp->idx==0)
		return strcmp(pp->a,qq->a);
	return 0;
}

int main()
{
	data s[101];
	int n=0;
	while(scanf("%s",s[n].a)!=-1)
		n++;
	for(int i=0;i<n;i++){
		s[i].idx=0;
		int cnt=strlen(s[i].a);
		for(int j=0;j<cnt;j++){
			if(s[i].a[j]>='0'&&s[i].a[j]<='9'){
				s[i].idx=1;
				s[i].number=s[i].number*10+(s[i].a[j]-'0');
			}
		}
	}
	qsort(s,n,sizeof(s[0]),cmp);
	for(int i=0;i<n;i++)
	printf("%s ",s[i].a);
	return 0;
}