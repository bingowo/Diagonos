#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main()
{
    char T;scanf("%d",&T);
    for(int step=0;step<T;printf("case #%d:\n",step),step++){
        int m;scanf("%d",&m);
        char t;t=getchar();
        char s[2050];gets(s);
        int num=2*strlen(s)/m;
        int l=m/2;
        char c[num][l],len[num];
        int k=0,kc=0;
        for(int i=0;i<strlen(s);i++){
            if(s[i]==' '){
                c[k][kc]=0;
                len[k]=strlen(c[k]);
                k++;kc=0;
                continue;
            }
            c[k][kc++]=s[i];
        }
        len[k]=0;
        int judge=0,jud=0,space=m,line=0;
        while(jud<k){
            if(judge+len[jud]<=m){
                judge+=len[jud];
                line++;
            }
            if(judge+len[jud+1]+1<=m&&jud+1<k){
                judge++;
            }
            else{
                for(int i=jud+1-line;i<=jud+1;i++){
                    space-=len[i];
                }
                int sp=space/line;
                space=space-sp*line;
                    for(int i=jud+1-line,k=1;i<=jud+1;i++,k++){
                        printf("%s",c[i]);
                        if(k<=line-space){
                            for(int z=0;z<sp;z++){
                                printf("%c",' ');
                            }
                        }
                        else{
                            for(int z=0;z<sp+1;z++){
                                printf("%c",' ');
                            }
                        }
                    }
                    printf("\n");
                    judge=0;space=m;line=0;
                }
                jud++;
            }
            printf("\n");
        }
    return 0;
}
