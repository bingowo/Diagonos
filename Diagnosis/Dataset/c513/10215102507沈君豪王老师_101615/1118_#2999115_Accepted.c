#include <stdio.h>
#include <math.h>


int main(void)
{
	int w, h, d;
	int w1, h1;
	int sgn;
	char c;
	scanf("%d %d %d %c", &w, &h, &d, &c);
	int image[h][w];
	for(int i = 0 ; i < h; i ++){
		for(int j = 0 ; j < w; j ++){
			scanf("%d", &image[i][j]);
		}
	}
	if(c == 'L'){
		sgn = 1;
	}else if(c == 'R'){
		sgn = -1;
	}
	int rmatrix[2][2];
	if(d % 360 == 0){
		rmatrix[0][0] = 1;
		rmatrix[0][1] = 0;
		rmatrix[1][0] = 0;
		rmatrix[1][1] = 1;
	}else if(d % 360 == 90){
		rmatrix[0][0] = 0;
		rmatrix[0][1] = sgn * (-1);
		rmatrix[1][0] = sgn * 1;
		rmatrix[1][1] = 0;
	}else if (d % 360 == 180){
		rmatrix[0][0] = -1;
		rmatrix[0][1] = 0;
		rmatrix[1][0] = 0;
		rmatrix[1][1] = -1;
	}else if (d % 360 == 270){
		rmatrix[0][0] = 0;
		rmatrix[0][1] = sgn * 1;
		rmatrix[1][0] = sgn * (-1);
		rmatrix[1][1] = 0;
	}
	w1 = abs(w * rmatrix[0][0] + h * rmatrix[0][1]);
	h1 = abs(w * rmatrix[1][0] + h * rmatrix[1][1]);
	int rot_image[h1][w1];
	for(int i = 0 ; i < h; i ++){
		for(int j = 0 ; j < w; j ++){
			int i1, j1, i0, j0;
			j1 = (j) * rmatrix[0][0] + (h - 1 - i) * rmatrix[0][1];
			i1 = (j) * rmatrix[1][0] + (h - 1 - i) * rmatrix[1][1];
			if((sgn * (abs(d) % 360) + 360) % 360== 0){
				j1 = j1;
				i1 = i1;
			}else if((sgn * (abs(d) % 360) + 360) % 360 == 270){
				j1 = j1;
				i1 = i1  + (h1 - 1);
			}else if((sgn * (abs(d) % 360) + 360) % 360 == 180){
				j1 = j1 + (w1 - 1);
				i1 = i1 + (h1 - 1);
			}else if((sgn * (abs(d) % 360) + 360) % 360 == 90){
				j1 = j1 + (w1 - 1);
				i1 = i1;
			}
			rot_image[h1 - 1- i1][j1] = image[i][j];
		}
	}
	printf("%d %d\n", w1, h1);
	for(int i = 0 ; i < h1; i ++){
		for(int j = 0 ; j < w1; j ++){
			printf("%d%c", rot_image[i][j], j == w1 - 1? '\n':' ');
		}
	}
	
	return 0;
}