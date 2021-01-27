# Lab0 CProgrammingLab

The original tar file is `cprogramminglab-handout.tar` and the writeup is
`cprogramminglab.pdf`. My solution is in `cprogramminglab-handout-solution`.

After untaring cprogramminglab-handout.tar, you follow the instructions in 
`cprogramming.pdf` to untar the folder and start implementing assignments.

- To use `driver.py` directly:
1. Install python2 in your environment;
2. Run `python2 driver.py`.

The most tricky part in this lab is to pass trace case 11 and 12. 

One can try to commennt out the 2 lines in `queue.c` marked as "IMPORTANT", which would cause
memory leak.

Lesson: when a function relies on the success of a series of memory allocation,
remember to free all previous allocated memory, in case any one of the memory
allocation step fails.

I read the book: *The C Programming Language* before doing this lab. The note
when reading the book is in folder `TheCProgrammingLanguage`.
