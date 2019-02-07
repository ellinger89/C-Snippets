#include <iostream>

// THE REASUON FOR THE CONFUSION WITH CONST CHAR *:
	// the reason lies actually not - as i suspected - in some missunderstanding with the const char * -type itself
	// (it does indeed just store the memoryadress of the first character in the constchararray)
	// instead the confusing part is a property of the std::cout function. this function
	// recognises the const char * and treats it specially. instead of printing the actuall memoryadress
	// as i had suspected, it prints the values of all the memorieadresses (of the first and the proceeding 
	// characters in the const char array) in a row untill it hits the null-termination character.
	// --> therfore: the actual value of argv[1] is indeed a const cha *! to use it in something
	// like if(argv[1]=="y") it must be dereferenced!

	// using 'argv[1] of type const char *' as an if-switch (raw c++)
if (argc > 1) {
	// all elements of const char argv** are pointers, so they must be 
	// assigned to a char* or a const char*
	const char* firstArg_ptr = argv[1];
	// this firstArg_ptr can then be derefferecend, and its value can be 
	// assigned to a const char
	const char firstArg = *firstArg_ptr;
	std::cout << "firstArg: " << firstArg << std::endl;
	//if the value of a const char variable is compared with a "sourcecode-string",
	// the sourcecode-string must also be dereferenced first, since something like
	// "mystring" in the sourcecode is actually a const char pointer to the first
	// character, in this case the memoryie-adress of this particular "m"
	if (firstArg == *"y") {
		std::cout << firstArg << " = y" << std::endl;
	}
}