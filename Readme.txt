Project Cmatrix implenting the class CMatrix in C++, using Visual Studio 2017 on Windows
The execution of the file is with the syntax : ./Matrix.exe [filename]
you can put as many filenames as you want at once

TypeMatrix=<type_base_C>
NBLines=<Number_of_lines_of_the_matrix>
NBColumns=<Number_of_columns_of_the_matrix>
Matrix=[
<Row_1: as many elements as columns>
<Line_n: as many elements as columns>
…
<Line_NBLines: as many elements as columns>
]

For an external use, here the differents method of CMatrix : 

CMatrix(): a default constructor which creates an empty matrix with 0 rows and 0 columns.
CMatrix(unsigned int nbRow, unsigned int nbColum): a constructor which creates a matrix with the specified number of rows and columns.
CMatrix(const CMatrix<MType>& MATParam): a copy constructor which creates a new matrix that is a copy of an existing matrix MATParam.
CMatrix(const char* pcFileName): a constructor which reads matrix data from a text file specified by the file name pcFileName.
~CMatrix(): a destructor which frees the dynamically allocated memory used by the matrix data.
MATGetNbColum(): a function which returns the number of columns in the matrix.
MATGetNbRow(): a function which returns the number of rows in the matrix.
MATGetValue(unsigned int uiNumColum, unsigned int uiNumRow): a function which returns the value of the matrix element located in the specified column uiNumColum and row uiNumRow.
MATSetValue(unsigned int uiNumColum, unsigned int uiNumRow, MType mtValue): a function which sets the value of the matrix element located in the specified column uiNumColum and row uiNumRow to the given value mtValue.
operator+(): an overloaded operator which performs matrix addition between two matrices using the '+' operator.
operator-(): an overloaded operator which performs matrix subtraction between two matrices using the '-' operator.
operator=(): an overloaded operator which replaces the matrix data of the object with the matrix data of an existing matrix object.
operator*(): an overloaded operator which performs matrix multiplication between two matrices using the '*' operator.
operator*(): an overloaded operator which performs scalar multiplication of the matrix by a double value using the '*' operator.
operator/(): an overloaded operator which performs scalar division of the matrix by a double value using the '/' operator.
MATTranspose(): a function which returns a new matrix that is the transpose of the current matrix.
MATPrint(): a function which prints the matrix data to the console.