#include<stdio.h>
#include<malloc.h>
int* trans(int*a,int d,int w,int h){
    int *b;
    b=(int*)malloc(w*h*sizeof(int));
    if(d==2){
        for(int i=0;i<h;i++){
            for(int k=0;k<w;k++){
                b[i*w+k]=a[(h-1-i)*w+(w-1-k)];
            }
        }
    }
    else if(d==1){
        for(int i=0;i<w;i++){
            for(int k=0;k<h;k++){
                b[i*h+k]=a[(h-1-k)*w+i];
            }
        }
    }
    else{
        for(int i=0;i<w;i++){
            for(int k=0;k<h;k++){
                b[i*h+k]=a[k*w+(w-i-1)];
            }
        }
    }
    return b;
}
int main(){
    int w,h,d,*a,*b;
    char c;
    scanf("%d%d%d %c",&w,&h,&d,&c);
    a=(int*)malloc(w*h*sizeof(int));
    d=d%360;
    if(c=='L')d=360-d;
    d=d/90;
    d=d%4;
    for(int i=0;i<w*h;i++)scanf("%d",&a[i]);
    if(d!=0)b=trans(a,d,w,h);
    else b=a;
    if(d%2==0){
        printf("%d %d\n",w,h);
        for(int i=0;i<h;i++){
            for(int k=0;k<w;k++){
                printf("%d ",b[i*w+k]);
            }
            printf("\n");
        }
    }
    else{
        printf("%d %d\n",h,w);
        for(int i=0;i<w;i++){
            for(int k=0;k<h;k++){
                printf("%d ",b[i*h+k]);
            }
            printf("\n");
        }
    }
    free(a);
    if(d!=0)free(b);
    return 0;
}