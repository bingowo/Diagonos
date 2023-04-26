#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void printimg(int *img,int h,int w)
{
    printf("%d %d\n",w,h);
    for (int i=0;i<h;i++)
    {
        for (int j=0;j<w;j++){
            if (j==w-1) printf("%d\n",img[i*w+j]);
            else printf("%d ",img[i*w+j]);
        }
    }

}

void swap(int *w,int *h)
{
    int tmp=*w;
    *w=*h;
    *h=tmp;
}


int main()
{
    int w,h,angle;
    char dirn;
    scanf("%d%d%d %c",&w,&h,&angle,&dirn);
    angle=(angle%360)/90;
    int img[h*w];
    int img2[h*w];
    for (int i=0;i<h*w;i++)
    {
        scanf("%d",&img[i]);
    }
    if (angle ==0) printimg(img,h,w);
    if( (angle==1 && dirn=='R') ||(angle==3 && dirn=='L') )
    {
        swap(&h,&w);
        for(int i1=0;i1<h;i1++)
        {
            for(int j1=0;j1<w;j1++)
                img2[i1*w+j1]=img[(w-1-j1)*h+i1];
        }
        printimg(img2,h,w);
    }
    if(angle==2)
    {
        for (int i2=0;i2<h;i2++)
        {
            for(int j2=0;j2<w;j2++)
                img2[i2*w+j2]=img[(h-1-i2)*w+(w-1-j2)];
        }
        printimg(img2,h,w);
    }
    if( (angle==3 && dirn=='R') ||(angle==1 && dirn=='L') )
    {
        swap(&h,&w);
        for (int i3=0;i3<h;i3++)
        {
            for (int j3=0;j3<w;j3++)
                img2[i3*w+j3]=img[j3*h+(h-1-i3)];
        }
        printimg(img2,h,w);
    }


    return 0;
}