//*****************************************************************************************************************
//** This application will solve for the approximate roots of the function 0.25x^2 - xsin(x-1)  - 0.5cos(2x) - 5 **
//** using the Newton-Raphson method. The Newton-Raphson methods assumes that the function f is differentiable.  **
//** An initial "guess" serves as an approximate root (supplied by the user) to begin the process.               **
//*****************************************************************************************************************

#include <iostream>
#include <iomanip>
#include <cmath>

const float TOLERANCE = 0.0001;

double Newton();
double output(double);
double outputPrime(double);
void menu();

int main() {
	menu();

	std::cin.ignore();

	return 0;
}

void menu(){
	double approximateRoot;

	approximateRoot = Newton();

	std::cout << "\n The value of the approximate root of the function is: " << approximateRoot << "\n";
}

double Newton() {
	double initialGuess;
	double functionOutput;
	double functionOutputPrime;
	double root, rootPrevious;
	double error = 1;

	int n;

	std::cout << "Please enter an inital guess: ";
	std::cin >> initialGuess;

	std::cout << "\n n" << std::setw(15) <<"Xn" << std::setw(15) <<"f(Xn)" << std::setw(15) <<"f'(Xn)" << std::setw(15) <<"Error \n";

	for (n = 0; error > TOLERANCE; n++) {
		if (n > 0) {
			rootPrevious = root;

			root = (root - (functionOutput / functionOutputPrime));

			error = abs((root - rootPrevious));

			functionOutput = output(root);

			functionOutputPrime = outputPrime(root);
		}
		else {
			root = initialGuess;

			functionOutput = output(root);

			functionOutputPrime = outputPrime(root);
		}

		std::cout << n << std::setprecision(5) << std::setw(15) << root << std::setprecision(5) << std::setw(15) << functionOutput << std::setprecision(5) << std::setw(15) << functionOutputPrime << std::setprecision(5) << std::setw(15) << error << "\n";
	}
	return root;
}

double output(double x) {
	double y = (0.25 * pow(x, 2.0) - (x * sin(x - 1)) - (0.5 * cos(2 * x)) - 5);

	return y;
}

double outputPrime(double x) {
	double y_Prime = (0.5 * x - (sin(x - 1)) - (x * (cos(x - 1))) + sin(2 * x));

	return y_Prime;
}