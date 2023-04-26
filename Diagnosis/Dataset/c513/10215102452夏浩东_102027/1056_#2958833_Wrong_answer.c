#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int maxlen=0,num=0;
void func(char *s,int cn,char **L)
{
    if(cn==(int)strlen(s)) return;
    for(int j=maxlen; j>=1;j--)
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
int main()
{
    scanf("%d",&num);
    char **L=(char**)malloc((num+26)*sizeof(char*));
    for(int i=0;i<num;i++) {char* S=(char*)malloc(15*sizeof(char));scanf("%s",S);L[i]=S;}
    for(int i=num;i<num+26;i++)
    {
        char*NS=(char*)malloc(2*sizeof(char));
        NS[0]=(char)(i-num+'a');NS[1]='\0';
        L[i]=NS;
    }
    for(int i=0;i<num+26;i++) if((int)strlen(L[i])>maxlen) maxlen=(int)strlen(L[i]);
    char s[5001]={'\0'};
    scanf("%s",s);
    func(s,0,L);
    for(int i=0;i<num+26;i++) free(L[i]);
    free(L);
    return 0;
}