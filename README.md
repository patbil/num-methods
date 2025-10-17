# Numerical Methods Collection

C++ implementations of classic numerical methods used in scientific computing and engineering.

## Projects Overview

### [Polynomial Approximation](approximation/)
Least squares polynomial approximation using Gaussian elimination. Fits best-fit polynomial to data points.
- **Method**: Normal equations + Gaussian elimination
- **Features**: Degree up to 5, dynamic size arrays
- **Input**: Data points (x, y) pairs

### [Numerical Differentiation](differentiation/)
Estimates derivatives of tabulated functions using finite differences.
- **Methods**: Forward and backward differences
- **Features**: Difference tables, multiple methods
- **Input**: Equally spaced function values

### [Horner's Algorithm](horner/)
Efficient polynomial evaluation using Horner's nested multiplication scheme.
- **Complexity**: O(n) multiplications vs O(n²) naive method
- **Features**: Step-by-step computation display
- **Input**: Polynomial coefficients and evaluation point

### [Numerical Integration](integration/)
Approximates definite integrals using multiple quadrature methods.
- **Methods**: 
  - Rectangle (underestimate/overestimate)
  - Trapezoid rule
  - Simpson's rule
- **Features**: Menu-driven, easy method comparison
- **Input**: Equally spaced function values

### [Polynomial Interpolation](interpolation/)
Finds polynomial passing through given data points using Gaussian elimination.
- **Method**: Vandermonde matrix + Gaussian elimination
- **Features**: Exact interpolation, coefficient back substitution
- **Input**: Data points (exact pass-through)

## General Usage

Each project has its own directory with:
- `main.cpp` - C++ source code
- `test.txt` - Sample data
- `README.md` - Method-specific documentation

### Compilation

```bash
cd <project_directory>
g++ -o main main.cpp
./main
```

On Windows:
```bash
g++ -o main.exe main.cpp
main.exe
```

## Requirements

- C++11 or later
- G++ compiler (or compatible)
- Standard library (iostream, vector, cmath, fstream, etc.)

## Project Structure

```
num_methods/
├── approximation/      # Least squares fitting
├── differentiation/    # Finite differences
├── horner/             # Polynomial evaluation
├── integration/        # Numerical integration
├── interpolation/      # Exact polynomial fitting
└── README.md          # This file
```

## Typical Workflow

1. **Approximation**: Use when you want best-fit polynomial (noisy data)
2. **Interpolation**: Use when you need exact polynomial through points
3. **Differentiation**: Estimate derivatives from tables
4. **Integration**: Approximate area under curve
5. **Horner**: Fast evaluation of approximated/interpolated polynomials

## Notes

- All programs read from `test.txt` in the same directory
- Data format: space or newline separated x,y pairs
- Most use Gaussian elimination for numerical stability
- See individual README.md for method specifics
