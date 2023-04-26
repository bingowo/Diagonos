#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char res[102]={'\0'};

int main()
{
	int T;
	scanf("%d",&T);
	char c;
	gets(res);
	int i;
	for(i=0;i<T;i++)
	{
		printf("case #%d:\n",i);
		gets(res);
		int cnt=0;
		int val=0;
		int len=strlen(res);
		res[len]=' ';
		for(int i=0;i<len+1;i++)
        {
            if(res[i]==' ')
            {

                if(tolower(res[val])=='t' && tolower(res[val+1])=='h' && tolower(res[val+2])=='e' && val+3==i || tolower(res[val])=='a' && val+1==i || tolower(res[val])=='a' && tolower(res[val+1])=='n' && val+2==i || tolower(res[val])=='o' && tolower(res[val+1])=='f' && val+2==i || tolower(res[val])=='f' && tolower(res[val+1])=='o' && tolower(res[val+2])=='r' && val+3==i || tolower(res[val])=='a' && tolower(res[val+1])=='n' && tolower(res[val+2])=='d' && val+3==i)
                    {
                        val=i+1;
                    }
                else
                    cnt++;
                val=i+1;

            }
        }
        printf("%d\n",cnt);
	}
	return 0;
}
