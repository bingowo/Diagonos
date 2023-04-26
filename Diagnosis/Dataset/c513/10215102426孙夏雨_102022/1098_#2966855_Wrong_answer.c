#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int panduan(int* p,int num,int you0,int len)
{
    //printf("%d %d\n",num,you0);
    for(int i=0;i<num;i++){
        if(*(p+i)==0&&you0==1) continue;
        if((*(p+i))>=0){
            if(num==1) return 0;
            if(i==0){
                if((*(p+i))>=3) return i;
                else{
                   if((*(p+i+1))-(*(p+i))>3) return i;
                   else if((*(p+i+1))<0) return i;
                }
            }
            else if(i==num-1&&num>1){
                if((*(p+i))-(*(p+i-1))>3) return i;
                else if((*(p+i-1))<0) return i;
                else if(len-(*(p+i))>3) return i;
            }
            else if(i>0&&i<num-1){
                if((*(p+i-1))<0||(*(p+i+1))<0) return i;
                else if((*(p+i+1))-(*(p+i))>3||(*(p+i))-(*(p+i-1))>3) return i;
                else if((*(p+i+1))-(*(p+i-1))>=5) return i;
            }
        }
    }
    return -1;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int r=0,b=0,y=0,g=0;
        char s[101];
        scanf("%s",s);
        int len=strlen(s),num=0;
        int nor=0,nob=0,noy=0,nog=0;
        int* p=(int *)malloc(len*sizeof(int));
        for(int i=0;i<len;i++){
            if(s[i]=='!'){
                *(p+num)=i;
                num++;
            }
        }
        int you0=0;
        int weizhi=panduan(p,num,you0,len);
        while(weizhi!=-1){
            nor=0,nob=0,noy=0,nog=0;
            if(*(p+weizhi)==0) you0=1;
            int wei=*(p+weizhi);
            *(p+weizhi)=(-1)*(*(p+weizhi));
            int qian=0,hou=0,kq=1,kh=1;
            while((qian+hou)<3){
                if(kq==1){
                    qian++;
                    if(wei-qian<0){qian--;kq=0;}
                    else if(s[wei-qian]=='R') nor=1;
                    else if(s[wei-qian]=='B') nob=1;
                    else if(s[wei-qian]=='Y') noy=1;
                    else if(s[wei-qian]=='G') nog=1;
                    else if(s[wei-qian]=='!') {qian--;kq=0;}
                }
                if((qian+hou)>=3) break;
                if(kh==1){
                    hou++;
                    if(wei+hou>=len){hou--;kh=0;}
                    if(s[wei+hou]=='R') nor=1;
                    else if(s[wei+hou]=='B') nob=1;
                    else if(s[wei+hou]=='Y') noy=1;
                    else if(s[wei+hou]=='G') nog=1;
                    else if(s[wei+hou]=='!') {hou--;kh=0;}
                }
            }
            if(nor==0){
                r++;
                s[wei]='R';
            }
            else if(nob==0){
                b++;
                s[wei]='B';
            }
            else if(noy==0){
                y++;
                s[wei]='Y';
            }
            else if(nog==0){
                g++;
                s[wei]='G';
            }
            weizhi=panduan(p,num,you0,len);
        }
        printf("case #%d:\n",t);
        printf("%d %d %d %d\n",r,b,y,g);
        free(p);
    }
    return 0;
}
