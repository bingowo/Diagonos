#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  W,H;

int minmin(int *ans){
    int x=ans[0];
    for(int i=1;i<8;i++) {
        if(ans[i]<x) x=ans[i];
    }
    return x;
}

int minNum(int *nums){
    int ans[8];
    for(int i=0;i<8;i++){
        int tmp=0;
        for(int j=0;j<8;j++){
            tmp=tmp*2+nums[i+j];
        }
        ans[i]=tmp;
    }

    return minmin(ans);
}

int comLBP(int mage[H][W],int r,int c){
    int nums[16]={0};
    if(mage[r-1][c-1]>=mage[r][c]){
            nums[0]=nums[8]=1;}
    if(mage[r-1][c]>=mage[r][c]){
            nums[1]=nums[9]=1;}
    if(mage[r-1][c+1]>=mage[r][c]){
            nums[2]=nums[10]=1;}
    if(mage[r][c+1]>=mage[r][c]){
            nums[3]=nums[11]=1;}
    if(mage[r+1][c+1]>=mage[r][c]){
            nums[4]=nums[12]=1;}
    if(mage[r+1][c]>=mage[r][c]){
            nums[5]=nums[13]=1;}
    if(mage[r+1][c-1]>=mage[r][c]){
            nums[6]=nums[14]=1;}
    if(mage[r][c-1]>=mage[r][c]){
            nums[7]=nums[15]=1;}

    return minNum(nums);

}


int main()
{
    scanf("%d%d",&W,&H);
    int mage[H][W];
    for(int r=0;r<H;r++){
        for(int c=0;c<W;c++) scanf("%d",&mage[r][c]);
    }

    int LBP[H-2][W-2];
    memset(LBP,0,sizeof(LBP));
    for(int r=1;r<H-1;r++){
        for(int c=1;c<W-1;c++){
            LBP[r-1][c-1]=comLBP(mage,r ,c );
        }
    }


    for(int r=0;r<H-2;r++){
        for(int c=0;c<W-2;c++) printf("%d%c",LBP[r][c],c==W-3?'\n':' ');
    }

    return 0;
}
