#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[100];
	int i,count;
	while(scanf("%s",a)!=EOF){
		if(strchr(a,'.')==NULL){
			int num=atoi(a);//转换成数字
			count=sizeof(num);//记录字节数
			int* p=&num;
			unsigned char *p1=(unsigned char *)p;
			for(i=0;i<count;i++)
			{
				printf("%02x ",*(p1+i));
			}
			printf("\n");
		}
	else {
		double num=atof(a);
		count=sizeof(num);
		double* p=&num;
		unsigned char *p1=(unsigned char *)p;
		for(i=0;i<count;i++)
		{
			printf("%02x ",*(p1+i));
		}
		printf("\n");}
}

	return 0;
}
