#include <stdio.h>
#include <string.h>
void search(char x[],char y[],int f)
{	
	for(f;f<strlen(x);f++)
	{
		int t=strlen(y);
		printf("%s%c\n",y,x[f]);
		if(strlen(y)==0 && f==strlen(x)-1) return; //递归终止条件
		if(f==strlen(x)-1)
		{
			int i;
			for(i=0;i<strlen(x);i++)
			{
				if(y[t-1]==x[i]) break;
			}
			y[t-1]='\0';
			search(x,y,i+1);
		}
		else y[t]=x[f];
	}
}


int main()
{
	int T,js=0;
	scanf("%d",&T);
	int n,j;
    char c;
	char S[20];
	while(T--)
	{
        scanf("%s",S);
	    int m=strlen(S);
	    int t;
	    for (n=0;n<=m-2;n++)
	    {
           	for (j=0;j<=m-n-2;j++)
          	{
       			if (S[j+1]<=S[j])
       	    	{
       	 			t=S[j];
       	 	  		S[j]=S[j+1];
       	 	  		S[j+1]=t;
       	    	}
         	}
	    }
	   	char x[20]={'\0'};
	   	int z=0;
       	for (n=0;n<=m-1;n++)
       	{
       	 	if (S[n]!=S[n+1]) x[n-z]=S[n];
       	 	else z=z+1;
       	}

		//输出
		printf("case #%d:\n",js);
		char y[20]={'\0'};
		search(x,y,0);
		js++;
	}
	return 0;
}