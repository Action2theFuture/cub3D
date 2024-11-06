/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 04:18:51 by max               #+#    #+#             */
/*   Updated: 2024/11/04 14:08:25 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// // initialisation des variables DDA ...
// double distance_travelled = 0.0;

// while (distance_travelled < MAX_RENDER_DISTANCE)
// {
//     // Effectuer le calcul DDA habituel (mise à jour de side_dist_x et side_dist_y)

//     // Calculer la distance à chaque étape
//     distance_travelled = sqrt(pow(current_x - data->player.pos_x, 2) + pow(current_y - data->player.pos_y, 2));

//     if (distance_travelled >= MAX_RENDER_DISTANCE)
//         break;

//     // Vérifier s'il y a un mur, sinon passer à la prochaine intersection
// }

// void find_horizontal_intersection(t_data *data, double ray_vector_x, double ray_vector_y)
// {
//     double pos_y = data->player.pos_y; // Position y du joueur
//     double intersection_y;
//     double delta_y;

//     // Déterminer la ligne horizontale touchée
//     if (ray_vector_y < 0)
//     {
//         intersection_y = floor(pos_y); // Ligne supérieure
//     }
//     else
//     {
//         intersection_y = ceil(pos_y); // Ligne inférieure
//     }

//     // Calculer la distance à parcourir en y
//     delta_y = (intersection_y - pos_y) / ray_vector_y;

//     // Calculer x à l'intersection
//     double intersection_x = data->player.pos_x + delta_y * ray_vector_x;

//     // Afficher le résultat
//     printf("Horizontal Intersection: X = %f, Y = %f\n", intersection_x, intersection_y);
// }

// void find_vertical_intersection(t_data *data, double ray_vector_x, double ray_vector_y)
// {
//     double pos_x = data->player.pos_x; // Position x du joueur
//     double intersection_x;
//     double delta_x;

//     // Déterminer la colonne verticale touchée
//     if (ray_vector_x < 0)
//     {
//         intersection_x = floor(pos_x); // Colonne à gauche
//     }
//     else
//     {
//         intersection_x = ceil(pos_x); // Colonne à droite
//     }

//     // Calculer la distance à parcourir en x
//     delta_x = (intersection_x - pos_x) / ray_vector_x;

//     // Calculer y à l'intersection
//     double intersection_y = data->player.pos_y + delta_x * ray_vector_y;

//     // Afficher le résultat

//     printf("Vertical Intersection: X = %f, Y = %f\n", intersection_x, intersection_y);
// }

// void test_dda(t_data *data, double ray_vector_x, double ray_vector_y)
// {
//     (void)data;
//     double delta_x;
//     double delta_y;
//     double step_x;
//     double step_y;
//     double side_dist_x;
//     double side_dist_y;

//     bool hit_wall;
//     hit_wall = false;
//     // int side;

//     if (ray_vector_x < 0)
//         step_x = -1;
//     else
//         step_x = 1;
//     if (ray_vector_y < 0)
//         step_y = -1;
//     else
//         step_y = 1;

//     delta_x = fabs(1 / ray_vector_x);
//     delta_y = fabs(1 / ray_vector_y);

//     side_dist_x = (data->player.pos_x - floor(data->player.pos_x)) * delta_x;
//     side_dist_y = (data->player.pos_y - floor(data->player.pos_y)) * delta_y;

//     printf("ray x = %f\nray y = %f\n\n", ray_vector_x, ray_vector_y);
//     printf("delta x = %f\ndelta y = %f\n\n", delta_x, delta_y);
//     printf("step x = %f\nstep y = %f\n\n", step_x, step_y);
//     printf("side x = %f\nside y = %f\n\n", side_dist_x, side_dist_y);

//     for (int i = 0; i < 5; i++)
//     {
//         find_horizontal_intersection(data, ray_vector_x, ray_vector_y);
//         find_vertical_intersection(data, ray_vector_x, ray_vector_y);
//         printf("\n");
//     }
// }

// void test_dda(t_data *data, double ray_vector_x, double ray_vector_y) {
//     double pos_x = data->player.pos_x; // Position du joueur en x
//     double pos_y = data->player.pos_y; // Position du joueur en y
//     double delta_x, delta_y;
//     double step_x, step_y;
//     double side_dist_x, side_dist_y;

//     // Calculer delta_x et delta_y
//     delta_x = fabs(1 / ray_vector_x);
//     delta_y = fabs(1 / ray_vector_y);

//     // Initialiser les valeurs de step_x et step_y
//     if (ray_vector_x < 0) {
//         step_x = -1;
//         side_dist_x = (pos_x - floor(pos_x)) * delta_x; // distance au mur à gauche
//     } else {
//         step_x = 1;
//         side_dist_x = (ceil(pos_x) - pos_x) * delta_x; // distance au mur à droite
//     }

//     if (ray_vector_y < 0) {
//         step_y = -1;
//         side_dist_y = (pos_y - floor(pos_y)) * delta_y; // distance au mur en haut
//     } else {
//         step_y = 1;
//         side_dist_y = (ceil(pos_y) - pos_y) * delta_y; // distance au mur en bas
//     }

//     int hit = 0; // variable pour indiquer si un mur a été touché

//     while (hit == 0) {
//         // Vérifier quelle distance est la plus proche
//         if (side_dist_x < side_dist_y) {
//             side_dist_x += delta_x; // avancer vers la prochaine ligne verticale
//             pos_x += step_x;         // déplacer en x

//             // Vérifier si on a touché un mur
//             if (data->map[(int)pos_y][(int)pos_x] > 0) {
//                 hit = 1; // on a trouvé un mur
//                 printf("Hit vertical wall at: X = %f, Y = %f\n", floor(pos_x) + (step_x < 0 ? 0 : 1), pos_y);
//             }
//         } else {
//             side_dist_y += delta_y; // avancer vers la prochaine ligne horizontale
//             pos_y += step_y;         // déplacer en y

//             // Vérifier si on a touché un mur
//             if (data->map[(int)pos_y][(int)pos_x] > 0) {
//                 hit = 1; // on a trouvé un mur
//                 printf("Hit horizontal wall at: X = %f, Y = %f\n", pos_x, floor(pos_y) + (step_y < 0 ? 0 : 1));
//             }
//         }
//     }
// }

void raycast(t_data *data)
{
    int x;
    x = 0;
    // printf("pos x = %f\npos y = %f\n", data->player.pos_x, data->player.pos_y);
    while (x < data->screen_size_x)
    {
        data->player.ray_angle = data->player.view_angle + (x / (float)data->screen_size_x - 0.5) * FOV_DEGREE;
        // if (x % 100 == 0 || x == 960 || x == 1919)
        //     printf("\nray_angle_degree = %f\n", data->player.ray_angle);
        data->player.ray_angle = degrees_to_radians(data->player.ray_angle);
        data->player.ray_vector_x = cos(data->player.ray_angle);
        data->player.ray_vector_y = -sin(data->player.ray_angle);
        // if (x % 100 == 0 || x == 960 || x == 1919)
        //     printf("%d -> ray x = %f  ray y = %f\n\n", x, data->player.ray_vector_x, data->player.ray_vector_y);
        // if (x == 1919)
        //     test_dda(data, data->player.ray_vector_x, data->player.ray_vector_y);
        // printf("ray x = %f  ray y = %f\n", ray_vector_x, ray_vector_y);
        x++;
    }
}
