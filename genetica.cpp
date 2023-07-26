// Mochila C++.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <bitset>
#include "genetica.h"
#include<windows.h>

using namespace std;



int main()
{
	struct Mochila mochila;
	unsigned short arrayNums[6] = {};
	unsigned char countItems = 0;
	unsigned char value = 0;
	unsigned char weight = 0;
	unsigned int num = 0;
	unsigned char i,j;
	char bitIs = '1';
	unsigned char mascara = 5;
	string binary;
	
	for (i = 0; i <= 5; i++) {
		cout << "Digite um numero: ";
		cin >> num;
		if (num < 0 || num > 65535) {
			cout << "Range minimo e : 0. E o maximo e : 65535.";
			Sleep(3000);
			system("cls");
			i--;
		}
		else {
			arrayNums[i] = num;
		}
		
	}

	//convertendo numero decimal em numero binario.
	for (i = 0; i < sizeof(arrayNums) / 2; i++) {
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

		feedbackMochila(weight, arrayNums[i], value, countItems);
		

	};
	cruzamento(arrayNums);
	
}

int cruzamento(unsigned short arrayNums[])
{
	

	// 0000 0000 0000 0000
	int mascara = 0; 
	int num2 = arrayNums[1];
	int num = arrayNums[0];
	int lastBinary = 0;
	int currentBinary = 0;
	
	//pegar os primeiros 8 bits andando 8 bits para tras e voltando 8 bits zerados pra frente
	// exemplo 1111 1111 1111 1111 >>  0000 0000 1111 1111 << 1111 1111 0000 0000
	currentBinary = arrayNums[0] >> 8 << 8;
	lastBinary = currentBinary;
	cout << "Numero:      " << bitset<16>(num).to_string() << endl;
	cout << "Mascara:     " << bitset<16>(mascara).to_string() << endl;
	cout << "Novo numero: " << bitset<16>(currentBinary).to_string() << endl;
	cout << "numero:      " << currentBinary;
	
	//newbit = 1111 1111 0000 0000
 

	// antiga mascara = 0000 0000 0000 0000
	// nova mascara = 0000 0000 1111 1111
	mascara = num2;
	
	
	//1111 1111 0000 0000
	//0000 0000 1111 1111
	currentBinary = mascara | currentBinary;
	
	// newbit = 1111 1111 1111 1111
	cout << "\n\n\nNumero 1:    " << bitset<16>(lastBinary).to_string() << endl;
	cout << "Numero 2:    " << bitset<16>(mascara).to_string() << endl;
	cout << "Novo numero: " << bitset<16>(currentBinary).to_string() << endl;
	cout << "numero:      " << currentBinary;


	return 1;
}

void feedbackMochila(unsigned short weight, unsigned short currentNumberOfArray, unsigned char value, unsigned char countItems) {
	
	struct Mochila mochila;
	
	if (weight > mochila.weightLimit) {
		cout << "------------------------------------------- \n";
		cout << currentNumberOfArray << " - " << +countItems << "Qtd" << " - " << "$" << +value << " - " << weight << "KG" << " - " << "X \n";
		
	}
	else if (countItems > mochila.slotsLimit) {
		cout << "-------------------------------------------\n";
		cout << currentNumberOfArray << " - " << +countItems << "Qtd" << " - " << "$" << +value << " - " << weight << "KG" << " - " << "X \n";
	}
	else if (value > 40) {
		cout << "-------------------------------------------\n";
		cout << currentNumberOfArray << " - " << +countItems << "Qtd" << " - " << "$" << +value << " - " << weight << "KG" << " - " << "OK \n";
	}
	else if (value < 40) {
		cout << "-------------------------------------------\n";
		cout << currentNumberOfArray << " - " << +countItems << "Qtd" << " - " << "$" << +value << " - " << weight << "KG" << " - " << "OK \n";
	}
};