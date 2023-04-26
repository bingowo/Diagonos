#include <stdio.h>
#include <string.h>
int strcnp(char *a,char *b)
{
    for(int i=0;a[i]!='\0';i++) if(a[i]<='Z') a[i]=a[i]+'a'-'A';
    for(int i=0;b[i]!='\0';i++) if(b[i]<='Z') b[i]=b[i]+'a'-'A';
    return strcmp(a,b);
}
int main()
{
    char *S[6]={"the","an","a","of","and","for"};
    int cnt=0;
    scanf("%d",&cnt);
    for(int k=0;k<cnt;k++)
    {
        char s[101];
        char c=' ';
        int num=0;
        while(c!='\n')
        {
        	scanf("%s%c",s,&c);
            num++;
            for(int i=0;i<6;i++){
                if(strcnp(S[i],s)==0) num--;
            }
        }
        printf("case #%d:\n",k);
        printf("%d\n",num);
    }
    return 0;
}
