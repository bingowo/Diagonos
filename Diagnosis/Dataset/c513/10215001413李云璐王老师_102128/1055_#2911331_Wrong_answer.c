#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char a[1000001];
    scanf("%s",a);
    int len=strlen(a),i;
    int tmp = 1;
		int max = tmp;
		
		for( i = 1; i < len; i++)
		{
			if(a[i] != a[i-1])
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