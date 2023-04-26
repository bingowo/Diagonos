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
			li++;
		}while((c=getchar())!='\n');
	
		int num=0,j=0,e,res=0;
		char stro[16][14]={"the","a","an","of","for","and","THE","A","AN","OF","FOR","AND","anD","An","For","The"};
		for(j;j<li;j++)
		{
			for(e=0;e<16;e++){
				if(strcmp(str[j],stro[e])!=0) res++;
				else break;
			}
			if(res==16) num++;
			res=0;
		}
		printf("case #%d:\n",i);
		printf("%d\n",num);
		
	}
	return 0;
	
}