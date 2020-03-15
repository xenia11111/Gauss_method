#include<iostream>;
#pragma warning(disable : 4996)

using namespace::std;

class Matrix {

	int dim;

	int swap_counter = 0;

	double** mx;

public:

	Matrix(int n) {

		dim = n;

		mx = new double*[dim];

		for (int i = 0; i < dim; i++) {

			for (int j = 0; j < dim + 1; j++) {

				mx[i] = new double[dim + 1];

			}

		}



	}

	void generate()

	{

		{

			for (int i = 0; i < dim; i++)

				for (int j = 0; j < dim + 1; j++)

					mx[i][j] = rand() % 100;

		}

		cout << "\n";

		display();



	}

	void create() {
		cout << "Write extended matrix: "<< endl;
		for (int i = 0; i < dim; i++) {

			for (int j = 0; j < dim + 1; j++) {

				cin >> mx[i][j];

			}

		}

	}

	void swap(int n) {

		

		for (int k = n; k < dim; ++k) {

			if (mx[k][n] != 0) {

				for (int j = 0; j < dim + 1; ++j) {

					double t = mx[n][j];

					mx[n][j] = mx[k][j];

					mx[k][j] = t;



				}

				

				break;

			}



		}



		


	}

	void gauss() {

		

		for (int i = 0; i < dim; i++) {

			for (int k = i + 1; k < dim; k++) {

				if (mx[i][i] == 0) {

					swap(i);



					swap_counter++;

				}


				double sub = mx[k][i] / mx[i][i];
				for (int j = 0; j < dim + 1; j++) {
					
					mx[k][j] -= sub*mx[i][j];
					



				}
				



			}

		}

	}

	double determinant() {
		gauss();
		double det = 1;

		for (int k = 0; k < dim; ++k) {

			det *= mx[k][k];

		}

		return det;

	}

	void sol() {
		cout << "Solution: "<<endl;
		if (determinant() != 0) {

			double* x = new double[dim];

			for (int k = dim - 1; k >= 0; k--) {

				x[k] = mx[k][dim] / mx[k][k];

				for (int c = dim - 1; c > k; c--) {

					x[k] = x[k] - mx[k][c] * x[c] / mx[k][k];

				}

			}

			for (int i = 0; i < dim; ++i) {

				cout << x[i] << " ";

			}
			cout << endl;


		}

		else { cout << determinant(); }

	}

	void display() {
		
		cout << '\n';

		for (int i = 0; i < dim; i++) {

			for (int j = 0; j < dim; j++) {

				cout << mx[i][j] << " ";

			}

			cout << endl;

		}

	}

};

int main() {
	
	

	int dim;
	cout << "Size of matrix: "<<endl;
	cin >> dim;

	Matrix M(dim);

	M.create();
	M.gauss();
	M.display();
	M.sol();
	system("pause");
}

