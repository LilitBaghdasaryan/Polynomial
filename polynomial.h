#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <vector>

namespace Linux103
{
	    class Polynomial
		        {
				        public:
						            Polynomial (std::vector<std::vector<int>> input);
							                Polynomial (int argc, char** argv);
									            void       add(int coef, int degree);
										                void       print() const;
												            int        calculate(int xValue) const;
													    	        Polynomial derive() const;
															        private:
																void       remove_zeros();
															            std::vector<std::vector<int>> matrix;
																                void       make_matrix(int argc, char **argv);
																		    };
};


#endif
