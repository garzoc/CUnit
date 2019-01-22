#ifndef TYPE_COMP_H_
#define TYPE_COMP_H_
	
	#define INT_TYPES(px,sx)  px long long sx: 1, px long sx : 1,	\
							  px short int sx: 1, px int sx : 1 ,	\
							  px char sx: 1,
							  
	
	//short is reduntant due to other types Note(at least in Clang and GCC)						  
	#define UINT_TYPES(sx) INT_TYPES(unsigned,sx) //short sx: 1,
	
	
	//Void * ?
	#define INT_PTR_TYPES() INT_TYPES(,*)  void *: 1,
	
	#define UINT_PTR_TYPES() UINT_TYPES(*) void *: 1, //short sx: 1,
	
							  


	#define INT_COMP(x)\
				(_Generic((x),\
					INT_TYPES(,)	\
					default: 0		\
				))
				
				
	#define UINT_COMP(x)\
				(_Generic((x),\
					UINT_TYPES()	\
					default: 0		\
				))
				
	#define INT_PTR_COMP(x)\
				(_Generic((x),\
					INT_PTR_TYPES()	\
					default: 0		\
				))
	
	#define UINT_PTR_COMP(x)\
				(_Generic((x),\
					UINT_PTR_TYPES()	\
					default: 0		\
				))
	

	




#endif
