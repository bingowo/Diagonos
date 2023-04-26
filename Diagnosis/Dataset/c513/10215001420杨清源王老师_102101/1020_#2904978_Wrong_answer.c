#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct//用结构体定义file，其中有四个参数 
{
	char name[100];
	char time[20];
	char date[20];
	int size;
} File;

File file[100];

int cmp_name( const void *a , const void *b)
{
	File *p1 = (File *)a;
	File *p2 = (File *)b;
	return strcmp(p1 -> name , p2 -> name);
}

int cmp_time( const void *a , const void *b)
{
	File *p1 = (File *)a;
	File *p2 = (File *)b;
	if( p1 -> time == p2 -> time)
		return strcmp(p1 -> name , p2 -> name);
	else
		return strcmp(p1 -> time , p2 -> time);
}

int cmp_size( const void *a , const void *b)
{
	File *p1 = (File *)a;
	File *p2 = (File *)b;
	if( p1 -> size == p2 -> size)
		return strcmp(p1 -> name , p2 -> name);
	else
		return p1 -> size - p2 -> size;
}

int main()
{
	while(1)
	{
		int n , i , j;
		scanf("%d",&n);
		if( n == 0)// n=0时跳出循环 
			break;
		for( i = 0 ; i < n ; i++ )
			scanf("%s%s%d%s",file[i].date,file[i].time,&file[i].size,file[i].name);//对file赋初值 
		
		char command[10];
		scanf("%s",command); 
		scanf("%s",command); //两次输入读取空格后的内容
		
		if( strcmp( command , "/NAME" ) == 0 ) 
			qsort(file , n , sizeof(char) , cmp_name);
		if( strcmp( command , "/SIZE" ) == 0 ) 
			qsort(file , n , sizeof(char) , cmp_size);
		if( strcmp( command , "/TIME" ) == 0 ) 
			qsort(file , n , sizeof(char) , cmp_time);

		for( i = 0 ; i < n ; i++)
			printf("%s %s %16d %s\n",file[i].date,file[i].time,file[i].size,file[i].name);
		printf("\n");
	}
}