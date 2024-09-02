//Developer: Jorge Rael Fortes de Faria Lopes

//This is a malbolge interpreter.
//This will work with files.
//The source code should be stored in a file.
//The input should be stored in a file.
//The source code should have the name "code.mal"
//The input should have the name "input.bin"
//This program should work as same as original.
//This source code should be easier to understand

#include <stdio.h>
#include <stdint.h>

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
	unsigned int i;
	for(i = 0; i < 10; i++){
		word.digit[i] = initTernaryDigit();
	}
	return word;
}

malbolgeMemory initMalbolgeMemory(){
	malbolgeMemory memory;
	unsigned int i;
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

int main(){
	malbolgeVirtualMachine machine = initMalbolgeVirtualMachine();
	FILE *codeFile = fopen("code.mal", "rb");
	fclose(codeFile);
	return 0;
}
