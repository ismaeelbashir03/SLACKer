# SLACKer Runtime Library

This is a slacker-friendly runtime library for c that allows programmers to use llms even inside their code!

## Usage

An example of how to use the runtime library is provided in the `example` directory. To compile the example, run the following command:
```bash
make && ./example
```

To use the runtime library in your own c code, add the SLACKer folder to your include path and link against the runtime library (see example in example/Makefile).

Then include the following header file in your code (you will get a warning that its not being used, but that's fine):
```c
#include "slacker_runtime.h"
```

Then, you can use the following functions to interact with the slacker runtime:

### `malloc` - no need to worry about the size of the data type!
```c
int ptr = malloc("size of an integer");
```

### `printf` - no need to worry about writing nice messages to the console!
```c
printf("write a knock knock joke for the user");
```

### `condition` - no need to worry about evaluating conditions!
```c
condition("is 2+2 equal to 4???");
```

## Optimisations
You can delete this runtime library, since its calling an llm every time you evaluate a condition, print or allocate memory. This is a very inefficient way to write code, but it is slacker-friendly!

(could do batch calls of the llm at compile time, but that would require effort)