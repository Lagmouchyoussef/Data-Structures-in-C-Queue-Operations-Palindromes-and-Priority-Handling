## Exercise 1:

1. Implement an integer queue using a singly linked list with the following operations:  
   o enqueue()  
   o dequeue()  
   o front()  
   o is_empty()  

2. Display the queue contents after each operation.

Test example: enqueue 10, 20, 30 then dequeue twice and display the queue

## Exercise 2:

1. Write a function to reverse a queue using a stack (also implemented with a list).  
2. Test the function with a queue containing elements: \( 1 \rightarrow 2 \rightarrow 3 \rightarrow 4 \)

Expected result: \( 4 \rightarrow 3 \rightarrow 2 \rightarrow 1 \)

## Exercise 3:

1. Write a function that takes two queues and returns true if they are identical (same order, same elements).  
2. Test your function with different queues, both identical and non-identical.

## Exercise 4:

1. Implement a function that merges two queues (queue1 and queue2) into one, while maintaining their order.  
2. Expected result: queue1=\( 1 \rightarrow 3 \), queue2=\( 2 \rightarrow 4 \rightarrow \) merged = \( 1 \rightarrow 3 \rightarrow 2 \rightarrow 4 \)

## Exercise 5:

1. Each client is represented by an integer number.  
2. Write a program that:
   - Adds clients to the queue
   - Processes them one by one
   - When a client is served, removes them from the queue and displays "Client X served"
   - Displays the queue status after each service

Example: enqueue 101, 102, 103 → serve 101 → "Client 101 served" → queue: 102 → 103


# Exercise 6:

1. Ask the user to enter a character string.
2. Enqueue each character in a queue and also push it onto a stack.
3. Compare both to check if the string is a palindrome.

# Exercise 7:

1. Each patient has a name and an urgency level (1 to 10).
2. Create a queue where patients are inserted in descending order of urgency.
3. When a patient is treated, remove the one with the highest urgency.
4. Display the queue status after each addition or treatment.
