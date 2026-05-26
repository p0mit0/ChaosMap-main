#pragma once
#include "physique.h"

void yoshida(vec2 M[RES][RES])
{
    // coeffs yoshida, mettre "f" afin de confirmer double
    const double w1 = 1.3512071917951f;
    const double w0 = -1.7024143835903f;
    const double c1 = w1 / 2.0f;
    const double c2 = (w1 + w0) / 2.0f;
    const double c3 = c2;
    const double c4 = c1;
    const double d1 = w1;
    const double d2 = w0;
    const double d3 = w1;
    for (size_t i = 0; i < RES; i++)
    {
        for (size_t j = 0; j < RES; j++)
        {
            double pos_x = M[i][j].x;
            double pos_y = M[i][j].y;
            double vx = v_0_x;
            double vy = v_0_y;
            vec2 a;
            for (double t = 0; t < t_f; t += dt)
            {
                if (condition_capture(pos_x, pos_y))
                {
                    break;
                }
                // 1 calcul
                pos_x += c1 * vx * dt;
                pos_y += c1 * vy * dt;

                a = accel(pos_x, pos_y);
                vx += d1 * a.x * dt;
                vy += d1 * a.y * dt;
                // 2 calcul
                pos_x += c2 * vx * dt;
                pos_y += c2 * vy * dt;

                a = accel(pos_x, pos_y);
                vx += d2 * a.x * dt;
                vy += d2 * a.y * dt;
                // 3 calcul
                pos_x += c3 * vx * dt;
                pos_y += c3 * vy * dt;

                a = accel(pos_x, pos_y);
                vx += d3 * a.x * dt;
                vy += d3 * a.y * dt;
                // 4 dernier pas pour x_i+1 dernier pas de position
                pos_x += c4 * vx * dt;
                pos_y += c4 * vy * dt;
            }

            M[i][j].x = pos_x;
            M[i][j].y = pos_y;
        }
    }
}
