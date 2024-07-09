#ifndef HEADER_HPP
# define HEADER_HPP

/* 
 *	These prototypes can be useful as they can specify for the compilation if classes or
 *	other components exist and are used within this header file, allowing the compiler to
 *	understand their interfaces without needing their full definitions immediately.
 *	This helps manage dependencies and avoid circular inclusion issues in larger codebases.
 *	Sometimes it's not helping for particulary case like contact[8] which is an array :
 *	In this case, only the order of inclusion has an impact and must be respected.
 */

/* prototypes (forward declaration) */

class Contact;
class PhoneBook;

/* public library */

# include <iomanip>
# include <iostream>
# include <string>
# include <sstream>
# include <limits>

/* private library */

# include "Contact.hpp"
# include "PhoneBook.hpp"

/* Colors */

# define RED	"\e[0;31m"
# define RESET	"\x1b[0m"


#endif