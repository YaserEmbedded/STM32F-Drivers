#ifndef _H_TYPES_                  
#define _H_TYPES_                  
typedef unsigned char u8;          
typedef signed char s8;            
typedef unsigned short u16;        
typedef signed short s16;          
typedef unsigned long  u32;        
typedef signed long   s32;         
typedef unsigned long   u64;       
typedef signed long   s64;         
typedef float f32;                 
typedef double f64;


/*****************util*********************/
#define GET_BIT(Reg , bit)           (Reg & ((u32)1<<bit))>> bit
#define CLR_BIT(Reg , bit )           Reg &=~((u32)1<<bit)             // need it more optimized
#define SET_BIT(Reg , bit )           Reg |=((u32)1<<bit)
#define TOGGLE_BIT(Reg , bit )        Reg ^=((u32)1<<bit)
#define SET_REG(Reg)                  Reg =0xff
#define CLR_REG(Reg)                  Reg =0x00
#define TOGGLE_REG(Reg)               Reg ^=0xff
#define ASSIGN_REG(Reg,value)         Reg = value
#define GET_LOW_NIB(Reg)              Reg & 0x0f
#define CLR_LOW_NIB(Reg)              Reg &=0xf0;
#define SET_LOW_NIB(Reg)              Reg |=0x0f;
#define TOGGLE_LOW_NIB(Reg)           Reg ^= 0x0f
#define ASSIGN_LOW_NIB(Reg,value)     Reg= ((Reg &0xf0)|(value & 0x0f))    // need it more optimized
#define GET_HIGH_NIB(Reg)            ((Reg & 0xf0) >> 4 )
#define CLR_HIGH_NIB(Reg)             Reg &= 0x0f
#define SET_HIGH_NIB(Reg)             Reg |= 0xf0
#define TOGGLE_HIGH_NIB(Reg)          Reg ^= 0xf0
#define ASSIGN_HIGH_NIB(Reg,value)    Reg= ((Reg &0x0f)|( value << 4))
/********************************status**************************/

#define u8ERROR 0    // in types.h to be seen through all components as type
#define u8OK 1       //without DIO only U8

#endif                             
