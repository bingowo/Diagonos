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

                if(res[val]=='t' && res[val+1]=='h' && res[val+2]=='e' && val+3==i || res[val]=='a' && val+1==i || res[val]=='a' && res[val+1]=='n' && val+2==i || res[val]=='o' && res[val+1]=='f' && val+2==i || res[val]=='f' && res[val+1]=='o' && res[val+2]=='r' && val+3==i || res[val]=='a' && res[val+1]=='n' && res[val+2]=='d' && val+3==i)
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
