
---

# MyContainer Project

## Overview

This project implements a generic dynamic container class called `MyContainer`, designed for storing comparable elements (e.g., integers, strings, etc.).
The container supports insertion, removal, and multiple ways of iterating over the data using custom iterators.

## Features

* Add and remove elements dynamically.
* Automatically removes all occurrences of an element.
* Returns the container size.
* Custom `<<` operator for printing.
* Fully templated and supports any comparable type.
* Implements six iterator types:

  * `Order`: traverses in insertion order.
  * `AscendingOrder`: from smallest to largest.
  * `DescendingOrder`: from largest to smallest.
  * `SideCrossOrder`: alternates between smallest and largest.
  * `ReverseOrder`: reverse of insertion order.
  * `MiddleOutOrder`: starts from middle, then left and right alternately.

## Project Structure

```
.
├── MyContainer.hpp          # Container class and iterators
├── main.cpp                 # Demo run
├── TestMyContainer.cpp      # Unit tests with doctest
├── Makefile                 # Compilation and testing
└── README.md                # This file
```

## How to Run:

Make sure you have a C++20 compatible compiler. Then use the following commands:

* `make Main` – Compile and run the demo (`main.cpp`)
* `make test` – Compile and run unit tests (`TestMyContainer.cpp`)
* `make valgrind` – Run memory checks using Valgrind
* `make clean` – Remove compiled binaries and temporary files



## Testing

Unit tests are written using the [doctest](https://github.com/doctest/doctest) framework and cover:

* Basic container functionality (add, remove, size)
* Iterator traversal logic for all six iterator types
* Edge cases (empty containers, duplicates, etc.)


## Authors

* Noa Agassi
* Email: \[[agassinoa20@gmail.com](mailto:your@email.com)]

---

