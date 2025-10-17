# Numerical Integration

Approximates definite integrals using four different methods.

## Methods

1. **Rectangle (Underestimate)** - uses left endpoints
2. **Rectangle (Overestimate)** - uses right endpoints  
3. **Trapezoid Method** - averages left and right endpoints
4. **Simpson's Method** - uses parabolic approximation

## Usage

1. Create `test.txt` with equally spaced data points (y-values):
   ```
   x1 y1
   x2 y2
   ...
   ```
   Default step size: 0.5

2. Compile:
   ```bash
   g++ -o main main.cpp
   ```

3. Run and choose method (1-4):
   ```bash
   ./main
   ```

## Formulas

**Rectangle (Under)**: ∫ ≈ h·(y₀ + y₁ + ... + yₙ₋₁)

**Rectangle (Over)**: ∫ ≈ h·(y₁ + y₂ + ... + yₙ)

**Trapezoid**: ∫ ≈ h·((y₀ + yₙ)/2 + y₁ + y₂ + ... + yₙ₋₁)

**Simpson**: ∫ ≈ h/3·(y₀ + yₙ + 4·Σ(odd) + 2·Σ(even))

## Input Example

```
0.0 1.0
0.5 1.5
1.0 2.0
1.5 2.5
2.0 3.0
```

## Accuracy

Simpson's method: Most accurate (4th order)
Trapezoid: Good accuracy (2nd order)
Rectangle: Least accurate (1st order)