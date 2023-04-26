#include <stdio.h>
#include <string.h>
int A[30] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113};
char str1[60] = { 0 };
char str2[60] = { 0 };
int num1[60] = { 0 };
int num2[60] = { 0 };
int num3[60] = { 0 };
int f(int con1, int con2){
	int i, j = 0, max = con1 > con2 ? con1 : con2, len;
	if(con1 > con2){
		for(i = 0; i < con2;i++){
			num3[j] = num1[con1 - 1 - i] + num2[con2 - 1 - i];j++;
		}
		for(i = con2; i < con1;i++){
			num3[j] = num1[con1 - 1 - i];j++;
		}
		j = 0;
	}
	if(con1 < con2){
		for(i = 0; i < con1;i++){
			num3[j] = num1[con1 - 1 - i] + num2[con2 - 1 - i];j++;
		}
		for(i = con1; i < con2;i++){
			num3[j] = num2[con2 - 1 - i];j++;
		}
		j = 0;
	}
	if(con1 == con2){
		for(i = 0; i < con2;i++){
			num3[j] = num1[con1 - 1 - i] + num2[con2 - 1 - i];j++;
		}
		j = 0;
	}
	for(i = 0; i < max; i++){
		if(num3[i] >= A[i]){
			num3[i] -= A[i];
			num3[i+1] += 1;
		}
	}
	if(num3[max] == 0)i -= 1;
	return i;	
}

int ctoi(){
	int len1 = strlen(str1), len2 = strlen(str2), i = 0, j1 = 0, j2 = 0, ten = 0;
	for(i = 0; i < len1; i++){
		while(str1[i] != ',' && i < len1){
			ten = ten * 10 + (str1[i] - '0');
			num1[j1] = ten;
			i++;
		}
		j1++;ten = 0;
	}
	for(i = 0; i < len2; i++){
		while(str2[i] != ',' && i < len2){
			ten = ten * 10 + (str2[i] - '0');
			num2[j2] = ten;
			i++;
		}
		j2++;ten = 0;
	}
	return f(j1, j2);
}

int main()
{
    int i, t, wei, j, k;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
    	scanf("%s", &str1);scanf("%s", &str2);
    	wei = ctoi();printf("case #%d\n", i);
    	while(wei > -1){
    		printf("%d", num3[wei]);
			if(wei != 0)printf(",");wei--;
		}
		printf("\n");
	}
    return 0;

}