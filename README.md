<h1>Simple Shell</h1>

<h3>Background Context</h3>

<p>The Simple Shell is the creation of a UNIX command interpreter, which allows us to know in detail its execution from a system of own created functions.</p>
<hr/>
<h3>Learning Objectives</h3>

<li>How does a shell work</li>
<li>How does a pid and a ppid work</li>
<li>How to manipulate the environment of the current process</li>
<li>How to create processes</li>
<li>How does the shell use the PATH to find the programs</li>
<li>How to execute another program with the execve system call</li>
<li>How to suspend the execution of a process until one of its children terminates</li>
<li>EOF implementation / end of file </li>
<hr/>
<h3>Description of the files</h3>

<p>The following table describes each file exposed in the simple shell repository</p>

| FILE | SPECIAL FEATURE |
| :---: | --- |
| **main_shell.c** | Main function of simple shell | 
|**functions.c** | File containing the own functions, to be used according to the call of the main_shell |
| **shell.h** | Header file, contains the direct declarations or function prototypes |
| **free_function.c** | Own function, it is used to unassign the memory assigned by the functions malloc , calloc etc |
| **getline** | It reads the command line input stored in a buffer |
| **print_env.c** | Own function that prints the current environment |
| **_putchar.c** | Own function, writes the character c to stdout |
| **child.c** | Function that creates the child process |
| **prompt.c** | Function that prints the prompt line |
| **_atoi.c** | Convert a string to an integer |
| **_strcmp.c** | Own function that compare two string and return cero on success |
| **sp_string.c** | Own function that split a string with strtok function |
| **_strcat.c** | Own function that concatenate two string |
| **_strdup.c** | Own function that copy a string |
| **_strlen.c** | Own function that return the length of a string |
| **print_errors.c** | Own function that print errors of the program |
| **print_integer.c** | call a recursion function with an iterator |
| **recursion_int.c** | print and return amount of digits of the number n |
| **print_env.c** | function that prints environ |
| **free_arraybid.c** | free a array bidimentional |
| **_isdigit.c** | Own function that checks for a digit cero through nine |
| **manage_signal** | Own function that manage the signal CTRL + C |
| **exit_cmd.c** | Own outputs function in the program according to the data of the array in position one |
<hr/>
<h3>Installation and use </h3>

<p>Clone the repository with https into a directory on your terminal </p>

<img src="https://user-images.githubusercontent.com/55164863/79722644-09e0cc80-82aa-11ea-9e42-013915d1890f.PNG " style=" width:100px ; height:100px " />

<p>Compile all files ending in .c and then run the program with "./hsh".
This is how we enter our simple_shell </p>

<img src= "https://user-images.githubusercontent.com/55164863/79722679-1a914280-82aa-11ea-9649-f08884760b9f.PNG " style=" width:100px ; height:100px " />

<p>Now if we can work on it by typing commands like our example shown below : " /bin/ls " </p>

<img src="https://user-images.githubusercontent.com/55164863/79726762-eec58b00-82b0-11ea-8adb-77959e96791b.PNG " style=" width:100px ; height:100px " />
<hr>
<h3>Authors</h3>

<li> Diego Gomez - <a href="https://github.com/ikki2530">ikki2530</a></li>
<li> Ricardo Barrreto - <a href="https://github.com/RicardoBarretoR">RicardoBarretoR</a></li>
