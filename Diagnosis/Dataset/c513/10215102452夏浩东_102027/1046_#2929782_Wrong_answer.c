#include <stdio.h>
#include <string.h>
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
                if(strcmp(S[i],s)==0) num--;
            }
        }
        printf("case #%d:\n",k);
        printf("%d\n",num);
    }
    return 0;
}
