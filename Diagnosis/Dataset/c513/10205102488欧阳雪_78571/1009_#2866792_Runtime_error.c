#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int result(int m,int n){
	int a = m;
    int b = n;
    while(a % b)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    m /= b;
    n /= b;						
   	printf("%d",n);
   	printf("/");
   	printf("%d\n",m);
}
int diverse(char *a)
{
    int len = strlen(a),m;
    int s = 0;
    int i;
    for(i = 0; i < len; i++)
    {
        char temp = a[i];
        while(temp)
        {
            //temp = temp & (temp - 1);
            if(temp%2==1)s++;
            temp=temp/2;
        }
    }
    m = 8 * len;
    result(m,s);
}
int main()
{
int T;
char a;
int i,j=0,k;
char* p;
scanf("%d\n",&T);
for(i=0;i<T;i++)
{
	j=0;
char str[1000]={'\0'};
while( (a = getchar()) != '\n')
   {
   	str[j]=a;
   	j++;
   }
diverse(str);
}
}