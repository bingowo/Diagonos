#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    int a1=*(int*)a,b1=*(int*)b;
    return a1>b1?1:-1;
}
int main()
{
    int n,s;scanf("%d %d",&n,&s);
    int res=0,deno=n;
    int H[n];int judge[n];
    for(int i=0;i<n;i++)judge[i]=0;
    for(int i=0;i<n;i++)scanf("%d",&H[i]);
    qsort(H,n,sizeof(int),cmp);
    for(int i=1;i<n;i++){
        if(H[i]==H[i-1]){judge[i]=judge[i-1];continue;}
        for(int m=0;m<i;m++){
            judge[i]=H[i]-H[m]+judge[i];
        }
    }
    if(s>=judge[n-1]){
        res=H[n-1]+(s-judge[n-1])/n;
        s=(s-judge[n-1])%n;
        if(s==0){
            printf("%d",res);
            return 0;
        }
        else{
            int step=0;
            do{
                step++;
                if(s%step==0&&deno%step==0){
                    s/=step;deno/=step;
                    step=1;
                }
            }while(step<deno);
            printf("%d+%d/%d",res,s,deno);
            return 0;
        }
    }
    else{
        int sp=0;
        for(int i=0;i<n;i++)if(judge[i]<=s&&s<judge[i+1]){sp=i;break;}
        int width=sp+1;
        res=H[sp];
        if(s==judge[sp]){printf("%d",res);return 0;}
        else{
            s=s-judge[sp];
            res=res+s/width;
            s=s%width;
            int step=0;
            do{
                step++;
                if(s%step==0&&width%step==0){
                    s/=step;width/=step;
                }
            }while(step<width);
            if(res>0){
                if(s!=0)printf("%d+%d/%d",res,s,width);
                else printf("%d",res);
            }
            else{
                printf("%d/%d",s,width);
            }
            return 0;
        }
    }
}
