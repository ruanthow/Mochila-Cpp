// Mochila C++.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <bitset>
#include "genetica.h"
#include<windows.h>

using namespace std;

int main()
{
	struct Bag bag;
	unsigned short arrayNums[6] = {};
	unsigned char countItems = 0;
	unsigned char value = 0;
	unsigned char weight = 0;
	unsigned int num = 0;
	unsigned char i;
	const char bitIs = '1';
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
		
		calculatorWeightAndValue(arrayNums[i]);

	};

	cout << "\n\nNovas tentativas com cruzamentos geneticos. \n";
	geneticCross(arrayNums);
	crossArithmetic(arrayNums);
}

int geneticCross(unsigned short arrayNums[])
{
	

	// 0000 0000 0000 0000
	unsigned short mascara = 0; 
	unsigned short currentBinary = 0;
	
	//pegar os primeiros 8 bits andando 8 bits para tras e voltando 8 bits zerados pra frente
	// exemplo 1111 1111 1111 1111 >>  0000 0000 1111 1111 << 1111 1111 0000 0000
	currentBinary = arrayNums[0] >> 8 << 8;
	
	//currentBinary = 1111 1111 0000 0000
 

	// antiga mascara = 0000 0000 0000 0000
	// nova mascara = 0000 0000 1111 1111
	mascara = arrayNums[1] & 255;
	
	

	//1111 1111 0000 0000
	//0000 0000 1111 1111
	currentBinary = mascara | currentBinary;
	
	// currentBinary = 1111 1111 1111 1111
	calculatorWeightAndValue(currentBinary);

	return 1;
}

void calculatorWeightAndValue(unsigned short number) {

	struct Bag bag;

	unsigned char i = 0;
	const char bitIs = '1';
	unsigned char value = 0;
	unsigned char weight = 0;
	unsigned char countItems = 0;
	string newBinaryIs;

	newBinaryIs = bitset<16>(number).to_string();

	for (i = 0; i <= 15; i++) {
		if (newBinaryIs[i] == bitIs) {
			value += bag.arrayValue[i];
			weight += bag.arrayWeight[i];
			countItems++;
		}
	}

	feedbackBag(weight, number, value, countItems);
}

int crossArithmetic(unsigned short arrayNums[]) {
	unsigned short newBinary = 0;

	newBinary = arrayNums[0] ^ arrayNums[1];

	calculatorWeightAndValue(newBinary);
	return 0;

}

void feedbackBag(unsigned short weight, unsigned short currentNumberOfArray, unsigned char value, unsigned char countItems) {
	
	struct Bag bag;
	
	if (weight > bag.weightLimit) {
		cout << "------------------------------------------- \n";
		cout << currentNumberOfArray << " - " << +countItems << "Qtd" << " - " << "$" << +value << " - " << weight << "KG" << " - " << "X \n";
		
	}
	else if (countItems > bag.slotsLimit) {
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