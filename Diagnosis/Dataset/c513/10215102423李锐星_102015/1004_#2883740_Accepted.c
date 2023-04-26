#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char str[100];
	char *pch;
	int size,i;
	while (scanf("%s",str)!=EOF){
		pch=strchr(str,'.');
		if (pch==NULL){
			int num1;
			num1=atoi(str);
			size=sizeof(num1);
			unsigned char* pnum1;
			pnum1=(unsigned char*)&num1;
			for (i=0;i<size-1;i++){
				printf("%02x ",*(pnum1+i));
			}
			printf("%02x\n",*(pnum1+i));
		}
		else{
			double num2;
			num2=atof(str);
			size=sizeof(num2);
			unsigned char* pnum2;
			pnum2=(unsigned char*)&num2;
			for (i=0;i<size-1;i++){
				printf("%02x ",*(pnum2+i));
			}
			printf("%02x\n",*(pnum2+i));
		}
	}
	return 0;
}