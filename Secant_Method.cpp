//*****************************************************************************************************************
//** This application will solve for the approximate roots of the function 0.25x^2 - xsin(x-1)  - 0.5cos(2x) - 5 **
//** using the Secant method. 2 initial "guesses" of approximates roots are required, which are supplied by the  **
//** user.                                                                                                       **
//*****************************************************************************************************************

#include <iostream>
#include <iomanip>
#include <cmath>

const float TOLERANCE = 0.00001;

void menu();
double Secant();
double functionOutput(double);

int main() {
    menu();

    std::cin.ignore();

	return 0;
}

void menu(){
	double approximateRoot = 0.0;

	approximateRoot = Secant();

	std::cout << "\n" << "The value of the approximate root of the function is: " << approximateRoot << "\n";
}

double Secant() {
    double initialGuess_A;
	double initialGuess_B;

	double root, rootPrevious_A, rootPrevious_B;
	double functionResult, resultPrevious_A, resultPrevious_B;

	double error = 1.0;

	int n;

    std::cout << "Please enter initial value A: ";
	std::cin >> initialGuess_A;

	std::cout << "Please enter initial value B: ";
	std::cin >> initialGuess_B;

	std::cout << "\n" << "n" << std::setw(15) << "Xn" << std::setw(15) << "f(Xn)" << std::setw(15) << "Error" << "\n";

	for (n = 0; error > TOLERANCE; n++) {
		if (n == 0) {
			root = initialGuess_A;

			functionResult = functionOutput(root);

			rootPrevious_B = root;

			resultPrevious_B = functionResult;
		}
		else if (n == 1) {
			root = initialGuess_B;

			functionResult = functionOutput(root);

			rootPrevious_A = root;

			resultPrevious_A = functionResult;

			error = abs(rootPrevious_A - rootPrevious_B);
		}
		else {
			root = (rootPrevious_A - ((rootPrevious_A - rootPrevious_B) / (resultPrevious_A - resultPrevious_B)) * (resultPrevious_A));

			functionResult = functionOutput(root);

			rootPrevious_B = rootPrevious_A;

			rootPrevious_A = root;

			resultPrevious_B = resultPrevious_A;

			resultPrevious_A = functionResult;

			error = abs(rootPrevious_A - rootPrevious_B);
		}
		std::cout << n << std::setprecision(5) << std::setw(15) << root << std::setprecision(5) << std::setw(15) << functionResult << std::setprecision(5) << std::setw(15) << error << "\n";
	}
	return root;
}

double functionOutput(double x) {
	double y = (0.25 * pow(x, 2.0) - x * sin(x - 1.0) - 0.5 * cos(2.0 * x) - 5.0);

	return y;
}