#include <stdio.h>
#include "stub.h"

#include "main.h"



/*

#define MOCK(name,...) MOCK_ ## name (__VA_ARGS__);  void MOCK_ ## name

#define FUN(...) (__VA_ARGS__){printf("Mock\n");}

#define STUB(...) FUN(__VA_ARGS__) void __func__ ## ET_MOCK(__VA_ARGS__)

#define test(...)  MOCK(test,__VA_ARGS__) STUB(int t)
*/



int main (int argc, char *argv[]){
	test(10);
	//run();
	
	//printf(STR(test2(10)));
	//*func = test2;
	return 0;
}


static void loss(){}

