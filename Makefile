CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror 
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
GCC = gcc $(CFLAGS) # $(COVFLAGS) $(PROFFLAG)
OBJS =  pa04.o answer04.o
FUNCS = func1.o func2.o func3.o func4.o func5.o

# This Makefile can be shortened by using loop. 
# It shows all steps to explain what it does

c.o:
	\$(GCC) \$(CFLAGS) -c \$*.c

#Build pa04 using runIntegrate, and all five functions
#Creates 5 different executables, because of the dependences
pa04: pa04.c pa04.h answer04.o pa04-test1 pa04-test2 pa04-test3 pa04-test4 pa04-test5
	$(GCC) -DTEST_INTEGRATE -DRUN_INTEGRATE -lm pa04.c pa04.h answer04.c

#compile answer04
answer04.o: answer04.c pa04.c
	$(GCC) -c -DTEST_INTEGRATE -DRUN_INTEGRATE -lm answer04.c

#compile func1
func1.o: func1.o
	$(GCC) -c func1.c

#compile func2
func2.o: func2.o
	$(GCC) -c func2.c

#compile func3
func3.o: func3.o
	$(GCC) -c func3.c

#compile func4
func4.o: func4.o
	$(GCC) -c func4.c -lm

#compile func5
func5.o: func5.o
	$(GCC) -c func5.c -lm
 


#build each of the executables for integrate
pa04-test1: pa04.o answer04.o  
	$(GCC) -DTEST_INTEGRATE -DRUN_INTEGRATE pa04.c answer04.c -o pa04-test1 -lm

pa04-test2: pa04.o answer04.o
	$(GCC) -DTEST_INTEGRATE -DRUN_INTEGRATE pa04.c answer04.c -o pa04-test2 -lm

pa04-test3: pa04.o answer04.o
	$(GCC) -DTEST_INTEGRATE -DRUN_INTEGRATE pa04.c answer04.c -o pa04-test3 -lm

pa04-test4: pa04.o answer04.o
	$(GCC) -DTEST_INTEGRATE -DRUN_INTEGRATE pa04.c answer04.c -o pa04-test4 -lm

pa04-test5: pa04.o answer04.o
	$(GCC) -DTEST_INTEGRATE -DRUN_INTEGRATE pa04.c answer04.c -o pa04-test5 -lm

# test integrate using five different functions
# each function is tested using three sets of input data
testall: pa04
	echo "testing integrate"
	./pa04 testdir/test1 
	./pa04 testdir/test2
	./pa04 testdir/test3 
	./pa04 testdir/test4 
	./pa04 testdir/test5 

# generate 15 test cases: 5 functions and 3 test cases per function
testgen: testgen.c answer04.c pa04.h | testdir
	$(GCC) -DTEST_INTEGRATE -DRUN_INTEGRATE testgen.c answer04.c func1.c -o testgen
	./testgen test1 -5.0 10.5 100000
	$(GCC) -DTEST_INTEGRATE -RUN_INTEGRATE testgen.c answer04.c func2.c -o testgen
	./testgen test2 -1.0 23.0 10000	
	$(GCC) -DTEST_INTEGRATE -DRUN_INTEGRATE testgen.c answer04.c func3.c -o testgen
	./testgen test3 -5.8 37.9 100000
	$(GCC) -DTEST_INTEGRATE -DRUN_INTEGRATE testgen.c answer04.c func4.c -o testgen
	./testgen test4 8.0 102.5 100000 
	$(GCC) -DTEST_INTEGRATE -DRUN_INTEGRATE testgen.c answer04.c func5.c -o testgen
	./testgen test5 -7.2 91.8 100000
	mv test-func* testdir/

testdir:
	mkdir -p testdir

clean:
	/bin/rm -f input*
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa04 pa04.prof

