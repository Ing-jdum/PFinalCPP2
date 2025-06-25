
#include "CreditAnalyzer.h"
#include <algorithm>

const double CreditAnalyzer::MAX_DEBT_TO_INCOME_RATIO = 0.40; // 40%
const double CreditAnalyzer::MAX_PAYMENT_TO_INCOME_RATIO = 0.28; // 28%
const int CreditAnalyzer::MIN_CREDIT_SCORE = 600;

CreditResult CreditAnalyzer::evaluateCredit(const CreditProfile& profile) {
    CreditResult result;
    
    double debtToIncomeRatio = calculateDebtToIncomeRatio(profile.monthlyIncome, profile.debtLevel);
    double paymentToIncomeRatio = calculatePaymentToIncomeRatio(profile.monthlyIncome, profile.monthlyPayment);
    
    // Calculate maximum affordable loan amount
    double maxAffordablePayment = profile.monthlyIncome * MAX_PAYMENT_TO_INCOME_RATIO - profile.debtLevel;
    result.maxLoanAmount = std::max(0.0, maxAffordablePayment * 0.8); // Conservative estimate
    result.recommendedPayment = std::max(0.0, maxAffordablePayment);
    
    // Evaluation criteria
    bool creditScoreOk = profile.creditScore >= MIN_CREDIT_SCORE;
    bool debtRatioOk = debtToIncomeRatio <= MAX_DEBT_TO_INCOME_RATIO;
    bool paymentRatioOk = paymentToIncomeRatio <= MAX_PAYMENT_TO_INCOME_RATIO;
    
    if (creditScoreOk && debtRatioOk && paymentRatioOk) {
        result.decision = CreditDecision::APPROVED;
        result.reason = "All criteria met. Loan approved.";
    } else if (profile.creditScore < MIN_CREDIT_SCORE) {
        result.decision = CreditDecision::REJECTED;
        result.reason = "Credit score too low (minimum " + std::to_string(MIN_CREDIT_SCORE) + " required).";
    } else if (debtToIncomeRatio > MAX_DEBT_TO_INCOME_RATIO) {
        result.decision = CreditDecision::REJECTED;
        result.reason = "Debt-to-income ratio too high (" + 
                       std::to_string(int(debtToIncomeRatio * 100)) + "% vs " + 
                       std::to_string(int(MAX_DEBT_TO_INCOME_RATIO * 100)) + "% max).";
    } else if (paymentToIncomeRatio > MAX_PAYMENT_TO_INCOME_RATIO) {
        result.decision = CreditDecision::CONDITIONAL;
        result.reason = "Payment-to-income ratio high. Consider smaller loan amount.";
    } else {
        result.decision = CreditDecision::CONDITIONAL;
        result.reason = "Some criteria marginally met. Manual review recommended.";
    }
    
    return result;
}

double CreditAnalyzer::calculateDebtToIncomeRatio(double monthlyIncome, double totalMonthlyDebt) {
    if (monthlyIncome <= 0) return 1.0; // 100% if no income
    return totalMonthlyDebt / monthlyIncome;
}

double CreditAnalyzer::calculatePaymentToIncomeRatio(double monthlyIncome, double monthlyPayment) {
    if (monthlyIncome <= 0) return 1.0; // 100% if no income
    return monthlyPayment / monthlyIncome;
}
