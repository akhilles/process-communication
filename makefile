all:
	gcc -o p1.sh problem_1.c
	gcc -o p2.sh problem_2.c
	gcc -o p3.sh problem_3.c
	gcc -o p4.sh problem_4.c

clean:
	rm -f *.sh
	rm -f *.txt
