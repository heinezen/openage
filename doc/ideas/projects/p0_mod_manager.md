# Mod Manager (Package management)

Difficulty: Medium

Mentors: heinezen, simonsan

Requirements:
* Basic programming skills in Python *and* C++
* Basic knowledge of cryptographic signatures and hashing

Helpful skills:
* Konwledge of package management workflows (e.g. [dpkg](https://en.wikipedia.org/wiki/Dpkg) or [apt](https://en.wikipedia.org/wiki/APT_(software)))

## Motivation

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

## Description (long)

* Games and mods are modpacks
* UNIX-like package management

* Public repositories for mods
* Updates pulled from repos automatically
* Local installation also allowed

* Challenges:
    * Conflict resolving
    * Dependency management
    * Load order management
* At the end, the mod manager should provide a configuration of mods for the engine to load

* Address basic security checks
* Signature validation for single modpacks (MANIFEST file) and repos (RELEASE file)
* Searching for unsigned scripts (security issues)

* Launcher integration is optional, since launcher is not finished
* GUI can be designed by student if they have time and skill

## Expected Outcome

* CLI interface for managing modpacks (similar to apt/dpkg)

## Optional tasks

* GUI integration
* Accessing External APIs (mod.io)
* Game configurations (profiles)

## Further Reading

* Modpack definition format specification: https://github.com/SFTtech/openage/issues/632
