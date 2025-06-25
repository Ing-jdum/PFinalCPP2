
#ifndef LOAN_CALCULATOR_H
#define LOAN_CALCULATOR_H

#include <vector>

struct LoanDetails {
    double loanAmount;
    double annualInterestRate;
    int termInMonths;
    double monthlyPayment;
    double totalAmount;
    double totalInterest;
};

struct PaymentSchedule {
    int month;
    double payment;
    double principal;
    double interest;
    double remainingBalance;
};

class LoanCalculator {
public:
    static LoanDetails calculateLoan(double loanAmount, double annualInterestRate, int termInMonths);
    static std::vector<PaymentSchedule> generatePaymentSchedule(const LoanDetails& loan);
    static double calculateMonthlyPayment(double loanAmount, double monthlyRate, int termInMonths);
};

#endif
