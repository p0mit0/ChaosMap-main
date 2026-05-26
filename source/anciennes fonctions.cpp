// on retrouve ici d'anciennes fonctions et lignes de code qui on permis la crétion et l'optimisation du code, en l'occurence verlet

// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <fstream>
// struct vec2
// {
//     double x;
//     double y;
// };

// struct vec3
// {
//     double x;
//     double y;
//     double k;
// };
// double norme(vec2 v)
// {
//     double x = v.x;
//     double y = v.y;
//     // instructions
//     return sqrt(x * x + y * y);
// };
// double dt = 1e-3; // initialisation, constantes
// double t_f = 20;
// double k_1 = 200;
// vec2 Pole_1 = {
//     (double)100,
//     (double)125,
// }; // création des pôles
// vec2 Pos = {(double)0, (double)0};
// double e = 1e-7f;
// void euler(vec2 M)
// {
//     double pos_x = M.x;
//     double pos_y = M.y;
//     double vx = 0;
//     double vy = 0;
//     for (double t = 0; t < t_f; t += dt)
//     {
//         vec2 dist_1 = {(double)(pos_x - Pole_1.x), (double)(pos_y - Pole_1.y)};
//         double r_1 = norme(dist_1);
//         double r_cube_1 = r_1 * r_1 * r_1;
//         double ax = k_1 / (r_cube_1) * (Pole_1.x - pos_x); // calcul du tableau accéleration
//         double ay = k_1 / (r_cube_1) * (Pole_1.y - pos_y);
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
//     double pos_x = M.x;
//     double pos_y = M.y;
//     double vx = 0;
//     double vy = 0;
//     vec2 dist_1 = {(double)(pos_x - Pole_1.x), (double)(pos_y - Pole_1.y)};
//     double r_1 = norme(dist_1);
//     double r_cube_1 = r_1 * r_1 * r_1;
//     double ax = k_1 / (r_cube_1 + e) * (Pole_1.x - pos_x); // initialise le calcul du tableau accéleration
//     double ay = k_1 / (r_cube_1 + e) * (Pole_1.y - pos_y);
//     for (double t = 0; t < t_f; t += dt) // boucle t pour velo verlet
//     {
//         vx = vx + ax * dt * 0.5;
//         vy = vy + ay * dt * 0.5;
//         pos_x = pos_x + vx * dt;
//         pos_y = pos_y + vy * dt;
//         dist_1 = {(double)(pos_x - Pole_1.x), (double)(pos_y - Pole_1.y)};
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
