#include <stdio.h>
#include <string.h>

void changedigit(char *a,int num,int len);
void changebin(char *a,char *b)     //b是结果
{
    int temp;

    if(a[2]!=0)     //10位
    {
        temp=(a[0]-'0')*100+(a[1]-'0')*10+(a[2]-'0');
        changedigit(b,temp,10);
    }
    else if(a[1]==0)   //4位             //检测顺序，第三位等于0不代表第二位就有数字
    {
        temp=(a[0]-'0');
        changedigit(b,temp,4);
    }
    else if(a[2]==0)  //7位
    {
        temp=(a[0]-'0')*10+(a[1]-'0');
        changedigit(b,temp,7);
    }
}
void changedigit(char *a,int num,int len)
{
    int i=1,tim;
    i=i<<(len-1);
    for(tim=0;tim<len;tim++)
    {
        if((num&i)==0)                  //位运算符优先级
            a[tim]='0';
        else
            a[tim]='1';
        //a[tim]=num&i;
        i=i>>1;
    }
}
int main()
{
    int i,j;
    char a[501],res[1670],*c;
    memset(a,0,sizeof(char)*501);
    memset(res,0,sizeof(char)*1670);

    res[0]='0';res[1]='0';res[2]='0';res[3]='1';

    gets(a);

    changedigit(res+4,strlen(a),10);

    c=res+4+10;
    for(i=0,j=0;i<strlen(a);i+=3,j++)           //非同步进行
    {
        changebin(a+i,c+j*10);
    }
    puts(res);
    return 0;
}
