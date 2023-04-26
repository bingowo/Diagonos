#include<stdio.h>
#include<string.h>
int main()
{
    char s1[105],s2[105];
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        int c[105]={0};
        int a[50]= {0};
        int flag=1;
        int sum=0;
        int l=strlen(s1);
        int i=0;
        int j;
        while(i<=l)
        {
            if(s1[i]>='0'&&s1[i]<='9')
            {
                sum=sum*10+s1[i]-'0';
                i++;
            }
            if(i==l)
            {
                a[0]=flag*sum;
                i++;
                //flag=1;sum=0;
            }
            if(s1[i]=='x')
            {

                if((i<l-1)&&s1[i+1]=='^')
                {


                    int tmp=0;
                    for(j=i+2; (s1[j]!='-')&&(s1[j]!='+')&&(j!=l); j++)
                    {
                        tmp=tmp*10+s1[j]-'0';
                    }
                    if(i==0)a[tmp]=1;
                     else if(i>0&&s1[i-1]=='-')a[tmp]=-1;
                    else if(i>0&&s1[i-1]=='+')a[tmp]=1;
                    else a[tmp]=flag*sum;
                    i=j;
                    if(j==l)i=l+1;

                }
                else
                {
                    if(i==0)a[1]=1;

                    else if(i>0&&s1[i-1]=='-')a[1]=-1;
                    else if(i>0&&s1[i-1]=='+')a[1]=1;
                    else
                        a[1]=flag*sum;

                    i++;
                }
                flag=1;
                sum=0;
            }
            if(s1[i]=='+')
            {
                flag=1;
                sum=0;
                i++;
            }
            if(s1[i]=='-')
            {
                flag=-1;
                sum=0;
                i++;
            }


        }

     /*   for(int i=0; i<50; i++)
        {
            printf("%d ",a[i]);

        }*/


        int b[50]= {0};
        flag=1;
        sum=0;
        l=strlen(s2);
        i=0;
        while(i<=l)
        {
            if(s2[i]>='0'&&s2[i]<='9')
            {
                sum=sum*10+s2[i]-'0';
                i++;
            }
            if(i==l)
            {
                b[0]=flag*sum;
                i++;
                //flag=1;sum=0;
            }
            if(s2[i]=='x')
            {

                if((i<l-1)&&s2[i+1]=='^')
                {


                    int tmp=0;
                    for(j=i+2; (s2[j]!='-')&&(s2[j]!='+')&&(j!=l); j++)
                    {
                        tmp=tmp*10+s2[j]-'0';
                    }
                    if(i==0)b[tmp]=1;
                      else if(i>0&&s2[i-1]=='-')b[tmp]=-1;
                    else if(i>0&&s2[i-1]=='+')b[tmp]=1;
                    else b[tmp]=flag*sum;
                    i=j;
                    if(j==l)i=l+1;

                }
                else
                {
                    if(i==0)b[1]=1;

                    else if(i>0&&s2[i-1]=='-')b[1]=-1;
                    else if(i>0&&s2[i-1]=='+')b[1]=1;
                    else //if(i>0&&i<l-1&&s1[i+1]!='^')
                        b[1]=flag*sum;

                    i++;
                }
                flag=1;
                sum=0;
            }
            if(s2[i]=='+')
            {
                flag=1;
                sum=0;
                i++;
            }
            if(s2[i]=='-')
            {
                flag=-1;
                sum=0;
                i++;
            }


        }
/*printf("\n");
        for(int i=0; i<50; i++)
        {
            printf("%d ",b[i]);

        }
        printf("\n");*/
        for(int k=0;k<50;k++)
        {
            for(int t=0;t<50;t++)
            {
                c[k+t]+=a[k]*b[t];
            }
        }
        for(int k=100;k>=0;k--)
        {
            if(c[k]!=0)printf("%d ",c[k]);

        }
        printf("\n");

    }


return 0;
}



