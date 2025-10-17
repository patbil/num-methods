# Numerical Differentiation

Calculates derivative of tabulated functions using finite differences methods.

## Methods

1. **Forward Differences** - estimates derivative using forward divided differences
2. **Backward Differences** - estimates derivative using backward divided differences

## Usage

1. Create `test.txt` with equally spaced data points:
   ```
   x1 y1
   x2 y2
   ...
   ```

2. Compile:
   ```bash
   g++ -o main main.cpp
   ```

3. Run:
   ```bash
   ./main
   ```

4. Choose method (1 = Forward, 2 = Backward, 3 = Exit)

## Algorithm

- Builds difference table (forward or backward)
- Computes finite difference quotient
- Result: f'(x) ≈ Δy / h

## Input Example

```
1.0 2.0
2.0 4.0
3.0 6.0
```

## Output

Displays the difference table and calculated derivative at the last point.