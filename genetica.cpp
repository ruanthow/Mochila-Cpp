// Mochila C++.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <bitset>
#include <string>
#include "genetica.h"

using namespace std;



int main()
{	
	struct Mochila mochila;
	int arrayNums[6] = {};
	int countItems = 0;
	int value = 0;
	int weight = 0;
	int num = 0;
	int i,j;
	int result = 0;
	char bitIs = '1';
	unsigned char mascara = 5;
	string binary;
	
	for (i = 0; i <= 5; i++) {
		srand((unsigned)time(NULL));
		cout << "digite um numero: ";
		num = rand();
		arrayNums[i] = num;
	}

	//convertendo numero decimal em numero binario.
	for (i = 0; i < sizeof(arrayNums) / 4; i++) {
		binary = bitset<16>(arrayNums[i]).to_string();
		value = 0;
		weight = 0;
		for (j = 0; j <= 15; j++) {
			if (binary[j] == bitIs) {
				value += mochila.arrayValue[j];
				weight += mochila.arrayWeight[j];
				countItems++;
			}
		}

		if (weight > mochila.weightLimit) {
			cout << "========================================================\n";
			cout << "Numero testado: " << arrayNums[i] << "\nValor: " << value << "\nPeso: " << weight << "KG" << "\n"
				<< "Qauntidade de items: " << countItems << "\n";

			cout << "O a mochila rasgou !! Tome mais cuidado com o peso e a quantidade de items 'Limite e : 20KG'\n";
			cout << "========================================================\n";
		}
		else if (countItems > mochila.slotsLimit) {
			cout << "========================================================\n";
			cout << "Numero testado: " << arrayNums[i] << "\nValor: " << value << "\nPeso: " << weight << "KG" << "\n"
				<< "Qauntidade de items: " << countItems << "\n";

			cout << "O a mochila rasgou !! Tinha muitos items 'Limite e : 16'\n";
			cout << "========================================================\n";
		}
		else if (value > 40) {
			cout << "========================================================\n";
			cout << "Numero testado: " << arrayNums[i] << "\nValor: " << value << "\nPeso: " << weight << "KG" << "\n"
				<< "Qauntidade de items: " << countItems << "\n";
			cout << "Bom saque mas pode ser melhor da proxima vez\n";
			cout << "========================================================\n";
		}
		else if (value < 40) {
			cout << "========================================================\n";
			cout << "Numero testado: " << arrayNums[i] << "\nValor: " << value << "\nPeso: " << weight << "KG" << "\n"
				<< "Qauntidade de items: " << countItems << "\n";
			cout << "O saque foi um fracasso tente novamente\n";
			cout << "========================================================\n";
		}

	};
	cruzamento(arrayNums, result);
	
}

int cruzamento(int arrayAandB[], int result)
{
	system("cls");

	// 0000 0000 0000 0000
	int mascara = 0; 
	int num2 = 0;
	int num = 61257;
	int t = 0;
	int newbit = 0;
	
	//pegar os primeiros 8 bits andando 8 bits para tras fazendo ficar e voltando 8 bits zerados pra frente
	// exemplo 1111 1111 1111 1111 >>  0000 0000 1111 1111 << 1111 1111 0000 0000
	newbit = arrayAandB[0] >> 8 << 8;
	t = newbit;
	cout << "Numero:      " << bitset<16>(num).to_string() << endl;
	cout << "Mascara:     " << bitset<16>(mascara).to_string() << endl;
	cout << "Novo numero: " << bitset<16>(newbit).to_string() << endl;
	cout << "numero:      " << newbit;
	
	//newbit = 1111 1111 0000 0000

	//0000 0000 1111 1111
	num2 = arrayAandB[1]; 
	
	
	// antiga mascara = 0000 0000 0000 0000
	// nova mascara = 0000 0000 1111 1111
	mascara = num2;
	
	
	//1111 1111 0000 0000
	//0000 0000 1111 1111
	newbit = mascara | newbit;
	
	// newbit = 1111 1111 1111 1111
	cout << "\n\n\nNumero 1:    " << bitset<16>(t).to_string() << endl;
	cout << "Numero 2:    " << bitset<16>(mascara).to_string() << endl;
	cout << "Novo numero: " << bitset<16>(newbit).to_string() << endl;
	cout << "numero:      " << newbit;


	return 1;
}
