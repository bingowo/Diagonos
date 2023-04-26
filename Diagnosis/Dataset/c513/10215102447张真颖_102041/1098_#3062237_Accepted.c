#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int iswrong(char s[])
{
    for(int i=0;i<strlen(s);i++)
        if(s[i]=='!') return 1;
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        char s[101]={0};
        scanf("%s",s);

        int tb[90]={0};
        int arr[90]={0};
        while(iswrong(s)){
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='!')
            {
                if((i+3)<strlen(s)&&s[i+1]!='!'&&s[i+2]!='!'&&s[i+3]!='!')
                {
                    arr[s[i+1]]=1,arr[s[i+2]]=1,arr[s[i+3]]=1;
                    if(arr['R']==0) s[i]='R';
                    else if(arr['B']==0) s[i]='B';
                    else if(arr['Y']==0) s[i]='Y';
                    else if(arr['G']==0) s[i]='G';
                    arr[s[i+1]]=0,arr[s[i+2]]=0,arr[s[i+3]]=0;
                }
                else if((i+2)<strlen(s)&&i>0&&s[i+1]!='!'&&s[i+2]!='!'&&s[i-1]!='!')
                {
                    arr[s[i+1]]=1,arr[s[i+2]]=1,arr[s[i-1]]=1;
                    if(arr['R']==0) s[i]='R';
                    else if(arr['B']==0) s[i]='B';
                    else if(arr['Y']==0) s[i]='Y';
                    else if(arr['G']==0) s[i]='G';
                    arr[s[i+1]]=0,arr[s[i+2]]=0,arr[s[i-1]]=0;
                }
                else if((i+1)<strlen(s)&&i>1&&s[i+1]!='!'&&s[i-1]!='!'&&s[i-2]!='!')
                {
                    arr[s[i+1]]=1,arr[s[i-1]]=1,arr[s[i-2]]=1;
                    if(arr['R']==0) s[i]='R';
                    else if(arr['B']==0) s[i]='B';
                    else if(arr['Y']==0) s[i]='Y';
                    else if(arr['G']==0) s[i]='G';
                    arr[s[i+1]]=0,arr[s[i-1]]=0,arr[s[i-2]]=0;
                }
                else if(i>2&&s[i-1]!='!'&&s[i-2]!='!'&&s[i-3]!='!')
                {
                    arr[s[i-1]]=1,arr[s[i-2]]=1,arr[s[i-3]]=1;
                    if(arr['R']==0) s[i]='R';
                    else if(arr['B']==0) s[i]='B';
                    else if(arr['Y']==0) s[i]='Y';
                    else if(arr['G']==0) s[i]='G';
                    arr[s[i-1]]=0,arr[s[i-2]]=0,arr[s[i-3]]=0;
                }
                if(s[i]!='!') tb[s[i]]+=1;
            }
        }
        }
        printf("case #%d:\n%d %d %d %d\n",cas,tb['R'],tb['B'],tb['Y'],tb['G']);
    }
    return 0;
}