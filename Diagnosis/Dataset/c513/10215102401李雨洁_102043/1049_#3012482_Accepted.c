#include <string.h>
#include <stdio.h>

int main()
{
	char s[502][502];
	char temp[502];
	char ch;
	int T;
	scanf("%d",&T);
	getchar();
	for(int t = 0; t < T; t++)
    {
		int i = 0,j = 0;
		while(scanf("%c",&ch) != EOF && ch != '\n')
		{
			if(ch==',' || ch=='.' || ch=='?' || ch=='!' || ch==' ')
			{
				s[i][j] = '\0';
				if(j != 0) i++;
				j = 0;
			}
            else
            {
				s[i][j] = ch;
				j++;
			}
		}
		s[i][j] = '\0';
		for(int k = 0; k < i - 1; k++)
        {
			for(int l = 0; l < i - k - 1; l++)
			{
				if(strcmp(s[l],s[l+1]) > 0)
				{
					strcpy(temp,s[l]);
					strcpy(s[l],s[l+1]);
					strcpy(s[l+1],temp);
				}
			}
		}
		printf("case #%d:\n",t);
		for(int k = 0; k <= i; k++)
		{
			if(k != 0)
			{
				if(strcmp(s[k],s[k-1]) != 0)
				{
					printf(" %s",s[k]);
				}
			}
            else
            {
				printf("%s",s[k]);
			}
		}
		printf("\n");
	}
	return 0;
}
