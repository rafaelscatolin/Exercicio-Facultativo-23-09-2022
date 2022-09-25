/*Implemente a seguinte simulação:
1- Crie uma matriz quadrada de escopo global que represente uma thumbnail em escala de cinza de
de 64x64 (tamanho definido em constantes);
2 - crie um procedimento que a preencha com os níveis de cinza (256 cores, de 0 a 255) aleatórios;
3 -  crie um procedimento para imprimir a matriz na tela;
4 - crie uma função que permita a busca por um determinado pixel. Retorna -1 caso não encontre. Retorna o número de
ocorrências do pixel na matriz;
5 - um procedimento que salve em um vetor de escopo global a diagonal principal.
6 - um procedimento que salve em um vetor de escopo global a diagonal principal.
7 - um procedimento que troque na matriz a diagonal principal pela diagonal secundária.
8 - um procedimento que imprima a quantidade de pares, impares e o pixel médio ocorrido.*/


#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

int matriz[10][10], pixel, quant_pares = 0, pixel_medio = 0;
vector <int> diagonal_1, diagonal_2;

void init_matriz (int matriz[10][10]) {
	for (int i=0; i!=10; i++)
		for (int j=0; j!=10; j++){
			matriz[i][j] = rand()%256;
			if (i == j)
				diagonal_1.push_back(matriz[i][j]);
			if (i == 10 - j - 1)
				diagonal_2.push_back(matriz[i][j]);	
		}
}

void print_matriz (int matriz[10][10]) {
	for (int i=0; i!=10; i++) {
		for (int j=0; j!=10; j++)
			cout << matriz[i][j] << "\t";
		cout << "\n\n";
	}
}

int busca_pixel (int matriz[10][10]) {	

	int quant_pixel = 0;
	
	for (int i=0; i!=10; i++)
		for (int j=0; j!=10; j++)	
			if (matriz[i][j] == pixel)
				quant_pixel++;	
				
	if (quant_pixel == 0)
		return -1;
	else
		return quant_pixel;
}


void troca_diagonal (int matriz[10][10]) {
	for (int i=0; i!=10; i++)
		for (int j=0; j!=10; j++){
			if (i == j)
			matriz[i][j] = diagonal_2[i];
			if (i == 10 - j - 1)
			matriz[i][j] = diagonal_1[i];
		}
}


void proced_item_8 (int matriz[10][10]) {
	for (int i=0; i!=10; i++)
		for (int j=0; j!=10; j++) {	
			if (matriz[i][j]%2 == 0)
				quant_pares++;		
			pixel_medio = pixel_medio + matriz[i][j];	
		}		
	pixel_medio = pixel_medio / 100;		
}


int main () {
	
	srand(time(NULL));
	
	init_matriz (matriz);
	
	print_matriz (matriz);
	
	cout << "Digite o pixel a ser buscado: ";
	cin >> pixel;
	int quant_pixel = busca_pixel (matriz);
	
	if (quant_pixel == -1)
		cout << "\nNao foi encontrado o pixel solicitado." << endl << endl;
	else
		if (quant_pixel == 1)
			cout << "\nFoi encontrado somente 1 pixel com o valor de " << pixel << endl << endl;
		else
			cout << "\nForam encontrados " << quant_pixel << " pixels com o valor de " << pixel << endl << endl;
	
	
	cout << "A matriz com as diagonais trocadas fica da seguinte forma: " << endl << endl;
	troca_diagonal (matriz);
	print_matriz (matriz);
	
	
	proced_item_8 (matriz);
	
	cout << "A quantidade de pixels com valor par e " << quant_pares << endl;
	
	cout << "A quantidade de pixels com valor impar e " << 100 - quant_pares << endl;
	
	cout << "O valor do pixel medio ocorrido e " << pixel_medio << endl << endl;
	
	
	system ("pause");
	
	return 0;
}