#include <stdio.h>

#define MAX_LENGTH 10000 /* C程序最多的字符个数 */
#define IN_MULTI_ANN 3	/* 当前处于多行注释 */
#define IN_SINGLE_ANN 2	/* 当前处于单行注释 */
#define IN_QUO 1		/* 当前处于双引号内 */
#define OUT 0			


void delete_annotation(){
	/* 删除输入的C程序中的所有注释 */
	char source[MAX_LENGTH];	/* 保存删除注释后的内容 */
	int index = 0;				/* 数组索引 */
	int c,state,next;		/* next：c的下一个字符 */
	state = OUT;				

	while((c=getchar()) != EOF){
		if( state == OUT){
			switch(c){
				case '/': 
					next = getchar();
					if(next == '*')
						{
							state = IN_MULTI_ANN;	/* 进入多行注释 */
						}
					else if(next == '/')
						{
							state = IN_SINGLE_ANN;	/* 进入单行注释 */
						}
					else{	// 没有进入注释，则打印刚读入的字符
						source[index++] = c;		/* 保存不删除的字符 */
						source[index++] = next;
					}
					break;
				case '\"':
					state = IN_QUO;				/* 进入字符串内 */
					source[index++] = c;
					break;
				default:	/* 其他字符则打印 */
					source[index++] = c;
					break;
			}
		}else if(state == IN_MULTI_ANN){
			if(c == '*'){
				next = getchar();	
				if(next == '/')		// 遇到 */ 多行注释结束 
				{
					state = OUT;
				}
			}
		}else if(state == IN_SINGLE_ANN){
			if( c == '\n'){		// 单行注释结束
				state = OUT;
			}
		}else if(state == IN_QUO){
				/* 双引号内的所有内容都需要保存 */
				if(c == '\"'){	// 双引号结束
					source[index++] = c;
					state = OUT;
				}else if( c == '\\'){	// 如果当前是转义字符则即使下一个字符是 " 也不用管，直接不考虑
					next = getchar();
					source[index++] = c;
					source[index++] = next;
				}else{
					source[index++] = c;
				}
		}
	}
	source[index] = '\0';
}


void main(){
	delete_annotation();
}
