# matrix-sum

Simple program that calculates the sum of all entries of a large square matrix. All entries are randomly-generated numbers spanning from 0–99 inclusive — you get to choose the dimension.

The sum is calculated concurrently, where a thread is spawned for every row to calculate the (partial) sum of that row. Kind of came up with the idea while reviewing for my COMP2017 finals in USyd. 😅

## Usage
### Compilation
```bash
$ make main   # Quick compilation; includes linking executable main with object file matrix.o.
$ make matrix # Compile libs/matrix.c into an object file matrix.o.
```
### Running + cleaning up
Simply run with `./main <dimensions of matrix>`. To clean all executables / object files, run `make clean`.
