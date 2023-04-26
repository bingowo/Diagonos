#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
 char *base64_encode( char *str)
{
    long len;
    long str_len;
   char *res;
    int i,j;
//定义base64编码表
     char *base64="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
 
//计算经过base64编码后的字符串长度
    str_len=strlen(str);
    if(str_len % 3 == 0)
        len=str_len/3*4;
    else
        len=(str_len/3+1)*4;
 
    res=(char *)malloc(sizeof(char)*len+1);
    res[len]='\0';
 
//以3个8位字符为一组进行编码
    for(i=0,j=0;i<len-2;j+=3,i+=4)
    {
        res[i]=base64[str[j]>>2]; //取出第一个字符的前6位并找出对应的结果字符
        res[i+1]=base64[(str[j]&0x3)<<4 | (str[j+1]>>4)]; //将第一个字符的后位与第二个字符的前4位进行组合并找到对应的结果字符
        res[i+2]=base64[(str[j+1]&0xf)<<2 | (str[j+2]>>6)]; //将第二个字符的后4位与第三个字符的前2位组合并找出对应的结果字符
        res[i+3]=base64[str[j+2]&0x3f]; //取出第三个字符的后6位并找出结果字符
    }
 
    switch(str_len % 3)
    {case 1:
            res[i-2]='=';
            res[i-1]='=';
            break;
    case 2:
            res[i-1]='=';
            break;
    }
    return res;
}
int main(){
	int T;
	scanf("%d",&T);
	char s[150];
	for(int v=0;v<T;v++){
		scanf("%s",s);
		char *p=base64_encode(s);
		printf("case #%d\n",v);
		printf("%s",p);
		printf("\n");
	}
	return 0;
}