/*处理输入的函数
	读取16进制并转换的函数
	输出的函数*/
#include<stdio.h>
#include<string.h>
unsigned int trans(char* s);
void solveinput(char* s)
{
    char *pa=s;
    char *pb=pa+1;
    while(*pb)
    {
        char temp[101]={'\0'};
        while(*pa!='0'&&*pb!='x')
        {
            pa++;
            pb++;
        }
        char* pstart=pb+1;
        char* pend=pstart;
        while(*pend<='f')pend++;
        if(pstart==pend)
        {
            if(*pend=='\0')
            {
                printf("%d",-1);
            }
            else
            {
                pa=pstart;
                pb=pa+1;
                continue;
            }
        }
        else
        {
            memmove(temp,pstart,pend-pstart);
            temp[pend-pstart]='\0';
            //itob;
            unsigned int res=trans(temp);
            printf("%u ",res);
            pa=pend;
            pb=pa+1;
        }
    }

}
unsigned int trans(char* s)
{
    char*ps=s;
    unsigned int res=0;
    for(; *ps; ps++)
    {
        if(*ps>='a'&&*ps<='f')
        {
            res=res*16+*ps-'a'+10;
        }
        else
        {
            res=res*16+*ps-'0';
        }
    }
    return res;
}
int main()
{
    char s[100001]={'\0'};
    scanf("%s",s);
    solveinput(s);
	return 0;
}