# Polynomial Interpolation

Finds polynomial that passes through all given data points using Gaussian elimination.

## Usage

1. Create `test.txt` with data points:
   ```
   x1 y1
   x2 y2
   x3 y3
   ...
   xn yn
   ```
   For n points, will find polynomial of degree n-1.

2. Compile:
   ```bash
   g++ -o main main.cpp
   ```

3. Run:
   ```bash
   ./main
   ```

## Algorithm

1. Builds Vandermonde matrix from points
2. Applies Gaussian elimination
3. Back substitution to find coefficients
4. Outputs polynomial in form: a₀ + a₁x + a₂x² + ...

## Example

**Input** (`test.txt`):
```
1 2
2 3
3 5
```

**Output**:
```
0.5 + 0.5*x^1 + 0.5*x^2
```

Result: P(x) = 0.5 + 0.5x + 0.5x²

Verification:
- P(1) = 0.5 + 0.5(1) + 0.5(1²) = 2 ✓
- P(2) = 0.5 + 0.5(2) + 0.5(2²) = 3 ✓
- P(3) = 0.5 + 0.5(3) + 0.5(3²) = 5 ✓

## Notes

- Exact interpolation: passes through all points
- For n points, creates unique polynomial of degree ≤ n-1
- Maximum 20 points (can be increased by changing MAX constant)