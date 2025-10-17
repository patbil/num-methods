# Polynomial Approximation (Least Squares Method)

Approximates a set of data points using polynomial functions via the least squares method with Gaussian elimination.

## Usage

1. Prepare `test.txt` with data points (one per line):
   ```
   x1 y1
   x2 y2
   ...
   ```

2. Compile:
   ```bash
   g++ -o main main.cpp
   ```

3. Run and enter polynomial degree (max 5):
   ```bash
   ./main
   ```

## Example

**Input** (`test.txt`):
```
-1.8 5.68
-1 1.99
0.2 1.24
1.2 9.81
2 14.5
```

**Output** (degree 2):
```
The sought coefficients are:
x^0 = 1.973
x^1 = 2.164
x^2 = 2.269

The sought approximating function is:
F(x) = + (1.973)x^0 + (2.164)x^1 + (2.269)x^2
```

**Result**: `F(x) = 1.973 + 2.164·x + 2.269·x²`

## Algorithm

- Builds system of normal equations
- Applies Gaussian elimination with partial pivoting
- Performs back substitution to find coefficients
- Uses vectors for dynamic array sizes