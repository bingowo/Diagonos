#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char array[51];
	scanf("%s",array);
	int max = 1;
	int i;
	int start, left, right, length;
	start = 0;
	left = 0;
	right = 1;
	length = 1;
	while (right < strlen(array)){
		while (array[left] != array[right] && right < strlen(array)){
			length++;
			left++;
			right++;
		}
		if (max < length){
			max = length;
		}
		start = right;
		left = right;
		right = right + 1;
		length = 1;
	}
	printf("%d",max);
}