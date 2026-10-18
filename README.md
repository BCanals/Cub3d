# Cub3D

*This project has been created as part of the 42 curriculum by becanals and lartes-s.*

## Description

Cub3D is a 3D graphical project inspired by the legendary Wolfenstein 3D game, considered the first true FPS in video game history. Using raycasting techniques, this project renders a dynamic first-person view inside a maze where the player can navigate and explore.

The goal is to create a realistic 3D representation from a 2D map using the raycasting algorithm, handling textures, colors, and basic movement. This project provides a practical introduction to computer graphics concepts including projection, rendering, and event handling.

## Instructions

### Compilation
```bash
make
```

This will compile the project and generate the `cub3D` executable.

### Execution
```bash
./cub3D [path_to_map.cub]
```

Replace `[path_to_map.cub]` with the path to a valid `.cub` scene description file.

### Controls

- **W/A/S/D**: Move forward/left/backward/right
- **Left/Right Arrows**: Rotate camera view
- **ESC**: Exit the program

### Map Configuration

The `.cub` file must contain:
- Texture paths for North, South, East, and West walls (NO, SO, EA, WE)
- Floor and ceiling colors (F, C)
- A valid map using characters: `0` (empty space), `1` (wall), `N/S/E/W` (player start position and orientation)

## Resources

### Learning Materials

- [3D Ray-Casting Game with Cub3D by Dev Abdilah](https://devabdilah.medium.com/3d-ray-casting-game-with-cub3d-7a116376056a) - Comprehensive guide to implementing raycasting for Cub3D
- [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html) - In-depth explanation of raycasting algorithms with code examples
- 

### AI Usage

AI assistance was used for:
- Understanding raycasting mathematics and DDA (Digital Differential Analysis) algorithm
- Debugging texture mapping and wall rendering issues
- Clarifying MLX42/MiniLibX function usage and event handling
- Optimizing performance calculations for real-time rendering
- Generating code structure for parsing the `.cub` configuration file
- Explaining projection formulas and field of view calculations