#include<stdio.h>
#include<stdlib.h>

int main(void)

{
int i,k;

char hexad[80],str[80];

long number;

i=0;

while((str[i]=getchar())!='\n')

i++;

str[i]='\0';

/*过滤非十六进制字符后生成新字符串*/

k =0;

for(i=0;str[i]!='\0';i++)

if(str[i]<='9'&&str[i]>='0'||str[i]<='f'&&str[i]>='a'||str[i]<='F'&&str[i]>='A'){/*判断是数字字符*/

hexad[k]=str[i];

k++;

}

hexad[k]='\0';

/*输出十六进制新字符串*/

printf("New string:");

for(i=0;hexad[i]!='\0';i++)

putchar(hexad[i]);

printf("\n");

/*转换为十进制数*/

number=0;

for(i=0;hexad[i]!='\0';i++){
if(hexad[i]<='9'&&hexad[i]>='0')

number=number*16+hexad[i]-'0';

if(hexad[i]<='F'&&hexad[i]>='A')

number=number*16+hexad[i]-'A'+10;

if(hexad[i]<='f'&&hexad[i]>='a')

number=number*16+hexad[i]-'a'+10;

}

printf("Number=%ld\n",number);

return 0;

}