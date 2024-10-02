#ifndef TEST_H
# define TEST_H

/*===========================================*/
/*                 INCLUDES                  */
/*===========================================*/

# include <iostream>

/*===========================================*/
/*                  COLORS                   */
/*===========================================*/

# define RESET		"\033[0m"
# define RED		"\033[0;31m"
# define WHITE		"\033[37m"
# define GREEN		"\033[32m"
# define BLUE		"\033[0;34m"
# define YELLOW		"\033[0;33m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"

/*===========================================*/
/*                  CLASS                    */
/*===========================================*/

class Test
{
	private:
		int	_monAttribut;

	public:
		Test();
		Test();
		~Test();
		Test&	operator=(const Test& other);

		void	get();

		void	maMethode();
};

#endif /* TEST_H */