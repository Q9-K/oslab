.PHONY: clean

out: calc case_all
	./calc < case_all > out

# Your code here.
# 
calc: calc.c 
	gcc calc.c -o calc
case_add: casegen.c
	gcc casegen.c -o case_add

case_sub: casegen.c
	gcc casegem.c -o case_sub

case_mul: casegen.c
	gcc casegem.c -o case_mul

case_div: casegen.c
	gcc casegem.c -o case_div

case_all: casegen.c
	cat case_add case_sub case_mul case_div >> case_all
clean:
	rm -f out calc casegen case_*
