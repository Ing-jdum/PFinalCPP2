
#ifndef CREDIT_ANALYZER_H
#define CREDIT_ANALYZER_H

#include <string>

struct CreditProfile {
    double monthlyIncome;
    double debtLevel;
    int creditScore;
    double loanAmount;
    double monthlyPayment;
};

enum class CreditDecision {
    APPROVED,
    REJECTED,
    CONDITIONAL
};

struct CreditResult {
    CreditDecision decision;
    std::string reason;
    double maxLoanAmount;
    double recommendedPayment;
};

class CreditAnalyzer {
public:
    static CreditResult evaluateCredit(const CreditProfile& profile);
    static double calculateDebtToIncomeRatio(double monthlyIncome, double totalMonthlyDebt);
    static double calculatePaymentToIncomeRatio(double monthlyIncome, double monthlyPayment);
    
private:
    static const double MAX_DEBT_TO_INCOME_RATIO;
    static const double MAX_PAYMENT_TO_INCOME_RATIO;
    static const int MIN_CREDIT_SCORE;
};

#endif
