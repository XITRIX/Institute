#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file;
char ch[1000][10000];
int cr[1000][1000],h,i,j,z,x;

void recognize();
void show();
void mainloop();
void erazer();
void changer();
void controll();

int main(int argc, char *argv[])
{
	file = fopen(argv[1], "r");
	if (file==NULL) {printf("Введите путь к файлу с матрицей\n"); exit(1);}
	recognize();
	show();
	mainloop();
}

void recognize()
{
	char *buf;
	int d=1;
	i=1;
	h=1;
	while (fgets(ch[h], 1000, file))
	{
		h++;
	}

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

void show(){
	for(z=1;z<=cr[0][2];z++){
		for(x=1;x<=cr[0][1];x++)
			{printf("%d ",cr[z][x]);}
		printf("\n");	
	}
	printf("\n");
}

void mainloop(){
	for(;;){
		char q[5];
		printf("Введите:\n 1 - что бы очистить матрицу\n 2 - что бы поменять размер матрицы\n 3 - что бы управлять значениями матрицы\n 4 - что бы выйти из программы\n\n");
		scanf("%s",q);
		if (atoi(q)==1) erazer();
		else if (atoi(q)==2) changer();
		else if (atoi(q)==3) controll();
		else if (atoi(q)==4) return;
		else if (!atoi(q) || atoi(q)>4) printf("Ошибка: такого пункта меню не существует\n\n");
		show();
	}
}

void erazer(){
	int i,j;
	for (i=0;i<1000;i++)
		for (j=0;j<1000;j++)
			cr[i][j]=0;
	printf("Матрица успешно удалена\n\n");
}

void changer(){
	char x[5],y[5];
	printf("Введите размер матрицы по X: ");
	scanf("%s",x);
	if (!atoi(x) || atoi(x)<0) {printf("Ошибка: неверный размер матрицы\n\n");return;}
	printf("Введите размер матрицы по Y: ");
	scanf("%s",y);
	if (!atoi(y) || atoi(y)<0) {printf("Ошибка: неверный размер матрицы\n\n");return;}
	cr[0][1]=atoi(x);
	cr[0][2]=atoi(y);
	printf("Размер матрицы успешно изменён\n\n");
}

void controll(){
	char x[5],y[5],q[5];
	printf("Введите ячейку матрицы по X: ");
	scanf("%s",x);
	if (!atoi(x) || atoi(x)<1 || atoi(x)>cr[0][1]){printf("Ошибка: нарушена граница матрицы\n\n");return;}
	printf("Введите ячейку матрицы по Y: ");
	scanf("%s",y);
	if (!atoi(y) || atoi(y)<1 || atoi(y)>cr[0][2]){printf("Ошибка: нарушена граница матрицы\n\n");return;}
	printf("Сейчас значение этой ячейки: %d\n",cr[atoi(y)][atoi(x)]);
	printf("Введите новое значение: ");
	scanf("%s",q);
	if (!atoi(q)){printf("Ошибка: новое значение должно быть циферным\n\n");return;}
	cr[atoi(y)][atoi(x)]=atoi(q);
	printf("Значение ячейки успешно изменено\n\n");
}
