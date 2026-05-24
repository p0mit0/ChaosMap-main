#pragma once
#include "physique.h"

void euler(vec2 M[RES][RES])
{

    for (size_t i = 0; i < RES; i++)
    {
        for (size_t j = 0; j < RES; j++) // boucle for vecteur in mat_space
        {
            float pos_x = M[i][j].x;
            float pos_y = M[i][j].y;
            float vx = v_0_x;
            float vy = v_0_y;
            for (float t = 0; t < t_f; t += dt)
            {
                if (condition_capture(pos_x, pos_y))
                {
                   break; 
                }
                vec2 a = accel(pos_x, pos_y); // calcul du tableau accéleration
                pos_x = pos_x + vx * dt;
                pos_y = pos_y + vy * dt;
                vx = vx + a.x * dt;
                vy = vy + a.y * dt;

            }
            M[i][j].x = pos_x;
            M[i][j].y = pos_y;

           
        }
    }
}