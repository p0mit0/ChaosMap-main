// #pragma once
// #include "physique.h"
// void normalisation(float chaos[RES][RES], float chaos_norm[RES][RES])
// {
//     float log_chaos[RES][RES];
//     for (size_t i = 0; i < RES; i++)
//         for (size_t j = 0; j < RES; j++)
//             log_chaos[i][j] = log(chaos[i][j] + 1e-10f);

//     float min_val = 1e10f;
//     float max_val = -1e10f;

//     for (size_t i = 0; i < RES; i++)
//         for (size_t j = 0; j < RES; j++)
//         {
//             if (log_chaos[i][j] < min_val) min_val = log_chaos[i][j];
//             if (log_chaos[i][j] > max_val) max_val = log_chaos[i][j];
//         }

//     for (size_t i = 0; i < RES; i++)
//         for (size_t j = 0; j < RES; j++)
//             chaos_norm[i][j] = (log_chaos[i][j] - min_val) / (max_val - min_val);
// }