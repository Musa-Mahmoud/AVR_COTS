#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR, BIT_NO)    (VAR |=  (1 << BIT_NO))
#define CLR_BIT(VAR, BIT_NO)    (VAR &= ~(1 << BIT_NO))
#define TOGGLE_BIT(VAR, BIT_NO) (VAR ^=  (1 << BIT_NO))
#define GET_BIT(VAR, BIT_NO)    ((VAR >> BIT_NO) & 0x01)


#endif

/*

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(variable, bit)	 variable =  variable  |  (1 << bit)
#define CLR_BIT(variable, bit)	 variable =  variable  & ~(1 << bit)
#define TGL_BIT(variable, bit)	 variable =  variable  ^  (1 << bit)
#define GET_BIT(variable, bit)	((variable >> bit)     &   1 )

#endif
*/
