#pragma once
#include "physique.h"
void rk4(vec2 M[RES][RES])
{ 
     for (size_t i = 0; i < RES; i++)
     {
         for (size_t j = 0; j < RES; j++)
         {
             float px = M[i][j].x;
             float py = M[i][j].y;
            float vx = v_0_x;
             float vy = v_0_y;

            for (float t = 0; t < t_f; t += dt)
            {
            if (condition_capture(px, py)) break;

            // k1 — dérivées à t
            vec2 a1 = accel(px, py);
            float k1_x = vx,    k1_y = vy;      // dx/dt = v
            float k1_vx = a1.x, k1_vy = a1.y;  // dv/dt = a

            // k2 — dérivées à t + dt/2 en utilisant k1
            vec2 a2 = accel(px + k1_x * dt/2, py + k1_y * dt/2);
            float k2_x = vx + k1_vx * dt/2,    k2_y = vy + k1_vy * dt/2;
            float k2_vx = a2.x,                 k2_vy = a2.y;

            // k3 — dérivées à t + dt/2 en utilisant k2
            vec2 a3 = accel(px + k2_x * dt/2, py + k2_y * dt/2);
            float k3_x = vx + k2_vx * dt/2,    k3_y = vy + k2_vy * dt/2;
            float k3_vx = a3.x,                 k3_vy = a3.y;

            // k4 — dérivées à t + dt en utilisant k3
            vec2 a4 = accel(px + k3_x * dt, py + k3_y * dt);
            float k4_x = vx + k3_vx * dt,      k4_y = vy + k3_vy * dt;
            float k4_vx = a4.x,                 k4_vy = a4.y;

            // mise à jour finale
            px += dt/6.0f * (k1_x  + 2*k2_x  + 2*k3_x  + k4_x);
            py += dt/6.0f * (k1_y  + 2*k2_y  + 2*k3_y  + k4_y);
            vx += dt/6.0f * (k1_vx + 2*k2_vx + 2*k3_vx + k4_vx);
            vy += dt/6.0f * (k1_vy + 2*k2_vy + 2*k3_vy + k4_vy);
            }

            M[i][j].x = px;
            M[i][j].y = py;
         }
     }
 }