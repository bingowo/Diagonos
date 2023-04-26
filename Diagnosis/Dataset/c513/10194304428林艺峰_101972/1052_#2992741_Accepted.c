#include<stdio.h>
#include<string.h>
char str[30];
int count[300], num[30];
int main(){
	int t, i, j;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%s", &str);
		int l = strlen(str);
		for(j = 0; j < l; ++j){
			count[str[j]] ++;
		}
		while(count['Z']){//0
			count['Z']--;
			count['E']--;
			count['R']--;
			count['O']--;
			num[0]++;
		}
		while(count['W']){//2
			count['T']--;
			count['W']--;
			count['O']--;
			num[2]++;
		}
		while(count['U']){//4
			count['F']--;
			count['O']--;
			count['U']--;
			count['R']--;
			num[4]++;
		}
		while(count['F']){//5
			count['F']--;
			count['I']--;
			count['V']--;
			count['E']--;
			num[5]++;
		}
		while(count['X']){//6
			count['S']--;
			count['I']--;
			count['X']--;
			num[6]++;
		}
		while(count['S']){//7
			count['S']--;
			count['E']--;
			count['V']--;
			count['E']--;
			count['N']--;
			num[7]++;
		}
		while(count['G']){//8
			count['E']--;
			count['I']--;
			count['G']--;
			count['H']--;
			count['T']--;
			num[8]++;
		}
		while(count['I']){//9
			count['N']--;
			count['I']--;
			count['N']--;
			count['E']--;
			num[9]++;
		}
		while(count['O']){//1
			count['O']--;
			count['N']--;
			count['E']--;
			num[1]++;
		}
		while(count['R']){
			count['T']--;
			count['H']--;
			count['R']--;
			count['E']--;
			count['E']--;
			num[3]++; 
		}
		printf("case #%d:\n", i);
		for(j = 0; j <= 9; ++j){
			while(num[j]){
				num[j]--;
				printf("%d", j);
			}
		}
		printf("\n");
	}
	return 0;
}