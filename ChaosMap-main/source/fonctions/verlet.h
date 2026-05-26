#pragma once
#include "physique.h"
void velo_verlet(vec2 M[RES][RES])
{
    for (size_t i = 0; i < RES; i++)
    {
        for (size_t j = 0; j < RES; j++) // boucle for vecteur in mat_space
        {
            float pos_x = M[i][j].x;
            float pos_y = M[i][j].y;
            float vx = v_0_x;
            float vy = v_0_y;
            vec2 a = accel(pos_x, pos_y);       // initialise le calcul du tableau accéleration
            for (float t = 0; t < t_f; t += dt) // boucle t pour velo verlet
            {
                if (condition_capture(pos_x, pos_y))
                {
                    break;
                }

                vx += a.x * dt * 0.5;
                vy +=  a.y * dt * 0.5;
                pos_x +=  vx * dt;
                pos_y +=  vy * dt;

                a = accel(pos_x, pos_y);
                vx +=  a.x * dt * 0.5;
                vy +=  a.y * dt * 0.5;
            }
            M[i][j].x = pos_x;
            M[i][j].y = pos_y;
        }
    }
}