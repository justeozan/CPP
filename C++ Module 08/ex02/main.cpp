#include "MutantStack.hpp"

int main()
{
    std::cout << DARKYELLOW << "\n=====================================================\n" << RESET << std::endl;
    // ====== test print the top ======
    std::cout << DARKYELLOW << "\n-- test print the top --" << RESET << std::endl;
    std::cout << GRAY FAINT ITALIC "creating a MutantStack..." << RESET << std::endl;
    MutantStack<int> mstack;
    std::cout << GRAY FAINT ITALIC "pushing 5, 17..." << RESET << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "mstack.top(): " << GREEN << mstack.top() << RESET << std::endl; // normally 17
    std::cout << GRAY FAINT ITALIC "popping one..." << RESET << std::endl;
    mstack.pop();
    std::cout << "mstack.top(): " << GREEN << mstack.top() << RESET << std::endl; // normally 5
    std::cout << GRAY FAINT ITALIC "popping one..." << RESET << std::endl;
    mstack.pop();
    std::cout << "mstack.size(): " << GREEN << mstack.size() << RESET << std::endl; // normally 0

    // ====== test print the iterator ======
    std::cout << DARKYELLOW << "\n-- test print the iterator --" << RESET << std::endl;
    std::cout << GRAY FAINT ITALIC "pushing 3, 5, 737, 0..." << RESET << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << GRAY FAINT ITALIC "iterating..." << RESET << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << GREEN << *it << ' ' << RESET; // normally 3 5 737 0
    std::cout << std::endl;
    std::stack<int> s(mstack);

    // ====== test print the copy stack ======
    std::cout << DARKYELLOW << "\n-- test print the copy stack --" << RESET << std::endl;
    std::cout << GRAY FAINT ITALIC "creating a copy stack from the MutantStack..." << RESET << std::endl;
    std::cout << GRAY FAINT ITALIC "iterating..." << RESET << std::endl;
    while (!s.empty()) {
        std::cout << GREEN << s.top() << ' ' << RESET; // normally 737 5 3 0
        s.pop();
    }
    std::cout << std::endl;

    std::cout << DARKYELLOW << "\n=====================================================\n" << RESET << std::endl;
    // ====== test print the top ======
    std::cout << DARKYELLOW << "\n-- test print the top --" << RESET << std::endl;
    std::cout << GRAY FAINT ITALIC "creating a std::list<int>..." << RESET << std::endl;
    std::list<int> lstack;
    std::cout << GRAY FAINT ITALIC "pushing 5, 17..." << RESET << std::endl;
    lstack.push_back(5);
    lstack.push_back(17);
    std::cout << "lstack.top(): " << GREEN << lstack.back() << RESET << std::endl; // normally 17
    std::cout << GRAY FAINT ITALIC "popping one..." << RESET << std::endl;
    lstack.pop_back();
    std::cout << "lstack.top(): " << GREEN << lstack.back() << RESET << std::endl; // normally 5
    std::cout << GRAY FAINT ITALIC "popping one..." << RESET << std::endl;
    lstack.pop_back();
    std::cout << "lstack.size(): " << GREEN << lstack.size() << RESET << std::endl; // normally 0

    // ====== test print the iterator ======
    std::cout << DARKYELLOW << "\n-- test print the iterator --" << RESET << std::endl;
    std::cout << GRAY FAINT ITALIC "pushing 3, 5, 737, 0..." << RESET << std::endl;
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    lstack.push_back(0);
    std::cout << GRAY FAINT ITALIC "iterating..." << RESET << std::endl;
    for (std::list<int>::iterator it = lstack.begin(); it != lstack.end(); ++it)
        std::cout << GREEN << *it << ' ' << RESET; // normally 3 5 737 0
    std::cout << std::endl;
    std::stack<int> s2;
    for (std::list<int>::iterator it = lstack.begin(); it != lstack.end(); ++it)
        s2.push(*it);

    // ====== test print the copy stack ======
    std::cout << DARKYELLOW << "\n-- test print the copy stack --" << RESET << std::endl;
    std::cout << GRAY FAINT ITALIC "creating a copy stack from the std::list<int>..." << RESET << std::endl;
    std::cout << GRAY FAINT ITALIC "iterating..." << RESET << std::endl;
    while (!s2.empty()) {
        std::cout << GREEN << s2.top() << ' ' << RESET; // normally 737 5 3 0
        s2.pop();
    }
    std::cout << std::endl;

    return 0;
}


