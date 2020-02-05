# Sprite Editor

Difficulty: Medium

Mentors: heinezen, simonsan

Requirements:
* Basic programming skills in Python *or* C++
* Basic knowledge of UI/UX design

Helpful skills:
* Image manipulation with Python scripting or libpng
* Graphics modding experience for any sprite-based game

## Motivation

openage is a 2D sprite-based RTS engine where animations consist
of multiple frames/images (sprites). Sprites are organized in
spritesheets that store all frames relevant to a animation
in a PNG file. Metadata (e.g. order of frames) is configured in a
custom configuration format (`.sprite` files). Together, the spritesheet
and configuration file define an *animation* that can be used
by the openage renderer.

The goal of this project is to create a GUI tool to create and
edit animations by assembling spritesheets and configuring the
metadata.

## Description (long)

* graphics are stored in spritesheets as 32-Bit PNG files
* Config file for additional metadata relevant for animation
    * Location of individual frames in spritesheet
    * Layers
    * time per frame
    * Order of frames in animation
    * Anchorpoints for frames
    * etc.
* Config file can reference multiple spritesheets
* Spritesheet can be referenced by multiple config files

* Openage uses 32-Bit RGBA colors
* Last alpha bit marks "special" pixels for renderer
* Used for special ingame graphics properties: generating outlines, reflection, etc.

* Sprite Editor should accomplish:
    * Create spritesheet + config file from frames/images provided by users/modders
    * View spritesheet graphics and visualize "special" pixels. Also work with config file features
    to display different layers, the animation, hotspots and other things
    * Edit config file parameters for existing config file

* Main audience is modders
* User-friendly GUI is a must!
* GUI will probably designed with others from the dev team

# Expected Outcome

* Viewing frames and sprites in the Editor, including visualization for advanced info (layers, "special" pixels)
* View animations based on config file parameters
* Edit metadata of animation in existing config files
* Create new spritesheets and/or config files from scratch

## Optional tasks

* Integrating Blender/Krita/Photoshop scripting

## Further Reading

* Python image manipulation with *pillow*: https://pillow.readthedocs.io/en/stable/
* openage `.sprite` format definition: https://github.com/SFTtech/openage/issues/965#issuecomment-467404874
