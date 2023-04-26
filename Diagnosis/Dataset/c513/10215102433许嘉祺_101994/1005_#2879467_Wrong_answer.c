#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int t,p;
    scanf("%d",&t);
    char r[]="000125250375500625750875";
    int s1[151],s2[151];
    double b=0.0;
    char s[51];
    for(int i=0; i<t; i++)
    {   memset(s1,0,sizeof(s1));
        scanf("%s",s);
        int n=0;
        while (s[n]!='.') n++;
        n=n+1;
        for (int j=strlen(s)-1; j>=n; j--)
        {

            memset(s2,0,sizeof(s2));
            for(int k=0; k<=147; k++)
            {
                if (s1[k]<8)
                {
                    s2[k+1]=s2[k+1]+r[s1[k]*3]-'0';
                    s2[k+2]=s2[k+2]+r[s1[k]*3+1]-'0';
                    s2[k+3]=s2[k+3]+r[s1[k]*3+2]-'0';
                }
                else
                {
                    s2[k]=s2[k]+s1[k]/8;
                    s1[k]=s1[k]%8;
                    s2[k+1]=s2[k+1]+r[s1[k]*3]-'0';
                    s2[k+2]=s2[k+2]+r[s1[k]*3+1]-'0';
                    s2[k+3]=s2[k+3]+r[s1[k]*3+2]-'0';
                }

            }
            s2[0]=s2[0]+r[(s[j]-'0')*3]-'0';
            s2[1]=s2[1]+r[(s[j]-'0')*3+1]-'0';
            s2[2]=s2[2]+r[(s[j]-'0')*3+2]-'0';
            for(int k=147; k>=1; k--)
            {

                s1[k]=s2[k]%10;
                s2[k-1]=s2[k]/10+s2[k-1];


            }
            s1[0]=s2[0];
        }
        printf("0.");
        for ( p=150; p>=0; p--)
            if(s1[p]!=0) break;
        for (int k=0; k<=p; k++) printf("%d",s1[k]);
        printf("\n");
    }
    return 0;
}
