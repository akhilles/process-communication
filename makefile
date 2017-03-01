all:
	gcc -o p2.sh problem_2.c
	gcc -o p3.sh problem_3.c
	gcc -o p4.sh problem_4.c

clean:
	rm *.sh
	rm output.txt