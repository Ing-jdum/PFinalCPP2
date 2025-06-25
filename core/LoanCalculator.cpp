
#include "LoanCalculator.h"
#include <cmath>

LoanDetails LoanCalculator::calculateLoan(double loanAmount, double annualInterestRate, int termInMonths) {
    // TODO: Implement loan calculation
    // INSTRUCTIONS:
    // 1. Create a LoanDetails struct and fill in the basic information
    // 2. Calculate monthly interest rate: annualInterestRate / 100.0 / 12.0
    // 3. Use calculateMonthlyPayment() to get the monthly payment
    // 4. Calculate total amount: monthlyPayment * termInMonths
    // 5. Calculate total interest: totalAmount - loanAmount
    // 6. Return the completed LoanDetails struct
    
    LoanDetails loan;
    // Your implementation here
    return loan;
}

double LoanCalculator::calculateMonthlyPayment(double loanAmount, double monthlyRate, int termInMonths) {
    // TODO: Implement monthly payment calculation using the loan formula
    // INSTRUCTIONS:
    // 1. Handle special case: if monthlyRate == 0, return loanAmount / termInMonths
    // 2. Use the loan payment formula:
    //    Payment = P * [r * (1 + r)^n] / [(1 + r)^n - 1]
    //    Where: P = loanAmount, r = monthlyRate, n = termInMonths
    // 3. Use std::pow(base, exponent) for power calculations
    // 4. Return the calculated monthly payment
    
    // Your implementation here
    return 0.0;
}

std::vector<PaymentSchedule> LoanCalculator::generatePaymentSchedule(const LoanDetails& loan) {
    // TODO: Generate complete payment schedule
    // INSTRUCTIONS:
    // 1. Create an empty vector<PaymentSchedule> called schedule
    // 2. Calculate monthlyRate: loan.annualInterestRate / 100.0 / 12.0
    // 3. Initialize remainingBalance = loan.loanAmount
    // 4. Loop from month 1 to loan.termInMonths:
    //    a. Create PaymentSchedule payment
    //    b. payment.month = current month number
    //    c. payment.interest = remainingBalance * monthlyRate
    //    d. payment.principal = loan.monthlyPayment - payment.interest
    //    e. payment.payment = loan.monthlyPayment
    //    f. remainingBalance -= payment.principal
    //    g. payment.remainingBalance = remainingBalance (set to 0.0 if < 0.01)
    //    h. Add payment to schedule vector
    // 5. Return the schedule vector
    
    std::vector<PaymentSchedule> schedule;
    // Your implementation here
    return schedule;
}
