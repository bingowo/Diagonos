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
    char s0[501],ans[2000]="0001",*p,s[4],*ps=s0;
    s[3]='\0';
    p=(char*)malloc(11*sizeof(char));
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
    strcpy(s,ps);
    n=strlen(s);
    strcat(ans,bi(atoi(s),3*n+1,p));
    printf("%s",ans);
    free(p);
    return 0;
}
