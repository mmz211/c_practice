
cc = gcc
prom = test 
deps = $(shell find ./ -name "*.h")
src = $(shell find ./ -name "*.c" )
obj = $(src:%.c=%.o) 

inc = ../alg/

$(prom): $(obj)
	$(cc) -g -o $(prom) $(obj)

#include tools.h in other folder
%.o: %.c $(deps) $(inc)/*.h
	$(cc) -g -I$(inc) -c $< -o $@

clean:
	rm -rf $(obj) $(prom)

#test: test.cpp
	#gcc -o test.exe test.cpp

