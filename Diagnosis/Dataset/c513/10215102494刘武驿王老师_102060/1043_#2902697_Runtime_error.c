#include<string.h>
int main()
{
    int n,x,j;
    scanf("%d",&n);
    char m=getchar();
    for(int i=0;i<n;i++)
    {
        char s[200];
        scanf("%s",s);
        char tmp[200];
        j=0;
        int t;
        int test=1;
        while(test==1)
        {
            int cmp=0;
            j=0;
            for(x=0;x<strlen(s)-1;x++)
            {
                if(s[x]!=s[x+1]) tmp[j++]=s[x];
                else cmp=1;
            }
            if(s[x]!=s[x-1])
            {
                tmp[j]=s[x];
                tmp[j+1]='\0';
            }
            tmp[j]='\0';
            if(cmp==0) break;
            for(t=0;t<strlen(tmp);t++) s[t]=tmp[t];
            s[t]='\0';
        }
        printf("case #%d:\n%s\n",i,tmp);
    }
}
