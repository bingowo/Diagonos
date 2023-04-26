#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char* st;
    int num;

}STRING;

int get_num(char* s)
{
    int flag=0;
    int i=0,j=0;
    int* num;
    char* p=s;
    while((*p)!='\0')
    {
        if((*p)<='9'&&(*p)>='0')
        {
            flag=1;
            *(num+j)=(int)(*p-'0');
            j++;
        }
        p++;
    }
    for(i=0;i<j;i++)
        ;

    if(flag)return get_int(num,j);
    return -1;
}
int get_int(int*s,int j)
{
    int answer=0;
    for(int i=0;i<j;i++)
    {answer=(answer+*(s+i));
    answer*=10;}
    answer/=10;
    return answer;

}
int main()
{
    char* s="ab105cb";
    printf("%d",get_num(s));
    STRING* a[102];
    char* tem[31];
    //while(scanf("%s",tem)!=EOF)




}
