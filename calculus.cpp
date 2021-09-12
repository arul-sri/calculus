#include <iostream>
#include <iomanip>
using std::setprecision; using std::fixed;
using std::cout; using std::cin; using std::endl;

double fn(double x) {
    double a;
    a = ((-6.0*x*x) + (5.0*x) + 3.0);
    return a;
}

double integral(double x) {
    double a;
    a = ((-2.0*x*x*x) + ((2.5)*x*x) + 3.0*x);
    return a;
} 

double trapezoid(double a, double b, long n) {
    double increment = (b-a)/n;
    double a1;
    double b1;
    double total;
    increment = (b-a)/n;
    for (a1=a, b1=a1+increment; b>=b1; a1+=increment, b1+=increment){
        double y1;
        double y2;
        double area;
        y1 = fn(a1);
        y2 = fn(b1);
        area = (((y1+y2)/2.0) * increment);
        total += area;
    }
    return total;
}

int main(){
    double a,b, tolerance;
    long n;
    double actualArea, trapArea;
    cout << "Lower Range:"<< endl;
    cin >> a;
    cout << "Upper Range:"<<endl;
    cin >> b;
    cout << "Tolerance:"<<endl;
    cin >> tolerance;
    cout << "Initial trapezoid count:"<<endl;
    cin >> n;
    actualArea = integral(b)-integral(a);
    trapArea = trapezoid(a,b,n);
    cout << setprecision(4);
    cout << fixed;
    while (actualArea-trapArea > tolerance){
        double diff = actualArea-trapArea;
        cout<< "Intermediate Result:" << trapArea << ", traps:" << n << ", diff:" << diff << endl;
        n = n*2;
        trapArea = trapezoid(a,b,n);
    }
    cout << "Trap count:" << n << ", estimate:" << trapArea << ", exact:" << actualArea << ", tolerance:" << tolerance;
}