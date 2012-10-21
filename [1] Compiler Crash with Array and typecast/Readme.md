
Typecast and Arrays causes a compiler crash
===========================================

The following code snipplet crashes the compiler. I supspect it's an lexer issue.

  #define uint8_t unsigned char
  #define uint16_t unsigned short
  #define uint32_t unsigned int


  uint8_t doSomething(uint8_t* bytes, uint16_t len)
  {
    return (((uint8_t*)bytes)[len]);
  }


Just a bongous array access some like bytes[len] where *above* the code. It 
can be anywhere even within an other function. Out of the sudden it will work 
as expected: 

  #define uint8_t unsigned char
  #define uint16_t unsigned short
  #define uint32_t unsigned int

  uint8_t doSomething2(uint8_t* bytes, uint16_t len)
  {
    return bytes[len];
  }
  

  uint8_t doSomething(uint8_t* bytes, uint16_t len)
  {
    len = len +1 ;
    return (((uint8_t*)bytes)[len]);
  }
  
The really odd thing is when you rearange the code so that the newly added
array call is *below* it crashes again...   

  #define uint8_t unsigned char
  #define uint16_t unsigned short
  #define uint32_t unsigned int  

  uint8_t doSomething(uint8_t* bytes, uint16_t len)
  {
    return (((uint8_t*)bytes)[len]);
  }
  
  uint8_t doSomething2(uint8_t* bytes, uint16_t len)
  {
    return bytes[len];
  }

