# include <stdio.h>
# include <stdlib.h>

int main(){
    char a[50];
    int i=0;
	while ( i < 50 )
    {
    	scanf("%c",a[i]);
    	i++;
	}
	int max;
	int length,place;
	while ( place < 50 )
	{
		for ( length = 0; length < (50 - place); length++)
		{
			if ( a[place] != a[place + 1])
			{
				break;
			}
			place++;
			if (length > max)
			{
				max = length;
			}
		}
	}
	printf("%d",max);
	return 0;
}
