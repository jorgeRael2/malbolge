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

//Malbolge's virtual machine words have 10 ternary digits
typedef struct{
	ternaryDigit digit[10];
} malbolgeWord;

typedef struct{
	malbolgeWord word[59049];
} malbolgeMemory;

int main(){
	return 0;
}
