# Typecast and Arrays causes a compiler crash

The following code snipplet crashes the compiler. 

```C
unsigned char doSomething(unsigned char* bytes, unsigned short len)
{
  return (((unsigned char*)bytes)[len]);
}
```
## Workaround

Just a bongous array access some like `bytes[len]` where **above** the code. It 
can be anywhere even within an other function. Out of the sudden it will work 
as expected: 

```C
unsigned char doSomething(unsigned char* bytes, unsigned short len)
{
  bytes[len];
  return (((unsigned char*)bytes)[len]);
}
```
To make things even more odd the following code prevents the compiler crash too.

```C
unsigned char doSomething2(unsigned char* bytes, unsigned short len)
{
  bytes[len];
}

unsigned char doSomething(unsigned char* bytes, unsigned short len)
{
  return (((unsigned char*)bytes)[len]);
}
```

But when you rearange the code so that the newly added call is **below** it crashes again...   

```C
unsigned char doSomething(unsigned char* bytes, unsigned short len)
{
  return (((unsigned char*)bytes)[len]);
}

unsigned char doSomething2(unsigned char* bytes, unsigned short len)
{
  bytes[len];
}
```
