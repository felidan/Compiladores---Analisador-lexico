#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char f[100], var[10], tempC, matrizVariaveis[10][10], matrizPReservada[10][6];
int p=0, tempN, indice=0, qtVar=0;
int comparaString(char a[], char b[]);
void cpy(char *destino, const char *src);
void e0();
void e1();
void e2();
void e3();
void e4();
void e5();
void e6();
void funcao1(char simbolo);
void funcao2(char simbolo);
void funcao3();
void funcao4(char simbolo);
void funcao5(char simbolo);
void funcao6();
void funcao7();
void funcao8();
void funcao9(char simbolo);
void funcao10();
void print();

int comparaString(char a[], char b[]){
	int c;
	for(c=0; a[c] != '\0'; c++){
		if(a[c] != b[c])
		    return 0;
		}
		if(a[c] != b[c])
		    return 0;
		else
		    return 1;
}

void cpy(char *destino, const char *src)
{
  int i;
  for (i=0; src[i] != '\0'; ++i)
    destino[i] = src[i];

  destino[i]= '\0';
}

void e0(){
	if( (f[p] >= 65 && f[p] <= 90) || (f[p] >= 97 && f[p] <= 122) ){ // entre A-Z ou a-z
		funcao1(f[p]);
		p++;
		e1();
	}
	else{
		if(f[p] >= 48 && f[p] <= 57){ // entre 0-9
			funcao4(f[p]);
			p++;
			e2();
		}
		else{
			if(f[p] == ':'){
				p++;
				e3();
			}
			else{
				if(f[p] == '%'){
					p++;
					e5();
				}
				else{
					if(f[p] == 32){ // espaço
						p++;
						e0();
					}
					else{
						if(f[p] == '>' || f[p] == '<' || f[p] == '=' || f[p] == '(' || f[p] == ')' || f[p] == '+' || f[p] == '-' || f[p] == '*' || f[p] == '/' || f[p] == '@'){
							funcao9(f[p]);
							p++;
							e6();
						}
						else{
							if(f[p] == 0){
								printf("\n");
								print();
								getch();
								exit(0);
							}
							else{
								printf("\n-> FALHA e0()\n");
								getch();
								exit(0);
							}	
						}	
					}	
				}
			}
		}
	}
}

void e1(){
	
	if((f[p] >= 65 && f[p] <= 90) || (f[p] >= 97 && f[p] <= 122)){ // entre A-Z ou a-z
		funcao2(f[p]);
		p++;
		e1();
	}
	else{
		if(f[p] >= 48 && f[p] <= 57){ // entre 0-9
			funcao2(f[p]);
			p++;
			e1();
		}
		else{
			if(f[p] == 0){
                funcao3();
                print();
				getch();
				exit(0);
			}
			else{
                funcao3();
				e0();
			}
		}
	}
}

void e2(){
	if(f[p] >= 48 && f[p] <= 57){ // entre 0-9
		funcao5(f[p]);
		p++;
		e2();
	}
	else{
if(f[p] == 0){
    funcao6();
    	print();
				getch();
				exit(0);
			}
			else{
                funcao6();
				e0();
			}
	}
}

void e3(){
	if(f[p] == '='){
		p++;
		e4();
	}
	else{
  if(f[p] == 0){
        print();
				getch();
				exit(0);
			}
			else{
                funcao7();
				e0();
			}
	}
}

void e4(){
	if(f[p] == 0){
        print();
				getch();
				exit(0);
			}
			else{
                funcao8();
				e0();
			}
}

void e5(){
	if(f[p] == '\n'){
		p++;
		e0();
	}
	else{
		if(f[p] == 0){
			e0();
		}
		else{
			p++;
			e5();	
		}
	}
}

void e6(){
	
	funcao10();
	
	if(f[p] == '='){
		funcao9(f[p]);
		p++;
		e6();
	}
	else{
		e0();
	}
	
}

void funcao1(char simbolo){
	var[indice] = simbolo;
	indice++;
}

void funcao2(char simbolo){
	var[indice] = simbolo;
	indice++;
}

void funcao3(){
	int posicao = -1, i;
	
	var[indice] = 0;
	
	for(i=0; i< 9; i++){
		if(comparaString(var, matrizPReservada[i]) == 1){
			posicao = i;
		}
	}
	
	if(posicao != -1){
		printf("P(%d)", posicao);
	}
	else{
		for(i=0; i<qtVar; i++){
			if(comparaString(var, matrizVariaveis[i]) == 1){
				posicao = i;
			}
		}
		
		if(posicao == -1){
			cpy(matrizVariaveis[qtVar], var);
			posicao = qtVar;
			qtVar++;
		}
		
		printf("V(%d)", posicao);	
	}
	
	indice=0;
}

void funcao4(char simbolo){
	tempN = simbolo - '0';
}

void funcao5(char simbolo){
	tempN = tempN*10 + (simbolo - '0');
}

void funcao6(){
	printf("N(%d)", tempN);
	tempN = 0;
}

void funcao7(){
	printf(":");
}

void funcao8(){
	printf(":=");
}

void funcao9(char simbolo){
	tempC = simbolo;
}

void funcao10(){
	printf("%c", tempC);
}

void inicializaMatriz(){
	int i, j;
	
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			matrizVariaveis[i][j] = 0;
		}
	}
	
	cpy(matrizPReservada[0], "IF");
	cpy(matrizPReservada[1], "ELSE");
	cpy(matrizPReservada[2], "END");
	cpy(matrizPReservada[3], "GO");
	cpy(matrizPReservada[4], "TO");
	cpy(matrizPReservada[5], "OF");
	cpy(matrizPReservada[6], "PRINT");
	cpy(matrizPReservada[7], "READ");
	cpy(matrizPReservada[8], "LET");
	
}

void print(){
	int i;
	
	printf("\n--> Palavras reservadas\n");
	for(i=0; i<9; i++){
		printf("\t%d - %s\n", i, matrizPReservada[i]);	
	}
	
	printf("\n--> Variaveis\n");
	for(i=0; i<qtVar; i++){
		printf("\t%d - %s\n", i, matrizVariaveis[i]);	
	}
}

int main(int argc, char *argv[]){
	int i;
	
	inicializaMatriz();
		
	printf("Linha: ");
	
	gets(f);
	
	e0();
	
	system("pause");
	return 0;
}
