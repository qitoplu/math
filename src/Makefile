FLAGS= -lm -lsubunit -lcheck -lpthread 
CC=gcc -Wall -Wextra -Werror -std=c11
OS=MAC
FUNC_FILES_C= s21_math/*.c
FUNC_FILES_O= *.o
UNAME_S := $(shell uname -s)
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBNAME=s21_math.a
GLFLAGS=--coverage
sourceFilesArray=$(ls sourceFiles)

EXECS=./s21_test_abs ./s21_test_fabs ./s21_test_fmod ./s21_test_sin ./s21_test_cos ./s21_test_tan ./s21_test_acos ./s21_test_asin ./s21_test_atan ./s21_test_ceil ./s21_test_floor ./s21_test_exp ./s21_test_pow ./s21_test_sqrt

ifeq ($(UNAME_S),Linux)
	CHECKFLAGS= -lcheck
	OPEN_CMD = open
	ADD_LIB = -lcheck -lm -lpthread -lrt -lsubunit
	OS = LINUX
endif
 
ifeq ($(UNAME_S),Darwin)
	CHECKFLAGS= $(shell pkg-config --cflags --libs check)
	OPEN_CMD = open
endif
 
 
install:
	if [ $(OS) = "LINUX" ]; then \
		sudo apt-get install -y lcov; \
		sudo apt-get install -y check; \
		sudo apt-get install -y libcapture-tiny-perl; \
		sudo apt-get install -y libdatetime-perl; \
	else \
		brew install lcov; \
	fi
 
all: s21_math.a
 
peer: gcov_report
 
 
build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C)
 
build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)
 
s21_math.a:
	$(CC) $(FLAGS) -c $(FUNC_FILES_C)
	make build_library
	rm -rf *.o
 
test: s21_math.a
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_abs_test.c -L. s21_math.a  -o s21_test_abs -lcheck $(ADD_LIB)
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_pow_test.c -L. s21_math.a  -o s21_test_pow -lcheck $(ADD_LIB)
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_fabs_test.c -L. s21_math.a  -o s21_test_fabs -lcheck $(ADD_LIB)
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_fmod_test.c -L. s21_math.a  -o s21_test_fmod -lcheck $(ADD_LIB)
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_sin_test.c -L. s21_math.a  -o s21_test_sin -lcheck $(ADD_LIB)
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_cos_test.c -L. s21_math.a  -o s21_test_cos -lcheck $(ADD_LIB)
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_tan_test.c -L. s21_math.a  -o s21_test_tan -lcheck $(ADD_LIB)
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_acos_test.c -L. s21_math.a  -o s21_test_acos -lcheck $(ADD_LIB)
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_asin_test.c -L. s21_math.a  -o s21_test_asin -lcheck $(ADD_LIB)
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_atan_test.c -L. s21_math.a  -o s21_test_atan -lcheck $(ADD_LIB)
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_ceil_test.c -L. s21_math.a  -o s21_test_ceil -lcheck $(ADD_LIB)
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_exp_test.c -L. s21_math.a  -o s21_test_exp -lcheck $(ADD_LIB)
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_floor_test.c -L. s21_math.a  -o s21_test_floor -lcheck $(ADD_LIB)
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_log_test.c -L. s21_math.a  -o s21_test_log -lcheck $(ADD_LIB)
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test/s21_sqrt_test.c -L. s21_math.a  -o s21_test_sqrt -lcheck $(ADD_LIB)
	make start_tests
 
start_tests:
	# valgrind --tool=memcheck -q --leak-check=yes ./s21_test_abs
	# valgrind --tool=memcheck -q --leak-check=yes ./s21_test_fabs
	# valgrind --tool=memcheck -q --leak-check=yes ./s21_test_fmod
	# valgrind --tool=memcheck -q --leak-check=yes ./s21_test_sin
	# valgrind --tool=memcheck -q --leak-check=yes ./s21_test_cos
	# valgrind --tool=memcheck -q --leak-check=yes ./s21_test_tan
	# valgrind --tool=memcheck -q --leak-check=yes ./s21_test_acos
	# valgrind --tool=memcheck -q --leak-check=yes ./s21_test_asin
	# valgrind --tool=memcheck -q --leak-check=yes ./s21_test_atan
	# valgrind --tool=memcheck -q --leak-check=yes ./s21_test_ceil
	# valgrind --tool=memcheck -q --leak-check=yes ./s21_test_floor
	# valgrind --tool=memcheck -q --leak-check=yes ./s21_test_exp
	# valgrind --tool=memcheck -q --leak-check=yes ./s21_test_pow
	# valgrind --tool=memcheck -q --leak-check=yes ./s21_test_sqrt
	./s21_test_abs
	./s21_test_fabs
	./s21_test_fmod
	./s21_test_sin
	./s21_test_cos
	./s21_test_tan
	./s21_test_acos
	./s21_test_asin
	./s21_test_atan
	./s21_test_ceil
	./s21_test_floor
	./s21_test_exp
	./s21_test_pow
	./s21_test_sqrt
 
 
gcov_report: install clean build_object_files build_library test
	lcov -o tests.info -c -d .  
	genhtml -o report tests.info
	$(OPEN_CMD) report/index.html
	make clean
 
 
clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.a
	rm -rf *.info
	rm -rf $(EXECS)
 
rebuild:
	make clean
	make
 
