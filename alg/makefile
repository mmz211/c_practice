
cc = g++
prom = test 
deps = $(shell find ./ -name "*.h")
src = $(shell find ./ -name "*.c" )
obj = $(src:%.c=%.o) 

$(prom): $(obj)
	$(cc) -g -o $(prom) $(obj)

%.o: %.c $(deps)
	$(cc) -g -c $< -o $@

clean:
	rm -rf $(obj) $(prom)

#test: test.cpp
	#gcc -o test.exe test.cpp

