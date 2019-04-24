# ft_ssl_md5
This is project is a recode of part of the OpenSSL program, in particular md5 and sha hashing algorithms.

## Description
The goal of this project is to understand the the way hashing algorithms work and are made.

### Functions
`md5`
`sha224`
`sha256`
`sha384`
`sha512`


## Using this binary
Build the binary using `make`

`gcc` is required to build

Usage is:
`ft_ssl `[hash_type] [-pqr] [-s string] [files...]`

All functions read from `STDIN` when no input is given.
Any number of strings or files can be hashed.  
The following flags have been included:

`-p` - read from `STDIN`, print the input and it's hash

`-q` - quiet mode

`-r` - reverse output format

`-s` - print the hash for the string that follows
