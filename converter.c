#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file;
char ch[1000][10000];
int cr[1000][1000];
int cg[1000][1000];
int cb[1000][1000];
int gs[1000][1000];
int bw[1000][1000];
int g,h,i,j; // длинна, высота, дл¤ счЄта

void recognize(); //считывание строк
void colorprisv(); //присвоение цветов в массивы
void gradient(); //создание массива градиента серого
void binarizator(); //бинаризаци¤ серого массива
void show(); //вывод бинаризированного массива дл¤ записи в файл

int main(int argc, char *argv[])
{
	file = fopen(argv[1], "r");
	if (file==NULL) {printf("Введите в аргументах путь к изображению"); exit(1);}
	recognize();
	colorprisv();
	gradient();
	binarizator();
	show();
}

void recognize()
{
	h=1;
	while (fgets(ch[h], 1000, file))
	{
		h++;
	}
}

void colorprisv()
{
	char *buf;
	int d=1;
	g=1;
	i=1;

	for(j=1;j<h;j++)
	{
		buf = strtok(ch[j], " ");
		while (buf != NULL)
		{
			if (d==1) {cr[j][i] = atoi(buf); d++;}
			else if (d==2) {cg[j][i] = atoi(buf); d++;}
			else if (d==3) {cb[j][i] = atoi(buf); d=1; i++;}
			if (g<i) g=i;
			buf=strtok(NULL," ");
		}
		d=1;
		i=1;
	}
}

void gradient()
{
	for(j=4;j<h;j++)
		for(i=1;i<g;i++)
			gs[j][i]=(cr[j][i]+cg[j][i]+cb[j][i])/3;
}

void binarizator()
{
	for(j=4;j<h;j++)
		for(i=1;i<g;i++)
		{
			if (gs[j][i]>atoi(ch[3])/3) bw[j-3][i]=0;
			else bw[j-3][i]=1;
		}
}

void show()
{
	printf("P1\n");
	printf("%d %d\n", h-4, g-1);
	for(j=1;j<h-3;j++){
		for(i=1;i<g;i++)
		{
			printf("%d ",bw[j][i]);
		}
	printf("\n");
	}
}
