#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main()
{
	/* 变量声明 */
    int input_num;         //  输入行数 
	char **input_str;      //  输入字符串数组
	char simple[100];      //  去重字符串
	int simple_len;        //  去重字符串长度 
	int point;             //  游标 
	int **sum;             //  统计数据二维数组 
	int trans_num;         //  转换次数 
	 
	/* 变量初始化 */
	input_num = 0;
	simple_len = 0; 
	point = 0; 
    trans_num = 0;

    /* 获取行数n */
    scanf("%d", &input_num);
    
    /* 获取n行字符串 */ 
    input_str = (char **)malloc(sizeof(char*)*input_num);
    for(int i=0; i<input_num; i++)
    {
    	input_str[i] = (char*)malloc(sizeof(char)*100);
        scanf("%s", input_str[i]);
    }

    /* 第一行字符串去重 */
    strcpy(simple, input_str[0]);
	simple_len = strlen(simple);
    point = 0;
    for(int i=1; i<simple_len; i++) {
    	if(simple[i] != simple[point])
    	{
    		simple[point+1] = simple[i];
            point++;
		}
	}
    simple[point+1] = '\0';
    simple_len = strlen(simple);
    
    /* 统计数据 */
    sum = (int**)malloc(sizeof(int)*input_num);
    for(int i=0; i<input_num; i++)          // 初始化统计二维数组 
	{
		sum[i] = (int*)malloc(sizeof(int)*simple_len);
	    for(int j=0; j<simple_len; j++)
	    {
	    	sum[i][j] = 1;
		}
	} 
    for(int i=0; i<input_num; i++)
    {
    	point = 0;
    	for(int j=0; j<strlen(input_str[i]); j++)
    	{
    		if(input_str[i][j] != simple[point])
    		{
    			printf("-1");
    			return;
			}
			
    		if(input_str[i][j] == input_str[i][j+1])
    		{
    			sum[i][point]++;
			}
			else
			{
				point++;
			}
		}
	}
	
	/* 计算转换次数 */
	for (int i=0; i<simple_len; i++)
	{
		int count;         // 差值总和 
		int midd_small;    // 小中间值 
		int midd_big;      // 大中间值 
		int trans_small;   // 以小中间值的转换次数 
		int trans_big;     // 以大中间值的转换次数 
		
		count = 0;
		midd_small = 0;
		midd_big = 0;
		trans_small = 0;
		trans_big = 0;
		for(int j=0; j<input_num; j++)
		{
			count += sum[j][i];
		}
		midd_small = count / input_num;
		midd_big = midd_small + 1;
		
		for(int j=0; j<input_num; j++)
		{
			trans_small += abs(sum[j][i] - midd_small);
			trans_big += abs(sum[j][i] - midd_big);
		}
		
		if(midd_small < midd_big)
		{
			trans_num += midd_small;
		}
		else
		{
			trans_num += midd_big;
		}
	}
	
	/* 输出结果 */
    printf("%d", trans_num);
    
    return;
}
