# Brainf_ckCompiler

## How to start?
1. Write the code and save it in a '.b' or '.bf' file (The documentation is written below) (The .bf file must be in the same directory as the .exe file)
2. Open cmd.exe (Press WIN + R and type 'cmd.exe')
3. Enter 'cd C:\Path\to\file' (Replace '\Path\to\file' with the path to the directory where the file is located)
4. Type
```Batch
brainfuck filename.bf
```
to start program    
OR
```Batch
brainfuck
```
to open compiler

## Documentation
The program gives you 30,000 cells, each with 255 ASCII characters. The list of symbols can be found in the file 'bf_ascii_table.txt'  
Char - Meaning   
'>' - increment the data pointer (to point to the next cell to the right)   
'<' - decrement the data pointer (to point to the next cell to the left)   
'+' - increment (increase by one) the byte at the data pointer   
'-' - decrement (decrease by one) the byte at the data pointer   
'.' - output the byte at the data pointer   
',' - accept one byte of input, storing its value in the byte at the data pointer   
'[' - 	if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command   
']' - 	if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command   

## Hello world! example
```
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.+++++++++++++++++++++++++++++.+++++++..+++.-------------------------------------------------------------------------------.+++++++++++++++++++++++++++++++++++++++++++++++++++++++.++++++++++++++++++++++++.+++.------.--------.-------------------------------------------------------------------.-----------------------.
```
