/**
  @file      Funckje.cpp
  @brief     Plik z funkcjami
 */
#include "Funkcje.h"
 /**
@brief Funkcja znajduj�ca reprezentanta zbioru dla danego wierzcho�ka
@param x Wierzcho�ek, dla kt�rego szukany jest reprezentant.
@param parents Wektor rodzic�w ka�dego wierzcho�ka.
@return Indeks wierzcho�ka reprezentuj�cego zbi�r zawieraj�cy wierzcho�ek x.
*/
int find(int x, std::vector<int>& parents) {
    if (parents[x] == x) return x;
    return parents[x] = find(parents[x], parents);
}
/**
 @brief Funkcja wyznaczaj�ca minimalne drzewo rozpinaj�ce grafu
 @param parents - wektor przechowuj�cy informacj� o rodzicach wierzcho�k�w
 @param edges - wektor przechowuj�cy kraw�dzie grafu
 @return vector<pair<double, pair<int, int>>> - wektor par przechowuj�cy wag� kraw�dzi i pary wierzcho�k�w
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

