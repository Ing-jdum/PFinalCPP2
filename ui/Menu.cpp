#include "Menu.h"
#include "InputHandler.h"
#include "../core/LoanCalculator.h"
#include "../core/CreditAnalyzer.h"
#include <iostream>
#include <iomanip>

Menu::Menu() {}

void Menu::run() {
    bool running = true;

    while (running) {
        showMainMenu();
        int choice = InputHandler::getInt("Enter your choice: ");

        switch (choice) {
            case 1:
                handleLoanSimulator();
                break;
            case 2:
                handleCreditAnalysis();
                break;
            case 3:
                running = false;
                std::cout << "Thank you for using the Loan Simulator!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        if (running) {
            InputHandler::waitForEnter();
        }
    }
}

void Menu::showMainMenu() {
    std::cout << "\n=== LOAN SIMULATOR ===" << std::endl;
    std::cout << "1. Loan Calculator" << std::endl;
    std::cout << "2. Credit Analysis" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "======================" << std::endl;
}

void Menu::handleLoanSimulator() {
    std::cout << "\n--- LOAN CALCULATOR ---" << std::endl;

    double loanAmount = InputHandler::getDouble("Enter loan amount: $");
    double annualRate = InputHandler::getDouble("Enter annual interest rate (%): ");
    int termMonths = InputHandler::getInt("Enter repayment term (months): ");

    if (loanAmount <= 0 || annualRate < 0 || termMonths <= 0) {
        std::cout << "Invalid input values. Please enter positive numbers." << std::endl;
        return;
    }

    LoanDetails loan = LoanCalculator::calculateLoan(loanAmount, annualRate, termMonths);

    std::cout << "\n=== LOAN CALCULATION RESULTS ===" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Loan Amount:        $" << loan.loanAmount << std::endl;
    std::cout << "Interest Rate:      " << loan.annualInterestRate << "% per year" << std::endl;
    std::cout << "Term:               " << loan.termInMonths << " months" << std::endl;
    std::cout << "Monthly Payment:    $" << loan.monthlyPayment << std::endl;
    std::cout << "Total Amount:       $" << loan.totalAmount << std::endl;
    std::cout << "Total Interest:     $" << loan.totalInterest << std::endl;

    if (InputHandler::getYesNo("Would you like to see the payment schedule?")) {
        std::vector<PaymentSchedule> schedule = LoanCalculator::generatePaymentSchedule(loan);

        std::cout << "\n=== PAYMENT SCHEDULE ===" << std::endl;
        std::cout << std::setw(6) << "Month" 
                  << std::setw(12) << "Payment" 
                  << std::setw(12) << "Principal" 
                  << std::setw(12) << "Interest" 
                  << std::setw(15) << "Balance" << std::endl;
        std::cout << std::string(57, '-') << std::endl;

        for (const auto& payment : schedule) {
            std::cout << std::setw(6) << payment.month
                      << std::setw(12) << payment.payment
                      << std::setw(12) << payment.principal
                      << std::setw(12) << payment.interest
                      << std::setw(15) << payment.remainingBalance << std::endl;
        }
    }
}

void Menu::handleCreditAnalysis() {
    std::cout << "\n--- CREDIT ANALYSIS ---" << std::endl;

    CreditProfile profile;
    profile.monthlyIncome = InputHandler::getDouble("Enter monthly income: $");
    profile.debtLevel = InputHandler::getDouble("Enter current monthly debt payments: $");
    profile.creditScore = InputHandler::getInt("Enter credit score (300-850): ");
    profile.loanAmount = InputHandler::getDouble("Enter requested loan amount: $");

    // Calculate monthly payment for the requested loan
    double annualRate = InputHandler::getDouble("Enter proposed interest rate (%): ");
    int termMonths = InputHandler::getInt("Enter proposed term (months): ");

    if (profile.monthlyIncome <= 0 || profile.debtLevel < 0 || 
        profile.creditScore < 300 || profile.creditScore > 850 ||
        profile.loanAmount <= 0 || annualRate < 0 || termMonths <= 0) {
        std::cout << "Invalid input values. Please check your entries." << std::endl;
        return;
    }

    LoanDetails proposedLoan = LoanCalculator::calculateLoan(profile.loanAmount, annualRate, termMonths);
    profile.monthlyPayment = proposedLoan.monthlyPayment;

    CreditResult result = CreditAnalyzer::evaluateCredit(profile);

    std::cout << "\n=== CREDIT ANALYSIS RESULTS ===" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Monthly Income:           $" << profile.monthlyIncome << std::endl;
    std::cout << "Current Monthly Debt:     $" << profile.debtLevel << std::endl;
    std::cout << "Credit Score:             " << profile.creditScore << std::endl;
    std::cout << "Requested Loan:           $" << profile.loanAmount << std::endl;
    std::cout << "Proposed Monthly Payment: $" << profile.monthlyPayment << std::endl;

    double debtRatio = CreditAnalyzer::calculateDebtToIncomeRatio(profile.monthlyIncome, profile.debtLevel);
    double paymentRatio = CreditAnalyzer::calculatePaymentToIncomeRatio(profile.monthlyIncome, profile.monthlyPayment);

    std::cout << "\nDebt-to-Income Ratio:     " << std::setprecision(1) << (debtRatio * 100) << "%" << std::endl;
    std::cout << "Payment-to-Income Ratio:  " << (paymentRatio * 100) << "%" << std::endl;

    std::cout << "\n--- DECISION ---" << std::endl;
    switch (result.decision) {
        case CreditDecision::APPROVED:
            std::cout << "✅ APPROVED" << std::endl;
            break;
        case CreditDecision::CONDITIONAL:
            std::cout << "⚠️  CONDITIONAL APPROVAL" << std::endl;
            break;
        case CreditDecision::REJECTED:
            std::cout << "❌ REJECTED" << std::endl;
            break;
    }

    std::cout << "Reason: " << result.reason << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Maximum Recommended Loan: $" << result.maxLoanAmount << std::endl;
    std::cout << "Maximum Monthly Payment:  $" << result.recommendedPayment << std::endl;
}