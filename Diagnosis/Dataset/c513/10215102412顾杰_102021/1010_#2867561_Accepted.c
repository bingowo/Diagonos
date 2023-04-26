#include <stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
char* bi(int n,int k,char *p)
{
    int i;
    *(p+k)='\0';
    for(i=0;i<k;i++){*(p+k-1-i)='0'+(n&1);n>>=1;}
    return p;
}
int main() {
    int n,i,k;
    char s0[5001],ans[5000]="0001",*p,s[4],*ps=s0;
    s[3]='\0';
    p=(char*)malloc(110*sizeof(char));
    scanf("%s",s0);
    n=strlen(s0);
    strcat(ans,bi(n,10,p));
    k=(n-n%3)/3;
    for(i=0;i<k;i++)
    {
        strncpy(s,ps,3);
        ps+=3;
        strcat(ans,bi(atoi(s),10,p));
    }
    if(n%3){strncpy(s,ps,n%3);
    s[n%3]='\0';
    strcat(ans,bi(atoi(s),3*(n%3)+1,p));}
    printf("%s",ans);
    free(p);
    return 0;
}
