//Developer: Jorge Rael Fortes de Faria Lopes

//This is a malbolge interpreter.
//This will work with files.
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
	malbolgeWord v0 = uint16ToMalbolgeWord(59048);
	printMalbolgeWord(v0);
	return 0;
}
