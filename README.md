# What's this?

This repository is collection of script and hack to launch a Anomaly, a standalone mod for S.T.A.L.K.E.R.: Call of Pripyat that really doesn't require the base game, with Steam Proton with Steam hours tracking and working overlay, without messing with game content.

It consists of launcher script and runner.

Theoretically, it can be adopted to launch anything with overlay with whatever Steam appid you specify that you own in library.

Inspired by and borrowed from [
openmw-steam-launcher
](https://github.com/steevp/openmw-steam-launcher).

## Launcher python script

Place anywhere. You **need** to edit all pointing values because they are all different on your PC.

## Runner

You need Steamworks SDK to actually compile it. Makefiles for compiling with mingw are provided.

Place _steamrunner.exe_ in mod root folder where AnomalyLauncher.exe is. Provided .exe requires _steam\_api64.dll_, grab it from any game and place near as well.

### but why? can't you just load steam_api.so like in original script?

I tried. Game throws error, dunno why.
