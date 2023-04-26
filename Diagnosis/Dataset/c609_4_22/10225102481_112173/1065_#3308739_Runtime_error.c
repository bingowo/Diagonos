#include <stdio.h>
#include <stdlib.h>
int j=-1;

double trans(char s[])
{
   j++;

   switch(s[j])
   {
       case'+':return trans(s)+trans(s);
       case'-':return trans(s)-trans(s);
       case'*':return trans(s)*trans(s);
       case'/':return trans(s)/trans(s);
       default:
			return s[j]-'0'; //将char转换成对应的浮点数
			break;
   }
}

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        char s[11];
        int t=0;
        while(scanf("%c",&s[t])!=EOF)t++;
        printf("case #%d:",i);
        printf("%.6lf\n",trans(s));
    }


    printf("Hello world!\n");
    return 0;
}
