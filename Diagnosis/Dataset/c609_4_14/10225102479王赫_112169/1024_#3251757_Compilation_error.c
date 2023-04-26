#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct FILE
{
  int size;
  char name[64];//为什么是unsignedchar
  char day[11];
  char time[6];//为什么数组大小是10
}file;
int cmp_size(const void* _a;const void* _b)
{
    file* a=(file*)_a;
    file* b=(file*)_b;
    return ((a->size)>(b->size)?1:-1);
}
int cmp_time(const void* _a;const void* _b)
{
    file* a=(file*)_a;
    file* b=(file*)_b;
    if(strcmp(a->day,b->day)) return strcmp(a->day,b->day);
    else if(strcmp(a->time,b->time)) return strcmp(a->time,b->time);
    else return strcmp(a->name,b->name);//数字类型的也可以按照字典序进行排列
}
int cmp_name(const void* _a;const void* _b)
{
    file* a=(file*)_a;
    file* b=(file*)_b;
    return (strcmp(a->name,b->name));
}
int main()
{
    int n,flag=1;//flag的作用我还掌握得不是很熟练
    scanf("%d",&n);
    file s[100];
    char a[15];
    while(n)
    {if(flag!=1) printf("\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s %s %d %s\n",s[i].day,s[i].time,s[i].size,s[i].name);//对size的存储形式不做处理吗

    }
    gets(a);//从键盘接受一个字符串 并且以a为首地址开始存储但是原题为什么有两个gets
    if(a[6]='N') qsort(s,n,sizeof(file),cmp_name);
    else if(a[6]='S') qsort(s,n,sizeof(file),cmp_size);
    else(a[6]='T') qsort(s,n,sizeof(file),cmp_time);
    for(int i=0,i<n,i++)
    {
        printf("%s %S %16d %s\n",s[i].day,s[i].time,s[i].size,s[i].name)；//这里16d不合法吗它画个波浪线
    }
    flag=o;
    scanf("%d",&n);
    }
    return o;
}
