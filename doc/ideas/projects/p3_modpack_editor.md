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

* *Warning*: This is a challenging task with lots of components to consider. It requires dedication and learning about the connected engine components. If you are not afraid to work your way deeply into openage's engine components and fulfill the requirements, this is a task for you. However, if you do not feel comfortable with the scope of this task, you should take a look at the Sprite Editor project instead.

* Modpacks contain game data and assets used in the engine
* Data stored as human-readable nyan files on disk
* nyan is our object-oriented database language with is used for the openage modding API
* Objects are plain-text definitions similar to YAML or JSON formats

* openage API uses Entity Component System structure to provide an RTS interface
* e.g. units are objects and store a list of passive/active abilities (Move, Live, Attack, Die)
* abilities contain members for units stats (movement speed, max HP, damage)
* by changing member values, modders are configuring their units' behavior ingame

* We would like to make this modding as accessible as possible
* However, plain-text files are not very friendly for beginners
* Also hard to keep track of for larger modpacks
* Modpack Editor should provide a *visual aid* to modders and make editing easier

* Underlying structure is the openage modding API
* Thus the editor must orient itself towards its structure
* It's best that Student understands the API very well before writing any code
* The Editor should be seen as a user-friendly, high-level interface to the API

* Modpack Editor should be sustainable for long-term, i.e. the software should be maintainable to integrate new API changes
* Might be beneficial to support different/older API versions
* **Flexibility** and **modularity** is mandatory
* Thus the student should use some form of software modelling practices like DDD or WAM

* GUI is a very important component
* Without good UI/UX, the modpack editor is not as powerful as we desire
* Therefore, the student must be capable of standard UI design techniques
* GUI design will take place at the start of the project (together with other from dev team and mentors)

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
