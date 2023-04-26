#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);

    char s[105];
    for(int i=0;i<T;i++)
    {char ans[5];
    int a[128]={0};
        scanf("%s",s);
        int l=strlen(s);

        for(int j=0;j<(l/4);j++){
            if(s[j*4]!='!')ans[0]=s[j*4];
            if(s[j*4+1]!='!')ans[1]=s[j*4+1];
            if(s[j*4+2]!='!')ans[2]=s[j*4+2];
            if(s[j*4+3]!='!')ans[3]=s[j*4+3];
        }
        for(int j=(l/4)*4;j<l;j++)
        {
            if((j%4)==0)ans[0]=s[j];
            if((j%4)==1)ans[1]=s[j];
            if((j%4)==2)ans[2]=s[j];

        }
        ans[4]='\0';

        for(int j=0;j<l;j++){
            if(s[j]=='!'){
               if((j%4)==0)a[ans[0]]++;
            if((j%4)==1)a[ans[1]]++;
            if((j%4)==2)a[ans[2]]++;
            if((j%4)==3)a[ans[3]]++;
            }
        }



        printf("case #%d:\n%d %d %d %d\n",i,a['R'],a['B'],a['Y'],a['G']);


    }
}
