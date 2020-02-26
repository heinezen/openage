# Modpack Editor (Only Data)

Difficulty: Hard

Mentors: heinezen, simonsan, jj

Requirements:
* Good programming skills in Python *or* C++
* Familiarity with software modelling/engineering practices such as Domain Driven Design
* Good knowledge of UI/UX design

Helpful skills:
* Real-time Data and graph visualization
* Knowledge of the openage nyan API specification
* Knowledge about the nyan language specification
* Modding experience for any RTS game

## Motivation

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

## Description (long)

*Warning*: This is a challenging task with lots of components to consider.
It requires dedication and learning about the connected engine components.
If you are not afraid to work your way deeply into openage's engine components
and fulfill the requirements, this is a task for you. However, if you
do not feel comfortable with the scope of this task, you should take a
look at the Sprite Editor project instead.

*Modpacks* refers to a collection of game data and assets used
by the openage engine. On disk, game data is stored as human-readable
plain-text nyan files. nyan is our database and language format
used in the engine and the modding API. The format is very similar
to YAMl and JSON in its definition.

Game data nyan files in a modpack make use of the openage modding API for
configuration. This API is structured as a entity component system and
provides modders with functionality for the usual RTS features. As the API
is the basis for openage modding, the Modpack Editor should build upon
its structure. It is a good idea to get a good understanding of the API
first, before writing any code.

The preliminary goal of the Modpack Editor is to remove the need to
edit the game data files manually and instead provide a high-level view
for editing and creating modpacks. We would like to make modding as
easy as possible for beginners as well as aiding more advanced users
through an ease-of-use principle. The Modpack Editor can be understood
as a visual aid for using the modding API.

It is important that the Modpack Editor is sustainable long-term, i.e.
we should be able to easily integrate API changes without a hassle.
**Flexibility** and **modularity** is mandatory for this task. You should
use some form of software modelling practice to ensure this such as
Domain Driven Design.

The GUI of the Modpack Editor is a very important component and should
not be an afterthought. Without a good user experience, the editor will
not be as powerful as we desire. Therefore, you must be capable of
standard UI design practices.

# Expected Outcome

* GUI Editor for editing modpacks using the openage modding API
* Changing values of unit stats (member values) and other API objects
* Adding and removing units and other API objects
* Creating a release version of a modpack that modders can distribute

## Optional tasks

* Modpack signing
* Non-destructive editing (changing data in a modpack creates another modpack0)
* Merging modpacks
* Collaboration tools (git integration)

## Further Reading

**nyan**

* nyan quickstart guide: https://github.com/SFTtech/openage-modding/blob/master/tutorials/nyan/getting_started.md
* nyan language design and implementation: https://stuff.sft.mx/openage/thesis_nyan.pdf
* nyan language specification: https://github.com/SFTtech/nyan/blob/master/doc/nyan.md

**openage API**

* openage API design: https://github.com/SFTtech/openage/blob/master/doc/nyan/openage-lib.md
* openage API reference: https://simonsan.github.io/openage-webdocs/sphinx/doc/nyan/api_reference/index.html

**Existing AoE2 modding tools**

* Advanced Genie Editor: http://aok.heavengames.com/blacksmith/showfile.php?fileid=11002
* Turtle Pack: http://aok.heavengames.com/blacksmith/showfile.php?fileid=11349
