#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

struct vec2
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
float norme(vec2 v)
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
              
    // anneau extérieur (8 pôles)
    {{100, 175}, 100},
    {{149, 161}, 100},
    {{175, 125}, 100},
    {{161, 76},  100},
    {{125, 50},  100},
    {{76,  50},  100},
    {{40,  76},  100},
    {{26,  125}, 100},
    // anneau moyen (7 pôles)
    {{100, 145}, 80},
    {{133, 134}, 80},
    {{145, 100}, 80},
    {{133, 66},  80},
    {{100, 55},  80},
    {{67,  66},  80},
    {{55,  100}, 80},
    // centre (5 pôles)
    {{100, 120}, 60},
    {{115, 110}, 60},
    {{110, 93},  60},
    {{90,  90},  60},
    {{85,  110}, 60}};


const int RES = 201;
vec2 Mat_space[RES][RES];                 // création de la matrice de vecteurs positions
vec2 Mat_space_var[RES][RES];             // matrice +d donc des positions décalées
vec2 Mat_space_euler[RES][RES];           // matrice positions après euler
vec2 Mat_space_var_euler[RES][RES];       // matrice positions +d après euler
vec2 Mat_space_velo_verlet[RES][RES];     // matrice après leapfrog
vec2 Mat_space_var_velo_verlet[RES][RES]; // matrice +d après leapfrog
vec2 Mat_space_yoshida[RES][RES];
vec2 Mat_space_var_yoshida[RES][RES];
float Mat_chaos_euler[RES][RES];            // création de la matrice contenant le chaos (méthode euler)
float Mat_chaos_norm_euler[RES][RES];       // matrice contenant le chaos normée (méthode euler)
float Mat_chaos_velo_verlet[RES][RES];      // création de la matrice contenant le chaos (méthode verlet)
float Mat_chaos_norm_velo_verlet[RES][RES]; // matrice contenant le chaos normée (méthode verlet)
float Mat_chaos_yoshida[RES][RES];
float Mat_chaos_norm_yoshida[RES][RES];
float dt = 1e-2; // initialisation, constantes
float t_f = 20;
float e = 0.5;
float v_0_x = 0;
float v_0_y = 0;
float d = 1e-3; 
vec2 dist(vec2 pos, Pole pole)
{
    return {(float)(pos.x - pole.pos.x), (float)(pos.y - pole.pos.y)};
}

float r_cube(float r)
{
    return r * r * r;
}

// fonction accel pour pole dans liste_pole:
float m = 1;
vec2 accel(float pos_x, float pos_y)
{
    float ax = 0;
    float ay = 0;

    for (size_t p = 0; p < liste_poles.size(); p++)
    {
        vec2 d = dist({pos_x, pos_y}, liste_poles[p]);
        ax += (liste_poles[p].k / (r_cube(norme(d))+e) * (liste_poles[p].pos.x - pos_x)) / m;
        ay += (liste_poles[p].k / (r_cube(norme(d))+e) * (liste_poles[p].pos.y - pos_y)) / m;
    }
    return {ax, ay};
}

