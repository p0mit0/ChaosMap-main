#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "fonctions/physique.h"
#include "fonctions/euler.h"
#include "fonctions/verlet.h"
#include "fonctions/yoshida.h"
#include "fonctions/rk4.h"

int main()
{
    std::cout << "Hello world" << std::endl;

    for (size_t x = 0; x < RES; x++)
    {
        for (size_t y = 0; y < RES; y++)
        {
            Mat_space[x][y] = vec2{(float)x, (float)y};
        }
    }
// matrice positions ayant variées
    for (size_t x = 0; x < RES; x++)
    {
        for (size_t y = 0; y < RES; y++)
        {
            Mat_space_var[x][y] = vec2{x + delta, y + delta};
        }
    }

    std::cout << "initialisation euler" << std::endl;
    for (int i = 0; i < RES; i++)
    {
        for (int j = 0; j < RES; j++)
        {
            Mat_space_euler[i][j] = Mat_space[i][j];
            Mat_space_var_euler[i][j] = Mat_space_var[i][j];
        }
    }
    euler(Mat_space_euler);
    euler(Mat_space_var_euler);
    std::cout << "fin euler" << std::endl;
    std::cout << "initialisation verlet" << std::endl;
    for (int i = 0; i < RES; i++)
    {
        for (int j = 0; j < RES; j++)
        {
            Mat_space_velo_verlet[i][j] = Mat_space[i][j];
            Mat_space_var_velo_verlet[i][j] = Mat_space_var[i][j];
        }
    }
    velo_verlet(Mat_space_velo_verlet);
    velo_verlet(Mat_space_var_velo_verlet);
    for (int i = 0; i < RES; i++)
    {
        for (int j = 0; j < RES; j++)
        {
            Mat_space_yoshida[i][j] = Mat_space[i][j];
            Mat_space_var_yoshida[i][j] = Mat_space_var[i][j];
        }
    }
    std::cout << "fin verlet" << std::endl;
    std::cout << "initialisation yoshida" << std::endl;
    yoshida(Mat_space_yoshida);
    yoshida(Mat_space_var_yoshida);

    for (size_t i = 0; i < RES; i++)
    {
        for (size_t j = 0; j < RES; j++)
        {
            Mat_chaos_euler[i][j] = float(norme({(float)(Mat_space_euler[i][j].x - Mat_space_var_euler[i][j].x), (float)(Mat_space_euler[i][j].y - Mat_space_var_euler[i][j].y)}));
        }
    }
    for (size_t i = 0; i < RES; i++)
    {
        for (size_t j = 0; j < RES; j++)
        {
            Mat_chaos_velo_verlet[i][j] = float(norme({(float)(Mat_space_velo_verlet[i][j].x - Mat_space_var_velo_verlet[i][j].x), (float)(Mat_space_velo_verlet[i][j].y - Mat_space_var_velo_verlet[i][j].y)}));
        }
    }
    for (size_t i = 0; i < RES; i++)
    {
        for (size_t j = 0; j < RES; j++)
        {
            Mat_chaos_yoshida[i][j] = float(norme({(float)(Mat_space_yoshida[i][j].x - Mat_space_var_yoshida[i][j].x), 
                                                   (float)(Mat_space_yoshida[i][j].y - Mat_space_var_yoshida[i][j].y)}));
        }
    }
    std::cout << "fin yoshida" << std::endl;
std::cout << "initialisation rk4" << std::endl;
    // 1. On remplit les matrices RK4 avec la grille de départ
    for (int i = 0; i < RES; i++)
    {
        for (int j = 0; j < RES; j++)
        {
            Mat_space_rk4[i][j] = Mat_space[i][j];
            Mat_space_var_rk4[i][j] = Mat_space_var[i][j];
        }
    }

    // 2. On lance l'algorithme ! (C'est ce qu'il manquait)
    rk4(Mat_space_rk4);
    rk4(Mat_space_var_rk4);

    std::cout << "fin rk4" << std::endl;

    // 3. On calcule le chaos (un seul bloc suffit)
    for (size_t i = 0; i < RES; i++)
    {
        for (size_t j = 0; j < RES; j++)
        {
            Mat_chaos_rk4[i][j] = float(norme({
                Mat_space_rk4[i][j].x - Mat_space_var_rk4[i][j].x,
                Mat_space_rk4[i][j].y - Mat_space_var_rk4[i][j].y
            }));
        }
    }
    // export 3 fichiers
auto export_csv = [&](std::string nom, float matrice[RES][RES])
{
    std::ofstream f(nom);
    for (size_t i = 0; i < RES; i++)
    {
        for (size_t j = 0; j < RES; j++)
        {
            f << matrice[i][j] << (j < RES - 1 ? "," : "");
        }
        f << "\n";
    }
    f.close();
};

    export_csv("chaos_euler.csv", Mat_chaos_euler);
    export_csv("chaos_verlet.csv", Mat_chaos_velo_verlet);
    export_csv("chaos_yoshida.csv", Mat_chaos_yoshida);
    export_csv("chaos_rk4.csv", Mat_chaos_rk4);

    std::cout << "Export terminé" << std::endl;
    system("python ../../../ChaosMap-main/ChaosMap-main/chaos_map.py");
}