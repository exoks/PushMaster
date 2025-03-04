# push_swap #

The push_swap is a 1337 (42 network) project, It is about ***creating an efficient sorting algorithm*** using a limited set of moves.

The challenge is to ***sort a stack of integers*** with the ***fewest*** possible operations, including ***push***, ***swap***, and ***rotate***. This project focuses on **algorithm optimization**, **stack manipulation**, and **solving complex problems** with **limited resources**.

To **improve** and **optimize my algorithm**, I also ***created my own tester*** (*using bash script and C language*), which helps me analyze performance and reduce the number of moves needed for sorting.

## `oezzaou_tester` | Test Your Sorting Algorithm ##
If you want to create your own **sorting algorithm**, `oezzaou_tester` will help you **analyze** and **improve** it. This tool **generates random numbers** and **counts every move** your algorithm makes, helping you understand its efficiency.

1 - Copy `oezzaou_tester` into your push_swap project folder.. 

2 - Add this rule to your Makefile:
```Makefile
test: all 
	@cd oezzaou_tester && ./run.sh -999 999 $(STACK_SIZE) 
```
3 - Run the tester with:
```bash
make test STACK_SIZE=<Integer_value>
```
Example Output:

![Tester](https://github.com/user-attachments/assets/dc8cd64d-32ba-41ec-bbe0-79b0a5d97ab1)

---
