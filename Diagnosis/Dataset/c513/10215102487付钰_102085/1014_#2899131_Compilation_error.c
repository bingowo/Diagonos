#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void itof(double x,char a[])
{
    int i=0,before=0,after=0,len=0;
    double y=x;
    while(x){
        x/=10;
        before++;
    }
    int c=10;
    while(y*10!=(int)(y*c)){
            c*=10;
            after++;
    }
    len=after+before;
    for(i;i<before;i++){
        a[i]=(char)(y/(pow(10,(before-1))));
    }
    for(i=before;i<len;i++){
        a[i]=(char)((y-(int)y)*(pow(10,(i-before+1))));
    }

}
double conversion(double x,int k,int point)
{
    char w[1000];
    itoa(x,w,10);
    //找小数点

    int i=0;
    for(i;i<strlen(w);i++){
        if(w[i]=='.')
            point=i;
    }
    int before=0;
    for(i=0;i<point;i++){

        int m=1;
        before+=w[i]*m;
        m*=k;
    }
    double after=0;
    for(i=strlen(w)-1;i>point;i--){

        int n=1;
        after+=w[i]*n;
        n/=k;
    }
    double sum=before + after;
    return sum;

}
int main()
{
    int a,b,point;
    scanf("%d %d",&a,&b);
    int c,d;
    double x;
    if(a>b){
        c=a-((a/b)*b);
        d=a/b;
        double x=(double)a/(double)b;
    }
    //int point=0;
    double sum=conversion(x,3,point);
    double q;
    for(int i=0;i<point;i++){
        int y=1;
        q+=(1*y);
         y*=10;
    }
    int j;
    while(sum){
        sum/=10;
        j++;
    }
    double p;
    for(j;j>point;j--)
    {
        int y=1;
         p+=1*y;
        y*=0.1;
    }
    double putong=p+q;

    char y1[1000];
    itof(putong,y1);
    double x1=putong+sum;
    char y2[1000];
    itof(x1,y2);
    int z1[1000];
    for(int i=0;i<j;i++){
        z1[i]=(y1[i]-'0')-(y2[i]-'0');
        if(z1[i]==-1){
            z1[i]=2;
        }
    }
    for(int i=0;i<point;i++)
    {
        printf("%c",(char)(z1[i]-'0'));
    }
    printf(".");
    for(int i=point+1;i<j;i++)
    printf("%c",(char)(z1[i]-'0'));


}
