#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,j;
	char Octal[55],decimal[155],temp;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int numbers = 0;
		scanf("%s",Octal);
        int len= strlen(Octal)-1;
        for (; len != 1; --len)
        {
            int digit = Octal[len]-'0';
            j = 0;
            do {
                if (j < numbers)
                    temp = digit*10 + decimal[j]-'0';
                else
                    temp = digit*10;
                decimal[j++] = temp/8+'0';
                digit = temp%8;
            } while (digit!=0 || j < numbers);
            numbers = j;
        }
        decimal[numbers] = '\0';

    	printf("case #%d:\n%s\n",i,decimal);
	}

	

	
	return 0;
	
	
 } 