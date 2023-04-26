#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		char str[101][101],c;
		int li=0;
		do{
			scanf("%s",str[li]);
			strlwr(str[li]);
			li++;
		}while((c=getchar())!='\n');
	
		int num=0,j=0,e,res=0;
		char stro[6][5]={"the","a","an","of","for","and"};
		for(j;j<li;j++)
		{
			for(e=0;e<6;e++){
				if(strcmp(str[j],stro[e])!=0) res++;
				else break;
			}
			if(res==6) num++;
			res=0;
		}
		printf("case #%d:\n",i);
		printf("%d\n",num);
		
	}
	return 0;
	
}