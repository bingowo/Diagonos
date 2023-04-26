 #include<stdio.h>
typedef struct{
    int a,b;
}pos;
int solution(int r,int t){
    if(r==0&&t==0)return -1;  //任意解
    if(r!=0&&t==0)return -2;   //无解
    if(r*t<0&&r%t!=0)return -2;  //无法整除或者解为负值
    return r/t;
}
int main(){
    char s[101],*s1;
    scanf("%s",s);
    int x1=0,y1=0,i=0;
    pos f[100]={0,0};
    s1=s;
    while(*s1){
        if(*s1=='U')y1++;
        else if(*s1=='D')y1--;
        else if(*s1=='L')x1--;
        else x1++;
        f[i].a=x1;
        f[i++].b=y1;
        s1++;
    }
    int times;
    scanf("%d",&times);
    for(int k=0;k<times;k++){
        int x,y,m,n,flag=0;
        scanf("%d%d",&x,&y);
        for(int p=0;p<i;p++){
            m=solution(x-pos[p].a,x1);
            n=solution(y-pos[p].b,y1);
            if(m==-2||n==-2)continue;
            if(m==-1||n==-1||m==n){flag=1;break;}
        }
        if(flag)printf("Yes\n");
        else printf("No\n");
        
    }
    return 0;
}