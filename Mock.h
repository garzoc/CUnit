#ifndef MOCK_DEFINITIONS_H_
#define MOCK_DEFINITIONS_H_
	

	#include <string.h>
	#include "types_comp.h"
	
	#define MOCK(Name,...) MOCK_ ## Name(__VA_ARGS__);
	#define STUB(Type,...) Type ET_MOCK ## __func__ (__VA_ARGS__)
	

	
	
	#define IF(statement) (statement) ?
	#define ELSE :
	
	typedef unsigned int range;
	#define ANY ((0x01 << SHIFT_FL(range)))
	#define SHIFT_FL(x) (sizeof(x) * 8 -1) //Param is used to get the size of the var
	#define MAX_B(val) ((SHIFT_FL(val) -1 )/2)
	
	//IF the most significant bit is set
	#define MSIG_BIT(val) (val & ((range)0x01 << SHIFT_FL(val)))
	//IF Next significant bit is set
	#define NSIG_BIT(val) (val & ((range)0x01 << (SHIFT_FL(val) -1) ))
	
	//Bit flipping and shiffing right only works properly with unsigned
	#define RANGE_START(r) (r & (((~(range) 0) >> 2) >> MAX_B(r)))
	#define RANGE_END(r) (RANGE_START(r >> MAX_B(r)) + RANGE_START(r))
	#define RANGE(start,offset)\
						IF((start) < (0x01 << MAX_B(start)) && (offset-start) < (0x01 << MAX_B(offset)))\
/*Enable special mode*/		ANY |																		\
/*Set it to range */		(0x01 << (SHIFT_FL(start) -1)) |											\
/*Set the lower value*/		start |																		\
/*Set the upper bound*/		((offset-start) << MAX_B(offset)) ELSE -1
									
									
	
	
	#define MATCH_RANGE(a,b) 													\
	/*If in special mode*/	IF(MSIG_BIT(a) != 0) 								\
	/*If in range mode*/		IF(NSIG_BIT(a) != 0)							\
	/*Within range?*/				b >= RANGE_START(a) && b <= RANGE_END(a) 	\
	/*Any value acceptable*/ 	ELSE 											\
	/*Always return true*/			1											\
							 ELSE	 											\
								a==b

	#define MATCH_STR(a,b) strcmp(a,b) == 0 ? 1:0
	#define MATCH_DEF(a,b) a == b
	
	
	/*#define Safe_cast(x) \
			(_Generic((x),\
				range 	: x,		\
				char* 	: x,	\
				int		: x		\
			))
			
	*/		
			
	#define MATCH(x,y) \
			(_Generic((x),\
				range 	: UINT_COMP(y) || INT_COMP(y) ? (MATCH_RANGE((range)x,(range)y)) : 0,	\
				char* 	: INT_PTR_COMP(y) ? (MATCH_STR((char*)x,(char*)y)): 0,					\
				default : (MATCH_DEF(x,y)) 														\
			))
		
	
	
	
	
	#if defined(__GNUC__) || defined(__GNUG__)
		#define Pragma_SUPRESSION() _Pragma("GCC diagnostic push")								\
									_Pragma("GCC diagnostic ignored \"-Wpointer-to-int-cast\"")	\
									_Pragma("GCC diagnostic ignored \"-Wint-to-pointer-cast\"")	\
									_Pragma("GCC diagnostic ignored \"-Wint-conversion\"")	\
									_Pragma("GCC diagnostic ignored \"-Wnonnull\"")

		#define Pragma_UnSupress() _Pragma("GCC diagnostic pop")
	#elif defined (__clang__)
		#define Pragma_SUPRESSION() _Pragma("clang diagnostic push")								\
									_Pragma("clang diagnostic ignored \"-Wpointer-to-int-cast\"")	\
									_Pragma("clang diagnostic ignored \"-Wint-to-pointer-cast\"")	\
									_Pragma("clang diagnostic ignored \"-Wnonnull\"")				\
		#define Pragma_UnSupress() _Pragma("clang diagnostic pop")
		
	#endif

	#define IF_MATCH(x,y)						\
		Pragma_SUPRESSION()								\
		if((_Generic((x),						\
			range : (MATCH_RANGE((range)x,(range)y)),	\
			char* : MATCH_STR((char*)x,(char*)y),		\
			default : MATCH_DEF(x,y) )))				\
			Pragma_UnSupress()
	
	
	
	/*//Only properly works in clang, although you're redefine a new variable each time for the results	
	#define MATCH_CLANG(x,y) {\
			result = (_Generic((x),\
			range : (MATCH_RANGE((range)x,(range)y)),	\
			char* : (MATCH_STR((char*)x,(char*)y)),	\
			default : MATCH_DEF(x,y) ))			\
		}
	
	//#pragma GCC diagnostic pop
	//#pragma clang diagnostic pop*/

#endif
