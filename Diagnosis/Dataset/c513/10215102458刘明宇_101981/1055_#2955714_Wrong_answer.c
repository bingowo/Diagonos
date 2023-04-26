#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main()
{
    char *s = (char *)malloc(sizeof(char)*100001);
    int num[128];
    for(int i = 0;i<128;i++) num[i] = -1;
    gets(s);
    int max = 1;
    int sum = 1;
    char *p = s;
    while(*p){
        //如果对应的下标为-1，表示没有出现过，则长度加1
        //如果对应下标不为1 ，则说明之前出现过，那
        //现有的sum再和max比较大小，然后选一个较大的存起来，sum = 0
        //while 不为1 然后建一个新的指针，新指针去移动，sum++
        char *p1 = p;
        while(*p1 == -1){
            num[*p1] = 1;
            p1++;
            sum++;
        }
        max = max>sum?max:sum;
        p++;
        //如果*p1 
        }
    printf("%d",max);
    return 0;

}