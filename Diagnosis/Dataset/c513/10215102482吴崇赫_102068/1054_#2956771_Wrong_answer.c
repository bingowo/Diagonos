#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 2005
#define M 75

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
    int length;
    scanf("%d\n",&length);

    char input[N]={0};char s[N]={0};
    gets(input);
    char word[N][M],ret[N][M];
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j)word[i][j]=ret[N][M]=0;
    }
    int wordnum=0,pj=0;

    for(int i=0,p=0;i<strlen(input);){
        if(input[i]!=' ')s[p++]=input[i++];
        else{
            while(input[i]==' ')i++;
            s[p++]=' ';
        }
    }
    for(int i=strlen(s)-1;s[i]==' ';--i)s[i]=0;

    for(int i=0;i<strlen(s);++i){
        if(s[i]==' '){wordnum++; pj=0;}
        else word[wordnum][pj++]=s[i];
    }
    //for(int i=0;i<=wordnum;++i)printf("%s\n",word[i]);


    int start[M],end[M];int pstr=0,pend=0;
    for(int i=0;i<M;++i)start[i]=end[i]=0;
    //printf("%d\n",wordnum);
    for(int pw=0;pw<=wordnum;){
        int cnt=0;
        int st=pw;
        while(cnt<length&&pw<=wordnum){
            cnt+=strlen(word[pw]);
            if(cnt>length){pw--; break;}
            if(cnt==length)break;
            cnt++;
            if(cnt==length)break;
            //printf("%d\n",cnt);
            pw++;
        }
        start[pstr++]=st;
        end[pend++]=pw++;
    }
    printf("case #%d:\n",x++);
    for(int i=0;i<pend-1;++i){
        int sum=0;
        for(int j=start[i];j<=end[i];++j)sum+=strlen(word[j]);
        int whitesum=length-sum; int _ws=whitesum;
        int space=end[i]-start[i];

        int first,other,f,o;
        f=first=_ws/space;
        if(space!=1)o=other=(_ws-first)/(space-1);
        else o=other=0;
        //printf("%d\n",first);


        strcat(ret[i],word[start[i]]);
        while(first--)strcat(ret[i]," ");
        for(int k=start[i]+1;k<end[i];++k){
            strcat(ret[i],word[k]);
            while(other--)strcat(ret[i]," ");
            other=(_ws-f)/(space-1);
        }
        strcat(ret[i],word[end[i]]);

        printf("%s\n",ret[i]);
    }
    for(int k=start[pend-1];k<=end[pend-1];++k){
        printf("%s%c",word[k],' ');
    }
    printf("\n");
    }
    return 0;
}
