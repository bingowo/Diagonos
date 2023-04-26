#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char c;
        char s[100][100];
        int j=0;
        int k=0;
        while((c=getchar())!='\n')
        {
            if(c==' ')
            {
                scanf("%s",s[k]);
                k++;
            }
            else
            {
                s[0][j]=c;
                j++;
                k=1;
            }
        }
        int ans=0;
        for(int p=0;p<k;p++)
        {
            for(int q=0;q<strlen(s[p]);q++)
            {
                if(s[p][q]>='A'&&s[p][q]<='Z') s[p][q]=s[p][q]+32;
            }
        }
        for(int p=0;p<k;p++)
        {
            if((strcmp(s[p],"a")==0)||(strcmp(s[p],"an")==0)||(strcmp(s[p],"of")==0)||(strcmp(s[p],"the")==0)||(strcmp(s[p],"for")==0)||(strcmp(s[p],"and")==0) ) continue;
            else ans++;
        }

        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
}
