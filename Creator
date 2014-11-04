#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tbl[1000][1000];
int x,y,h,g,i,j;
char *args[100];

int main(int argc, char *argv[]){
	int k;
	
	for (k=1;k<argc-1;k++)
		args[k]=argv[k];
		
	exeptions(argc);
	prisv();
	tblconstruct();
	for (k=5;k<argc;k++)
		setmrk(k-4,atoi(argv[k]));
	tblshow();
}

int exeptions(int argc){
	if (argc == 1) {
		printf("\nПравило заполнения аргументов: (ширина ячейки) (высота ячейки) (количество столбцов) (количество строк) (ответы)\n\n");
		exit(1);
	}
	else if (atoi(args[4]) != argc-5) {
		printf("\nВсего вопросов %d, а вы ввели %d ответов\n\n",atoi(args[4]),argc-5);
		exit(1);
	}
	for (i=5;i<argc-1;i++) //НЕ ПРОВЕРЯЕТ ПОСЛЕДНИЙ АРГУМЕНТ (КАКОГО ТО ХРЕНА)
		if (atoi(args[3]) < atoi(args[i]) || atoi(args[i]) < 1){
			printf("\nВсего вариантов ответа %d, а вы ввели ответ %d\n\n",atoi(args[3]),atoi(args[i]));
			exit(1);
		}
	
}

int prisv(){
	h=atoi(args[1]);
	g=atoi(args[2]);
	x=(atoi(args[1])+1)*atoi(args[3])+1;
	y=(atoi(args[2])+1)*atoi(args[4])+1;
}

int tblconstruct(){
	for (i=1;i<y+1;i=i+g+1)
		for (j=1;j<x+1;j++)
			tbl[i][j]=1;
			
	for (j=1;j<x+1;j=j+h+1)
		for (i=1;i<y+1;i++)
			tbl[i][j]=1;
}

int setmrk(int vpr, int otv){
	int m,n;
	m=3+((h+1)*(otv-1));
	n=3+((g+1)*(vpr-1));
	for (i=0;i<g-2;i++)
		for (j=0;j<h-2;j++)
			tbl[n+i][m+j]=1;
}

int tblshow(){
	printf("P1\n");
	printf("%d %d\n",x,y);
	for (i=1;i<y+1;i++){
		for (j=1;j<x+1;j++){
			printf("%d",tbl[i][j]);
		}
		printf("\n");
	}
}
