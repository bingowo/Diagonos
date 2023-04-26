#include<stdio.h>
#include<string.h>

int main()
{
    int T;
    char ans[105];
    char ans1[105];
    scanf("%d",&T);
    char s[105];

    for(int i=0; i<T; i++)
    {int max=0;
        scanf("%s",s);
        int l=strlen(s);
        int cnt1=0;
        int a[105]= {0};
        for(int j=0; j<l; j++)
        {
            if(s[j]!=s[j+1])a[cnt1++]=j;
        }
        for(int j=0; j<cnt1; j++)
        {
       //     printf("%d ",a[j]);
            char s1[105];
            int cnt=0;
            for(int k=0; k<=a[j]; k++)
            {
                s1[cnt++]=s[k];
            }

            for(int k=a[j]; k<l; k++)
            {
                s1[cnt++]=s[k];
            }
            s1[cnt]='\0';

  //          printf("%s\n",s1);

            strcpy(ans,s1);

           while(1){

            int cnt1=1;
            int a[105]= {0};
            a[0]=-1;

            for(int k=0;ans[k]; k++)
            {
                if(ans[k]!=ans[k+1])a[cnt1++]=k;
            }
            for(int k=0; k<cnt1-1; k++)
            {
              //  printf("%d ",a[i]);
              if((a[k]+1)!=a[k+1])
               {
                   for(int p=a[k]+1; p<=a[k+1]; p++)
                {
                    ans[p]='1';
                }
               }
            }

            int cnt2=0;
            for(int k=0;ans[k];k++)
            {
                if(ans[k]!='1')ans1[cnt2++]=ans[k];
            }
            ans1[cnt2]='\0';

           int flag=1;
            for(int k=0;k<cnt2;k++)
            {
                if(ans1[k]==ans1[k+1]){flag=0;break;}
            }
            if(flag==0){strcpy(ans,ans1);}
            else break;




           }
if((strlen(s)-strlen(ans1))>max)max=strlen(s)-strlen(ans1);
//printf("%s\n",ans1);
        }


        printf("case #%d:\n%d\n",i,max+1);
    }
}
