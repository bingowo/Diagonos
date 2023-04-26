#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int dic[26];
typedef struct{
	int len;
	char s[25];
}p; 
int cmp1(const void *a, const void *b){
	int i;
	int l1=(*(p*)a).len,l2=(*(p*)b).len;
	int l=l1>l2?l2:l1;
	for(i=0;i<l;i++){
		char t1=(*(p*)a).s[i],t2=(*(p*)b).s[i];
		t1-='A',t2-='A';
		if(t1>25) t1=t1+'A'-'a';
		if(t2>25) t2=t2+'A'-'a';
		//printf("%d %d\n",t1,t2);
		if(dic[t1]!=dic[t2]) return dic[t1]>dic[t2];
	}
	return l1>l2;
}
int main(){
	int cnt=0;
	p a[105];
	int f=0;
	int i;
	char t[30];
	while(scanf("%s",t)!=EOF){
		if(strlen(t)==26){
			//printf("%d\n",cnt);
			if(f!=0){
				qsort((void *)a,cnt,sizeof(p),cmp1);
				for(i=0;i<cnt;i++){
					printf("%s ",a[i].s);
				}
				printf("\n");
			}
			f=1;
			for(i=0;i<strlen(t);i++){
				dic[t[i]-'A']=i;
			}
		//	for(i=0;i<25;i++){
		//		printf("%d  ",dic[i]);
		//	}
		//	printf("\n");
			cnt=0;
		}
		else{
			t[strlen(t)]='\0';
			strcpy(a[cnt].s,t);
			a[cnt].len=strlen(t);
			//printf("%s	%d\n",a[cnt].s,a[cnt].len);
			cnt++;
		}
	}
	qsort((void *)a,cnt,sizeof(a[0]),cmp1);
	for(i=0;i<cnt;i++){
		printf("%s ",a[i].s);
	}
	printf("\n");
}
/*
QWERTYUIOPASDFGHJKLZXCVBNM
How are you
QWERTYUIOPASDFGHJKLZXCVBNM
hat cat bat book bookworm Dallas Austin Houston fire firefox fumble
QAZWSXEDCRFVTGBYHNUJMIKOLP
How are you
ABCDEFGHIJKLMNOPQRSTUVWXYZ
How are you
*/