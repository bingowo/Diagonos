#include<stdio.h>
#include<string.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        char s[500];
        scanf("%s",&s);
        int l=strlen(s);
        int t=1;
        int a[500];
        char c[500];
        int start=0;
        for(int j=0;j<l;j++)
        {
        	if(s[j+1]==s[j])
        	{
        		t++;
			}
			else
			{
				a[start]=t;
				c[start]=s[j];
				start++;
				t=1;
				continue;
			}	
		}
        printf("case #%d:\n",i);
        for(int j=0;j<start-1;j++)
        {
            if(a[j]<=255)
            {
                printf("%d",a[j]);
                printf("%c",c[j]);
            }
            else
            {
                int r=a[j]/255;
                for(int x=0;x<r;x++)
                {
                    printf("%d",255);
                    printf("%c",c[j]);
                }
                printf("%d",r%255);
                printf("%c",c[j]);
            }
        }
        if(a[start-1]<=255)
        {
            printf("%d",a[start-1]);
            printf("%c\n",c[start-1]);
        }
        else
        {
            int y=a[start-1]/255;
            for(int j=0;j<y;j++)
            {
                printf("%d",255);
                printf("%c",c[start-1]);
            }
            printf("%d",y%255);
            printf("%c\n",c[start-1]);
        } 
    }
    return 0;
}