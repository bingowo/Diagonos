#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	char *aa=(char*)a;
	char *bb=(char*)b;
	while(*aa&&*bb)
	{
		char x=(*aa)>='a'?*aa-32:*aa;
		char y=(*bb)>='a'?*bb-32:*bb;
		if(p[x-'A']!=p[y-'A'])
		{
			return p[x-'A']-p[y-'A'];
		}
		else
		{	
			aa++;bb++;
		}
	}
	if(*aa==0) return -1;
	else return 1;
}
int main()
{
	for(int q=0;q<100;q++){
		int p[26]; 
		char s[27]; 
		int k=0;
		while(scanf("%s\n",s)!=EOF)
		{    
			for(k=0; k<26; k++) {p[s[k]-'A']=k;} 
		}//字母表排序
		char str[2200];
	char a[100][21];
	gets(str);
	int count=0,j,i=0;
	while(1){
	j=0;
	while(str[i]!=' '&&str[i])  a[count][j++]=str[i++];
	a[count][j]='\0';
	count++;
	if(!str[i]) break;
	else i++;
	}
	
	qsort(a,count,sizeof(a[0]),cmp);//排序 
	
	for(i=0;i<count-1;i++){
		printf("%s ",a[i]);
	}
	printf("%s\n",a[count]-1);//输出 
 } 	
}
	
	