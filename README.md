בהתאם לדרישות המטלה שלך, הנה קובץ `README.md` מסודר וברור:

---

```markdown
# MyContainer Project

## Overview

This project implements a generic container (MyContainer) for comparable elements,
supporting dynamic add/remove operations and multiple custom iterators.
The iterators allow traversal in various orders: insertion, ascending, descending, side-cross, reverse, and middle-out.
The code is modular and follows modern C++ practices.
---

## Features

### Generic Container – `MyContainer<T>`
- Dynamic container for comparable types.
- Supports:
  - `add(T value)` – Add an element.
  - `remove(T value)` – Remove all instances of a given element (throws if not found).
  - `size()` – Returns the number of elements.
  - `operator<<` – Pretty prints the container.

### Iterators Implemented
Each iterator provides a unique traversal order:
- **Order** – Insertion order.
- **AscendingOrder** – Sorted ascending.
- **DescendingOrder** – Sorted descending.
- **SideCrossOrder** – Alternates: smallest, largest, second smallest, second largest, etc.
- **ReverseOrder** – From last inserted to first.
- **MiddleOutOrder** – Starts at the middle, alternates left and right.

All iterators support `begin()` and `end()` methods, and comply with STL-style iteration.

---

## Project Structure

```

Sys\_4/
├── MyContainer.hpp         # Class and all iterators
├── main.cpp                # Demo program
├── MyContainerTests.cpp    # Unit tests using doctest
├── Makefile                # Build & test automation
└── README.md               # Project description

````

---

## Build and Run

###  Compile and run the demo:
```bash
make Main
./Main
````

### Run all tests:

```bash
make test
```

### Check for memory leaks:

```bash
make valgrind
```

### Clean all build files:

```bash
make clean
```

---

## Notes

* All components are in the `Container` namespace.
* Input validation is enforced (e.g., `remove()` throws on missing value).
* The project includes both numeric and string usage examples.
* Fully tested using `doctest`, covering edge cases and iterator behavior.
* Checked for memory leaks using `valgrind`.



רוצה שאוסיף את הקובץ הזה ל־ZIP או שתשלחי לי את המייל שלך להכניס ב־README?
```
