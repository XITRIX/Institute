#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file;
int tbl[1000][1000];
int otvet[100];
int x,y,h,g,kvpr,kotv,i,j;

void tblbuild();
void recognize();
void chekmark();
void otvprint();
void tblshow();

int main(int argc, char *argv[]){
	file = fopen(argv[1], "r");
	
	tblbuild();
	recognize();
	chekmark();
	otvprint();
	//tblshow(y,x); Функция для проверки правильности прочтения и построения таблицы
}

void tblbuild(){
	char ch[2];
	i = 1;
	y = 1;
	while (!feof(file))
    {
        fgets(ch, 2, file);

		if (ch[0] == '\n')
		{
			y++;
			if (x<i) x=i;
			i=1;
		}

        if (ch[0] == '1' && y>=3)
		{
			tbl[y-2][i] = 1;
			i++;
		}

        if (ch[0] == '0' && y>=3)
		{
			tbl[y-2][i] = 0;
			i++;
		}
        ch[0] = 0;
    }
	y=y-3;
	x=x-1;
}

void recognize(){
	for (i=1,j=0;j<2;i++){
		if (tbl[2][i] == 1) j++;
		if (tbl[2][i] == 0) h++;
	}
	for (i=1,j=0;j<2;i++){
		if (tbl[i][2] == 1) j++;
		if (tbl[i][2] == 0) g++;
	}
	kotv=(x-1)/(h+1);
	kvpr=(y-1)/(g+1);
}

void chekmark(){
	int vpr,otv;
	for (vpr=1;vpr<kvpr+1;vpr++){
		for (otv=1;otv<kotv+1;otv++){
			if ((tbl[((1+g)/2+1)+(1+g)*(vpr-1)][((1+h)/2+1)+(1+h)*(otv-1)]) == 1) otvet[vpr]=otv;
		}
	}
}

void otvprint(){
	for (i=1;i<kvpr+1;i++)
		printf("%d\n",otvet[i]);
}

void tblshow(int y, int x){
	for (i=1;i<y+1;i++){
		for (j=1;j<x+1;j++){
			printf("%d",tbl[i][j]);
		}
		printf("\n");
	}
}
