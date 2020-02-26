# nyan Python API

**Difficulty:** Easy

**Mentors:** jj, heinezen

**Requirements:**
* Basic programming skills in C++ *and* Python

**Helpful skills:**
* Basic programming skills in Cython (if you fulfil the requirements, learning it should be very easy)
* Knowledge about the nyan language specification
* API design

## Motivation

Our engine uses [nyan](https://github.com/SFTtech/nyan) as a database for
storing game relevant data such as unit attributes and configuration. The
system uses an object-oriented approach by managing data as hierarchical
objects with key-value pairs. nyan is custom made and tailored to fulfil
the needs of RTS games.

Currently, the main library is written in C++. This project is aimed at
making the nyan database accessible to Python scripting by exposing
the functionality of `libnyan` via an API.

## Description (long)

nyan is our database for storing and managing data (i.e. unit attributes
and configuration) during a game. Internally, nyan data is organized using
an object-oriented approach where each object stores attributes as
key-value pairs (members). Objects in nyan can also inherit other objects
to gain their properties. nyan allows for object attributes to be updated
by applying nyan patches; special objects that change the value's of another
object's existing members.

Right now, nyan is used in openage as a shared library that is only accessible
via a C++ interface. The primary goal of this project is to expose the
functionality of the nyan library via a Python interface. This interface is
intended to be used non-core utilities of openage, namely the converter and
the modpack editor. The engine core will still use the C++ interface.

Example features to expose include:

* Adding/removing objects
* Manipulating objects via patches
* Operate on database views and create new ones
* Sanity check for nyan files
* Import resolving
* Parsing nyan objects from files
* Writing objects to file

Our recommended approach would be to create a Cython wrapper for the C++
code of nyan. Python scripts can then call the wrapper to directly
call the nyan library. The API should be designed to be usable without
deep knowledge of the nyan database internals.

# Expected Outcome

* nyan functionality can be accessed via a Python nodule

## Optional tasks

* nyan parser integration for the openage converter (Python)

## Further Reading

* nyan quickstart guide: https://github.com/SFTtech/openage-modding/blob/master/tutorials/nyan/getting_started.md
* nyan language design and implementation: https://stuff.sft.mx/openage/thesis_nyan.pdf
* nyan language specification https://github.com/SFTtech/nyan/blob/master/doc/nyan.md
