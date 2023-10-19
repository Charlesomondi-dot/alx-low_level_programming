#include <stdio.h>

int main(){ 
	// Inline assembly to call printf with the message "Hello, Holberton\n"
	asm("mov $1, %%rax\n"   // RAX = 1 (syscall number for write)
		"mov $1, %%rdi\n"   // RDI = 1 (file descriptor for stdout)
		"mov $hello, %%rsi\n" // RSI = address of the hello string
		"mov $16, %%rdx\n"   // RDX = length of the hello string
		"syscall"            // Invoke syscall to write to stdout
		:
		: "r"(hello)         // Input operand: address of hello string
		: "%rax", "%rdi", "%rsi", "%rdx"  // Clobbered registers
	);

	        return 0;
}

