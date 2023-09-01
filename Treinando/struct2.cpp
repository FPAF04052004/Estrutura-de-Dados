#include<iostream>
#include<string>

using namespace std;

enum Genero{
    terror, 
    acao,
    romance,
    drama, 
    investigacao
};

struct Livro{
    string nome_do_livro;
    string nome_do_autor;
    int numero_de_paginas;
    Genero genero;
};
int main(){
    Livro livro;
    getline(cin, livro.nome_do_livro);
    getline(cin, livro.nome_do_livro);
    typedef std::basic_istream<char> >> livro.genero;
}