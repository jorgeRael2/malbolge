//Developer: Jorge Rael Fortes de Faria Lopes

//This is a malbolge interpreter.
//This should work with files.
//The source code should be stored in a file.
//The input should be stored in a file.
//The source code should have the name "code.mal"
//The input should have the name "input.bin"
//This program should work as same as original.
//This source code should be easier to understand

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//This is a ternary digit
//Ternary digits can only be 0, 1 or 2
typedef struct{
	uint8_t value;
} ternaryDigit;

//Malbolge's virtual machine words has 10 ternary digits
typedef struct{
	ternaryDigit digit[10];
} malbolgeWord;

//Malbolge's virtual machine has 59049 words
typedef struct{
	malbolgeWord word[59049];
} malbolgeMemory;

//The virtual machine has 3 registers
typedef struct{
	malbolgeMemory memory;
	malbolgeWord a;
	malbolgeWord c;
	malbolgeWord d;
} malbolgeVirtualMachine;

ternaryDigit initTernaryDigit(){
	ternaryDigit digit;
	digit.value = 0;
	return digit;	
}

malbolgeWord initMalbolgeWord(){
	malbolgeWord word;
	int i;
	for(i = 0; i < 10; i++){
		word.digit[i] = initTernaryDigit();
	}
	return word;
}

malbolgeMemory initMalbolgeMemory(){
	malbolgeMemory memory;
	int i;
	for(i = 0; i < 59049; i++){
		memory.word[i] = initMalbolgeWord();
	}
	return memory;
}

malbolgeVirtualMachine initMalbolgeVirtualMachine(){
	malbolgeVirtualMachine machine;
	machine.memory = initMalbolgeMemory();
	machine.a = initMalbolgeWord();
	machine.c = initMalbolgeWord();
	machine.d = initMalbolgeWord();
	return machine;
}

ternaryDigit crazyOperation(ternaryDigit digit1, ternaryDigit digit2){
	ternaryDigit digit;
	uint8_t table[3][3] = {
	{1, 0, 0},
	{1, 0, 2},
	{2, 2, 1}
	};
	digit.value = table[digit1.value][digit2.value];
	return digit;
}

malbolgeWord crazyOperationWord(malbolgeWord word1, malbolgeWord word2){
	malbolgeWord word;
	int i;
	for(i = 0; i < 10; i++){
		word.digit[i] = crazyOperation(word1.digit[i], word2.digit[i]);
	}
	return word;
}

uint8_t xlat1(uint8_t number){
	if(94 <= number){
		printf("Error:\n");
		printf("Big number (%u) in xlat1.\n", number);
		printf("xlat1 can only hold values from 0 to 93");
		exit(1);
	}
	uint8_t table[94] = {43, 98, 40, 50, 57, 101, 42, 106, 49, 86, 77, 69, 75,
	76, 121, 67, 125, 41, 56, 38, 109, 35, 126, 87, 62, 113, 120, 100, 82, 112,
	48, 119, 107, 114, 85, 111, 91, 68, 55, 44, 88, 84, 99, 65, 34, 108, 73,
	46, 118, 37, 123, 103, 74, 104, 52, 71, 92, 45, 61, 79, 64, 53, 96, 95, 51,
	105, 60, 63, 90, 39, 59, 70, 78, 81, 117, 89, 93, 115, 122, 102, 36, 33,
	66, 83, 47, 124, 116, 58, 80, 110, 54, 94, 72, 97
	};
	return table[number];
}

uint8_t inverseXlat1(uint8_t number){
	if(number < 33 || 126 < number){
		printf("Error:\n");
		printf("Number (%u) is not allowed in inverseXlat1.\n", number);
		printf("xlat1 can only hold values from 33 to 126");
		exit(1);
	}
	uint8_t table[94] = {81, 44, 21, 80, 49, 19, 69, 2, 17, 6, 0, 39, 57, 47,
	84, 30, 8, 3, 64, 54, 61, 90, 38, 18, 4, 87, 70, 66, 58, 24, 67, 60, 43,
	82, 15, 37, 11, 71, 55, 92, 46, 52, 12, 13, 10, 72, 59, 88, 73, 28, 83, 41,
	34, 9, 23, 40, 75, 68, 36, 56, 76, 91, 63, 62, 93, 1, 42, 27, 5, 79, 51,
	53, 65, 7, 32, 45, 20, 89, 35, 29, 25, 33, 77, 86, 74, 48, 31, 26, 14, 78,
	50, 85, 16, 22
	};
	return table[number - 33];
}

malbolgeWord uint8ToMalbolgeWord(uint8_t number){
	int i;
	malbolgeWord word;
	for(i = 0; i < 10; i++){
		word.digit[i].value = number % 3;
		number /= 3;
	}
	return word;
}

malbolgeWord uint16ToMalbolgeWord(uint16_t number){
	if(59049 <= number){
		printf("Error:\n");
		printf("Big number (%u) in malbolge word.\n", number);
		printf("A malbolge word can only hold values from 0 to 59048.");
		exit(1);
	}
	int i;
	malbolgeWord word;
	for(i = 0; i < 10; i++){
		word.digit[i].value = number % 3;
		number /= 3;
	}
	return word;
}

void printMalbolgeWord(malbolgeWord word){
	int i;
	for(i = 9; 0 <= i; i--){
		printf("%u", word.digit[i].value);
	}
}

int main(){
	uint8_t i;
	for(i = 0; i < 94; i++){
		if(i != inverseXlat1(xlat1(i))){
			exit(1);
		}
	}
	return 0;
}
