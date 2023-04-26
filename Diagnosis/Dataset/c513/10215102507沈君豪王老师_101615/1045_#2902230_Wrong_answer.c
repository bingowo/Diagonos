#include <stdio.h> 
#include <string.h>
#include <math.h>

typedef struct{
	char s[110];
	char min_s[110];
	int frequency[26];
}Str;

void CreateMin(char ms[], char s[])
{
	char *ps1 = s, *ps2 = s, *pms = ms;
	while(*ps2){
		if(*ps2 != *ps1){
			*pms = *ps1;
			ps1 = ps2;
			pms ++;
		}else{
			ps2 ++;
		}
	}
	*pms = *ps1;
	pms ++;
	*pms = '\0';
}

void CountFrequency(int f[], char s[])
{
	char *ps = s;
	while(*ps){
		f[*ps - 'a']++;
		ps ++;
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	Str in[n];
	int AverageFrequency[26] = {0, };
	int isValid = 1, step = 0;
	for(int i = 0; i < n ; i ++){
		scanf("%s", in[i].s);
		CreateMin(in[i].min_s, in[i].s);
		memset(in[i].frequency, 0, sizeof(in[i].frequency));
		CountFrequency(in[i].frequency, in[i].s);
		for(int j = 0 ; j < 26 ; j ++){
			AverageFrequency[j] += in[i].frequency[j];
		}
	}
	for(int i = 0; i < 26 ; i ++){
		AverageFrequency[i] = ceil(AverageFrequency[i] / (double)n);
	}
	for(int i = 0 ;i < n ; i ++){
		for(int j = 0 ; j < n ; j ++){
			if(j != i && strcmp(in[j].min_s, in[i].min_s) != 0){
				isValid = 0;
				goto out;			
			}
		}
		for(int j = 0 ; j < 26 ; j ++){
			step += abs(in[i].frequency[j] - AverageFrequency[j]);
		}
	}
	out :
	if(isValid){
		printf("%d", step);
	}else{
		printf("-1");
	}
	
	return 0;
}