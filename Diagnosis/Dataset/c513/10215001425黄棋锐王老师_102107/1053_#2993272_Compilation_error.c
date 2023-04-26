#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int put(char* words,char(*dic)[20],int ori,int des,int n)
{  int j,k,fr,,fr1,t;
	for(k=0;k<n&&(dic[k][0]!=words[0]);k++);
	fr=k;
	fr1=fr;
	for(;k<n&&(dic[k][0]==words[0]);k++);
	t=k-1;
	for(j=des-1;j>ori;j--)
	{   int flag=0;
		char f[6000]={'\0'};
	    strncpy(f,words,j+1-ori);
		for(fr=fr1;fr<=t;fr++){
			if(!strcmp(dic[fr],f)) flag=1;
			if(flag==1) {
				printf("%s ",f);
				return j+1;
			} 
		}
	}
	printf("%c ",words[0]);
	return j+1;
}
int cmp(const void*a,const void*b)
{
	return (strcmp((char*)a,(char*)b));
}
int main()
{  int n,i;
	 char dic[4002][20]={'\0'};
	 char words[6000]={'\0'};
	 scanf("%d\n",&n);
	 for(i=0;i<n;i++) scanf("%s\n",dic[i]);
	 scanf("%s\n",words);
	 qsort(dic,n,sizeof(dic[0]),cmp);
	 int j,t,l=strlen(words),len=l;
	 for(j=0;j<l&&len>0;)
	 {	t=j;
	 	j=put(&words[j],dic,j,l,n);
	 	len-=j-t;
	 }
	 
	return 0;
}