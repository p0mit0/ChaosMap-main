#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "fonctions/physique.h"
#include "fonctions/euler.h"
#include "fonctions/verlet.h"
#include "fonctions/yoshida.h"
#include "fonctions/rk4.h"
#include "fonctions/normalisation.h"

int main()
{
    std::cout << "Hello world" << std::endl;
    // remplissage de la matrice des positions initiales
    for (size_t x = 0; x < RES; x++)
    {
        for (size_t y = 0; y < RES; y++)
        {
            Mat_space[x][y] = vec2{(double)x, (double)y};
        }
    }
    // matrice positions initales ayant variées de delta
    for (size_t x = 0; x < RES; x++)
    {
        for (size_t y = 0; y < RES; y++)
        {
            Mat_space_var[x][y] = vec2{x + delta, y - delta};
        }
    }
    // on rempli mat euler avec matspace et matspace var
    std::cout << "initialisation euler" << std::endl;
    for (int i = 0; i < RES; i++)
    {
        for (int j = 0; j < RES; j++)
        {
            Mat_space_euler[i][j] = Mat_space[i][j];
            Mat_space_var_euler[i][j] = Mat_space_var[i][j];
        }
    }
    // on fait euler pour matspace et matspace var
    euler(Mat_space_euler);
    euler(Mat_space_var_euler);
    std::cout << "fin euler" << std::endl;
    // on rempli mat velo_verlet avec matspace et matspace var
    std::cout << "initialisation verlet" << std::endl;
    for (int i = 0; i < RES; i++)
    {
        for (int j = 0; j < RES; j++)
        {
            Mat_space_velo_verlet[i][j] = Mat_space[i][j];
            Mat_space_var_velo_verlet[i][j] = Mat_space_var[i][j];
        }
    }
    // on fait velo verlet sur les matrices
    velo_verlet(Mat_space_velo_verlet);
    velo_verlet(Mat_space_var_velo_verlet);
    // on rempli mat yoshida avec matspace et matspace var
    std::cout << "fin verlet" << std::endl;
    std::cout << "initialisation yoshida" << std::endl;
    for (int i = 0; i < RES; i++)
    {
        for (int j = 0; j < RES; j++)
        {
            Mat_space_yoshida[i][j] = Mat_space[i][j];
            Mat_space_var_yoshida[i][j] = Mat_space_var[i][j];
        }
    }
    // on fait yoshida sur les matrices
    yoshida(Mat_space_yoshida);
    yoshida(Mat_space_var_yoshida);
    std::cout << "fin yoshida" << std::endl;
    // on rempli mat rk4 avec matspace et matspace var
    std::cout << "initialisation rk4" << std::endl;
    for (int i = 0; i < RES; i++)
    {
        for (int j = 0; j < RES; j++)
        {
            Mat_space_rk4[i][j] = Mat_space[i][j];
            Mat_space_var_rk4[i][j] = Mat_space_var[i][j];
        }
    }
    // on fait rk4 sur les matrices
    rk4(Mat_space_rk4);
    rk4(Mat_space_var_rk4);
    std::cout << "initialisation calcul chaos" << std::endl;
    // On calcul le chaos pour chacune de matrices possible d'en faire une fonction
    for (size_t i = 0; i < RES; i++)
    {
        for (size_t j = 0; j < RES; j++)
        {
            Mat_chaos_euler[i][j] = (norme({(Mat_space_euler[i][j].x - Mat_space_var_euler[i][j].x),
                                            (Mat_space_euler[i][j].y - Mat_space_var_euler[i][j].y)}));
            Mat_chaos_velo_verlet[i][j] = (norme({(Mat_space_velo_verlet[i][j].x - Mat_space_var_velo_verlet[i][j].x),
                                                  (Mat_space_velo_verlet[i][j].y - Mat_space_var_velo_verlet[i][j].y)}));
            Mat_chaos_yoshida[i][j] = (norme({(Mat_space_yoshida[i][j].x - Mat_space_var_yoshida[i][j].x),
                                              (Mat_space_yoshida[i][j].y - Mat_space_var_yoshida[i][j].y)}));
            Mat_chaos_rk4[i][j] = (norme({Mat_space_rk4[i][j].x - Mat_space_var_rk4[i][j].x,
                                          Mat_space_rk4[i][j].y - Mat_space_var_rk4[i][j].y}));
        }
    }
    // ancienne matrices de normalisation non gardées, voir fonctions normalisation:
    // std::cout << "normalisation" << std::endl;
    // normalisation(Mat_chaos_euler,Mat_chaos_norm_euler);
    // normalisation(Mat_chaos_velo_verlet,Mat_chaos_norm_velo_verlet);
    // normalisation(Mat_chaos_yoshida,Mat_chaos_norm_yoshida);
    // normalisation(Mat_chaos_rk4,Mat_chaos_norm_rk4);
    // std::cout << "fin normalisation" << std::endl;
    // export 3 fichiers
    auto export_csv = [&](std::string nom, double matrice[RES][RES])
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
    // ancien export des matrices normalisées
    // export_csv("chaos_norm_euler.csv", Mat_chaos_norm_euler);
    // export_csv("chaos_norm_verlet.csv", Mat_chaos_norm_velo_verlet);
    // export_csv("chaos_norm_yoshida.csv", Mat_chaos_norm_yoshida);
    // export_csv("chaos_norm_rk4.csv", Mat_chaos_norm_rk4);

    std::cout << "fin export" << std::endl;
    system("python ../chaos_map.py");
}
