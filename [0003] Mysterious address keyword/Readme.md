# Mysterious address keyword

The following code snipplet does not compile. The error message is 
`"(error) C1000 syntax error, unexpected TYPE_NAME, expecting ')'"`

```C
unsigned char doSomething(unsigned char* address)
{
  return address;
}
```

It reads as if the parameter name `address` is already defined, but it is 
obiously not. It also can't be defined in other files as it's a compiler and 
not a linker error message. Very strange...

So somehow `address` is somekind of a reserved and undocumented keyword. 

## Workaround

Just rename `address` to something else like `addr` and the code will compile
without any error messages.

```C
unsigned char doSomething(unsigned char* addr)
{
  return addr;
}
```

