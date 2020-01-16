#include <iostream>
#include <dijkstra.hpp>

int main() {
    std::cout << "Dijkstra" << std::endl;
    node i;
    graph g=graph("plik");
    g.dijkstra();
    g.visualize();

}