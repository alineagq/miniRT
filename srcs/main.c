/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:08:29 by fsuomins          #+#    #+#             */
/*   Updated: 2023/10/16 11:57:14 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int main(int argc, char **argv) 
{
    if (argc != 2) {
        printf("Usage: %s <scene.rt>\n", argv[0]);
        return 1;
    }
    char *scene_file = argv[1];
    t_data *data = parse_scene(scene_file);  // Implement this function

    if (data == NULL) 
	{
        printf("Error: Unable to parse the scene file.\n");
        return 1;
    }

    // Initialize MiniLibX and set up the window (not shown here)

    // Render the scene
    render_scene(data);  // Implement this function

    // Clean up and exit
    free_data(data);  // Implement this function

    return 0;
}
