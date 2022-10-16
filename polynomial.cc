#include <iostream>
#include <cstdlib>
#include <math.h>
#include "polynomial.h"

Linux103::Polynomial::Polynomial(std::vector<std::vector<int>> input) 
{
	matrix = input;
    	remove_zeros();
}

Linux103::Polynomial::Polynomial(int argc, char** argv)
{
		make_matrix(argc, argv);
			remove_zeros();
}

void Linux103::Polynomial::remove_zeros()
{
	    for (int i = 0; i < matrix.size(); i++)
		        {
				        if (matrix[i][0] == 0)
						        {
								         matrix.erase(matrix.begin() + i);
									                i--;
											        }
					    }
}
void Linux103::Polynomial::print() const
{
	    for(int i = 0; i < matrix.size(); i++)
		        {
				        if(std::abs(matrix[i][0]) != 1)
						            std::cout << matrix[i][0];
					        else if(std::abs(matrix[i][0]) == 1 && matrix[i][1] == 0)
							            std::cout << matrix[i][0];
						        if (matrix[i][1] != 0)
										{    std::cout << "x";
													    if (matrix[i][1] != 1)
														    		    {
																	    			    std::cout << "^";
																				    			    std::cout << matrix[i][1];
																							    		    }
													    		}
									if(i + 1 < matrix.size() && matrix[i + 1][0] > 0)
												    std::cout << "+";
										}
}

void Linux103::Polynomial::add(int coef, int degree)
{
	    for (int i = 0; i < matrix.size(); i++)
		            if (matrix[i][1] == degree)
				            {
						                matrix[i][0] += coef;
								            return;
									            }
	        std::vector<int> v1 = {coef, degree};
		    matrix.push_back(v1);
}

void Linux103::Polynomial::make_matrix(int argc, char **argv)
{
		for (int i = 0; i < argc / 2; i++)
				{
					        std::vector<int> v1;
						        for (int j = 0; j < 2; j++)
										{
														int num = atoi(argv[i * 2 + j + 1]);
														            v1.push_back(num);
															    		}
							        matrix.push_back(v1);
								    }
}

int  Linux103::Polynomial::calculate(int xValue) const
{
		int result = 0;
			for(int i = 0; i < matrix.size(); i++)
						result += matrix[i][0] * pow((long double)xValue, matrix[i][1]);
				return (result);
}

Linux103::Polynomial Linux103::Polynomial::derive() const
{
		std::vector<std::vector<int>> tmp;
			for(int i = 0; i < matrix.size(); i++)
					{
							    std::vector<int> v1;
							    	    v1.push_back(matrix[i][0] * matrix[i][1]);
								    	    v1.push_back(matrix[i][1] - 1);
									    	    tmp.push_back(v1);
										    	}
				return Polynomial(tmp);
}

