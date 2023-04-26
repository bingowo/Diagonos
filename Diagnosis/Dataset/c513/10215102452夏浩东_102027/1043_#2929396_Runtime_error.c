#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* Remove(char *L,int num)
{
    char NL[101]={"\0"};
    int k=0;
    if(L[0]!=L[1]){NL[0]=L[0];k++;}
    for(int i=1;i<num-1;i++) if(L[i]!=L[i-1] && L[i]!=L[i+1]){NL[k]=L[i];k++;}
	if(L[num-1]!=L[num-2]) NL[k]=L[num-1];
	char *p = NL;
	int flag=0;
	for(int y=0;NL[y]!='\0';y++) if(NL[y]==NL[y+1]){ flag=1; break;}
	if(flag==1) p=Remove(NL,(int)strlen(NL));
	//for(int i=0;NL[i]!='\0';i++) printf("%c ",NL[i]);
	//printf("\n"); 
    return p;
}
int main()
{
    int num=0;
    scanf("%d",&num);
    for(int cnt=0;cnt<num;cnt++)
    {
        char s[101];
        int lastlen=100;
        int sns=0;
        scanf("%s",s);
        char *ns =Remove(s,strlen(s));
        for(int i=0;ns[i]!='\0';i++) sns=i+1;
        for(int k=0;k<sns;k++)
        {
            char *nl=(char*)malloc((sns+2)*sizeof(char));
            for(int i=0;i<sns;i++)
            {
                if(i==k){nl[i]=ns[i];nl[i+1]=ns[i];}
                else if(i<k) nl[i]=ns[i];
                else nl[i+1]=ns[i];
        	}
        	nl[sns+1]='\0';
            char *p=Remove(nl,sns+1);
            for(int i=0;p[i]!='\0';i++) printf("%c ",p[i]);
            printf("\n");
            int len=0;
            for(int i=0;p[i]!='\0';i++) len=i+1;
            lastlen= lastlen>len ? len:lastlen;
            free(nl);
        }
        if(lastlen==100) lastlen=0;
        printf("case #%d:\n",cnt);
        printf("%d %d\n",lastlen,strlen(s));
    }
    return 0;
}