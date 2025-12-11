# 🕹️ Cub3D - Raycasting Engine

**Cub3D** is a project from the **42 School** curriculum, inspired by the legendary *Wolfenstein 3D*.
The goal is to build a dynamic "first-person" graphic engine using **Raycasting** technology, implemented from scratch in C.

This project dives deep into the mathematics behind 3D rendering, window event management, and rendering optimization.

![Screenshot](path/to/screenshot.png)
*(Tip: Replace this link with a screenshot of your running game)*

## ✨ Key Features

* **Raycasting Rendering:** Mathematical implementation to simulate 3D depth in a 2D environment.
* **Texture Mapping:** Support for distinct textures on walls based on cardinal directions (North, South, East, West).
* **Custom Colors:** RGB color management for floor and ceiling defined in the configuration file.
* **Player Movement:**
    * Smooth movement (forward, backward, strafe).
    * Camera rotation.
    * **Collision Detection:** Proper wall collision handling.
* **Map Parsing:** Robust reading and validation of `.cub` files to configure the map and assets.

---

## 🛠️ Tech Stack

* **Language:** C (strictly adhering to the 42 Norm).
* **Graphics:** MiniLibX (42's simple X-Window interface library).
* **Math:** Heavy usage of trigonometric functions (`math.h`) for ray calculations.
* **Build:** Custom Makefile.

---

## 🎮 Controls

| Key | Action |
| :--- | :--- |
| `W` / `▲` | Move Forward |
| `S` / `▼` | Move Backward |
| `A` | Strafe Left |
| `D` | Strafe Right |
| `←` | Rotate Camera Left |
| `→` | Rotate Camera Right |
| `ESC` | Exit Game |

---

## 🚀 Installation & Usage

### Prerequisites
* GCC or Clang
* Make
* X11 libraries (Linux) or AppKit (MacOS)

### Instructions

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/your-username/cub3d.git](https://github.com/your-username/cub3d.git)
    cd cub3d
    ```

2.  **Compilation:**
    Use the Makefile to generate the executable:
    ```bash
    make
    ```

3.  **Execution:**
    Run the program by passing a `.cub` map file as an argument:
    ```bash
    ./cub3D maps/map.cub
    ```

---

## 🗺️ Map Configuration (.cub)

The program parses map files formatted as follows:

```text
NO ./path/to/north_texture.xpm
SO ./path/to/south_texture.xpm
WE ./path/to/west_texture.xpm
EA ./path/to/east_texture.xpm

F 220,100,0    # Floor Color (RGB)
C 225,30,0     # Ceiling Color (RGB)

111111
100001
10N001
111111
