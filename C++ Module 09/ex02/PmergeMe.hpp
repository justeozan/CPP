#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>

# define RED		"\e[31m"
# define BLUE		"\e[34m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[93m"
# define DISCRET	"\e[90;2;3m"
# define RESET		"\e[0m"

class PmergeMe
{
	private:
		std::list<int> _list;
		std::vector<int> _vector;

		PmergeMe(const PmergeMe &src);
		PmergeMe&	operator=(const PmergeMe &src);

		void parseInput(char **av);
		void printNumbers(std::string str) const;
		void benchmark();
		
		// Jacobsthal helper
		std::vector<int> generateJacobsthalIndices(int size) const;

		// Helpers
		int		getNth(const std::list<int>& lst, int n);
		int		getNth(const std::vector<int>& vec, int n);
		void	insertSorted(std::list<int>& lst, int value);
		void	insertSorted(std::vector<int>& vec, int value);
		
		template <typename T>
		void sort(T& container) {
			// Cas de base : si le conteneur a 0 ou 1 élément, il est déjà trié et egalement la derniere chaine
			if (container.size() <= 1)
				return;
		
			// Alias pour simplifier l'écriture des itérateurs
			typedef typename T::iterator It;
			// On prépare deux nouveaux conteneurs :
			// - bigs : les plus grands éléments de chaque paire
			// - smalls : les plus petits éléments de chaque paire
			T bigs;
			T smalls;
		
			It it = container.begin();
			while (it != container.end()) {
				It next = it;
				++next;
				// Si on a une paire
				if (next != container.end()) {
					if (*it < *next) {
						// Si l'élément actuel est plus petit que le suivant, on ajoute le suivant dans bigs et l'actuel dans smalls
						bigs.push_back(*next);
						smalls.push_back(*it);
					} else {
						// Sinon, on ajoute l'actuel dans bigs et le suivant dans smalls
						bigs.push_back(*it);
						smalls.push_back(*next);
					}
					++it; ++it; // on avance de deux
				} else {
					// Si l’élément est seul (impair), on le met dans les grands
					bigs.push_back(*it);
					++it;
				}
				// std::cout << "bigs: ";
				// for (It it = bigs.begin(); it != bigs.end(); ++it)
				// 	std::cout << *it << " ";
				// std::cout << std::endl;
				// std::cout << "smalls: ";
				// for (It it = smalls.begin(); it != smalls.end(); ++it)
				// 	std::cout << *it << " ";
				// std::cout << std::endl;
			}
		
			sort(bigs);
		
			std::vector<int> indices = generateJacobsthalIndices(smalls.size());

			// std::cout << YELLOW "indices: " RESET ;
			// for (std::vector<int>::size_type i = 0; i < indices.size(); ++i)
			// 	std::cout << indices[i] << " ";
			// std::cout << std::endl;

			// Pour suivre quels éléments de "smalls" ont été insérés
			std::vector<bool> inserted(smalls.size(), false);

			// std::cout << BLUE "inserted: " RESET;
			// for (std::vector<bool>::size_type i = 0; i < inserted.size(); ++i)
			// 	std::cout << (inserted[i] ? 1 : 0) << " ";
			// std::cout << std::endl;

			// On remplace le conteneur de départ par les éléments triés de "bigs"
			container = bigs;
		
			// On insère dans le conteneur trié les éléments de "smalls"
			// dans l’ordre Jacobsthal
			// for (std::vector<int>::size_type i = 0; i < indices.size(); ++i) {
			// 	int idx = indices[i]; // je recup l'indice depuis la suites de jacobsthal
			// 	if (idx < static_cast<int>(smalls.size()) && !inserted[idx]) {
			// 		inserted[idx] = true;
			// 		int value = getNth(smalls, idx);	// Récupère la valeur à l'indice idx
			// 		insertSorted(container, value);		// Insère à la bonne position dans container
			// 	}
			// }
			// // Insertion des petits restants (non couverts par la suite Jacobsthal)
			// for (std::vector<int>::size_type i = 0; i < smalls.size(); ++i) {
			// 	if (!inserted[i]) {
			// 		int value = getNth(smalls, i);
			// 		insertSorted(container, value);
			// 	}
			// }

			for (std::vector<int>::size_type i = 0; i < indices.size(); ++i) {
				int idx = indices[i];
				if (idx < static_cast<int>(smalls.size()) && !inserted[idx]) {
					inserted[idx] = true;
					int value = getNth(smalls, idx);
					It pos = std::lower_bound(container.begin(), container.end(), value);
					container.insert(pos, value);
				}
			}

			for (std::vector<int>::size_type i = 0; i < smalls.size(); ++i) {
				if (!inserted[i]) {
					int value = getNth(smalls, i);
					It pos = std::lower_bound(container.begin(), container.end(), value);
					container.insert(pos, value);
				}
			}
		}
		
	public:
		PmergeMe();
		~PmergeMe();
		
		void run(char **av);
};



#endif