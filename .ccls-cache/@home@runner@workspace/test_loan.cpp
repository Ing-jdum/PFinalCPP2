
#include <iostream>
#include <iomanip>
#include "core/LoanCalculator.h"
#include "core/CreditAnalyzer.h"

int main() {
    std::cout << "=== Loan Calculator Test ===" << std::endl;
    
    // Test loan calculation
    double loanAmount = 250000.0;  // $250,000
    double annualRate = 4.5;       // 4.5%
    int termMonths = 360;          // 30 years
    
    LoanDetails loan = LoanCalculator::calculateLoan(loanAmount, annualRate, termMonths);
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Loan Amount: $" << loan.loanAmount << std::endl;
    std::cout << "Annual Rate: " << loan.annualInterestRate << "%" << std::endl;
    std::cout << "Term: " << loan.termInMonths << " months" << std::endl;
    std::cout << "Monthly Payment: $" << loan.monthlyPayment << std::endl;
    std::cout << "Total Amount: $" << loan.totalAmount << std::endl;
    std::cout << "Total Interest: $" << loan.totalInterest << std::endl;
    
    std::cout << "\n=== Credit Analysis Test ===" << std::endl;
    
    // Test credit analysis
    CreditProfile profile;
    profile.monthlyIncome = 8000.0;
    profile.debtLevel = 1200.0;
    profile.creditScore = 720;
    profile.loanAmount = loanAmount;
    profile.monthlyPayment = loan.monthlyPayment;
    
    CreditResult result = CreditAnalyzer::evaluateCredit(profile);
    
    std::cout << "Monthly Income: $" << profile.monthlyIncome << std::endl;
    std::cout << "Current Debt: $" << profile.debtLevel << std::endl;
    std::cout << "Credit Score: " << profile.creditScore << std::endl;
    std::cout << "Decision: ";
    
    switch (result.decision) {
        case CreditDecision::APPROVED:
            std::cout << "APPROVED";
            break;
        case CreditDecision::CONDITIONAL:
            std::cout << "CONDITIONAL";
            break;
        case CreditDecision::REJECTED:
            std::cout << "REJECTED";
            break;
    }
    
    std::cout << std::endl;
    std::cout << "Reason: " << result.reason << std::endl;
    std::cout << "Max Loan: $" << result.maxLoanAmount << std::endl;
    
    return 0;
}
