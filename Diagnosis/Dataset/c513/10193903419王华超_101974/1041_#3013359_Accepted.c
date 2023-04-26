#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 55

int main() {
	char line[N];
	gets(line);
	int maxlen=1;
	char judge1[]="|-";
	char judge2[]="-|";
	for(int i=0;i<strlen(line);i++){
		int len=1,j=i+1;
		if(line[i]=='|'){
			while(line[j]==judge1[len%2]){
				len++;
				j++;
			}
		}
		else{
			while(line[j]==judge2[len%2]){
				len++;
				j++;
			}
		}
		if(len>maxlen){
			maxlen=len;
		}
		i=j-1;
	}
	printf("%d",maxlen);
	return 0;
}