# Intro

These tasks are only meant as a source of inspiration and you
are welcome to discuss your own ideas with the project team.

Regardless of whether you take on a recommended project or come
up with an idea on your own: Please discuss everything with
the mentors and the development team first. This will ensure
that you get all the relevant infos you need and enables
us to find a scope for the project you want to work on.

Contact: [#sfttech:matrix.org](https://riot.im/app/#/room/#sfttech:matrix.org)

## Project 1: Mod Manager (Package management)

User-generated content for openage is organized in *modpacks*. Modpacks
contain everything relevant to a game or mod, including game data,
assets, scripts and scenarios. openage allows several modpacks to
be active at the same time (at runtime). Thus modpack definitions
can use advanced features usually found in package management systems
used in Linux environments. For example, modpacks can have dependencies
or conflicts with other modpacks.

The goal of this project is to create a basic package management
system for organizing openage modpacks. The package management should
allow users to install, manage and configure modpacks as well
as resolving problems and interdependencies.

[Read More](p0_mod_manager.md)

## Project 2: nyan Python API

Our engine uses [nyan](https://github.com/SFTtech/nyan) as a database for
storing game relevant data such as unit attributes and configuration. The
system uses an object-oriented  approach by managing data as hierarchical
objects with key-value pairs. nyan is custom made and tailored to fulfill
the needs of RTS games.

Currently, the main library is written in C++. This project is aimed at
making the nyan database accessible to Python scripting by exposing
the functionality of `libnyan` via an API.

[Read More](p1_nyan_python_api.md)

## Project 3: Sprite Editor

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

[Read More](p2_sprite_editor.md)

## Project 4: Modpack Editor (Only Data)

*Modpacks* are collections of user-generated content usable by the engine.
This includes game data, assets, scripts and scenarios. For this purpose,
the modpacks contain configuration data written in the [nyan](https://github.com/SFTtech/nyan)
language which accesses the *openage nyan API*. The API provides a high-level
interface of the engine's functions to modders and lets them define ingame
objects such as units and buildings as well as enabling them to configure
parameters for those.

By default, the data in these modpacks is stored as human-readable plain-text
files. While these are easily editable by modders, this approach is probably
not very user-friendly and requires knowledge of the nyan language, thus
creating a significant overhead for modders.

This project's goal is the design and implementation of a Graphical
Modpack Editor for openage modpacks. The Editor should provide modders
with tools to manage and manipulate data in the modpack, even if they are
not trained in the nyan language.

[Read More](p3_modpack_editor.md)
