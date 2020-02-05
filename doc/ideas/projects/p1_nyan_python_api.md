# nyan Python API

Difficulty: Easy

Mentors: jj, heinezen

Requirements:
* Basic programming skills in C++ *and* Python

Helpful skills:
* Basic programming skills in Cython (if you fulfill the requirements, learning it should be very easy)
* Knowledge about the nyan language specification
* API design

## Motivation

Our engine uses [nyan](https://github.com/SFTtech/nyan) as a database for
storing game relevant data such as unit attributes and configuration. The
system uses an object-oriented  approach by managing data as hierarchical
objects with key-value pairs. nyan is custom made and tailored to fulfill
the needs of RTS games.

Currently, the main library is written in C++. This project is aimed at
making the nyan database accessible to Python scripting by exposing
the functionality of `libnyan` via an API.

## Description (long)

* nyan is our database language for storing and accessing game data (unit stats, abilities)
* Right now integrated in the C++ code of openage for gamestate

* Goal: Access nyan operations via Python
* Direct communication (so not only for ingame access)
* Intended to be used by other tools such as the openage converter and a modpack editor

* Recommended approach: Cython wrapper for C++ code
* Expose cython functions to Python
* Usable API design is important

* Example functionality:
    * Adding/removing objects
    * Manipulating objects via patches
    * Operate on database views and create new ones
    * Sanity check for nyan files
    * Import resolving
    * Writing objects to file

# Expected Outcome

* nyan functionality can be accessed via a Python nodule

## Optional tasks

* nyan parser integration for the openage converter (Python)

## Further Reading

* nyan quickstart guide: https://github.com/SFTtech/openage-modding/blob/master/tutorials/nyan/getting_started.md
* nyan language design and implementation: https://stuff.sft.mx/openage/thesis_nyan.pdf
* nyan language specification https://github.com/SFTtech/nyan/blob/master/doc/nyan.md
