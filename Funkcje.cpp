/**
  @file      Funckje.cpp
  @brief     Plik z funkcjami
 */
#include "Funkcje.h"
 /**
@brief Funkcja znajduj¹ca reprezentanta zbioru dla danego wierzcho³ka
@param x Wierzcho³ek, dla którego szukany jest reprezentant.
@param parents Wektor rodziców ka¿dego wierzcho³ka.
@return Indeks wierzcho³ka reprezentuj¹cego zbiór zawieraj¹cy wierzcho³ek x.
*/
int find(int x, std::vector<int>& parents) {
    if (parents[x] == x) return x;
    return parents[x] = find(parents[x], parents);
}
/**
 @brief Funkcja wyznaczaj¹ca minimalne drzewo rozpinaj¹ce grafu
 @param parents - wektor przechowuj¹cy informacjê o rodzicach wierzcho³ków
 @param edges - wektor przechowuj¹cy krawêdzie grafu
 @return vector<pair<double, pair<int, int>>> - wektor par przechowuj¹cy wagê krawêdzi i pary wierzcho³ków
 */
std::vector<std::pair<double, std::pair<int, int>>> kruskal(std::vector<int>& parents, std::vector<Edge>& edges) {

    std::sort(edges.begin(), edges.end());

    for (int i = 0; i <= edges.size(); i++)
        parents[i] = i;

    std::vector<std::pair<double, std::pair<int, int>>> result;
    for (int i = 0; i < edges.size(); i++) {
        int x = find(edges[i].x, parents);
        int y = find(edges[i].y, parents);
        if (x != y) {
            parents[x] = y;
            result.push_back({ edges[i].weight, {edges[i].x, edges[i].y} });  
        }
    }

    return result;

}

