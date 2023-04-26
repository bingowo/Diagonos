#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
typedef struct{
	char str[16];
	int len;
}qwq;
int find_str(char* str1,char* str2,int n)
{
    int i,j,flag=-1;
    for(i=n,j=0;str1[i];i++)
    {	//printf("i %d\n",i);
    	int k=0;
        while(str1[i+k]==str2[j]&&str1[i+k]&&str2[j])
        {
            k++;
            j++;
            if(j>=strlen(str2))
            {
                flag=i+k-j;
                return flag;
            }
        }
        j=0;
    }
    return flag;
}

int main()
{
	int n;
	scanf("%d",&n);
	qwq*p=(qwq*)malloc(n*sizeof(qwq));
	for(int i=0;i<n;i++) 
	{
		scanf("%s",p[i].str);
		p[i].len=strlen(p[i].str);
		//printf("%s %d\n",p[i].str,p[i].len);
	}
	//int l_max=0;
	//for(int i=0;i<n;i++) if(l_max<p[i].len) l_max=p[i].len;
	char exa[5050];
	scanf("%s",exa);
	int j=n-1;int i=0;
	while(i<strlen(exa))
	{
		for(j=n-1;j>=0;j--)
		{
			int flag=find_str(exa,p[j].str,i);//printf("\np:%s\n",p[j].str);
			if(flag!=i) continue;
			else 
			{
				printf("%s",p[j].str);i+=p[j].len;
				if(i<strlen(exa)) printf(" ");
				else printf("\n");
				break;
			}
		}
		if(j<0) {
		printf("%c",exa[i++]);
		if(i<strlen(exa)) printf(" ");
		else printf("\n");
	}
	}
	
	
	free(p);
	return 0;
}