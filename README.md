# ft_ssl_md5
This prorgamm was a first project of security branch at [42 Silicon Valley](https://www.42.us.org/). The goal was to recreate part of the [OpenSSL](https://en.wikipedia.org/wiki/OpenSSL) functionality. OpenSSL is a cryptographic toolkit library written C that is used to secure communications over computer networks. It implements the Secure Sockets Layer (SSL) and Transport Layer Security (TLS) network protocols to protect against eavesdropping and verify identities during network communication.

Implemented functions for this project: [MD5](https://en.wikipedia.org/wiki/MD5), [SHA254](https://en.wikipedia.org/wiki/SHA-2), [SHA256](https://en.wikipedia.org/wiki/SHA-2), [SHA384](https://en.wikipedia.org/wiki/Secure_Hash_Algorithms), [SHA512](https://en.wikipedia.org/wiki/SHA-2).

## How to use

1. Build

	`make`

2. Launch

	`./ft_ssl command [command opts] [command args]`

## Usage

* command: `md5` `sha224` `sha256` `sha384` `sha512`

* command opts: `[-pqr] [-s string] [files ...]`

    * `-p`, echo STDIN to STDOUT and append the checksum to STDOUT
    * `-q`, quiet mode
    * `-r`, reverse the format of the output
    * `-s`, print the sum of the given string
## Examples

`./ft_ssl md5 -s "Hello World"`

MD5 ("Hello World") = b10a8db164e0754105b7a99be72e3fe5

`echo "Some important message" | ./ft_ssl sha256 -p -s "Hello World" Makefile`

Some important message

31d1104978e7f73a0da6375f1b0d9add90bf96fbc5ef4dc9fb16804697ef2894

SHA256("Hello World")= a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e

SHA256(Makefile)= 8f959d6ccc1e4127677099b0a0f99f85cf97e232eccc1def7c13e7437c2d9b2e
