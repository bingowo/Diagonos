#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int maxlen=0,num=0;
void func(char *s,int cn,char **L)
{
    if(cn==(int)strlen(s)) return;
    for(int j=maxlen; j>=1;j--)
    {
    	if(j==1) { printf("%c ",s[cn]);func(s,cn+1,L);return;}
    	else
		{
			char c[15]={'\0'};
	        for(int i=cn;i<(j+cn);i++) c[i-cn]=s[i];
	        for(int k=0;k<num;k++)
	        {
	            if(strcmp(L[k],c)==0)
	            {
	                printf("%s ",c);
	                func(s,cn+j,L);
	                return;
	            }
			}
		}
    	
    }
}
int main()
{
    scanf("%d",&num);
    char **L=(char**)malloc(num*sizeof(char*));
    for(int i=0;i<num;i++) {char* S=(char*)malloc(15*sizeof(char));scanf("%s",S);L[i]=S;}
    for(int i=0;i<num;i++) if((int)strlen(L[i])>maxlen) maxlen=(int)strlen(L[i]);
    char s[5001]={'\0'};
    scanf("%s",s);
    func(s,0,L);
    for(int i=0;i<num;i++) free(L[i]);
    free(L);
    return 0;
}