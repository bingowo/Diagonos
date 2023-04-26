#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int a[5][5]={{0,32,20,30},{32,321,321,321},{20,321,20,3210},{30,321,3210,30}};
    char s1[3],s2[3],s3[3];
    scanf("%s %s %s",s1,s2,s3);
    char table[]="OXBA";
    int x,y;int ans[5];
    if(strcmp(s3,"?")==0)
    {
        if(strcmp(s1,"AB")==0) x=1;
        else if(s1[0]=='A') x=3;
        else if(s1[0]=='B') x=2;
        else if(s1[0]=='O') x=0;
        if(strcmp(s2,"AB")==0) y=1;
        else if(s2[0]=='A') y=3;
        else if(s2[0]=='B') y=2;
        else if(s2[0]=='O') y=0;
        int num=a[x][y];
        printf("%s %s ",s1,s2);
        if(num>0)
        {
            printf("{");int k=0;
            while(num>0)
            {
                ans[k]=num%10;
                num/=10;k++;
            }
            for(int i=k-1;i>0;i--)
            {
                char c=table[ans[i]];
                if(c=='X') printf("AB,");
                else printf("%c,",c);
            }
            if(table[ans[0]]=='X') printf("AB}");
            else printf("%c}",table[ans[0]]);

        }
        else
        {
            printf("{%c}",table[num]);
        }
    }
    else
    {
        char pp[10];int k=0;
        if(strcmp(s3,"AB")==0) x=1;
        else if(s3[0]=='A') x=3;
        else if(s3[0]=='B') x=2;
        else if(s3[0]=='O') x=0;
        if(strcmp(s1,"?")==0)
        {
            if(strcmp(s2,"AB")==0) y=1;
            else if(s2[0]=='A') y=3;
            else if(s2[0]=='B') y=2;
            else if(s2[0]=='O') y=0;
            for(int i=3;i>=0;i--)
            {
                int num=a[y][i];
                do
                {
                    int ff=num%10;num/=10;
                    if(ff==x)
                    {
                        pp[k]=table[i];k++;break;
                    }
                }while(num>0);
            }
            if(k==0) printf("impossible ");
            else
            {
                printf("{");
                for(int i=0;i<k-1;i++)
                {
                   if(pp[i]=='X') printf("AB,");
                   else printf("%c,",pp[i]);
                }
                if(pp[k-1]=='X') printf("AB} ");
                else printf("%c} ",pp[k-1]);
            }
            printf("%s %s",s2,s3);
        }
        else
        {
            printf("%s ",s1);
            if(strcmp(s1,"AB")==0) y=1;
            else if(s1[0]=='A') y=3;
            else if(s1[0]=='B') y=2;
            else if(s1[0]=='O') y=0;
            for(int i=3;i>=0;i--)
            {
                int num=a[i][y];
                do
                {
                    int ff=num%10;num/=10;
                    if(ff==x)
                    {
                        pp[k]=table[i];k++;break;
                    }
                }while(num>0);
            }
            if(k==0) printf("impossible ");
            else
            {
                printf("{");
                for(int i=0;i<k-1;i++)
                {
                   if(pp[i]=='X') printf("AB,");
                   else printf("%c,",pp[i]);
                }
                if(pp[k-1]=='X') printf("AB} ");
                else printf("%c} ",pp[k-1]);
            }
            printf("%s",s3);
        }
    }
    return 0;
}
