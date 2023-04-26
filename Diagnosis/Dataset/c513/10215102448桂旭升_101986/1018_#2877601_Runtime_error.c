#include <stdio.h>
#include <string.h>
int A[30] = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103};
char str[100] = { '\0' };
int num1[60] = { 0 };
int num2[60] = { 0 };
int num3[60] = { 0 };
int con = 0;
void jia2(){
	int i = 59;
	for(i = 59; i > 0; i--){
		if(num2[i] >= 10){
			num2[i - 1] += (num2[i]/10);
			num2[i] = num2[i]%10;
		}
	}
}
void jia3(){
	int i = 59;
	for(i = 59; i > 0; i--){
		if(num3[i] >= 10){
			num3[i - 1] += num3[i]/10;
			num3[i] = num3[i]%10;
		}
	}
}
void cheng(int n){
	int i;
	if(n > 10){
		for(i = 1; i < 60; i++){
			num3[i - 1] = num2[i];
		}
		num3[0] = 0;
		for(i = 0; i < 60; i++){
			num2[i] *= n%10;
		}
		jia2();
		for(i = 0; i < 60; i++){
			num3[i] *= n/10;
		}
		jia3();
		for(i = 0; i < 60; i++){
			num2[i] += num3[i];
		}
		jia2();
	}
	else{
		for(i = 0; i < 60; i++){
			num2[i] *= (n%10);//printf("%d\n", num2[i]);
		}
		jia2();
	}
}
int ctoi(int n){
	int i = 0, ten = 0, k;
	for(i = 0; i < n; i++){
			num2[59] += num1[i];
			jia2();//printf("%d %d %d\n", num2[57], num2[58], num2[59]);
			cheng(A[n - i - 1]);
		}
}
int main()
{
    int i, len;
	int j = 0, ten = 0, k;
    gets(str);
	len = strlen(str);
	for(i = 0; i < len; i++){
		while(str[i] != ',' && i < len){
			ten = ten * 10 + (str[i] - '0');
			num1[j] = ten;
			i++;
		}
		j++;ten = 0;
	}con = j;
	ctoi(j);
	i = 0;
	while(num2[i] == 0)i++;
	for(;i < 60; i++){
		printf("%d", num2[i]);
	}
    return 0;

}