#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char str[100];
	char *pch;
	unsigned char* pnum;
	int size,i;
	while (scanf("%s",str)!=EOF){
		pch=strchr(str,'.');
		if (pch==NULL){
			int num1;
			num1=atoi(str);
			size=sizeof(num1);
			pnum=(unsigned char*)&num1;
		}
		else{
			double num2;
			num2=atof(str);
			size=sizeof(num2);
			pnum=(unsigned char*)&num2;
			
		}
		for (i=0;i<size-1;i++){
				printf("%02x ",*(pnum+i));
			}
			printf("%02x\n",*(pnum+i));
	}
	return 0;
}