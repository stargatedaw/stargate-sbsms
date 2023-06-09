# stargate-sbsms
Fork of the audio time stretching, pitch shifting library+CLI
[SBSMS](https://sourceforge.net/projects/sbsms/).
The original has been unmaintained for many years, this is a hard fork that
has diverged significantly from the original.

# Current Differences
* Support for Unicode/UTF-16/widechar file paths for `sbsms.exe` CLI args
  on Windows (as to say, does not fail when run on non US/English locales)
* Unused functionality (in Stargate DAW) has been stripped away, this is now
  just the CLI without the library
* Remove the original build system (clunky, outdated autotools), replace with
  a streamlined and simple Makefile
* Vastly improved support for Windows/MSYS2, M1 Mac and ARM on Linux
* Remove all x86 assembly language

# Original README
```
Content
=======

libsbsms is a library for high quality time and pitch scale modification.  It uses octave subband sinusoidal modeling.

sbsms has optional support for libsndfile(--enable-sndfile) and libmad(--enable-mp3) for reading(.wav and .mp3) and writing(.wav) files, and optional support for portaudio for playing .sbsms format files(--enable-portaudio) with sbsmsplay.

The API is found in sbsms.h.  sbsms_create is called and supplied a callback which feeds sbsms_process samples.  The pitch_create and pitch_process functions are called only if pitch shifting is required.  It simply sticks a resampler on the end of the FIFO.

A program called sbsms is included.  It reads PCM files such as .wav and .aif (and .mp3 files if --enable-mp3), and writes .wav files using libsndfile.  The usage is:
sbsms infile outfile rate-start rate-end halfsteps-start halfsteps-end <quality>

For example:
sbsms blob.wav blobOut.wav .5 .5 0 2
will slow down blob.wav by a factor of 2, while simultaneously sliding the pitch up two half-steps, and put the output in blobOut.wav

Without sndfile support, the sbsms program will read text files in the format:
%g %g\n
...
and write output in the same format.

sbsms can also write .sbsms format files:
sbsms blob.wav blob.sbsms 1 1 0 0

which can be quickly rendered into .wav files at a new rate/pitch:
sbsms blob.sbsms blobOut.wav .5 .5 0 2

or played in realtime with sbsmsplay (if --enable-portaudio):
sbsmsplay blob.sbsms .5 .5 0 2

NOTE:
When reading the output from sbsms, you must determine a stopping condition for yourself, as the library zero pads the output ad infinitum and never returns 0 samples.  The simplest method for doing so is found in test.cpp.

Clayton Otey (otey@users.sourceforge.net)

Requirements
============

  POSIX systems (e.g. Linux, OS X):
  ---------------------------------

  You need at least to have libtool installed to be able to build the
  library with "./configure && make".

Compiling
=========

  Call './configure && make' on the console to compile the library, all
  tools and demo applications, documentation and install them with
  'make install'. The latter has to be called as root.

  If you are compiling from CVS you have to call 'make -f Makefile.cvs'
  to generate all autotools build files before calling
  './configure && make'.

  You can use 'make distclean' and probably 'make -f Makefile.cvs clean'
  to clean up everything again. The latter will also delete all automatic
  generated autools build files.
```
