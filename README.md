# Corewar

Corewar is a UNIT Factory project. The purpose of this project is an implementation of the programming game **“Core War”**.

## Project Structure

This project consists of five parts:

* Champion
* Assembler
* Disassembler (Bonus)
* Virtual Machine
* Visualizer (Bonus)

Virtual Machine + Visualizer are modules of the program `corewar`.

## Usage

### `asm`

```
Usage:	./asm [-hmlcind] champion[.s or .cor]
	-h see the usage
	-m turn on musical accompaniment
	-l show leaks
	-c enable colors
	-i a new file is created in the current directory
	-n show the number of line where the error occurred
	-d disassembler
```

### `corewar`

```
Usage:	./coreawar [-hmlcv] [-dump[64|32] N] [-s N] [-n N] <champ1.cor> [-n N] <champ2.cor> ...
	-h	: see the usage
	-m	: turn on musical accompaniment
	-l	: show leaks
	-c	: enable colors
	-v	: enable visualization
	-dump N	: dumps memory after N cycles then exits (64 or 32 octets per line)
	-n N	: set number of player(champ) to N
	-s N	: show verbosity levels, can be added together to enable several

		- 0	: show only essentials
		- 1	: show lives
		- 2	: show cycles
		- 4	: show operations (Params are NOT litteral ...)
		- 8	: show deaths
		- 16	: show PC movements (Except for jumps)
```

## Visualizer
<img width="1798" alt="2" src="https://user-images.githubusercontent.com/38104685/59042662-8bdb2900-8883-11e9-9732-113c989a5856.png">

<img width="1797" alt="Screen Shot 2019-06-06 at 5 44 58 PM" src="https://user-images.githubusercontent.com/38104685/59042744-add4ab80-8883-11e9-830a-9d489948f3cf.png">

