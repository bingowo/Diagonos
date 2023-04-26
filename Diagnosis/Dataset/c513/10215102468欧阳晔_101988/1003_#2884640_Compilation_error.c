#include <stdio.h>
#include <stlib.h>

struct  //定义，赋值
{
    long long int a;
    int number;
}stu1,stu2;

int cmp(const void *a, count void *b)  //排序
{
    struct stu1,stu2;
    stu1=*((struct *)a);
    stu2=*((struct *)b);
    
    if(stu2.number - stu1.number)
        return stu2.number-stu1.number;
    else
    {
        if(stu1.a > stu2.a)
            return 1;
        else return -1;
    }
}
