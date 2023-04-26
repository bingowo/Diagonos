#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int t, i, j;
    scanf("%d",&t);//问题数 
    for(j = 0; j < t; j++)
    {
        char s[100];//输入三进制串 
        scanf("%s",s);
       	long long int ans = 0;
       	int len = strlen(s);
       	
       	for(i = 0;i<len;i++)
       	{
       		if(s[i] == '-')
       			ans -= pow(3,len - i - 1);
       		if(s[i] == '1')
       			ans += pow(3,len - i - 1);
		}


        printf("case #%d:\n",j);
        printf("%lld\n",ans);
    }

}