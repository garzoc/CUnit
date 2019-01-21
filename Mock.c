#include "Mock.h"
//Obsolete

int supress(void* a,void* b){
	_Pragma("GCC diagnostic ignored \"-Wpointer-to-int-cast\"");
	return 1;
}

int unsupress(void* a,void* b){
	_Pragma("GCC diagnostic pop");
	return 1;
	
}
