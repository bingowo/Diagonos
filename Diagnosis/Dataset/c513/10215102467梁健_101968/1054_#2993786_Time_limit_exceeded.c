#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        printf("case #%d:\n",step);
        int m;scanf("%d",&m);
        int t=1+m/2,k=0;
        char s[1000][t],c;
        do{
            scanf("%s",s[k++]);
        }while(c=getchar()==' ');
        if(k==1)printf("%s\n",s[0]);
        int judge=0,space=m,line=0;
        for(int i=0;i<k;i++){
            if(judge+strlen(s[i])<=m){
                judge+=strlen(s[i]);
                judge++;
                space-=strlen(s[i]);
                line++;
            }
            else{
                int sp=space%(line-1),spa=space/(line-1);
                for(int t=0;t<line;t++){
                    printf("%s",s[i-line+t]);
                    if(i==k-1){
                        printf("%c",' ');
                    }
                    else{
                        if(sp==0){
                            for(int q=0;q<spa;q++)
                                printf("%c",' ');
                        }
                        else{
                            if(t<line-1-sp){
                                for(int q=0;q<spa;q++)
                                    printf("%c",' ');
                            }
                            else{
                                for(int q=0;q<spa+1;q++)
                                    printf("%c",' ');
                            }
                        }
                    }
                }
                printf("\n");
                judge=0;line=0;space=m;
                if(i!=k-1)
                    i--;
            }
        }
    }
    return 0;
}
