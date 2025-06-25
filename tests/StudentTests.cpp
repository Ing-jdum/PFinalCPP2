
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include "../core/LoanCalculator.h"
#include "../core/CreditAnalyzer.h"
#include "../utils/Validation.h"
#include "../ui/InputHandler.h"

// Test helper function
bool isClose(double a, double b, double tolerance = 0.01) {
    return std::abs(a - b) < tolerance;
}

void testLoanCalculator() {
    std::cout << "=== Testing LoanCalculator ===" << std::endl;
    
    // Test 1: Basic loan calculation
    std::cout << "Test 1: Basic loan calculation... ";
    LoanDetails loan = LoanCalculator::calculateLoan(100000, 5.0, 360); // $100k, 5%, 30 years
    
    // Expected monthly payment: ~$536.82
    bool test1Pass = isClose(loan.monthlyPayment, 536.82, 1.0) &&
                     isClose(loan.totalAmount, 193255.20, 100.0) &&
                     isClose(loan.totalInterest, 93255.20, 100.0);
    
    std::cout << (test1Pass ? "PASS" : "FAIL") << std::endl;
    if (!test1Pass) {
        std::cout << "  Expected monthly payment: ~536.82, got: " << loan.monthlyPayment << std::endl;
    }
    
    // Test 2: Zero interest loan
    std::cout << "Test 2: Zero interest loan... ";
    LoanDetails zeroLoan = LoanCalculator::calculateLoan(12000, 0.0, 12); // $12k, 0%, 1 year
    bool test2Pass = isClose(zeroLoan.monthlyPayment, 1000.0, 0.01) &&
                     isClose(zeroLoan.totalInterest, 0.0, 0.01);
    
    std::cout << (test2Pass ? "PASS" : "FAIL") << std::endl;
    if (!test2Pass) {
        std::cout << "  Expected monthly payment: 1000.00, got: " << zeroLoan.monthlyPayment << std::endl;
    }
    
    // Test 3: Payment schedule generation
    std::cout << "Test 3: Payment schedule generation... ";
    std::vector<PaymentSchedule> schedule = LoanCalculator::generatePaymentSchedule(zeroLoan);
    bool test3Pass = schedule.size() == 12 &&
                     isClose(schedule[0].principal, 1000.0, 0.01) &&
                     isClose(schedule[0].interest, 0.0, 0.01) &&
                     isClose(schedule[11].remainingBalance, 0.0, 0.01);
    
    std::cout << (test3Pass ? "PASS" : "FAIL") << std::endl;
    if (!test3Pass) {
        std::cout << "  Expected 12 payments, got: " << schedule.size() << std::endl;
    }
    
    std::cout << "LoanCalculator tests completed.\n" << std::endl;
}

void testCreditAnalyzer() {
    std::cout << "=== Testing CreditAnalyzer ===" << std::endl;
    
    // Test 1: Debt-to-income ratio
    std::cout << "Test 1: Debt-to-income ratio calculation... ";
    double ratio1 = CreditAnalyzer::calculateDebtToIncomeRatio(5000, 1500); // 30%
    double ratio2 = CreditAnalyzer::calculateDebtToIncomeRatio(0, 1000); // No income
    
    bool test1Pass = isClose(ratio1, 0.30, 0.01) && isClose(ratio2, 1.0, 0.01);
    std::cout << (test1Pass ? "PASS" : "FAIL") << std::endl;
    if (!test1Pass) {
        std::cout << "  Expected 0.30 and 1.0, got: " << ratio1 << " and " << ratio2 << std::endl;
    }
    
    // Test 2: Payment-to-income ratio
    std::cout << "Test 2: Payment-to-income ratio calculation... ";
    double ratio3 = CreditAnalyzer::calculatePaymentToIncomeRatio(4000, 800); // 20%
    bool test2Pass = isClose(ratio3, 0.20, 0.01);
    
    std::cout << (test2Pass ? "PASS" : "FAIL") << std::endl;
    if (!test2Pass) {
        std::cout << "  Expected 0.20, got: " << ratio3 << std::endl;
    }
    
    // Test 3: Credit evaluation - APPROVED case
    std::cout << "Test 3: Credit evaluation (approved case)... ";
    CreditProfile goodProfile;
    goodProfile.monthlyIncome = 8000;
    goodProfile.debtLevel = 1000;  // 12.5% debt ratio
    goodProfile.creditScore = 750;
    goodProfile.loanAmount = 200000;
    goodProfile.monthlyPayment = 1200; // 15% payment ratio
    
    CreditResult result1 = CreditAnalyzer::evaluateCredit(goodProfile);
    bool test3Pass = result1.decision == CreditDecision::APPROVED;
    
    std::cout << (test3Pass ? "PASS" : "FAIL") << std::endl;
    if (!test3Pass) {
        std::cout << "  Expected APPROVED, got different decision" << std::endl;
    }
    
    // Test 4: Credit evaluation - REJECTED case (low credit score)
    std::cout << "Test 4: Credit evaluation (rejected - low score)... ";
    CreditProfile badProfile = goodProfile;
    badProfile.creditScore = 550; // Below minimum
    
    CreditResult result2 = CreditAnalyzer::evaluateCredit(badProfile);
    bool test4Pass = result2.decision == CreditDecision::REJECTED;
    
    std::cout << (test4Pass ? "PASS" : "FAIL") << std::endl;
    if (!test4Pass) {
        std::cout << "  Expected REJECTED, got different decision" << std::endl;
    }
    
    std::cout << "CreditAnalyzer tests completed.\n" << std::endl;
}

void testValidation() {
    std::cout << "=== Testing Validation ===" << std::endl;
    
    // Test 1: Valid double checking
    std::cout << "Test 1: Double validation... ";
    bool test1Pass = Validation::isValidDouble("123.45") &&
                     Validation::isValidDouble("0") &&
                     Validation::isValidDouble("-50.5") &&
                     !Validation::isValidDouble("abc") &&
                     !Validation::isValidDouble("12.34.56") &&
                     !Validation::isValidDouble("");
    
    std::cout << (test1Pass ? "PASS" : "FAIL") << std::endl;
    
    // Test 2: Valid integer checking
    std::cout << "Test 2: Integer validation... ";
    bool test2Pass = Validation::isValidInt("123") &&
                     Validation::isValidInt("0") &&
                     Validation::isValidInt("-45") &&
                     !Validation::isValidInt("12.5") &&
                     !Validation::isValidInt("abc") &&
                     !Validation::isValidInt("");
    
    std::cout << (test2Pass ? "PASS" : "FAIL") << std::endl;
    
    // Test 3: String trimming
    std::cout << "Test 3: String trimming... ";
    bool test3Pass = Validation::trim("  hello  ") == "hello" &&
                     Validation::trim("world") == "world" &&
                     Validation::trim("   ") == "" &&
                     Validation::trim("") == "";
    
    std::cout << (test3Pass ? "PASS" : "FAIL") << std::endl;
    
    // Test 4: Lowercase conversion
    std::cout << "Test 4: Lowercase conversion... ";
    bool test4Pass = Validation::toLowerCase("HELLO") == "hello" &&
                     Validation::toLowerCase("World") == "world" &&
                     Validation::toLowerCase("123ABC") == "123abc" &&
                     Validation::toLowerCase("") == "";
    
    std::cout << (test4Pass ? "PASS" : "FAIL") << std::endl;
    
    // Test 5: Unit name validation
    std::cout << "Test 5: Unit name validation... ";
    bool test5Pass = Validation::isValidUnitName("meter") &&
                     Validation::isValidUnitName("square meter") &&
                     Validation::isValidUnitName("kg") &&
                     !Validation::isValidUnitName("123abc") &&
                     !Validation::isValidUnitName("") &&
                     !Validation::isValidUnitName("   ");
    
    std::cout << (test5Pass ? "PASS" : "FAIL") << std::endl;
    
    std::cout << "Validation tests completed.\n" << std::endl;
}

int main() {
    std::cout << "=== STUDENT TEST SUITE ===" << std::endl;
    std::cout << "Run this after implementing each class to verify your work!\n" << std::endl;
    
    testValidation();
    testLoanCalculator();
    testCreditAnalyzer();
    
    std::cout << "=== ALL TESTS COMPLETED ===" << std::endl;
    std::cout << "If you see PASS for all tests, your implementation is working correctly!" << std::endl;
    std::cout << "If you see FAIL, check the expected vs actual values and fix your code." << std::endl;
    
    return 0;
}
