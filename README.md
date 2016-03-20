# CppSeamphore
A simple implementation of Semaphore in C++11 using only Std library

# Usage
Copy both .hpp and .cpp into your project

# Implementation
The seamphore is implemented to work in a very traditional way: 

P() blocks until internal counter is greater than 0.
V() increments the internal counter and signals waiting threads on P() to wake up. 

# Potential issues
Waiting and signaling is done by using condition variable in C++11 std,
hence the order of waking up threads are not in FIFO order, causing potential bargin problem. 
Using this simple version of seamphore to synchronize massive amount of threads in a big project is not recommended. 
