#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int m,k=0,start=0,end=0,len=0;
        char *d[2000],s1[70],c;
        scanf("%d",&m);
        printf("%d\n",m);
        c=getchar();
        while((c=getchar())!='\n'){
            ungetc(c,stdin);
            scanf("%s",s1);
            d[k++]=(char*)malloc((strlen(s1)+1)*sizeof(char));
            strcpy(d[k-1],s1);
        }
        printf("case #%d:\n",i);
        if(k==1){printf("%s\n",d[0]);continue;}
        while(start<k){
            len=-1;
            while(end<k&&(len+strlen(d[end])+1)<=m){
                len+=strlen(d[end])+1;
                end++;
            }
            int cnt=end-start,yu=0,z=0;
            if(cnt!=1){yu=(m-len)%(cnt-1);z=(m-len)/(cnt-1);z+=1;}
            if(end!=k){
                for(int q=start;q<end;q++){
                    printf("%s",d[q]);
                    for(int t=0;t<z;t++)printf(" ");
                    if(end-q<=yu+1)printf(" ");
                }
            }
            else{
                for(int q=start;q<end;q++){
                    printf("%s ",d[q]);
                }
            }
            printf("\n");
            start=end;
        }

    }
    return 0;
}