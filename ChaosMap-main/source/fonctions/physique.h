#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

struct vec2 // structure vecteur dimension 2
{
    float x;
    float y;
};

struct vec3
{
    float x;
    float y;
    float k;
};
float norme(vec2 v) // fonction calcule norme
{
    float x = v.x;
    float y = v.y;
    // instructions
    return sqrt(x * x + y * y);
};

// type pôle (pas nécessaire mais pratique)
struct Pole
{
    vec2 pos;
    float k;
};
// tableau de pôles
std::vector<Pole> liste_poles =
    {

        {{35, 120}, 85},
        {{160, 45}, 110},
        {{95, 180}, 60},
        {{110, 25}, 90},
        {{50, 150}, 75},
        {{140, 130}, 105},
        {{70, 70}, 95},
        {{125, 165}, 80},
        {{20, 80}, 120},
        {{175, 100}, 70},
        {{85, 40}, 100},
        {{150, 85}, 65},
        {{60, 110}, 115},
        {{105, 145}, 55},
        {{45, 35}, 105},
        {{130, 50}, 85},
        {{80, 160}, 90},
        {{165, 155}, 75},
        {{25, 170}, 100},
        {{180, 20}, 80}};

const int RES = 201;                      // taille de l'espace, malheureusement je n'ai pas eu le temps de modifier afin que cela augmente la résolution plutot que
                                          // agrandir l'espace
vec2 Mat_space[RES][RES];                 // création de la matrice de vecteurs positions
vec2 Mat_space_var[RES][RES];             // matrice +delta donc des positions décalées
vec2 Mat_space_euler[RES][RES];           // matrice positions de euler
vec2 Mat_space_var_euler[RES][RES];       // matrice positions +delta de euler
vec2 Mat_space_velo_verlet[RES][RES];     // matrice de velocity verlet
vec2 Mat_space_var_velo_verlet[RES][RES]; // matrice +delta de velocity verlet
vec2 Mat_space_yoshida[RES][RES];         // matrice de yoshida
vec2 Mat_space_var_yoshida[RES][RES];     // matrice positions +delta de yoshida
vec2 Mat_space_rk4[RES][RES];             // matrice position de rk4
vec2 Mat_space_var_rk4[RES][RES];         // matrice positions +delta de rk4
float Mat_chaos_euler[RES][RES];          // création de la matrice contenant le chaos (méthode euler)
// float Mat_chaos_norm_euler[RES][RES];       // matrice contenant le chaos normée (méthode euler)
float Mat_chaos_velo_verlet[RES][RES]; // création de la matrice contenant le chaos (méthode verlet)
                                       // float Mat_chaos_norm_velo_verlet[RES][RES]; // matrice contenant le chaos normée (méthode verlet)
float Mat_chaos_yoshida[RES][RES];     // création de la matrice contenant le chaos (méthode euler)
                                       // float Mat_chaos_norm_yoshida[RES][RES];// création de la matrice contenant le chaos (méthode euler)
float Mat_chaos_rk4[RES][RES];         // création de la matrice contenant le chaos (méthode euler)
// float Mat_chaos_norm_rk4[RES][RES];// création de la matrice contenant le chaos (méthode euler)
float dt = 1e-3;               // initialisation, constantes
float t_f = 50;                // temps final
float m = 1;                   // masse de l'objet
float v_0_x = 3;               // vitesse initiale selon x
float v_0_y = 3;               // vitesse initiale selon y
float delta = 1e-3;            // décalage entre position initiale et finale
float r_capture = 2;           // rayon a partir du quel on considère une particule comme capturée par le pôle
vec2 dist(vec2 pos, Pole pole) //  fonction calcul distance
{
    return {(float)(pos.x - pole.pos.x), (float)(pos.y - pole.pos.y)};
}

float r_cube(float r)
{
    return r * r * r;
}

// fonction acceleration pour pole dans liste_pole:

vec2 accel(float pos_x, float pos_y)
{
    float ax = 0;
    float ay = 0;

    for (size_t p = 0; p < liste_poles.size(); p++)
    {
        vec2 d = dist({pos_x, pos_y}, liste_poles[p]);
        ax += (liste_poles[p].k / (r_cube(norme(d))) * (liste_poles[p].pos.x - pos_x)) / m;
        ay += (liste_poles[p].k / (r_cube(norme(d))) * (liste_poles[p].pos.y - pos_y)) / m;
    }
    return {ax, ay};
}
bool condition_capture(float &x, float &y) // fonction condition de capture
{
    for (size_t i = 0; i < liste_poles.size(); i++)
    {
        vec2 d = dist({x, y}, liste_poles[i]);

        if (norme(d) <= r_capture)
        {
            x = liste_poles[i].pos.x;
            y = liste_poles[i].pos.y;
            return true;
        }
    }
    return false;
}
