# Horner's Algorithm

Efficient polynomial evaluation using Horner's method.

## Usage

1. Create `test.txt` with polynomial coefficients on a single line:
   ```
   x_value
   a0 a1 a2 a3 ...
   ```
   Where x_value is the point to evaluate and a0, a1, a2... are coefficients.

2. Compile:
   ```bash
   gcc -o main main.cpp
   ```

3. Run:
   ```bash
   ./main
   ```

## Algorithm

For polynomial P(x) = a₀ + a₁x + a₂x² + ... + aₙxⁿ

Horner's method computes: P(x) = (...((aₙ)x + aₙ₋₁)x + ... + a₁)x + a₀

- Time complexity: O(n) - only n multiplications
- More efficient than naive evaluation: O(n²)
- Numerically more stable

## Example

Input (`test.txt`):
```
2
1 2 3
```

For P(x) = 1 + 2x + 3x², evaluate at x=2:
- W₂(2) = 1 + 2(2) + 3(2²) = 1 + 4 + 12 = 17

Output shows step-by-step computation.