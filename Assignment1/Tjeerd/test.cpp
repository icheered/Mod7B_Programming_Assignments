#include <iostream>
void function();
int a = 20;
int main() {
    int a = 10;
    function();
    std::cout << a;
    return 0;
}
void function() {
    std::cout << a << std::endl;
}