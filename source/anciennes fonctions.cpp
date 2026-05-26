//on retrouve ici d'anciennes fonctions et lignes de code qui on permis la crétion et l'optimisation du code, en l'occurence verlet

// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <fstream>
// struct vec2
// {
//     float x;
//     float y;
// };

// struct vec3
// {
//     float x;
//     float y;
//     float k;
// };
// float norme(vec2 v)
// {
//     float x = v.x;
//     float y = v.y;
//     // instructions
//     return sqrt(x * x + y * y);
// };
// float dt = 1e-3; // initialisation, constantes
// float t_f = 20;
// float k_1 = 200;
// vec2 Pole_1 = {
//     (float)100,
//     (float)125,
// }; // création des pôles
// vec2 Pos = {(float)0, (float)0};
// float e = 1e-7f;
// void euler(vec2 M)
// {
//     float pos_x = M.x;
//     float pos_y = M.y;
//     float vx = 0;
//     float vy = 0;
//     for (float t = 0; t < t_f; t += dt)
//     {
//         vec2 dist_1 = {(float)(pos_x - Pole_1.x), (float)(pos_y - Pole_1.y)};
//         float r_1 = norme(dist_1);
//         float r_cube_1 = r_1 * r_1 * r_1;
//         float ax = k_1 / (r_cube_1) * (Pole_1.x - pos_x); // calcul du tableau accéleration
//         float ay = k_1 / (r_cube_1) * (Pole_1.y - pos_y);
//         vx = vx + ax * dt;
//         vy = vy + ay * dt;
//         pos_x = pos_x + vx * dt;
//         pos_y = pos_y + vy * dt;
//     }
//     M.x = pos_x;
//     M.y = pos_y;
// }
// void velo_verlet(vec2 M)
// {
//     float pos_x = M.x;
//     float pos_y = M.y;
//     float vx = 0;
//     float vy = 0;
//     vec2 dist_1 = {(float)(pos_x - Pole_1.x), (float)(pos_y - Pole_1.y)};
//     float r_1 = norme(dist_1);
//     float r_cube_1 = r_1 * r_1 * r_1;
//     float ax = k_1 / (r_cube_1 + e) * (Pole_1.x - pos_x); // initialise le calcul du tableau accéleration
//     float ay = k_1 / (r_cube_1 + e) * (Pole_1.y - pos_y);
//     for (float t = 0; t < t_f; t += dt) // boucle t pour velo verlet
//     {
//         vx = vx + ax * dt * 0.5;
//         vy = vy + ay * dt * 0.5;
//         pos_x = pos_x + vx * dt;
//         pos_y = pos_y + vy * dt;
//         dist_1 = {(float)(pos_x - Pole_1.x), (float)(pos_y - Pole_1.y)};
//         r_1 = norme(dist_1);
//         r_cube_1 = r_1 * r_1 * r_1;
//         ax = k_1 / (r_cube_1 + e) * (Pole_1.x - pos_x);
//         ay = k_1 / (r_cube_1 + e) * (Pole_1.y - pos_y);
//         vx = vx + ax * dt * 0.5;
//         vy = vy + ay * dt * 0.5;
//     }
//     M.x = pos_x;
//     M.y = pos_y;
// }
// int main()
// {
// }
