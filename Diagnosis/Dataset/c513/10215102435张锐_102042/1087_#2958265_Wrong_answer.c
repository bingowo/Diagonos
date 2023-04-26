#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add(int *ans)
{
    int last=1;
    for(int i=999;i>=0;i--)
    {
        int temp=ans[i]+last;
        if(temp>9) ans[i]=temp-10,last=1;
        else ans[i]=temp,last=0;
    }
}
int yes(int *ans)
{
    int p;int b=1;
    for(p=0;p<1000;p++) {if(ans[p]!=0) break;}
    for(int i=p;i<999;i++)
    {
        if(ans[i]==ans[i+1]) {b=0;break;}
    }
    return b;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[1000];int bo=1;
        scanf("%s",s);
        int ans[1000]={0};int len=strlen(s);int jj=999;
        for(int j=len-1;j>=0;j--) ans[jj--]=s[j]-'0';
        if(yes(ans)==0) bo=0;
        bo=1;
        if(yes(ans)==0) bo=0;
        if(bo==0)
        {
            int h,p;
            for(p=0;p<1000;p++) {if(ans[p]!=0) break;}
            for(int ii=p;ii<999;ii++)
            {
                if(ans[ii]==ans[ii+1]) {h=ii;break;}
            }
            if(ans[h+1]==0)
            {
                for(int ii=h+1;ii<1000;ii++)
                {
                    if((ii-h-1)%2==0) ans[ii]=1;
                    else ans[ii]=0;
                }
            }
            else if(ans[h+1]==9)
            {
                int ii;
                for(ii=h;ii>jj;ii--)
                {
                    if(ans[ii]<9) {ans[ii]++;break;}
                }
                if(ii==jj)
                {
                    for(int kk=jj;kk<1000;kk++)
                    {
                        if((kk-jj)%2==0) ans[kk]=1;
                        else ans[kk]=0;
                    }
                }
                else
                {
                    for(int kk=ii+1;kk<1000;kk++)
                    {
                        if((kk-ii-1)%2==0) ans[kk]=0;
                        else ans[kk]=1;
                    }
                }
            }
            else
            {
                ans[h+1]=ans[h+1]+1;
                for(int ii=h+2;ii<1000;ii++)
                {
                    if((ii-h-2)%2==0) ans[ii]=0;
                    else ans[ii]=1;
                }
            }
        }
        if(bo==1)
        {
            int d=-1;
            for(int f=jj-1;f<999;f++)
            {
                if(ans[f]==8&&ans[f+1]==9) {if(d==-1) d=f;}
                else if(ans[f]==9&&ans[f+1]==8) {if(d==-1) d=f;}
                else if(d!=-1&&((ans[f]==8&&ans[f+1]!=9)||(ans[f]==9&&ans[f+1]!=8))) break;
                if(f==998&&d!=-1) bo=0;
                if(bo==0)
                {
                    if(ans[d]==9)
                    {
                        int ii;
                        for(ii=d-1;ii>jj;ii--)
                        {
                            if(ans[ii]<9) {ans[ii]++;break;}
                        }
                        if(ii==jj)
                        {
                            for(int kk=jj;kk<1000;kk++)
                            {
                                if((kk-jj)%2==0) ans[kk]=1;
                                else ans[kk]=0;
                            }
                        }
                        else
                        {
                            for(int kk=ii+1;kk<1000;kk++)
                            {
                                if((kk-ii-1)%2==0) ans[kk]=0;
                                else ans[kk]=1;
                            }
                        }
                    }
                    if(ans[d]==8)
                    {
                        ans[d]=9;
                        for(int kk=d+1;kk<1000;kk++)
                        {
                            if((kk-d-1)%2==0) ans[kk]=0;
                            else ans[kk]=1;
                        }
                    }
                }
            }
            bo=1;
            if(yes(ans)==0) bo=0;
            if(bo==0)
            {
                int h,p;
                for(p=0;p<1000;p++) {if(ans[p]!=0) break;}
                for(int ii=p;ii<999;ii++)
                {
                    if(ans[ii]==ans[ii+1]) {h=ii;break;}
                }
                if(ans[h+1]==0)
                {
                    for(int ii=h+1;ii<1000;ii++)
                    {
                        if((ii-h-1)%2==0) ans[ii]=1;
                        else ans[ii]=0;
                    }
                }
                else if(ans[h+1]==9)
                {
                    int ii;
                    for(ii=h;ii>jj;ii--)
                    {
                        if(ans[ii]<9) {ans[ii]++;break;}
                    }
                    if(ii==jj)
                    {
                        for(int kk=jj;kk<1000;kk++)
                        {
                            if((kk-jj)%2==0) ans[kk]=1;
                            else ans[kk]=0;
                        }
                    }
                    else
                    {
                        for(int kk=ii+1;kk<1000;kk++)
                        {
                            if((kk-ii-1)%2==0) ans[kk]=0;
                            else ans[kk]=1;
                        }
                    }
                }
                else
                {
                    ans[h+1]=ans[h+1]+1;
                    for(int ii=h+2;ii<1000;ii++)
                    {
                        if((ii-h-2)%2==0) ans[ii]=0;
                        else ans[ii]=1;
                    }
                }
            }
        }
        while(bo==1)
        {
            add(ans);
            if(yes(ans)==1) break;
        }
        int p;
        for(p=0;p<1000;p++) {if(ans[p]!=0) break;}
        printf("case #%d:\n",i);
        for(int k=p;k<1000;k++) printf("%d",ans[k]);
        printf("\n");
    }
    return 0;
}
