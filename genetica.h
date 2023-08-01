struct Bag {
	int	weightLimit = 20;
	int slotsLimit = 16;
	int arrayWeight[16] = { 12, 3, 5, 4, 9, 1, 2, 3, 4, 1, 2, 4, 5, 2, 4, 1 };
	int arrayValue[16] = { 4, 4, 8, 10, 15, 3, 1, 1, 2, 10, 20, 15, 10, 3, 4, 12 };
};

void geneticCross(unsigned short arrayNums[]);

void crossArithmetic(unsigned short arrayNums[]);

void feedbackBag(unsigned short weight, unsigned short currentNumberOfArray, unsigned char value, unsigned char countItems);

void calculatorWeightAndValue(unsigned short number);

void mutation(unsigned short arrayNums[]);

void doubleMutation(unsigned short arrayNums[]);