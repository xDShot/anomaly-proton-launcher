#!/usr/bin/env python 
import os
import sys
from subprocess import run

os.environ["STEAM_COMPAT_CLIENT_INSTALL_PATH"] = os.getenv("HOME") + "/.local/share/Steam/"
os.environ["PROTONDIR"] = os.getenv("STEAM_COMPAT_CLIENT_INSTALL_PATH") + "steamapps/common/Proton - Experimental/"
os.environ["WINEDEBUG"] = "-all"
os.environ["STEAM_COMPAT_DATA_PATH"] = "/evo/wineprefixes/anomaly/"
os.environ["STEAM_COMPAT_SHADER_PATH"] = os.getenv("STEAM_COMPAT_DATA_PATH") + "/shadercache/"
os.environ["WINEPREFIX"] = os.getenv("STEAM_COMPAT_DATA_PATH") + "/pfx/"
os.environ["STEAM_COMPAT_INSTALL_PATH"] = os.getenv("WINEPREFIX") + "/drive_c/anomaly_redux/"

# Stalker CoP
os.environ["SteamAppId"] = "41700"

# Enable Steam Overlay
os.environ["LD_PRELOAD"] = os.getenv("STEAM_COMPAT_CLIENT_INSTALL_PATH") + "/ubuntu12_64/gameoverlayrenderer.so"

run( [ os.getenv("PROTONDIR") + "proton", "waitforexitandrun", os.getenv("STEAM_COMPAT_INSTALL_PATH") + "steamrunner.exe" ], cwd=os.getenv("STEAM_COMPAT_INSTALL_PATH") )
