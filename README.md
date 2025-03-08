# PushMaster #

The pushMaster (push_master) is a 1337 (42 network) project, It is about ***creating an efficient sorting algorithm*** using a limited set of instructions.

The challenge is to ***sort a stack of integers*** with the ***fewest*** possible operations, including ***push***, ***swap***, and ***rotate***. This project focuses on **algorithm optimization**, **stack manipulation**, and **solving complex problems** with **limited resources**.

To **improve** and **optimize my algorithm**, I also **created my own tester | `oezzaou_tester`** (*using bash script and C language*), which helps me analyze performance and reduce the number of moves needed for sorting.

* Test my pushMaster
``` bash
./pushMaster nbr1 nbr2 ... nbrN
```
- It prints the instructions used to sort a stack of {nbr1, nbr2, …, nbrN}.

**Example Output**:

[<img width="1000" alt="Image" src="https://github.com/user-attachments/assets/364d2474-6e2c-4de1-b35d-38fff4d2faa7"/> ]()

## `oezzaou_tester` | Test Your Sorting Algorithm ##
If you want to create your own **sorting algorithm**, `oezzaou_tester` will help you **analyze** and **improve** it. This tool **generates random numbers** and **counts every move** your algorithm makes, helping you understand its efficiency.

1 - Copy `oezzaou_tester` into your pushMaster project folder.. 

2 - Add this rule to your Makefile:
```Makefile
test: all 
	@cd oezzaou_tester && ./run.sh -999 999 $(STACK_SIZE) 
```
3 - Run the tester with:
```bash
make test STACK_SIZE=<Integer_Value>
```
Example Output:

![Tester](https://github.com/user-attachments/assets/dc8cd64d-32ba-41ec-bbe0-79b0a5d97ab1)

---
