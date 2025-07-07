# ChessMaster Challenge

---

## 🎯 Objective

To implement two core computational geometry modules:

1️⃣ **ChessSolver**  
- Create a 2D matrix (chessboard).
- Sort each row in ascending or descending order.
- Count inversions in the entire matrix.
- Display the sorted matrix.

2️⃣ **ClosestSolver**  
- Find the closest pair of points among a given set using **Divide and Conquer**.
- Handle tie-breaking by input order to return lex smallest output.

This demonstrates:
- **Recursion**
- **Merge sort with inversion count**
- **Divide and Conquer for closest pair**
- Clean **OOP design** using classes, functors, and helper methods.

---

## 🧩 Core Components

### ✅ **Sorting**
- Implements merge sort with inversion count.
- Reusable as a functor.

### ✅ **ChessSolver**
- Manages a 2D matrix.
- Supports row-wise sorting.
- Flattens matrix to count total inversions.
- Displays matrix contents.

### ✅ **ClosestSolver**
- Handles a list of 2D points.
- Uses divide and conquer to find the closest pair.
- Maintains lex smallest pair if distances tie.
- Sorts points by X and Y coordinates for efficient checks.

---

## Input Format

Commands are given one by one:

          CREATE_2D
          N
          
          SORT_2D
          ascending | descending
          
          INVERSION_2D
          DISPLAY_2D
          CLOSEST_2D
          K
          x1 y1
          x2 y2
          ...
          xK yK
          
          END

---

## ⚙️ Constraints

- Matrix is always square: N × N.
- Row sorting order: ascending or descending.
- ClosestSolver must find the pair with minimum squared Euclidean distance.
- Ties are broken by input order for consistency.
- Merge sort correctly counts all inversions for the 1D flattened matrix.

---

## Outcome

✅ For `SORT_2D` — sorts each row of the matrix.  
✅ For `INVERSION_2D` — prints total inversion count.  
✅ For `DISPLAY_2D` — displays the matrix row by row.  
✅ For `CLOSEST_2D` — prints:
x1 y1 x2 y2

where `(x1,y1)` and `(x2,y2)` are the closest pair.

✅ For `END` — stops the program.

---

## 📄 Reference

[Chess Master Challenge](https://github.com/user-attachments/files/21110185/Assignment.Week.7.1.pdf)
