#include<stdio.h>
#include<string.h>


int main()
{
    char s1[101],s2[101];
    int a1[101],a2[101],a3[101];
    while (scanf("%s%s",s1,s2)!=EOF)
    {
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        memset(a3,0,sizeof(a3));

        int n=0,x=0;
        int point=1;
        for (int i=0; i<=strlen(s1); i++)
        {
            if (s1[i]=='-') point=-1;
            else if (s1[i]=='+') point=1;
            else if (s1[i]>='0'&&s1[i]<='9') x=x*10+s1[i]-'0';
            else if (s1[i]=='x')
            {
                if (x==0)x=1;
                x=x*point;
                if(s1[i+1]=='^') {
                    i=i+2;
                    while (s1[i]>='0'&&s1[i]<='9') {n=n*10+s1[i]-'0';i++;}
                    a1[n]=x;
                    i=i-1;
                }
                else {
                    a1[1]=x;
                }
                point=1;
                x=0;
                n=0;
            }
            else if (s1[i]=='\0'&&x!=0) a1[0]=x*point;

        }



        n=0,x=0;
        point=1;
        for (int i=0; i<=strlen(s2); i++)
        {
            if (s2[i]=='-') point=-1;
            else if (s2[i]=='+') point=1;
            else if (s2[i]>='0'&&s2[i]<='9') x=x*10+s2[i]-'0';
            else if (s2[i]=='x')
            {
                if (x==0)x=1;
                x=x*point;
                if(s2[i+1]=='^') {
                    i=i+2;
                    while (s2[i]>='0'&&s2[i]<='9') {n=n*10+s2[i]-'0';i++;}
                    a2[n]=x;
                    i=i-1;
                }
                else {
                    a2[1]=x;
                }
                point=1;
                x=0;
                n=0;
            }
            else if (s2[i]=='\0'&&x!=0) a2[0]=x*point;

        }
        
        for (int i=0;i<50;i++)
            for (int j=0;j<50;j++)
            a3[i+j]+=a1[i]*a2[j];
        int find=0;
        for (int i=98;i>=0;i--)
            if (a3[i]!=0)
        if (find==0){printf("%d",a3[i]);find++;}
        else printf(" %d",a3[i]);
        printf("\n");
    }
    return 0;
}
