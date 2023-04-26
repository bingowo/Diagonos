#include <stdio.h>

int delrep(int*, int*, int); 
//delete the repetitive number in the int array,
//retern the number of members in the new array

int a_cmp(void *a, void *b) {
	int n1 = *(int*)a, n2 = *(int*)b;
	return n1 - n2;
}

int d_cmp(void *a, void *b) {
	int n1 = *(int*)a, n2 = *(int*)b;
	return n2 - n1;
}

int main() {
	int data[100] = {0}; //store the numbers inputted in
	char flag; //A stands for ascending order and D stands for descending one
	scanf("%s", &flag);
	int cnt = 0;
	while((scanf("%d", &data[cnt++])) != EOF);
	cnt--;
	int nonrep_data[100] = {0};
	if(flag == 'A') qsort(data, cnt, sizeof(int), a_cmp);
	else qsort(data, cnt, sizeof(int), d_cmp);
	delrep(data, nonrep_data, cnt);
	return 0;
}

int delrep(int* inp, int* otp, int num) {
	int j = 0;
	otp[j] = inp[0];
	for (int i = 0; i < num; i++) {
		if(inp[i] != otp[j]) {
			otp[++j] = inp[i];
		}
	}
	j++;
	for(int k = 0; k < j; k++){
		printf("%d ", otp[k]);
	}
	return j;
}
