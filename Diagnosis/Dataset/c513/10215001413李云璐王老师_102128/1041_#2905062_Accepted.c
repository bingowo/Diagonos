#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char s[60];
    scanf("%s",s);
    int len=strlen(s);
    
    	int tmp = 1,i;
		int max = tmp;
		
		for( i = 1; i < len; i++)
		{
			if(s[i] != s[i-1])
				tmp++;
			else
			{
				tmp = 1;
				continue;
			}
			
			if(max < tmp)
				max = tmp;
		}
    printf("%d",max);
    return 0;
    
}