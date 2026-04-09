# 🚀 High-Performance C++ Expression Parser

A fast and lightweight mathematical expression parser written in modern C++.

Designed for **high performance**, **low memory overhead**, and **real-time evaluation**, this project implements a stack-based parsing engine capable of handling complex expressions with precision.

---

## ⚡ Features

* 🔥 High-performance stack-based evaluation
* ➕ Supports operators: `+ - * /`
* 📐 Operator precedence handling
* ➖ Unary operator support (`-5`, `2*-3`)
* 🔢 Floating-point number support
* 🧩 Parentheses support `( )`
* ⚠️ Error handling:

  * Division by zero
  * Invalid expressions
* 🚀 Zero-allocation number parsing (faster than `std::stod`)
* ⚙️ Single-pass O(n) parsing

---

## 🧪 Demo

```
==== BASIC TESTS ====
Expression: 2+2
Result: 4
------------------------
Expression: 10-3
Result: 7
------------------------
Expression: 4*5
Result: 20
------------------------
Expression: 20/4
Result: 5
------------------------

==== PRIORITY TESTS ====
Expression: 2+3*4
Result: 14
------------------------
Expression: (2+3)*4
Result: 20
------------------------

==== FLOAT TESTS ====
Expression: 2.5+1.5
Result: 4
------------------------
Expression: 10.2/2
Result: 5.1
------------------------

==== UNARY TESTS ====
Expression: -5+3
Result: -2
------------------------
Expression: 2*-3
Result: -6
------------------------
Expression: (-2+5)*3
Result: 9
------------------------

==== COMPLEX TESTS ====
Expression: 10+(2*3)-(4/2)
Result: 14
------------------------
Expression: (1+2)*(3+4)*(5+6)
Result: 231
------------------------

==== ERROR TESTS ====
Expression: 5/0
Error: Division by zero
------------------------
Expression: 5+*2
Error: Invalid expression
------------------------
Expression: ((2+3)
Error: Invalid expression
------------------------
```

---

## 🛠 Build

```bash
make
```

Executable will be generated in:

```
build/calculator.exe
```

---

## ▶️ Run

```bash
./build/calculator.exe
```

Type expressions directly:

```
> (1+2)*(3+4)
Result: 21
```

---

## 🧪 Run Tests

```bash
test.bat
```

This will automatically run multiple test cases including:

* Basic operations
* Operator precedence
* Floating-point calculations
* Unary expressions
* Error handling

---

## 🧠 Architecture

This parser is based on a **two-stack evaluation model**:

* **Values stack** → stores numbers
* **Operators stack** → stores operators

### Core Concepts:

* Operator precedence handling
* Single-pass parsing
* On-the-fly evaluation (no AST required)
* Minimal memory allocations

---

## 📊 Performance

Optimized for speed using:

* Manual number parsing (no `std::stod`)
* Minimal dynamic allocations
* Cache-friendly stack operations
* O(n) time complexity

---

## 📁 Project Structure

```
.
├── src/
│   ├── main.cpp
│   ├── calculator.cpp
│   └── calculator.h
├── build/
├── test.bat
├── Makefile
└── README.md
```

---

## 🎯 Use Cases

* CLI calculators
* Game engines (expression evaluation)
* Embedded systems
* Real-time data processing
* Custom scripting engines

---

## 🌍 Compatibility

* Windows (MinGW64) ✅
* Linux (GCC/Clang) ✅

---

## 🧩 Future Improvements

* Support for functions (`sin`, `cos`, `pow`)
* Variables (`x = 5`)
* Exponent operator (`^`)
* SIMD optimizations
* Benchmark suite

---

## 📌 Author

Developed by a performance-focused C++ engineer specializing in system-level programming and real-time computation.

---

## ⭐ Why this project?

This is not just a calculator.

It demonstrates:

* Low-level parsing techniques
* Algorithmic problem solving
* Performance optimization in C++
* Real-world system design principles

---

## 📜 License

Open-source and free to use.
