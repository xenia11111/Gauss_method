#include<iostream>;

using namespace::std;

void swap(int firstRow, int secondRow, double** &matrix,const double dim) {
	for (int j = 0; j < dim + 1; ++j) {
		double t = matrix[secondRow][j];
		matrix[secondRow][j] = matrix[firstRow][j];
		matrix[firstRow][j] = t;
	}
}
void gauss(double** matrix,int matrixDim) {

	int dim = matrixDim;
	for (int i = 0; i < dim; i++) {
		for (int k = i + 1; k < dim; k++) {
			if (matrix[i][i] == 0) {
				for (int k = i; k < dim; ++k) {
					if (matrix[k][i] != 0) {
						swap(k,i,matrix,dim);

					}
				}
			}
			double sub = matrix[k][i] / matrix[i][i];
			for (int j = 0; j < dim + 1; j++) {
				matrix[k][j] -= sub * matrix[i][j];
			}
		}
	}

	double* x = new double[dim];

	for (int k = dim - 1; k >= 0; k--) {

		x[k] = matrix[k][dim] / matrix[k][k];

		for (int c = dim - 1; c > k; c--) {

			x[k] = x[k] - matrix[k][c] * x[c] / matrix[k][k];

		}

	}
	cout << "Answer: " << endl;
	cout << "<";
	for (int i = 0; i < dim; ++i) {

		cout << x[i] << " ";

	}
	cout << ">";
	cout << endl;
}
int main() {

	int dim;
	cout << "Size of matrix: "<<endl;
	cin >> dim;
	
	double** matrix = new double*[dim];

	for (int i = 0; i < dim; i++) {
		matrix[i] = new double[dim + 1];
	}

	cout << "Write extended matrix: " << endl;

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim + 1; j++) {
			cin >> matrix[i][j]; 
		}
	}
	
	gauss(matrix, dim);
	system("pause");
}

