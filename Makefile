CC := gcc
MN := main
MT := matrix
LIBS := libs/${MT}.c libs/${MT}.h

${MN}: source/${MN}.c ${MT}.o
	@echo -n "Compiling main.c into executable 'main': "
	${CC} source/${MN}.c ${MT}.o -o ${MN}
	@echo
	@echo "All programs successfully compiled. Run with './main <dimension>'."

${MT}.o: ${LIBS}
	@echo -n "Compiling matrix.c into object file 'matrix.o': "
	${CC} -c libs/${MT}.c -o ${MT}.o

clean:
	@if [ -e ${MN} ] ; then echo "'main' executable found. Removing..." ; rm ${MN} ; fi
	@if [ -e ${MT}.o ] ; then echo "'matrix.o' object file found. Removing..." ; rm ${MT}.o ; fi
	@echo "All executable / object files removed."
