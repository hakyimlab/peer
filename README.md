# PEER

This repository is an attempt to have a stable, working version of the `PEER` utility available for members of the Im Lab.

# Pre-compiled Executables

On CRI: `module load gcc/6.2.0 peer/1.3`

On Washington: `/vol/bmd/meliao/software/other_software/peer/build/src/peertool`

# Installation Instructions -- peertool executable

1. Go to the peer directory `cd peer`. 
1. Make a build directory and go to it `mkdir build ; cd build`
1. Run cmake `cmake ./..`
    1. This has two dependencies, cmake and swig. These can be installed with your package manager (on MacOS, I use `brew`, and on Ubuntu I use `apt`).
    1. On CRI, swig can be made available with `module load gcc/6.2.0 swig/3.0.12`
1. Run `make`. This should generate a lot of warnings, but hopefully no errors. 
1. Run `make install`. This should add the `peertool` executable to `/usr/local/bin`.
    1. If you want the executable installed somewhere else, you need to run the `cmake` command with the option `-DCMAKE_INSTALL_PREFIX=path/to/install`.
1. Check whether `peertool` was installed: `which peertool`

So all in all, here are the commands in order:
```
cd peer
mkdir build ; cd build
cmake ./..
make
make install
which peertool
peertool #Just to see if it runs
```


# Installation Instructions -- R package

TODO !!!

The first step is to edit line 9 of CMakeLists.txt so that the BUILD R option is ON. Then, follow most of the steps above and debug when you see errors.

# Tutorial

See [here](https://github.com/PMBio/peer/wiki/Tutorial) for tutorial.