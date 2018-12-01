@echo off
nim compile --threads:on --passL=-lstdc++ --run src/Newtoo.nim
pause