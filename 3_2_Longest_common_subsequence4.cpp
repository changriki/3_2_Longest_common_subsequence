#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std; 

int lcs(char *X, char *Y, int m, int n) {
	int c[2][n+1];

	for(int h=0; h<=m; h++) {
		for(int k=0; k<=n; k++)
			c[h%2][k] = 0;
	}

	if(m == 0 || n == 0) return 0;

	else {
		for(int i=1; i<=m; i++) {
			for(int j=1; j<=n; j++) {
				if(X[i] == Y[j]) {
					c[i%2][j] = c[(i+1)%2][j-1] + 1;
				}
				else if(c[(i+1)%2][j] >= c[i%2][j-1]) {
					c[i%2][j] = c[(i+1)%2][j];
				}
				else {
					c[i%2][j] = c[i%2][j-1];
				}
			}
		}
		return c[m%2][n];
	}
}

int main() {
	int stringLong[3] = {20100, 0, 0};
	char X[stringLong[0]];
	char Y[stringLong[0]];

//############# read by cin, begin
	// for(int i=0; i<stringLong[0]; i++) {
	// 	X[i] = getchar();
	// 	stringLong[1] = i;
	// 	if(X[i] == '\n') break;
	// }

	// for(int j=0; j<stringLong[0]; j++) {
	// 	Y[j] = getchar();
	// 	stringLong[2] = j;
	// 	if(Y[j] == '\n') break;
	// }
//############# read by cin, end

//############# read from file, begin
	string filename("3_2_input2.txt");
	char character=0;
  	ifstream input_file(filename);

  	if (!input_file.is_open()) {
    	cerr << "Could not open the file - '" << filename << "'" << endl;
    	return EXIT_FAILURE;
  	}

  	int i = 0;
  	cout << endl << "Loading X part.." << endl;
  	while (input_file.get(character) && character!='\n') {
  		i++;
    	if(character=='\n') {
			cout << stringLong[1] << endl;
			break;
		}
		else if(character<65 || character>90) cout << "shit! X!" << endl;
    	else {
    		X[i] = character;
    		stringLong[1] = i;
    	}
  	}
  	cout << "i = " << stringLong[1] << endl;
  	int j = 0;
  	cout << "X finished. " << endl << "Loading Y part.." << endl;
  	while (input_file.get(character) && character!='\n') {
  		j++;
    	if(character=='\n') {
      		cout << stringLong[2] << endl;
      		break;
    	}
    	else if(character<65 || character>90) cout << "shit! Y!" << endl;
    	else {
    		Y[j] = character;
    		stringLong[2] = j;
    	}
  	}
  	cout << "Y finished. " << endl;
  	cout << "j = " << stringLong[2] << endl;
  	input_file.close();
//############# read from file, end

  	cout << "File reading is finished. " << endl;

	int m = stringLong[1];
	int n = stringLong[2];

	// for(int k=0; k<=m; k++) 
	cout << X[m];
	cout << m << endl;
	// for(int l=0; l<=n; l++) 
	cout << Y[n];
	cout << n << endl;

	cout << lcs( X, Y, m, n ) << endl;
	
	return 0;
}