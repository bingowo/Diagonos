#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char *line = malloc(1000000 * sizeof(char));
    gets(line);
    bool success = false;
    int flag = 1;
    for(char *begin = line, *end = line + strlen(line);begin < end; begin++){       
        if((*begin == '0') && *(begin + 1) == 'x') {
            char *end_ptr = NULL;
            long int k = strtol(begin + 2, &end_ptr, 16);
			/*long int strtol(const char *nptr,char**endptr,int base)strtol()扫描参数nptr字符串，
			跳过前面的空格字符，直到遇上数字或正负符号开开始做转换，转换为base进制的数，再遇上非数字或字符串结束时结束转换，endptr指向停止转换的位置*/
            if(end_ptr != begin + 2) {
                success = true;
                if(flag!=0) {
                    printf(" ");
                } else {
                    flag = 0;
                }
                printf("%ld", k);
                begin = end_ptr;
            }
        }
    }
    if(!success) {
        printf("-1");
    }
    printf("\n");
    return 0;
}