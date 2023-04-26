#include /************ 前后倒置函数 ***************/

void reverse(char *str)

{

unsigned int i,j;

char c;

for(i = 0 , j = strlen(str)-1; i < j; i++,j--)

{

c = str[i]; str[i] = str[j]; str[j] = c ;

}

}

void main()

{

char str1[100], str2[100],str[101];

char *p1 = NULL, *p2 = NULL,*p = NULL;

unsigned int len1 = 0,len2 = 0,len = 0;

unsigned int i = 0;

printf("input the first number : ");

scanf("%s",str1);

printf("input the second number : ");

scanf("%s",str2);

len1 = strlen(str1);

len2 = strlen(str2);

if(len1 > 100 || len2 > 100)

return;

len = len1 > len2 ? len1 : len2 ;

/********** 补0 ************/

reverse(str1);

reverse(str2);

for(i = len1 ; i < len + 1; i++)

{

str1[i] = '0';

}

str1[i] = '\0';

for(i = len2 ; i < len + 1; i++)

{

str2[i] = '0';

}

str2[i] = '\0';

/***** 从最低位开始相加，一直加到最前端的0 ******/

p1 = str1 ;

p2 = str2 ;

p = str ;

while(*p1 != '\0')

{

*p = (*p1 -48) + (*p2 - 48) ;

if(*p >= 10)

{

*p = *p - 10;

p2 ++;

*p2 = *p2 + 1;

}

else

p2 ++ ;

*p = *p + 48 ;

p1 ++;

p ++;

}

*p = '\0';

len = strlen(str);

reverse(str);

if(str[0] == '0')

for(i = 0; i < len; i++)

str[i] = str[i+1];

puts(str);

}
