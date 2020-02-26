# Sprite Editor

**Difficulty:** Medium

**Mentors:** heinezen, simonsan

**Requirements:**
* Basic programming skills in Python *or* C++
* Basic knowledge of UI/UX design

**Helpful skills:**
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

Graphics for openage are stored as (PNG) spritesheets with
attached metadata files. The PNG spritesheet contains animation
frames in 32-Bit colour depth. For metadata, a plain-text
config file that stores additional renderer settings is used.

It should be noted that openage spritesheets are not purely
32-Bit RGBA images. The last bit of every pixel is reserved as
a *special marker* for fast rendering options. The marker
tells the renderer to assign a special property for the pixel.
Which property this is depends on the value of the last 8 bit
of the pixel (i.e. the alpha channel value). In practice,
special pixels are used for unit outlines, reflections and other
custom rendering modes of a pixel.

Information in the metadata config file includes relevant
parameters for reading and rendering the image such as:

* Assigned spritesheets
* Position and size of frames in the PNG spritesheet
* Anchorpoints of the frames
* Layer assignment
* Display time per frame
* etc.

Config metadata files can reference more than one spritesheet.
Spritesheets can also be referenced by multiple config metadata
files.

Taking this into account, the Sprite Editor should accomplish the
following:

1. It should be able to create the PNG spritesheet from frames/images
   provided by modders.
2. Similarly, modders should be able to create the configuration file
   by specifying the necessary parameters.
3. View spritesheet graphics and visualize "special" pixels. The visualization
   should include configuration file properties (layers, animation, anchor points).
4. Edit existing configuration file parameters.

The main audience of this tool is expected to be modders which have
no extensive knowledge about the technical background of the spritesheet
and configuration metadata formats described above. Therefore, a
user-friendly GUI is a must! Others from the development team can
assist you with the interface, if you have no experience in visual
design.

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
