# wadmaps

WADMaps is an attempt to determine what levels a doom wad is meant to be played on. Not all WADs come with a handy txt file that tells you which level it is and not all of them use E1M1 or MAP01 when there is only one level. 

## How
This program will look through the binary wad file passed as an argument and return the levels in the wad. It will try to match a known level name (such as E3M5) to text in the file. If there is a match the level is assumed to used in the game. It is a basic text search like the UNIX `strings` command but is designed to just find doom level names.

## Why
This program will be useful for automation. With it you could parse a wad, load it into a server, then set the server to the correct map. 
I made it for a project involving the automation of playing the 1830 wad files from Maximum Doom on my Master Levels for Doom 2 disc.

## Example

```
$ wadmap doom1.wad 
E1M1 E1M2 E1M3 E1M4 E1M5 E1M6 E1M7 E1M8 E1M9 
$ wadmap doom.wad
E1M1 E1M2 E1M3 E1M4 E1M5 E1M6 E1M7 E1M8 E1M9 E2M1 E2M2 E2M3 E2M4 E2M5 E2M6 E2M7 E2M8 E2M9 E3M1 E3M2 E3M3 E3M4 E3M5 E3M6 E3M7 E3M8 E3M9 E4M1 E4M2 E4M3 E4M4 E4M5 E4M6 E4M7 E4M8 E4M9 
$ wadmap airwalk.wad 
E1M1
$ wadmap 4pdeath.wad 
MAP01 
$ wadmap hotel_vu.wad # Corrupt Version on the Master Levels for Doom 2 disc and only plays music
```

