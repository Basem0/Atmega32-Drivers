#ifndef STD_UTILS_H_
#define STD_UTILS_H_

// ************************* BIT OPERATION ***************************
#define	GET_BIT(REG, BIT)			((REG >> BIT) & 1)
#define SET_BIT(REG, BIT)			(REG |= (0x1 << BIT))
#define CLR_BIT(REG, BIT)			(REG &= ~(0x1 << BIT))
#define TOGGLE_BIT(REG, BIT)		(REG ^= (1 << BIT))
// *******************************************************************

// ************************* REG OPERATION ***************************
#define	GET_REG(REG)				(REG)
#define SET_REG(REG)				(REG = 0XFF)
#define CLR_REG(REG)				(REG = 0X00)
#define TOGGLE_REG(REG)				(REG ^= 0xFF)
#define ASSIGN_REG(REG, VALUE)		(REG = VALUE)
// *******************************************************************

// ************************ NIBBLE OPERATION *************************
#define	GET_LOW_NIB(REG)			(REG & 0X0F)
#define SET_LOW_NIB(REG)			(REG |= 0X0F)
#define CLR_LOW_NIB(REG)			(REG &= 0XF0)    // Changed here
#define TOGGLE_LOW_NIB(REG)			(REG ^= 0X0F)
#define ASSIGN_LOW_NIB(REG, VALUE)	(REG = ((REG & 0XF0) | (VALUE & 0x0F)))

#define	GET_HIGH_NIB(REG)			((REG & 0XF0) >> 4)
#define SET_HIGH_NIB(REG)			(REG |= 0XF0)
#define CLR_HIGH_NIB(REG)			(REG &= 0X0F)    // Changed here
#define TOGGLE_HIGH_NIB(REG)		(REG ^= 0XF0)
#define ASSIGN_HIGH_NIB(REG, VALUE)	(REG = ((VALUE << 4) | (REG & 0X0F)))
// *******************************************************************

#endif /* STD_UTILS_H_ */
