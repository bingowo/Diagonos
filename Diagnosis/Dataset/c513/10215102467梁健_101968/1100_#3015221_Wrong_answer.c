#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char s[120];scanf("%s",s);
    int len=strlen(s);
    long long D[len][2];
    int x=0,y=0;
    for(int i=0;i<len;i++){
        if(s[i]=='U')y++;
        else if(s[i]=='D')y--;
        else if(s[i]=='L')x--;
        else if(s[i]=='R')x++;
        D[i][0]=x;
        D[i][1]=y;
    }
    long long T,a,b;scanf("%lld",&T);

    int fx,fy=0;
    if(x>0)fx=1;
    else if(x<0)fx=-1;
    if(y>0)fy=1;
    else if(y<0)fy=-1;

    for(int t=0;t<T;t++){
        scanf("%lld %lld",&a,&b);
        if(a==0&&b==0)printf("Yes\n");
        else{
            int flag=0;
            for(int i=0;i<len;i++){
                long long da=a-D[i][0],db=b-D[i][1];
                if(da==0&&db==0){
                    flag=1;break;
                }
                int fa=0,fb=0;
                if(da>0)fa=1;
                else if(da<0)fa=-1;
                if(db>0)fb=1;
                else if(db<0)fb=-1;
                if(x!=0&&y==0){
                    if(fa==fx&&fa!=0)
                        if(da%x==0&&db==0)flag=1;
                }
                else if(x==0&&y!=0){
                    if(fb==fy&&fb!=0)
                        if(da==0&&db%y==0)flag=1;
                }
                else if(x&&y){
                    if(fa==fx&&fb==fy&&fa!=0&&fb!=0){
                        long long ta=1,tb=-1;
                        if(da%x==0&&fa==fx&&fa!=0)ta=da/x;
                        if(db%y==0&&fb==fy&&fb!=0)tb=db/y;
                        if(ta==tb){
                            flag=1;
                            //printf("ta=%d tb=%d\n",ta,tb);
                        }
                    }
                }
            }
            if(flag==1)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

