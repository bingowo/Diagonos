#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);

    char s[105];
    for(int i=0; i<T; i++)
    {
        char ans[5];
        int a[128]= {0};
        int f[128]= {0};
        scanf("%s",s);
        int l=strlen(s);


        for(int j=0; j<l; j++)
        {
            if(s[j]!='!')
            {
                if((j%4)==0)
                {
                    ans[0]=s[j];
                    f[0]=1;
                }
                if((j%4)==1)
                {
                    ans[1]=s[j];
                    f[1]=1;
                }
                if((j%4)==2)
                {
                    ans[2]=s[j];
                    f[2]=1;
                }
                if((j%4)==3)
                {
                    ans[3]=s[j];
                    f[3]=1;
                }
                f[s[j]]=1;
            }
        }
        int k;
        for(k=0; k<4; k++)
        {
            if(f[k]==0)break;
        }
        if(f['R']==0)
            ans[k]='R';
        if(f['G']==0)
            ans[k]='G';
        if(f['Y']==0)
            ans[k]='Y';
        if(f['B']==0)
            ans[k]='B';
        ans[4]='\0';
//printf("%s\n",ans);
        for(int j=0; j<l; j++)
        {
            if(s[j]=='!')
            {
                if((j%4)==0)a[ans[0]]++;
                if((j%4)==1)a[ans[1]]++;
                if((j%4)==2)a[ans[2]]++;
                if((j%4)==3)a[ans[3]]++;
            }
        }



        printf("case #%d:\n%d %d %d %d\n",i,a['R'],a['B'],a['Y'],a['G']);


    }
}
