<h1>Simple Shell</h1>

<h3>Background Context</h3>

<p>Create a simple UNIX command interpreter based on <em><b>Everything you need to know to start coding your own shell</b></em> and other resources, such as contributing to a test suite </p>
<hr/>
<h3>Learning Objectives</h3>

<li>How does a shell work</li>
<li>What is a pid and a ppid</li>
<li>How to manipulate the environment of the current process</li>
<li>What is the difference between a function and a system call</li>
<li>How to create processes</li>
<li>What are the three prototypes of main</li>
<li>How does the shell use the PATH to find the programs</li>
<li>How to execute another program with the execve system call</li>
<li>How to suspend the execution of a process until one of its children terminates</li>
<li>What is EOF / end-of-file?</li>
<hr/>
<h3>Description of the files</h3>

<p>The following table describes each file exposed in the simple shell repository</p>

| FILE | SPECIAL FEATURE |
| :---: | --- |
| **main_shell** | Main function of simple shell | 
|**functions** | File containing the own functions, to be used according to the call of the main_shell |
| **Simple_shell** | Header file, contains the direct declarations or function prototypes |
| **free_function** | Own function, it is used to unassign the memory assigned by the functions malloc , calloc etc |
| **_getline** | Own function, it reads the command line input stored in a buffer |
| **_getenv** | Own function, searches for the environment string pointed to by name |
| **_putchar** | Own function, writes the character c to stdout |
| **child** | Function that creates the child process |
| **prompt** | Function that prints the prompt line |
<hr/>
<h3>Authors</h3>

<li> Diego Gomez - <a href="https://github.com/ikki2530">ikki2530</a></li>
<li> Ricardo Barrreto - <a href="https://github.com/RicardoBarretoR">RicardoBarretoR</a></li>
