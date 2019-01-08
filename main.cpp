#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string problem = "Hello, World!";
    std::cout << problem << std::endl;
    std::reverse(problem.begin(), problem.end());
    std::cout << problem << std::endl;
    return 0;
}