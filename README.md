# cub3D

### Commit Rules 📜
---
- **Force push and push to main branch are prohibited**
- Create and push a sub-branch instead of the main branch
- Sub-branch should have a title and a comment
- Each commit have to be pushed with a brief comment of what you've written code
- Use **labeling and questions** for peer review

### Process 🧶
---
#### 1. Project Overview
Cub3D is a simple 3D game engine in the style of Wolfenstein 3D that utilizes raycasting techniques to render 3D environments based on 2D maps. The project is mainly covered in the curriculum of 42 schools and is implemented using the C language and the MinilibX (MLX) library.


- Map parsing and validation: Reads in a 2D text map file and validates the player's position, the map's boundaries, and objects.
- Player setup: Set the player's position, gaze direction, rotation angle, and more, and handle movement and rotation based on input.
- Rendering: Renders walls using raycasting techniques and uses texture mapping to display wall details.
- Animation: Adds animation to walls and doors to enhance the visual quality of the game.
- Event handling: Process user input (keyboard) to implement player movement, rotation, and interaction with objects.
- Resource management: Properly frees allocated resources to prevent memory leaks when the game ends.

#### 2. Project structure

```
cub3d Directory
├── assets
├── includes
├── lib
│   ├── libft
│   │   ├── includes
│   │   └── src
│   ├── mlx
├── maps
├── src
│   ├── clean-destroy
│   ├── debug
│   ├── init
│   ├── input
│   ├── parsing
│   └── rendering
└── textures
    ├── custom
    └── wolfenstein
```

#### 3. Parsing and validating maps
The game's map is defined as a 2D text file, where each character represents the location of an object or player in the game. For example:
>  '1': Wall
'0', ' ': Empty space
'N, S, W, E': Player's starting position and view direction
'P: Door

- The Map Parsing step performs the following tasks
    1. Read the map file: Opens the file, reads each line, and stores it in a 2D array.
    2. Validate: Validates that the map is surrounded by walls, that the player has exactly one starting position, and that objects are placed correctly.
    3. Initialize objects: Finds doors that exist within the map and initializes the location and state of those objects.
- Validation

    - Ensuring that the map's boundaries are all walled in.
    - Verify that the player has exactly one starting position
    -  Ensure that doors are properly surrounded by walls
    -  Verify that the map does not contain any disallowed characters

#### 4. Player Setup
The player is the main character that can move and rotate within the game. Player settings include the following elements
- Location: Set based on coordinates within the map.
- Orientation: Indicates the direction the player is facing, expressed as an angle of view.
- Movement: Handles forward, backward, and side-to-side movement via keyboard input.
- Rotation: Implemented to allow the player to rotate to the left or right.
- Player movement and rotation allow for natural navigation in the game and interact with the raycasting algorithm to provide a realistic 3D environment.

#### 5. Rendering and animation
#### Rendering 
The rendering phase is the process of displaying the visual elements of the game on the screen, utilizing raycasting to create a 3D environment. Animation adds dynamic changes to walls and doors to bring the game to life.
    Raycasting is the core algorithm for rendering 3D environments based on 2D maps. The algorithm fires virtual rays based on the direction of the player's view, calculates the collision points with walls, and renders walls to the screen based on that. Raycasting has the advantage of being efficient and enabling real-time 3D effects with limited resources.

#### Basic principles of raycasting
Ray firing: Fire rays corresponding to each pixel on the screen based on the player's viewing angle.
DDA algorithm: Detects collisions with walls as each ray travels along a grid (cell) on the map.
Distance calculation: Calculates the distance traveled by the ray until it reaches the wall (vertical distance).
Draw the wall: Based on the calculated distance, we determine the height of the wall on the screen, map a texture, and render it.
Perspective effect: Adjusts the height of the wall based on distance to create a sense of perspective.
Digital Differential Analyzer (DDA) Algorithm

#### DDA(Digital Differential Analyzer)
The DDA algorithm is a way to find collision points by moving a ray along a grid on the map until it hits a wall. It's efficient, simple to implement, and widely used in raycasting.

#### Raycasting steps explained
1. Set Field of View: Calculate the orientation of each ray based on the player's viewing direction and viewing angle.
2.Initialize Grid: Converts the current player's position to grid coordinates.
3. Determine Leasestep: Calculates the number of steps the ray takes to move one space along the x and y axes as it moves.
4. Detect collision: The ray moves along the grid until it collides with a wall, checking for collisions.
5. Calculate distance: Calculates the distance the ray has traveled until it reaches the wall.
6. Render the wall: Determines the height of the wall on the screen based on the calculated distance, maps a texture to it, and renders it.
7. Perspective and distortion correction
In raycasting, when rays are fired at an angle to the player's view, distortion of the wall can occur. To compensate for this, we use the following methods
Perspective compensation: Calculates the angle between the ray and the player's line of sight to compensate for the distance value. This ensures that the height of the wall is represented correctly.

```C
corrected_distance = distance * cos(ray_angle - player_angle)
// Texture mapping: Using the corrected distance value, we calculate the x-coordinates of the texture and accurately map the texture to the wall.
```

#### animation
Door animation is a feature that visually represents the behavior of doors opening and closing. The implementation process is as follows

- Define a Door Struct: Define a structure that manages the position of the door object, its current state (open, closed, opening, closing), animation timer, etc.
- Manage state: Change the state of the door based on player interaction (e.g., certain keystrokes; R).
- Update Animation: Update the animation timer when the door opens or closes, and change the rendered y-axis position of the door's texture over time.
- Render: maps the texture of the current animation frame to the door position via raycasting and displays it on the screen.

#### 6. Implementing the Minimap
#### Implementing a minimap using the Bresenham algorithm
The Bresenham algorithm is an efficient algorithm used to draw a straight line between two points, and is commonly used to draw lines in pixel-based graphics. In our minimap implementation, we used the Brayham algorithm to draw lines that represent the direction of the player's view, or to visually display the player's path of travel.

#### Steps to implement a minimap
1. Setting the minimap drawing area: Set the area to draw the minimap in a specific location on the screen (e.g., top right).
2. Grid mapping: Convert the grid of the physical map to the pixel grid of the minimap. This is done by calculating a scale factor to map cells in the physical map to pixels in the minimap.
3. Transform player position: Converts the player's real-world coordinates to minimap coordinates and displays them. The player is represented within the minimap by a specific color or shape (such as a triangle).
4. Show view direction: Uses the Bryham algorithm to draw a line to indicate the direction of the player's view. This provides a visual indication of where the player is currently looking.
5. Update in real-time: Update the minimap in real-time as the player moves and rotates. The line of sight using the Bryham algorithm is also updated in real time.

#### Example of the Brayham algorithm in action
- Set a start and end point:
    - Start point: The player's current location converted to minimap coordinates.
    - End point: The point within the minimap where the player's line of sight reaches based on the player's view direction.
- Apply Algorithm: Calculate a line between the start and end points using the Bryham algorithm, and draw that line on the minimap.
- Render: Displays the pixels of the calculated line as colors in the minimap image buffer to visually represent the line of sight direction.

#### 7. Event Handling
Event Handling is the ability to take input from the user (keyboard, mouse, etc.) and implement in-game behaviors. The main types of event handling include

- Keyboard input: Handles player movement, rotation, and object interaction.
- Move: Accepts keystrokes for forward, backward, left and right movement to update the player's position.
- Rotate: Accepts keystrokes for left and right rotation to change the direction of the player's gaze.
- Interactions: Implement interactions with objects, such as opening or closing a door by pressing a specific key (e.g. the 'R' key).
- Window closing events: Safely exit the game when the user closes a window, releasing any allocated resources.

#### 8. Resource management
The project needs to properly manage the dynamically allocated memory and loaded image resources during game execution. The main resource management topics include

- Memory allocation: Dynamically allocate map data, statement object arrays.
- Image resources: Prevent memory leaks by releasing texture images loaded via MLX at game end.
- Game Exit Handling: Releases all allocated memory when the game exits, and safely closes the MLX window and images.
- Proper resource management is essential to maintaining the stability and performance of your game.

#### 9. Performance Optimization
To optimize the performance of our project to ensure smooth gameplay, we applied the following optimization techniques

- Conditional rendering: Reduce unnecessary computation by only updating animations and rendering objects that are close to the player.
- Efficient memory management: Optimizes memory usage by allocating only the resources needed and releasing all resources when the game ends.
- Frame buffer initialization: Increase rendering speed by updating only what is needed instead of clearing the entire screen every frame.
- Animation timer management: Efficiently manage frame transitions in animations to reduce CPU usage.

### Reference 📄
- [42 Docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
- [Raycasting lecture Video](https://www.youtube.com/watch?v=g8p7nAbDz6Y)
- [Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [DDA algorithm](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm))
- [Bresenhams's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)

### Version
- norminette 3.3.51
- [minilibx-linux](https://github.com/42Paris/minilibx-linux)
- minilibx_mms_20200219_beta