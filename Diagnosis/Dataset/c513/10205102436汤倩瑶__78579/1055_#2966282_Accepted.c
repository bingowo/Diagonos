#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[1000001];
    char ans[1000001]= {0};
    int max=0;
    scanf("%s",s);
    int l=strlen(s);
    int j,i;
    for(i=0;i<l;i++)
    {
        int a[128]= {0};
        j=i;
        a[s[j]]=1;
        j++;

        while(j<l)
        {

            if(a[s[j]]!=1)
            {
                a[s[j]]=1;
                j++;
            }
            else
            {

                break;
            }

        }
        if((j-i)>max)
        {
            max=j-i;
            int k;
            for(k=0; k<(j-i); k++)ans[k]=s[i+k];
            ans[k]='\0';
        }
    }

    printf("%s\n",ans);
}


