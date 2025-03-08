# PushMaster #

The PushMaster is a 1337 (42 network) project, It is about ***creating an efficient sorting algorithm*** using a limited set of instructions.

The challenge is to ***sort a stack of integers*** with the ***fewest*** possible operations, including ***push***, ***swap***, and ***rotate***. This project focuses on **algorithm optimization**, **stack manipulation**, and **solving complex problems** with **limited resources**.

To **improve** and **optimize my algorithm**, I also **created my own tester | `oezzaou_tester`** (*using bash script and C language*), which helps me analyze performance and reduce the number of moves needed for sorting.

### Building the Project ###
1. Clone **PushMaster** repository: 
```bash
git clone https://github.com/exoks/PushMaster.git
cd PushMaster
```

2. Compile the **PushMaster** :
```bash
make
```
3. Run `push_swap`:
``` bash
./push_swap nbr1 nbr2 ... nbrN
```
- It prints the instructions used to sort a stack of {nbr1, nbr2, …, nbrN}.

### **Cleanup** ###
* Remove object files:
```sh
make clean
```

* Remove all binaries and object files:
```sh
make fclean
```

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
