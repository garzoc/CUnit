#ifndef STUB_H_
#define STUB_H_

	#include "Mock.h"
	
	
	#define test(...)  MOCK(test,__VA_ARGS__) STUB(void,int t)
	
	
	//#define hello(...)  MOCK(hello,__VA_ARGS__) STUB(int t)
#endif
