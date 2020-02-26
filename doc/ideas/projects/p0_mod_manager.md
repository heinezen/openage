# Mod Manager (Package management)

**Difficulty:** Medium

**Mentors:** heinezen, simonsan

**Requirements:**
* Basic programming skills in Python *and* C++
* Basic knowledge of cryptographic signatures and hashing

**Helpful skills:**
* Knowledge of package management workflows (e.g. [dpkg](https://en.wikipedia.org/wiki/Dpkg) or [apt](https://en.wikipedia.org/wiki/APT_(software)))

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

In the openage eco-system, games and mods are distributed as *modpacks*.
Modpacks are conceptualized to provide the same functionality packages
in Linux and UNIX environments for modding purposes. Doing so gives
modders access to several advanced features such as versioning and
defining other mods as dependencies for their content.

As a result, the requirements of the openage mod manager are the same as
for general package management systems. The core functionality of the
mod manager should therefore provide these basic features:

1. Modpack installation and configuration
2. Conflict resolving
3. Dependency management
4. Load order management
5. Updating mods to newer versions

It is the responsibility of the mod manager to automate these tasks and
create a configuration of modpacks that is safe for the engine to load.

Regarding modpack installation, the mod manager should be able to
handle the two main installation methods: Local installation and
fetching from a (public) repository.

The mod manager should execute basic integrity and security
checks to prevent malicious mods from exploiting the engine's scripting
interface to damage the user's system. This involves signature validation
for single modpacks and indices of public repositories. Unsigned scripts
should be detected, flagged and deactivated.

It is recommended to design the command-line interface of the mod manager
first and add a GUI for the launcher later on. However, if you have time
and skill to create a user interface for the mod manager, you can design
CLI and GUI in parallel.

## Expected Outcome

* CLI interface for managing modpacks (similar to apt/dpkg)

## Optional tasks

* GUI integration
* Accessing External APIs (mod.io)
* Game configurations (profiles)

## Further Reading

* Modpack definition format specification: https://github.com/SFTtech/openage/issues/632
