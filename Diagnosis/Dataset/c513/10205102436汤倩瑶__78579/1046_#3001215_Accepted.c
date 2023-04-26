#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);

    char s[105];
    gets(s);
    char s1[30];
    char s2[30];
    int cnt=0;
    char p[][20]={"the","a","an","of","for","and"};
    for(int i=0;i<T;i++)
    {
        int ans=0;
        gets(s);
        int l=strlen(s);
        for(int j=0;j<=l;j++)
        {

            if(s[j]==' '||j==l){
                s1[cnt]='\0';
                s2[cnt]='\0';
                //printf("%s %s\n",s1,s2);

                int flag=1;
                for(int k=0;k<6;k++)
                {
                    if(strcmp(s2,p[k])==0){flag=0;break;}

                }
                if(flag)ans++;


                cnt=0;
            }
            else {
                s1[cnt]=s[j];
                if(s[j]>='A'&&s[j]<='Z')s2[cnt]=s[j]-'A'+'a';
                else s2[cnt]=s[j];
                cnt++;
            }

        }


        printf("case #%d:\n%d\n",i,ans);


    }



}
