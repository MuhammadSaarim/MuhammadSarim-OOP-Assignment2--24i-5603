[README.md](https://github.com/user-attachments/files/23241399/README.md)
 OOP Assignment 2

Course: CS2012 – Introduction to Object-Oriented Programming  
Language Used: C++  
IDE Used:Visual Studio Code  
Student Name:Muhammad Sarim
Submission: Google Classroom  

---

 Question 1 – Recursive Function Pattern

 Task
Write a recursive function `void PrintPattern(int &n);` to print the following pattern.

Example Input:  
Enter any number = 4

Output:
```
4
2 2
1 3
1 1 2
1 1 1 1
```

Concepts Used:Recursion, loops, pattern generation.

---

 Question 2 – Singly Linked List (NASA Geospatial System)

 Scenario
NASA’s Earth Observation team manages geospatial data (Land and Water features).

Each node stores:
- `FeatureID`
- Pointer to a `Feature` (LandFeature or WaterFeature)
- Pointer to the next node

 Implemented Classes
- Feature(Base class with pure virtual function `analyze()`)
- LandFeature and WaterFeature(Derived classes)
- SinglyLinkedList (Manages all features)

 Implemented Functions
- `insertAtEnd(int featureID, Feature* f)`  
- `deleteByID(int featureID)`  
- `displayAll()`  
- `reverseList()`  

**Bonus:**
- Overloaded `+` operator → Concatenate two lists.  
- Overloaded `=` operator → Deep copy of a list.

Concepts Used: Inheritance, polymorphism, dynamic memory, operator overloading.

---

 Question 3 – Doubly Linked List (Library System)

 Task
Implement a Doubly Linked List to track books.

 Node Data
- `BookID`
- `Title`
- `Author`

 Implemented Functions
- Add book at beginning
- Add book at end
- Add book at specific position
- Delete book by ID
- Display list in **order** and **reverse order**

Bonus:
Iterator class compatible with `stl::iterator` for ranged-for traversal (forward and backward).

Concepts Used:** Doubly linked lists, pointers, iterators, encapsulation.

---

 Question 4 – Queue (Movie Ticket Booking System)

 Scenario
Simulate a queue for a movie ticket booking system.

Each customer includes:
- Customer ID
- Customer Name
- Number of tickets requested

Implemented Functions
- `enqueue()` → Add customer to queue  
- `dequeue()` → Serve first customer  
- `display()` → Show current queue  

Bonus: 
Priority queue where customers with higher ticket requests are served first.

Concepts Used: Queues (FIFO), dynamic memory management.

---

Question 5 – Stack & Algorithm Analysis

 Part 1: Stack Implementations
Implemented two stack versions:
1. Linked List-based Stack**
2. Array-based Stack (Dynamic Array)**

Both are used to write iterative solutions for Question 1.

 Part 2: Algorithm Analysis

| Operation | Linked List Stack | Array Stack |
|------------|------------------|--------------|
| Push | O(1) | O(1) (Amortized) |
| Pop| O(1) | O(1) |
| Memory Usage | Dynamic (per node) | Contiguous (may require resizing) |

Observation:
- Linked List Stack → flexible memory, slightly slower.  
- Array Stack → faster access, limited by initial capacity.

Concepts Used:** Dynamic memory, data structures, runtime analysis.

---

 General Notes
- Each question implemented separately in C++.  
- Code follows proper OOP principles: Encapsulation, Inheritance, Polymorphism*.  
- Proper memory management ensured via constructors and destructors.  
- Tested and compiled using `g++` on Visual Studio Code.

---

Submitted By: [Muhammad Sarim]  
Roll No: [24i-5603]  
Date: [30-10-25]  

