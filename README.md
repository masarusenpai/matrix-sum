# matrix-sum

Simple program that calculates the sum of all entries of a large matrix. All entries are randomly-generated numbers spanning from 0–99 inclusive — you get to choose the dimensions.

The sum is calculated concurrently, where every row of the matrix spawns a thread which calculates the sum of its respective row. Kind of came up with the idea while reviewing for my COMP2017 finals in USyd. 😅

## Usage
### Compilation
```bash
$ make main   # Quick compilation; includes linking executable main with object file matrix.o.
$ make matrix # Compile libs/matrix.c into an object file matrix.o.
```
### Running + cleaning up
Simply run with `./main <dimensions of matrix>`. To clean all executables / object files, run `make clean`.
