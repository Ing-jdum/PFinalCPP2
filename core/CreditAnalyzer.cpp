
#include "CreditAnalyzer.h"
#include <algorithm>

const double CreditAnalyzer::MAX_DEBT_TO_INCOME_RATIO = 0.40; // 40%
const double CreditAnalyzer::MAX_PAYMENT_TO_INCOME_RATIO = 0.28; // 28%
const int CreditAnalyzer::MIN_CREDIT_SCORE = 600;

CreditResult CreditAnalyzer::evaluateCredit(const CreditProfile& profile) {
    // TODO: Implement credit evaluation logic
    // INSTRUCTIONS:
    // 1. Create a CreditResult struct called result
    // 2. Calculate debt-to-income ratio using calculateDebtToIncomeRatio()
    // 3. Calculate payment-to-income ratio using calculatePaymentToIncomeRatio()
    // 4. Calculate maximum affordable payment: profile.monthlyIncome * MAX_PAYMENT_TO_INCOME_RATIO - profile.debtLevel
    // 5. Set result.maxLoanAmount = max(0.0, maxAffordablePayment * 0.8)
    // 6. Set result.recommendedPayment = max(0.0, maxAffordablePayment)
    // 7. Check three criteria:
    //    - creditScoreOk = profile.creditScore >= MIN_CREDIT_SCORE
    //    - debtRatioOk = debtToIncomeRatio <= MAX_DEBT_TO_INCOME_RATIO
    //    - paymentRatioOk = paymentToIncomeRatio <= MAX_PAYMENT_TO_INCOME_RATIO
    // 8. Set decision and reason based on criteria:
    //    - If all OK: APPROVED, "All criteria met. Loan approved."
    //    - If credit score low: REJECTED, "Credit score too low (minimum 600 required)."
    //    - If debt ratio high: REJECTED, "Debt-to-income ratio too high (X% vs 40% max)."
    //    - If payment ratio high: CONDITIONAL, "Payment-to-income ratio high. Consider smaller loan amount."
    //    - Otherwise: CONDITIONAL, "Some criteria marginally met. Manual review recommended."
    // 9. Return the result
    
    CreditResult result;
    // Your implementation here
    return result;
}

double CreditAnalyzer::calculateDebtToIncomeRatio(double monthlyIncome, double totalMonthlyDebt) {
    // TODO: Calculate debt-to-income ratio
    // INSTRUCTIONS:
    // 1. If monthlyIncome <= 0, return 1.0 (100% ratio - no income means can't afford debt)
    // 2. Otherwise, return totalMonthlyDebt / monthlyIncome
    
    // Your implementation here
    return 0.0;
}

double CreditAnalyzer::calculatePaymentToIncomeRatio(double monthlyIncome, double monthlyPayment) {
    // TODO: Calculate payment-to-income ratio
    // INSTRUCTIONS:
    // 1. If monthlyIncome <= 0, return 1.0 (100% ratio - no income means can't afford payment)
    // 2. Otherwise, return monthlyPayment / monthlyIncome
    
    // Your implementation here
    return 0.0;
}
