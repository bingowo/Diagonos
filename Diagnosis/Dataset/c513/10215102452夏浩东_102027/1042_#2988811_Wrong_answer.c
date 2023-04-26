#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char L[1<<16][16];
char NL[1<<16][17];
int cmp(const void *a, const void *b)
{
    char *A = (char*)a;
    char *B = (char*)b;
    char L1[16],L2[16];
    int i=0,j=0,k=0;
    while(A[k]!='\0'){
    	if(A[k]!=' ') L1[i++]=A[k];
    	k++;
	}
	L1[i]='\0';
	k=0;
	while(B[k]!='\0'){
    	if(B[k]!=' ') L2[j++]=B[k];
    	k++;
	}
	L2[j]='\0';
	return strcmp(L1,L2);
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int q=0;q<cnt;q++)
    {
        char s[17];
        scanf("%s",s);
        int k=0,len=(int)strlen(s);
        for(int i=0;i<len;i++) L[k][i]='1';
        while((k+2)<(1<<len))
        {
            for(int i=0;i<len;i++) L[k+1][i]=L[k][i];
            k++;
        	if(L[k][len-1]=='1') L[k][len-1]='0';
		    else{L[k][len-1]='1';L[k][len-2]=L[k][len-2]-1;}
		    for(int i=len-2;L[k][i]==('0'-1);i--)
		    {
		        L[k][i]='1';
		        L[k][i-1]=L[k][i-1]-1;
		    }
        }
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<len;j++)
            {
                if(L[i][j]=='1') NL[i][j]=s[j];
                else NL[i][j]=' ';
            }
        }
        qsort(NL,k+1,sizeof(NL[0]),cmp);
        printf("case #%d:\n",q);
        for(int i=0;i<=k;i++) 
        {
        	for(int j=0;j<len;j++)
            {
                if(NL[i][j]!=' ') printf("%c",NL[i][j]);
            }
            printf("\n");
		}
    }
    return 0;
}