// #pragma once
// #include "physique.h"

// void rk4(vec2 M[RES][RES])
// {
//     for (size_t i = 0; i < RES; i++)
//     {
//         for (size_t j = 0; j < RES; j++)
//         {
//             float px = M[i][j].x;
//             float py = M[i][j].y;
//             float vx = v_0_x;
//             float vy = v_0_y;

//             for (float t = 0; t < t_f; t += dt)
//             {
//                 // k1
//                 vec2 a1 = accel(px, py);
//                 float k1_px = vx,        k1_py = vy;
//                 float k1_vx = a1.x,      k1_vy = a1.y;

//                 // k2
//                 vec2 a2 = accel(px + k1_px * dt/2, py + k1_py * dt/2);
//                 float k2_px = vx + k1_vx * dt/2,  k2_py = vy + k1_vy * dt/2;
//                 float k2_vx = a2.x,  k2_vy = a2.y;

//                 // k3
//                 vec2 a3 = accel(px + k2_px * dt/2, py + k2_py * dt/2);
//                 float k3_px = vx + k2_vx * dt/2,  k3_py = vy + k2_vy * dt/2;
//                 float k3_vx = a3.x,                k3_vy = a3.y;

//                 // k4
//                 vec2 a4 = accel(px + k3_px * dt, py + k3_py * dt);
//                 float k4_px = vx + k3_vx * dt,    k4_py = vy + k3_vy * dt;
//                 float k4_vx = a4.x,                k4_vy = a4.y;

//                 // mise à jour
//                 px += dt/6.0f * (k1_px + 2*k2_px + 2*k3_px + k4_px);
//                 py += dt/6.0f * (k1_py + 2*k2_py + 2*k3_py + k4_py);
//                 vx += dt/6.0f * (k1_vx + 2*k2_vx + 2*k3_vx + k4_vx);
//                 vy += dt/6.0f * (k1_vy + 2*k2_vy + 2*k3_vy + k4_vy);
//             }

//             M[i][j].x = px;
//             M[i][j].y = py;
//         }
//     }
// }