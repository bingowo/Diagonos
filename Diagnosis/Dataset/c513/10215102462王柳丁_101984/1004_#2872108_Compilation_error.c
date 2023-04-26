#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[100];
	int i,count;
	scanf("%s",a);
	if(strchr(a,'.')==NULL){
		int num=atoi(a);
		count=sizeof(num);
		int* p=&num;}
	else {
		double num=atof(a);
		count=sizeof(num);
		double* p=&num;}
	p=(unsigned char *)p;
	for(i=0;i<count;i++)
	{
		printf("%02x ",*(p+i));
	}
	printf("\n");
	
	return 0;
	
	
}