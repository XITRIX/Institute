#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file;
char ch[1000][10000];
int cr[1000][1000],h,i,j,z,x;

void recognize(); //считывание строк
void colorprisv(); //присвоение цветов в массивы

int main(int argc, char *argv[])
{
	file = fopen(argv[1], "r");
	if (file==NULL) {printf("ARGS!!!!"); exit(1);}
	recognize();
	colorprisv();
	for(z=1;z<=cr[0][2];z++){
		for(x=1;x<=cr[0][1];x++)
			{printf("%d ",cr[z][x]);}
		printf("\n");	
	}
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
	i=1;

	for(j=1;j<h;j++)
	{
		buf = strtok(ch[j], " ");
		while (buf != NULL)
		{
			cr[j-1][i] = atoi(buf); i++;
			buf=strtok(NULL," ");
		}
		i=1;
	}
}
