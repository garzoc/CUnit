#include "stub.h"
//#include "test.c"
//#include "start.c"
//#include "test.h"

#include <stdio.h>



#include "main.h"//Must inlcude the header containg the fuctions to be stubbed
//If functions is defined in a c file, include that C file

inline void MOCK_test(int t){
	printf("Mock: %s\n",__func__);
	
	/*range test1 = 100;
	printf("Test 1.1 %i\n",MATCH(test1,100));
	printf("Test 1.2 %i\n",MATCH(test1,50));
	
	
	range test2 = RANGE(10,16);
	printf("Test 2.1 %i\n",MATCH(test2,16));
	printf("Test 2.2 %i\n",MATCH(test2,17));
	printf("Test 2.3 %i\n",MATCH(test2,10));
	printf("Test 2.4 %i\n",MATCH(test2,9));	
	
	range test3 = ANY;
	printf("Test 3.1 %i\n",MATCH(test3,102));
	printf("Test 3.2 %i\n",MATCH(test3,0));
	
	
	printf("Test 4.1 %i\n",MATCH("Hello","Hello"));
	printf("Test 4.2 %i\n",MATCH("WORLD","WORLDO"));
	
	range n = 2;
	printf("My Test %i\n",UINT_COMP(n));*/


	range result;
	IF_MATCH(100,100){
		printf("Test 1.1 %i\n");
	}
	

	IF_MATCH(RANGE(10,16),14){
		printf("Test 2.1 %i\n");
	}

	IF_MATCH(ANY,15){
		printf("Test 3.1 %i\n");
	}
	
	IF_MATCH("Hello","Hello"){
		printf("Test 3.1 %i\n");
	}
	
	

	
	
	
	
};


inline void MOCK_hello(int t){
	printf("Mock: %s\n",__func__);
};
