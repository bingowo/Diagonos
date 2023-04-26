#include <stdio.h>
#include <string.h>

void trans(char* s,int* num)
{
	int list[100];
	int i;
	for (i=0;i<100;i++){
		list[i]=0;
	}
	for (i=0;i<strlen(s);i++){
		list[s[i]]+=1;
	}
	while(list['Z']!=0){
		num[0]++;
		list['Z']--;
		list['E']--;
		list['R']--;
		list['O']--;
	}
	while(list['T']!=0){
		num[2]++;
		list['T']--;
		list['W']--;
		list['O']--;
	}
	while(list['X']!=0){
		num[6]++;
		list['S']--;
		list['I']--;
		list['X']--;
	}
	while(list['G']!=0){
		num[8]++;
		list['E']--;
		list['I']--;
		list['G']--;
		list['H']--;
		list['T']--;
	}
	while(list['S']!=0){
		num[7]++;
		list['S']--;
		list['E']-=2;
		list['V']--;
		list['N']--;
	}
	while(list['V']!=0){
		num[5]++;
		list['F']--;
		list['I']--;
		list['V']--;
		list['E']--;
	}
	while(list['F']!=0){
		num[4]++;
		list['F']--;
		list['O']--;
		list['R']--;
		list['E']--;
	}
	while(list['T']!=0){
		num[3]++;
		list['T']--;
		list['H']--;
		list['R']--;
		list['E']-=2;
	}
	while(list['O']!=0){
		num[1]++;
		list['O']--;
		list['N']--;
		list['E']--;
	}
	while(list['I']!=0){
		num[9]++;
		list['N']-=2;
		list['I']--;
		list['E']--;
	}
}

void solve(int T)
{
	char s[21];
	scanf("%s",s);
	int num[11];
	int i;
	for (i=0;i<11;i++){
		num[i]=0;
	}
	trans(s,num);
	for (i=0;i<11;i++){
		while(num[i]!=0){
			printf("%d",i);
			num[i]--;
		}
	}
	printf("\n");
}


int main()
{
	int T;
	scanf("%d",&T);
	for (int i;i<T;i++){
		printf("case #%d:\n",i);
		solve(i);
	}
	return 0;
}