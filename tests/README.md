
# Student Implementation Guide

## Overview
This project implements a Loan and Credit Analysis System following Clean Architecture principles. You need to implement the missing methods in the order specified below.

## Implementation Order

### 1. Validation Class (utils/Validation.cpp)
**Why first?** Basic string processing used everywhere.

Implement these methods:
- `isValidDouble()` - Check if string is a valid decimal number
- `isValidInt()` - Check if string is a valid integer
- `trim()` - Remove leading/trailing whitespace
- `toLowerCase()` - Convert string to lowercase
- `isValidUnitName()` - Validate unit names (starts with letter, alphanumeric)

### 2. InputHandler Class (ui/InputHandler.cpp)
**Why second?** Handles user input with validation.

Implement these methods:
- `getDouble()` - Get validated double input from user
- `getInt()` - Get validated integer input from user
- `getYesNo()` - Get yes/no confirmation from user
- `waitForEnter()` - Pause and wait for Enter key

### 3. LoanCalculator Class (core/LoanCalculator.cpp)
**Why third?** Core business logic for loan calculations.

Implement these methods:
- `calculateMonthlyPayment()` - Use loan payment formula
- `calculateLoan()` - Complete loan details calculation
- `generatePaymentSchedule()` - Create payment schedule table

**Important Formula:**
```
Monthly Payment = P * [r * (1 + r)^n] / [(1 + r)^n - 1]
Where: P = loan amount, r = monthly rate, n = term in months
```

### 4. CreditAnalyzer Class (core/CreditAnalyzer.cpp)
**Why last?** Uses all other components.

Implement these methods:
- `calculateDebtToIncomeRatio()` - Simple division with error handling
- `calculatePaymentToIncomeRatio()` - Simple division with error handling
- `evaluateCredit()` - Complex decision logic based on financial ratios

## Testing Your Work

Run tests after implementing each class:

```bash
cd tests
make run
```

The test suite will show you exactly which methods work and which need fixing.

## Key Learning Objectives

1. **Input Validation** - Always validate user input
2. **Error Handling** - Handle edge cases (division by zero, empty strings)
3. **Financial Calculations** - Learn loan payment formulas
4. **Decision Logic** - Implement business rules for credit decisions
5. **Clean Architecture** - Separate concerns into layers

## Business Rules

### Credit Analysis Rules:
- **Debt-to-Income Ratio**: Maximum 40%
- **Payment-to-Income Ratio**: Maximum 28%
- **Minimum Credit Score**: 600
- **Decision Logic**:
  - All criteria met → APPROVED
  - Credit score too low → REJECTED
  - Debt ratio too high → REJECTED
  - Payment ratio high → CONDITIONAL
  - Marginal cases → CONDITIONAL

## Tips for Success

1. **Read the TODO comments carefully** - they contain step-by-step instructions
2. **Test frequently** - run tests after each method implementation
3. **Handle edge cases** - empty strings, zero values, negative numbers
4. **Use the constants** - predefined values in CreditAnalyzer class
5. **Follow the math** - loan formulas are provided in comments

## Common Mistakes to Avoid

1. **Forgetting to handle zero income** - should return 100% ratio
2. **Not converting annual rate to monthly** - divide by 100 then by 12
3. **Off-by-one errors** - payment schedules start from month 1
4. **Not trimming input** - whitespace can break validation
5. **Hardcoding values** - use the provided constants

## Getting Help

If you're stuck:
1. Check the test output for expected vs actual values
2. Review the TODO comments for step-by-step instructions
3. Look at the test cases to understand expected behavior
4. Make sure you've implemented dependencies first (Validation before InputHandler)

Good luck with your implementation!
