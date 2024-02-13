/**
  @file      Funckje.h
  @brief     Plik nagłówkowy z implementacją algorytmu Kruskala
  @details   Struktura Edge opisująca krawędzie w grafie. Funkcja find służy do znajdowania reprezentanta zbioru dla danego wierzchołka. Funkcja kruskal realizuje algorytm Kruskala i zwraca minimalne drzewo rozpinające jako wektor par.
 */

#pragma once
#ifndef FUNKCJE_H
#define FUNCKJE_H
#include <vector>
#include <algorithm>
#include <iostream>

 /**
  @struct Edge
  @brief Struktura opisująca krawędzie w grafie
  @var Edge::x
  Wierzchołek startowy krawędzi
  @var Edge::y
  Wierzchołek końcowy krawędzi
  @var Edge::weight
  Waga krawędzi
  */
struct Edge {
    int x, y;
    double weight;
    

    /**
    @brief Operator porównania dwóch krawędzi
    @details Porównuje wagę dwóch krawędzi i zwraca true, jeśli waga pierwszej jest mniejsza.
    @param other Krawędź do porównania z obecną.
    @return true, jeśli waga obecnej krawędzi jest mniejsza od wagi krawędzi other.
    */
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};


/**
 @brief Funkcja znajdująca reprezentanta zbioru dla danego wierzchołka
 @param x Wierzchołek, dla którego szukany jest reprezentant.
 @param parents Wektor rodziców każdego wierzchołka.
 @return Indeks wierzchołka reprezentującego zbiór zawierający wierzchołek x.
 */
int find(int x, std::vector<int>& parents);




/**
 @brief Funkcja wyznaczająca minimalne drzewo rozpinające grafu
 @param parents - wektor przechowujący informację o rodzicach wierzchołków
 @param edges - wektor przechowujący krawędzie grafu
 @return vector<pair<double, pair<int, int>>> - wektor par przechowujący wagę krawędzi i pary wierzchołków
 */
std::vector<std::pair<double, std::pair<int, int>>> kruskal(std::vector<int>& parents, std::vector<Edge>& edges);

#endif FUNKCJE_H

