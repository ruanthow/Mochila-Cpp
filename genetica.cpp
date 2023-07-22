// Mochila C++.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <bitset>

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
	char bitIs = '1';
	unsigned char mascara = 5;
	string binary;
	
	for (i = 0; i <= 5; i++) {
		cout << "digite um numero: ";
		cin >> arrayNums[i];
	}


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
		else if(countItems > mochila.slotsLimit){
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

	}
	

	

	
}
