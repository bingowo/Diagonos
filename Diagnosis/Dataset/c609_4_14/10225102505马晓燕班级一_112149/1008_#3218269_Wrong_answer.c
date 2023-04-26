#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main()
// {
//     char p[1000];
//     while (scanf("%s",p) != -1)
//     {
//         if(strchr(p,'.') == NULL)  //整数
//         {
//             int val = atoi(p);
//             int *pp = &val;
//             for(int i=0;i<sizeof(val);i++)
//             {
//                 printf("%02x ",*((unsigned char*)pp+i));
//             }
//         }
//         else                    //double型
//         {
//             double f = atof(p);
//             double *pp = &f;
//             for(int i=0;i<sizeof(f);i++)
//             {
//                 printf("%02x ",*((unsigned char*)pp+i));
//             }
//         }
//         printf("\n");

//     }
//     return 0;
// }
int main()
{
	char s[100];
	int x;
	unsigned char* t;

	while((scanf("%s" ,s))!=EOF)
	{	
		if((strchr(s,'.')) == NULL)
		{
			int a = atoi(s);
			x =sizeof(a);
			int* b=&a;
			t=(unsigned char*)b;
		}else{
			double a = atof(s);
			x =sizeof(a);
			double* b=&a;
			t=(unsigned char*)b;
		}

		for(int i=0;i<x;i++){
			printf( "%02x " , *t++) ;	
		}
		printf("\n");
	}
		return 0;
}
