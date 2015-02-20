#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file;
char ch[300000][1000];
int mass[1000][1000];
int x,y,i,h,j;

int Xmin,Xmax,Yup,Ydown;
float cx,cy;

void recognize();
void tblbuild();
void Borders();
void Center();
void Pointer();
void tblprint();

int main(int argc, char *argv[])
{
	file = fopen(argv[1], "r");
	if (file==NULL) {printf("Введите в аргумент путь к изображению"); exit(1);}
	recognize();
	tblbuild();
	Borders();
	Center();
	Pointer();
	tblprint();
}

void recognize(){
	char *buf;
	int p=0;
	h=1;
	while (fgets(ch[h], 1000, file))
	{
		h++;
	}
	buf = strtok(ch[2], " ");
		while (buf != NULL)
		{
			if (p==0) {x = atoi(buf); p++;}     
			else if (p==1) {y = atoi(buf); p++;}
			buf=strtok(NULL," ");
		}
}

void tblbuild(){
	int z;
	i=1;
	j=1;
	
	for(z=4;z<=h;z++)
	{
		mass[j][i]=atoi(ch[z]);
		i++;
		if (i==x+1) {i=1; j++;}
	}
}

void Borders(){
	for (i=1;i<y;i++)
		for (j=1;j<x;j++){
			if (mass[i][j]<170) {
				if (j<Xmin || Xmin == 0) Xmin = j;
				if (j>Xmax) Xmax = j;
				if (i<Yup || Yup == 0) Yup = i;
				if (i>Ydown) Ydown = i;
			}
		}
}

void Center(){
	cx = (Xmin + Xmax)/2;
	cy = (Yup + Ydown)/2;
}

void Pointer(){
	for (i=1;i<y;i++)
		mass [i][(int)cx] = 125;
	for (j=1;j<x;j++)
		mass [(int)cy][j] = 125;
}

void tblprint(){
	printf("P2\n");
	printf("%d %d\n",x-1,y-1);
	printf("255\n");
	for (i=1;i<y;i++){
		for (j=1;j<x;j++)
			printf("%d ",mass[i][j]);
		printf("\n");
	}
}

