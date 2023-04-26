#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int put(char* words,char(*dic)[20],int ori,int des,int n)
{  int j,k;
	for(j=des-1;j>ori;j--)
	{   int flag=0;
		char f[6000]={'\0'};
	    strncpy(f,words,j+1-ori);
		for(k=0;k<n;k++){
			if(!strcmp(dic[k],f)) flag=1;
			if(flag==1) {
				printf("%s ",f);
				return j+1;
			} 
		}
	}
	printf("%c ",words[0]);
	return j+1;
}
int main()
{  int n,i;
	 char dic[4002][20]={'\0'};
	 char words[6000]={'\0'};
	 char wor[20]={'\0'};
	 scanf("%d\n",&n);
	 for(i=0;i<n;i++) scanf("%s\n",dic[i]);
	 scanf("%s\n",words);
	 int j,t,l=strlen(words),len=l;
	 for(j=0;j<l&&len>0;)
	 {	t=j;
	 	j=put(&words[j],dic,j,l,n);
	 	len=len-j;
	 }
	 
	return 0;
}