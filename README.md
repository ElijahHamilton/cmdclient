# Compiling
To start, you will need a copy of the voicetext library.
For windows, the library is vt_eng.dll (dll not provided for legal reasons)

To compile on msys2 (32 bit):  gcc cmdclient.c vt_eng.dll -o cmdclient

Other OSes supported soon!

# Cmd Usage
To generate a raw s16 audio file: cmdclient.exe "Input Text Here" output.pcm 100

First argument: input text
Second argument: output audio file
Third argument: output audio speed
