#include "../../header.h"

double calcProc(double initPay, double price, int time, double initRate)
{
    double credit = price - initPay;
    double PayToCredit = credit * initRate / 100 * time + credit;
    double PayToMonth = PayToCredit / time / 12;
    return PayToMonth;
}